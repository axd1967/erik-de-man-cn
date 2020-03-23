#include <stdio.h>
#include "../novas/novas.h"
#include "dimensions.h"



typedef struct

{ 
  int    type;

  double dGHA[9];
  double dDec[9];
  double SD[9];
  double JD[9];
  double Pbeta[9];
  double Ubeta[9];
} 

MoonPathType;




void DrawMoonPaths(FILE *fp, MoonPathType *MoonPaths)

{ int        i,j;
  short int  year,month,day;
  short int  m0,m1,d0,d1;
  double     hour,h0,h1;
  double     x,y,y0;
  double     xscale,yscale,scale=50.0;
  char      *months[12] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
  char      *months_short[12] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
  char       s[8],s0[8],s1[8];

  void       PrintHeader();
  char      *time2s();


  for(i=0; i<6; i++)
  { MoonPaths[i].type=0;

    if(MoonPaths[i].SD[1]>0.0) MoonPaths[i].type=1;
    if(MoonPaths[i].SD[2]>0.0) MoonPaths[i].type=2;
    if(MoonPaths[i].SD[3]>0.0) MoonPaths[i].type=3;
  }


  y0=13.3;
  x=0.0;
  y=715.2-18*y0;

  for(i=0; i<6; i++)
  { if(MoonPaths[i].type>0)
    { cal_date(MoonPaths[i].JD[4],&year,&month,&day,&hour);
      fprintf(fp,"%.1f %.1f moveto 10 f1 (%s %d :) show\n",x,y,months[month-1],day);

      cal_date(MoonPaths[i].JD[1],&year,&m0,&d0,&h0);
      cal_date(MoonPaths[i].JD[7],&year,&m1,&d1,&h1);
      if(MoonPaths[i].type==1) fprintf(fp,"%.1f %.1f moveto 10 f0 (a penumbral lunar eclipse) show\n",x+74.0,y);
      if(MoonPaths[i].type==2) fprintf(fp,"%.1f %.1f moveto 10 f0 (a partial lunar eclipse) show\n",x+74.0,y);
      if(MoonPaths[i].type==3) fprintf(fp,"%.1f %.1f moveto 10 f0 (a total lunar eclipse) show\n",x+74.0,y);
      fprintf(fp,"475.0 %.1f moveto 10 f0 (begin [ %s %d,  %s UTC ] /  end [ %s %d,  %s UTC ]) Rshow\n",y,months_short[m0-1],d0,time2s(h0,s0),months_short[m1-1],d1,time2s(h1,s1));


      if(MoonPaths[i].type>1) 
      { fprintf(fp,"gsave\n");
        fprintf(fp,"160 %.1f translate\n",y-92.0);
        fprintf(fp,"0.1 setlinewidth\n");

        xscale=scale*cos(0.5*(MoonPaths[i].SD[0]+MoonPaths[i].SD[8]));
        yscale=scale;
        
        fprintf(fp,"0.95 setgray newpath 0 0 %.1f 0 360 arc fill\n",scale*MoonPaths[i].Pbeta[4]);
        fprintf(fp,"0.85 setgray newpath 0 0 %.1f 0 360 arc fill\n",scale*MoonPaths[i].Ubeta[4]);
      
        fprintf(fp,"0.00 setgray newpath 0 0 %.1f 0 360 arc stroke\n",scale*MoonPaths[i].Pbeta[4]);
        fprintf(fp,"0.00 setgray newpath 0 0 %.1f 0 360 arc stroke\n",scale*MoonPaths[i].Ubeta[4]);

        fprintf(fp,"0.4 setlinewidth\n");
        fprintf(fp,"newpath %.1f %.1f moveto ",xscale*MoonPaths[i].dGHA[0],yscale*MoonPaths[i].dDec[0]);
        for(j=1; j<9; j++)
          if(MoonPaths[i].SD[j]!=0.0) fprintf(fp,"%.1f %.1f lineto ",xscale*MoonPaths[i].dGHA[j],yscale*MoonPaths[i].dDec[j]);
        fprintf(fp,"stroke\n");

        for(j=1; j<8; j++)
          if(MoonPaths[i].SD[j]>0.0) 
          { fprintf(fp,"newpath %.1f %.1f moveto 2 0 rlineto -4 0 rlineto 2 0 rlineto 0 2 rlineto 0 -4 rlineto stroke\n",
                        xscale*MoonPaths[i].dGHA[j],yscale*MoonPaths[i].dDec[j]);
            if(j!=4) 
            { fprintf(fp,"0.00 setgray newpath %.1f %.1f %.1f 0 360 arc stroke\n",xscale*MoonPaths[i].dGHA[j],yscale*MoonPaths[i].dDec[j],scale*MoonPaths[i].SD[j]);
              fprintf(fp,"%.1f %.1f moveto 8 f0 (%d) Cshow\n",xscale*MoonPaths[i].dGHA[j],yscale*MoonPaths[i].dDec[j]-9.2,j);
            }
          }

        fprintf(fp,"0 setgray 10 f0\n");
        if(MoonPaths[i].dDec[4] < 0) yscale*=-1;
        fprintf(fp,"0 %.1f moveto (umbra) Cshow\n",   -0.65*yscale*MoonPaths[i].Ubeta[4]-5.0);

        cal_date(MoonPaths[i].JD[1],&year,&month,&day,&hour);
        fprintf(fp,"142 %.1f moveto 10 f0 (%s %d) show\n",50.0,months[month-1],day);
        cal_date(MoonPaths[i].JD[7],&year,&month,&day,&hour);
        fprintf(fp,"142 %.1f moveto 10 f0 (%s %d) show\n",-50.0,months[month-1],day);
        fprintf(fp,"0 %.1f moveto (penumbra) Cshow\n",-0.78*yscale*MoonPaths[i].Pbeta[4]-5.0);

        for(j=1; j<8; j++)
          if(MoonPaths[i].SD[j]>0.0)
          { if(j!=4) fprintf(fp,"120 %.1f moveto 8 f0 ( %d -) show\n",48.0-j*12.0,j);

            cal_date(MoonPaths[i].JD[j],&year,&month,&day,&hour);
            fprintf(fp,"142 %.1f moveto 8 f0 (%s  UTC) show\n",48.0-j*12.0,time2s(hour,s));

            if(j==1) fprintf(fp,"200 %.1f moveto  8 f0 (begin of penumbral eclipse) show\n",48.0-j*12.0); 
            if(j==2) fprintf(fp,"200 %.1f moveto  8 f0 (begin of partial eclipse) show\n",48.0-j*12.0); 
            if(j==3) fprintf(fp,"200 %.1f moveto  8 f0 (begin of total eclipse) show\n",48.0-j*12.0); 
            if(j==4) fprintf(fp,"200 %.1f moveto  8 f0 (moment of greatest eclipse) show\n",48.0-j*12.0); 
            if(j==5) fprintf(fp,"200 %.1f moveto  8 f0 (end of total eclipse) show\n",48.0-j*12.0); 
            if(j==6) fprintf(fp,"200 %.1f moveto  8 f0 (end of partial eclipse) show\n",48.0-j*12.0); 
            if(j==7) fprintf(fp,"200 %.1f moveto  8 f0 (end of penumbral eclipse) show\n",48.0-j*12.0); 
          }

        fprintf(fp,"-150 60.0 moveto 6 f4 (Rp =%7.4f\\260) show \n",MoonPaths[i].Pbeta[4]);
        fprintf(fp,"-150 48.0 moveto 6 f4 (Ru =%7.4f\\260) show \n",MoonPaths[i].Ubeta[4]);

        y-=15*y0;
        fprintf(fp,"grestore\n");
      }
    }
    y-=3.0*y0;
  }

  return;
}




