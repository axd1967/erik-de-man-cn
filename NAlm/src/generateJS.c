#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "primitives.h"




int getDegMin(double f, int *deg, int *min)

{

  (*deg)=floor(f);
  (*min)=floor((f-(*deg))*600.0+0.5);

  return (*deg)*600 + (*min);
}





void GenerateJScompactEph(double *oJD, double oGHA[][6], double oDec[][6],double oDist[][6])

{ short int year,month,day;
  int       k,obj,ndays;
  char      filename[19];
  double    now,hour;
  double    GHA,DEC,DIS,delta;

  FILE *fp;


  now=oJD[0];
  cal_date(now,&year,&month,&day,&hour);
  ndays=366;

  if(year%4) ndays=365;

  sprintf(filename,"Data/eph_%04d.js",year);
  if((fp=fopen(filename,"w"))==NULL)
  { printf(" Error (GenerateJS) could not open file \"%s\" for writing!\n",filename);
    exit(-1);
  }

  fprintf(fp,"// This file contains the ephemerides data for %d \n",year);
  fprintf(fp,"// Data is arranged daywise with 3 entries (Dec,GHA,Distance) for each 6 objects (Sun,Venus,Moon,Mars,Jupiter,Saturn) valid at 00:00 UTC on that day.\n");
  fprintf(fp,"// The epemerides array is from \"Jan 1st\" to \"Jan 1st\" next year included!\n");
  fprintf(fp,"// \n");
  fprintf(fp,"// The last triplet in each line are the coefficients for correcting the linear interpolated  moon data. The correction term is calculated\n");
  fprintf(fp,"// as: -a/144 * x * (x-24) with a the tabulated coefficient and x the hour of the day between 0 and 24. The correction coefficients are\n");
  fprintf(fp,"// the deviation between the interpolated and real values at 12:00 hour. The deviation is approximated by a quadratic function\n");
  fprintf(fp,"// with roots at 00:00 and 24:00 hour (the base points of the tabulated data).\n");
  fprintf(fp,"// \n");
  fprintf(fp,"var eph%04d_range = %d;\n",year,year);
  fprintf(fp,"var eph%04d=new Array(%d);\n\n",year,ndays+1);    /* array is from "Jan 1st" to "Jan 1st" next year included! */

  for(k=0; k<ndays+1; k++)
  { 
    fprintf(fp,"eph%04d[%3d]=new Array(",year,k);

    for(obj=0; obj<6; obj++)
    { 
      DEC=oDec[k*24][obj];
      GHA=oGHA[k*24][obj];
      DIS=oDist[k*24][obj];

      fprintf(fp,"%9.5f,%9.5f,%10.7f",DEC,GHA,DIS);
      fprintf(fp,",");
    }

    /* for the MOON also plot the 12:00 deviation data to allow quadratic interpolation ... */
    if(k < ndays)
    { 
      delta = oDec[k*24+24][2] - oDec[k*24][2];
      DEC = oDec[k*24+12][2] - (oDec[k*24][2] + 0.5 * delta);
  
      delta = 360.0 + oGHA[k*24+24][2] - oGHA[k*24][2];
      if(delta > 400.0) delta -= 360.0;
      GHA = oGHA[k*24+12][2] - (oGHA[k*24][2] + 0.5 * delta);     /* this is the deviation between 12:00 value and 12:00 interpolated value */
      if(GHA < -10.0) GHA += 360.0;
      if(GHA >  10.0) GHA -= 360.0;
     
      delta = oDist[k*24+24][2] - oDist[k*24][2];
      DIS = oDist[k*24+12][2] - (oDist[k*24][2] + 0.5 * delta);
    } 
      else 
      { GHA = 0.0;
        DEC = 0.0;
        DIS = 0.0;
      }

    fprintf(fp,"%9.5f,%9.5f,%10.7f",DEC,GHA,DIS);
    fprintf(fp,");\n");
  }
  fclose(fp);

  return;
}






void GenerateJS(double *oJD, double oGHA[][6], double oDec[][6],double oHP[][6],double oSD[][6])

{ short int year,month,day;
  int       i,k,y,obj,ns,d;
  int       GHAdeg,DECdeg,GHAmin,DECmin,GHA0,DEC0,GHA1,DEC1;
  char     *planets[6] = {"sun","ven","moo","mar","jup","sat"};
  char      filename[19],ys[3];
  double    now,hour;
  double    GHA,DEC;

  FILE *fp;


  GHAdeg=DECdeg=GHAmin=DECmin=0;

  now=oJD[0];
  cal_date(now,&year,&month,&day,&hour);

  for(obj=0; obj<6; obj++)
  { y=year-2000;
    if(y<10) sprintf(ys,"0%d",y); else sprintf(ys,"%d",y);
    sprintf(filename,"Data/ad_%s%s.js",planets[obj],ys);
    if((fp=fopen(filename,"w"))==NULL)
    { printf(" Error (GenerateJS) could not open file \"%s\" for writing!\n",filename);
      exit(-1);
    }

    fprintf(fp,"var ead%s=new Array(366);\n\n",ys);

    for(k=0; k<366; k++)
    { day=(((int)(oJD[k]+1.25))%7)+1;
      GHA=oGHA[k*24][obj];
      DEC=oDec[k*24][obj];

      /* get the sign of declination ("N"=+1/"S"=-1) and get positive declination value ... */
      ns=1; 
      if(DEC<0) { ns=-1; DEC*=-1; }
      
      GHA0=getDegMin(GHA,&GHAdeg,&GHAmin);
      DEC0=getDegMin(DEC,&DECdeg,&DECmin);
      DEC0*=ns;
      
      fprintf(fp,"ead%s[%d]=new Array(%d,%d,%d,%d,%d,%d",ys,k,day,GHAdeg,GHAmin,ns,DECdeg,DECmin);

      for(i=1; i<25; i++)
      { GHA=oGHA[k*24+i][obj];
        GHA1=getDegMin(GHA,&GHAdeg,&GHAmin);
        d=GHA1-GHA0;
        if(d<0) d+=360*600;
        d-=15*600;
        fprintf(fp,",%d",d);
        GHA0=GHA1;
      }

      for(i=1; i<25; i++)
      { DEC=oDec[k*24+i][obj];
        ns=1;
        if(DEC<0) { ns=-1; DEC*=-1; }       

        DEC1=ns*getDegMin(DEC,&DECdeg,&DECmin);
        d=DEC1-DEC0;
        fprintf(fp,",%d",d);
        DEC0=DEC1;
      }

      for(i=2; i<24; i+=4)
      { d=floor(oHP[k*24+i][obj]*10.0+0.5);
        fprintf(fp,",%d",d);
      }

      for(i=2; i<24; i+=4)
      { d=floor(oSD[k*24+i][obj]*10.0+0.5);
        fprintf(fp,",%d",d);
      }

      
      fprintf(fp,");\n");
    }
    fprintf(fp,"\n");
    
    fclose(fp);
  }

  return;
}