void SetMoonPath(MoonPathType *MoonPaths, int m, int i, double dGHA, double dDec, double SD, double JD, double Pbeta, double Ubeta)

{        int j,k;
  static int ft=0;

  if(!ft)
  { for(j=0; j<6; j++) for(k=0; k<9; k++) MoonPaths[j].SD[k]=0.0;
    ft=1;
  } 

  MoonPaths[m].dGHA[i] =dGHA*57.29577951;
  if(MoonPaths[m].dGHA[i]>180.0) MoonPaths[m].dGHA[i]-=360.0;
  MoonPaths[m].dDec[i] =dDec*57.29577951;
  MoonPaths[m].SD[i]   =SD;
  MoonPaths[m].JD[i]   =JD;
  MoonPaths[m].Pbeta[i]=Pbeta;
  MoonPaths[m].Ubeta[i]=Ubeta;

  return;
}






void FormatMoonEclipse(double *oJD, double oRA[][6], double oDec[][6], double oDist[][6], double oSD[][6], int *page, FILE *fp)

{ int       i,k,m,n;
  int       UT,ydays;
  
  short int eclipse_state;
  short int year,month,day;


  double    y,y0;
  double    JD,now,hour,mT;
  double    mGHA,cGHA,mDec,cDec,Dis,SD,mDis;
  double    Pbeta;               /* Pbeta  is the apperture of the penumbra cone at the moon distance as seen from the Earth (in degrees)          */
  double    Pbeta0,Pbeta1; 
  double    Ubeta;               /* Ubeta  is the apperture of the umbra cone at the moon distance as seen from the Earth (in degrees)             */
  double    Ubeta0,Ubeta1; 
  double    MoonPath[9][6];      /* component dRA,dDec,SD,JD,Pbeta,Ubeta */

  MoonPathType MoonPaths[6];
 

  now=oJD[0];
  cal_date(now,&year,&month,&day,&hour);

  y0=13.3;
  y=715.2;

  fprintf(fp,"%%%%Page: %d %d\n",*page,*page);
  fprintf(fp,"54 0 translate\n");
  fprintf(fp,"  0.0 744.1 moveto 18 f1 (Lunar Eclipses) show\n");

  fprintf(fp,"  0.0 %.1f  moveto 10 f0 (An eclipse of the Moon - or lunar eclipse - can only occur at Full Moon,) show\n",y);
  fprintf(fp,"475.0 %.1f  moveto 10 f0 (and only if the Moon passes through) Rshow\n",y);
  y-=y0;
  fprintf(fp,"  0.0 %.1f  moveto 10 f0 (some  portion of the Earth's  shadow.) show\n",y);
  fprintf(fp,"475.0 %.1f  moveto 10 f0 (The Earth's  shadow   is  composed of  two  concentric  cone-shaped) Rshow\n",y);
  y-=y0;
  fprintf(fp,"  0.0 %.1f  moveto 10 f0 (components.  The outer or  penumbral  shadow is a region  where the Earth  blocks) show\n",y);
  fprintf(fp,"475.0 %.1f  moveto 10 f0 (part  \\(but not all\\)  of the) Rshow\n",y);
  y-=y0;
  fprintf(fp,"  0.0 %.1f  moveto 10 f0 (Sun's light  from reaching  the Moon.) show\n",y);
  fprintf(fp,"475.0 %.1f  moveto 10 f0 (The inner or  umbral shadow  is a region  where  the Earth  blocks  all) Rshow\n",y);
  y-=y0;
  fprintf(fp,"  0.0 %.1f  moveto 10 f0 (direct sunlight from reaching the Moon.) show\n",y);
  fprintf(fp,"175.0 %.1f  moveto 10 f0 (Based on this, three types of lunar eclipses are distinguised:) show\n",y);
  y-=y0;
  fprintf(fp,"  0.0 %.1f  moveto 10 f0 (1.) show\n",y);
  fprintf(fp," 10.0 %.1f  moveto 10 f0 (Penumbral Lunar Eclipse:  the Moon  passes  through  the  Earth's) show\n",y);
  fprintf(fp,"475.0 %.1f  moveto 10 f0 (penumbral  shadow.  These  kind  of) Rshow\n",y);
  y-=y0;
  fprintf(fp," 10.0 %.1f  moveto 10 f0 (eclipses are subtle and very difficult to observe.) show\n",y);
  y-=y0;
  fprintf(fp,"  0.0 %.1f  moveto 10 f0 (2.) show\n",y);
  fprintf(fp," 10.0 %.1f  moveto 10 f0 (Partial Lunar Eclipse:  a part of the Moon passes through the Earth's umbral shadow.) show\n",y);
  y-=y0;
  fprintf(fp,"  0.0 %.1f  moveto 10 f0 (3.) show\n",y);
  fprintf(fp," 10.0 %.1f  moveto 10 f0 (Total Lunar Eclipse:  the Moon passes entirely through the Earth's umbral shadow.) show\n",y);
  fprintf(fp,"475.0 %.1f  moveto 10 f0 (During this phase of) Rshow\n",y);
  y-=y0;
  fprintf(fp," 10.0 %.1f  moveto 10 f0 (the eclipse the Moon will take a vibrant range of dark red and brown colors.) show\n",y);
  y-=y0;
  y-=y0;
  fprintf(fp,"  0.0 %.1f  moveto 10 f0 (NOTICE:  Eclipse contact times  depend  on the angular diameters  of the Sun and Moon.) show\n",y);
  fprintf(fp,"475.0 %.1f  moveto 10 f0 (The calculations) Rshow\n",y);
  y-=y0;
  fprintf(fp,"  0.0 %.1f  moveto 10 f0 (in this Almanac are based on a perfect  circular form for the limb of the Moon,) show\n",y);
  fprintf(fp,"475.0 %.1f  moveto 10 f0 (and  do not take into account) Rshow\n",y);
  y-=y0;
  fprintf(fp,"  0.0 %.1f  moveto 10 f0 (effects  of  refraction of the sunlight  in the Earth atmosphere.) show\n",y);
  fprintf(fp,"475.0 %.1f  moveto 10 f0 (Since this is only an approximation  of reality,) Rshow\n",y);
  y-=y0;
  fprintf(fp,"  0.0 %.1f  moveto 10 f0 (contact times are accurate only within a couple of minutes.) show\n",y);
  y-=y0;
  y-=y0;
  fprintf(fp,"  0.0 %.1f  moveto 10 f0 (The following lunar eclipses may be observed during the year %d:) show\n",y,year);

 


  m=0;
  mDis=99.9;
  eclipse_state=0;

  if(year%4) ydays=365;
    else     ydays=366;

  for(i=0; i<ydays; i++)
  { now=oJD[i];
    cal_date(now,&year,&month,&day,&hour);

    if(fabs(fabs(oRA[i*24][0]-oRA[i*24][2])-12.0)<2.0)             /* this is approximately full moon condition ... */
    {
      for(UT=0; UT<24; UT++)
      { k=i*24+UT;

/*
 *    Palpha=57.29577951 * asin(RSUN/(oDist[k][0]*AU));
 *    Ualpha=57.29577951 * asin((RSUN-REARTH)/(oDist[k][0]*AU));
 */

/* Reduce the penumbra and umbra cones at the moon distance to circles on the earth surface 
 * The center of the penumbra and umbra circles is given by the (RA,Dec) components                    
 *
 * Assuming the following distances (from the center of the Earth:
 * dM = distance Earth-Moon (oDist[k][2])
 * dP = distance of the penumbra cone top (in the direction to the sun on the sun-earth center axis 
 * dU = distance of the umbra cone top (in the direction away from the sun on the sun-earth center axis 
 * 
 * then the following formulas for the "apperture" (in degrees) of the penumbra/umbra circles may be elaborated:
 * NOTICE that the angles Palpha and Ualpha must be taken in radians!
 * 
 * Pbeta=57.29577951 * (asin(dP/dM*sin(Palpha)) + Palpha);
 * Ubeta=57.29577951 * (asin(dU/dM*sin(Ualpha)) - Ualpha);
 * 
 * these formulas can be further simplified by resolving the alpha values:
 *   Palpha=asin(REARTH/(dP*AU);
 *   Ualpha=asin(REARTH/(dU*AU);
 *
 * Pbeta=57.29577951 * (asin(REARTH/(dM*AU)) + asin(REARTH/(dP*AU)));
 * Ubeta=57.29577951 * (asin(REARTH/(dM*AU)) - asin(REARTH/(dU*AU)));
 * 
 * this can be further simplified by resolving dP,dU and dM:
 *   dP=oDist[k][0]*REARTH/RSUN;
 *   dU=oDist[k][0]*REARTH/(RSUN-REARTH);
 *   dM=oDist[k][2];
 *
 * Pbeta=57.29577951 * (asin(REARTH/(oDist[k][2]*AU)) + asin(RSUN/(oDist[k][0]*AU)));
 * Ubeta=57.29577951 * (asin(REARTH/(oDist[k][2]*AU)) - asin((RSUN-REARTH)/(oDist[k][0]*AU)));
 *
 */


        Pbeta0=57.29577951 * asin(REARTH/(oDist[k][2]*AU)) + 57.29577951 * asin(RSUN/(oDist[k][0]*AU));
 
        if(oDist[k][0]*REARTH/(RSUN-REARTH)>oDist[k][2])
          Ubeta0=57.29577951 * asin(REARTH/(oDist[k][2]*AU)) - 57.29577951 * asin((RSUN-REARTH)/(oDist[k][0]*AU)); 
          else
          Ubeta0=0.0;

        Pbeta1=57.29577951 * asin(REARTH/(oDist[k+1][2]*AU)) + 57.29577951 * asin(RSUN/(oDist[k+1][0]*AU));

        if(oDist[k+1][0]*REARTH/(RSUN-REARTH)>oDist[k+1][2])
          Ubeta1=57.29577951 * asin(REARTH/(oDist[k+1][2]*AU)) - 57.29577951 * asin((RSUN-REARTH)/(oDist[k+1][0]*AU)); 
          else
          Ubeta1=0.0;

      
/* the angles Pbeta and Ubeta define two concentric circles on the surface of the Earth for the penumbra and umbra shadow regions 
 * These regions are defined for the moon only. The definition is such that if the geographical position of the moon lies 
 * within these regions the moon enters the penumbra or umbra cone and will be partly covered by the Earth's shadow.
 *
 * To account for the moon's own physical extention, the SD of the moon is used to define a region around the geographical
 * position of the moon, defining a third circle on the surface of the Earth, which is the coverage of the moon.
 * Moon eclipses (penumbral, partial or total, can now be determied by calulating the distance between the geographical position
 * of the moon and the geographical position of the center of the penumbra/umbra circles (RA,Dec).
 */



/* search for moon eclipses (minutes interval) ...                                                                              */


        for(mT=0.0; mT<1.0; mT+=0.025)
        { hour=(double)UT+mT;
          JD=julian_date(year,month,day,hour);

          if(oRA[k][0]<oRA[k+1][0]) cGHA=( oRA[k][0]*(1.0-mT)+( 0.0+oRA[k+1][0])*mT); 
            else                    cGHA=( oRA[k][0]*(1.0-mT)+(24.0+oRA[k+1][0])*mT); 
          cGHA+=12.0;                                                            /* need opposite point !! */
          if(cGHA>=24.0) cGHA-=24.0;    
          cGHA*=15.0/57.29577951;                                                 /* in radians !! */
          cDec=-(oDec[k][0]*(1.0-mT)+oDec[k+1][0]*mT)/57.29577951;                /* in radians !! */
  
          if(oRA[k][2]<oRA[k+1][2]) mGHA=( oRA[k][2]*(1.0-mT)+( 0.0+oRA[k+1][2])*mT);
            else                    mGHA=( oRA[k][2]*(1.0-mT)+(24.0+oRA[k+1][2])*mT);
          if(mGHA>=24.0) mGHA-=24.0;
          mGHA*=15.0/57.29577951;                                                 /* in radians !! */
          mDec= (oDec[k][2]*(1.0-mT)+oDec[k+1][2]*mT)/57.29577951;                /* in radians !! */
  
          Pbeta=1.3118;
          Pbeta=Pbeta0*(1.0-mT)+Pbeta1*mT;
          Pbeta*=1.0206; 
          Ubeta=0.7739;
          Ubeta=Ubeta0*(1.0-mT)+Ubeta1*mT;
          Ubeta*=1.0176;
          SD=(oSD[k][2]*(1.0-mT)+oSD[k+1][2]*mT)/60.0;                                            /* in degrees !! */
  
          Dis=57.29577951 * acos(sin(cDec)*sin(mDec) + cos(cDec)*cos(mDec)*cos(cGHA-mGHA));       /* in degrees !! */
  
  
/* -------------------------------------------------------------------------------------------------------------- */
          if((!eclipse_state)&&(Dis<=2.0))                   /* aproaching cone axis at 2 degrees from outside   */
          { for(n=0; n<54; n++) MoonPath[n%9][n/9]=0.0;
            SetMoonPath(MoonPaths,m,0,cGHA-mGHA,mDec-cDec,cDec,JD,Pbeta,Ubeta);
            mDis=Dis;
            eclipse_state=1;
          }

          if(( eclipse_state)&&(Dis>=2.0))                   /* leaving    cone axis at 2 degrees from inside    */
          { SetMoonPath(MoonPaths,m,8,cGHA-mGHA,mDec-cDec,cDec,JD,Pbeta,Ubeta);
            if(MoonPaths[m].SD[1]>0.0)
            { if(++m>5) 
              { printf(" Error: found more than 6 Moon Eclipses (array overflow)!\n\n");
                exit(-1);
              }
            }
            mDis=99.9;
            eclipse_state=0;
          }
/* -------------------------------------------------------------------------------------------------------------- */
          if((eclipse_state&1)&&(Dis<=Pbeta+SD))              /* moon entering penumbra                           */
          { SetMoonPath(MoonPaths,m,1,cGHA-mGHA,mDec-cDec,SD,JD,Pbeta,Ubeta);
            eclipse_state=2;
          }
  
          if((eclipse_state&2)&&(Dis>=Pbeta+SD))             /* moon left     penumbra                           */
          { SetMoonPath(MoonPaths,m,7,cGHA-mGHA,mDec-cDec,SD,JD,Pbeta,Ubeta);
            eclipse_state=1;
          }
/* -------------------------------------------------------------------------------------------------------------- */
          if((eclipse_state&2)&&(Dis<=Ubeta+SD))              /* moon entering    umbra                           */
          { SetMoonPath(MoonPaths,m,2,cGHA-mGHA,mDec-cDec,SD,JD,Pbeta,Ubeta);
            eclipse_state=4;
          }
  
          if((eclipse_state&4)&&(Dis>=Ubeta+SD))             /* moon left        umbra                           */
          { SetMoonPath(MoonPaths,m,6,cGHA-mGHA,mDec-cDec,SD,JD,Pbeta,Ubeta);
            eclipse_state=2;
          }
/* -------------------------------------------------------------------------------------------------------------- */
          if((eclipse_state&4)&&(Dis<=Ubeta-SD))              /* moon in          umbra                           */
          { SetMoonPath(MoonPaths,m,3,cGHA-mGHA,mDec-cDec,SD,JD,Pbeta,Ubeta);
            eclipse_state=8;
          }
  
          if((eclipse_state&8)&&(Dis>=Ubeta-SD))             /* moon leaving     umbra                           */
          { SetMoonPath(MoonPaths,m,5,cGHA-mGHA,mDec-cDec,SD,JD,Pbeta,Ubeta);
            eclipse_state=4;
          }
/* -------------------------------------------------------------------------------------------------------------- */
          if((eclipse_state)&&(Dis<mDis))
          { SetMoonPath(MoonPaths,m,4,cGHA-mGHA,mDec-cDec,SD,JD,Pbeta,Ubeta);
            mDis=Dis;
          }
        }
      }
    }
  }

  DrawMoonPaths(fp,MoonPaths);

  fprintf(fp,"showpage\n");

  *page = (*page)+1;

  return;
}




void PrintTidalPhase(FILE *fp, double x, double y, int phase)

{ int    i,n;
  double a,b;
  double tl,th,pi;

  n=100;             /* number of points in 1/2 of the phase cycle */
  a=4.0;
  b=1.4;
  pi=3.141593;
  th=15.0*pi/n;
  tl=pi/n;

  
  fprintf(fp,"newpath  %.1f %.1f moveto\n",x+35.0,6.0+y);
  for(i=0; i<=n; i++)
    fprintf(fp," %.1f %.1f lineto\n",x+i/2.0+35.0,6.0+y+a*sin(th*(i+n*phase))*b*(1.2+sin(tl*(i+n*phase))));
  fprintf(fp,"stroke\n");


  return;
}



void FormatMoonPhases(double *oJD, double oGha[][6], double oDec[][6], int *page, FILE *fp)

{ short int year,month,day,lastmonth;
  int       k,m,n,u,ndays;

  char     *phases[4]  = {"New Moon","First Quarter","Full Moon","Last Quarter"};
  char     *days[7]    = {"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};
  char     *months[12] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
  char      times[12];

  double    now,hour,time;
  double    x,x0,y,y0;
  char     *time2s();
  void      cal_date();


  now=oJD[0];
  cal_date(now,&year,&month,&day,&hour);

  if(year%4) ndays=365;
    else ndays=366;


  y0=13.3;
  y=715.2;
  fprintf(fp,"%%%%Page: %d %d\n",*page,*page);
  fprintf(fp,"gsave\n");
  fprintf(fp,"54 0 translate\n");
  fprintf(fp,"  0.0 744.1 moveto 18 f1 (Phases of the Moon) show\n");
  fprintf(fp,"  0.0 %.1f  moveto 10 f0 (The following table  lists the phases of the Moon  through the year %4d.) show\n",y,year);
  fprintf(fp,"475.0 %.1f  moveto 10 f0 (The table  shows the  day and the) Rshow\n",y);
  y-=y0;
  fprintf(fp,"  0.0 %.1f  moveto 10 f0 (approximate time  \\(in UTC\\)  when  the  particular  lunar phases  occur.) show\n",y);
  fprintf(fp,"475.0 %.1f  moveto 10 f0 (The calculations  are  based  on the) Rshow\n",y);
  y-=y0;
  fprintf(fp,"  0.0 %.1f  moveto 10 f0 (difference between the GHA of the Sun and the GHA of the Moon) show\n",y);
  fprintf(fp,"475.0 %.1f  moveto 10 f0 (\\(Delta_GHA = GHA_sun - GHA_moon\\).) Rshow\n",y);
  y-=y0;
  fprintf(fp,"  0.0 %.1f  moveto 10 f0 (The constellations \"new moon\", \"first quarter\", \"full Moon\") show\n",y);
  fprintf(fp,"475.0 %.1f  moveto 10 f0 (and \"last quarter\" are obtained when Delta_GHA) Rshow\n",y);
  y-=y0;
  fprintf(fp,"  0.0 %.1f  moveto 10 f0 (is equal to 0\\260, 90\\260, 180\\260 and 270\\260 respectively.) show\n",y);
  y-=2.0*y0;
  fprintf(fp,"0.1 setlinewidth\n");
  fprintf(fp,"newpath 2.0 %.1f  moveto 470 0 rlineto 0 -400 rlineto -470 0 rlineto closepath stroke\n",y);


  for(k=0; k< 4; k++)
    fprintf(fp,"newpath %.1f %.1f moveto 0 -400 rlineto stroke\n",k*100.0+72.0,y);

  for(k=0; k<12; k++) 
  { fprintf(fp,"newpath 2 %.1f moveto 470 0 rlineto stroke\n",y-30.0*k-40.0);
    fprintf(fp,"8.0 %.1f moveto 8 f0 (%-9s) show\n",y-30.0*k-51.4,months[k]);
  }

  m=0;
  fprintf(fp,"0.1 setlinewidth\n");
  for(k=0; k< 4; k++)
  { fprintf(fp,"%.1f %.1f moveto 8 f1 (%s) Cshow\n",k*100.0+132.0,y-18.0,phases[k]);
    if(k==0) fprintf(fp,"0.8 setgray newpath %.1f %.1f 10 0 360 arc fill 0.0 setgray\n",k*100.0+92.0,y-18.0);
    if(k==1) fprintf(fp,"newpath %.1f %.1f 10 225 45 arc closepath stroke\n",k*100.0+92.0,y-18.0);
    if(k==2) fprintf(fp,"newpath %.1f %.1f 10 0 360 arc stroke\n",k*100.0+92.0,y-18.0);
    if(k==3) fprintf(fp,"newpath %.1f %.1f 10 45 225 arc closepath stroke\n",k*100.0+92.0,y-18.0);
  }
  
  m=0;
  n=0;
  for(k=0; k<ndays; k++)
  { for(u=0; u<24; u++)
    { if((x =oGha[k*24+u  ][0]-oGha[k*24+u  ][2]) < 0.0) x +=360.0;
      if((x0=oGha[k*24+u+1][0]-oGha[k*24+u+1][2]) < 0.0) x0+=360.0;

      time=-1.0;
      if((x > 270.0)&&(x0< 90.0))  { time=u+(360.0-x)/(x0-(x-360.0)); m=0; }
      if((x <= 90.0)&&(x0> 90.0))  { time=u+( 90.0-x)/(x0-x); m=1; }
      if((x <=180.0)&&(x0>180.0))  { time=u+(180.0-x)/(x0-x); m=2; }
      if((x <=270.0)&&(x0>270.0))  { time=u+(270.0-x)/(x0-x); m=3; }

      if(time>=0.0)
      { lastmonth=month;
        now=oJD[k];
        cal_date(now,&year,&month,&day,&hour);
        if(month>lastmonth) n=0;

        fprintf(fp,"%.1f %.1f moveto 8 f4 ",82.0+100.0*m,y-(month-1)*30.0-n*12.0-51.4);
        fprintf(fp,"(%3s  %2d   %5s)show\n",days[((int)now+2)%7],day,time2s(time,times));
        
        if(m==3) n=1;
      }
    }
  }

  fprintf(fp,"newpath 2.0 %.1f  moveto 470 0 rlineto 0 -30 rlineto -470 0 rlineto closepath stroke\n",y-402.0);
  for(k=0; k< 4; k++)
    fprintf(fp,"newpath %.1f %.1f moveto 0 -30 rlineto stroke\n",k*100.0+72.0,y-402.0);
 
  y0=13.3;
  y-=32.0*y0;
  fprintf(fp,"  8.0 %.1f  moveto 8 f0 (Tidal Phase) show\n",y);
  fprintf(fp," %.1f %.1f  moveto 8 f0 (spring) show\n",82.0,y);
  fprintf(fp," %.1f %.1f  moveto 8 f0 (neap) show\n",82.0+100.0,y);
  fprintf(fp," %.1f %.1f  moveto 8 f0 (spring) show\n",82.0+200.0,y);
  fprintf(fp," %.1f %.1f  moveto 8 f0 (neap) show\n",82.0+300.0,y);

  PrintTidalPhase(fp,82.0,y,0);
  PrintTidalPhase(fp,182.0,y,1);
  PrintTidalPhase(fp,282.0,y,0);
  PrintTidalPhase(fp,382.0,y,1);

  y-=3.0*y0;
  fprintf(fp,"  0.0 %.1f  moveto 12 f1 (Lunar Phases and Tides) show\n",y);
  y-=y0;
  fprintf(fp,"  0.0 %.1f  moveto 10 f0 (The lunar phases  may be used to roughly  estimate  the occurrence of  spring  and  neap tides.) show\n",y);
  fprintf(fp,"475.0 %.1f  moveto 10 f0 (Spring tide) Rshow\n",y);
  y-=y0;
  fprintf(fp,"  0.0 %.1f  moveto 10 f0 (occurs around new and full moon. Neap tide occurs around the first and last quarter.) show\n",y);
  y-=y0;
  fprintf(fp,"  0.0 %.1f  moveto 10 f0 (Each  tidal region on Earth,  has a  characteristic  \"tidal delay\") show\n",y);
  fprintf(fp,"475.0 %.1f  moveto 10 f0 (which, specifies  the time difference between) Rshow\n",y);
  y-=y0;
  fprintf(fp,"  0.0 %.1f  moveto 10 f0 (the occurrence  of a particular lunar phase  and the occurrence  of the resulting tidal phase.) show\n",y);
  fprintf(fp,"475.0 %.1f  moveto 10 f0 (The tidal delay) Rshow\n",y);
  y-=y0;
  fprintf(fp,"  0.0 %.1f  moveto 10 f0 (can be a couple of hours for the open seas,) show\n",y);
  fprintf(fp,"475.0 %.1f  moveto 10 f0 (or up to several days for branched tidal waters such as parts of) Rshow\n",y);
  y-=y0;
  fprintf(fp,"  0.0 %.1f  moveto 10 f0 (the North Sea.) show\n",y);
  y-=y0;
  y-=y0;
  fprintf(fp,"  0.0 %.1f  moveto 10 f0 (Reliable tidal predictions are obtained from a Tidal Almanac.) show\n",y);

  fprintf(fp,"grestore\n");
  fprintf(fp,"showpage\n");

  *page = (*page)+1;

  return;
}
