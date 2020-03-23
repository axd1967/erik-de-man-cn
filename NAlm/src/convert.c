#include <stdio.h>
#include <string.h>
#include <math.h>
#include "primitives.h"



char *gha2s(double Gha,char *string)

{ int    deg;
  double min;

  deg=floor(Gha);
  min=60*(Gha-deg);

  if(min<9.95) sprintf(string,"%3d 0%3.1f",deg,min);
    else sprintf(string,"%3d %4.1f",deg,min);

  return string;
}

char *dgha2s(double Gha0, double Gha1,char *string)

{ int    gha0,gha1;
  double min;
  char   sgn;

  gha0=floor(Gha0*600.0+0.5);
  gha1=floor(Gha1*600.0+0.5);

  
  if(gha1<gha0) min=gha1-gha0+360.0*600.0;
    else min=gha1-gha0;

  min-=15.0*600.0;
  min/=10.0;

  if(min<0.0) { sgn='-'; min*=-1.0; }
    else sgn='+';

  sprintf(string,"%c%04.1f",sgn,min);

  return string;
}





char *dec2s(double Dec, char *string)

{ int    deg;
  char   NS='N';
  double min;

  if(Dec<0.0) { NS='S'; Dec=-Dec; }

  deg=floor(Dec);
  min=60*(Dec-deg);

  sprintf(string,"%c %02d %04.1f",NS,deg,min);

  return string;
}


char *ddec2s(double Dec0, double Dec1, char *string)

{ int    dec0,dec1;
  int    min;
  char   sgn;

  dec0=floor(Dec0*600.0+0.5);
  dec1=floor(Dec1*600.0+0.5);

  min=dec1-dec0;
  if(dec0<0.0) min*=-1;

  if(min<0) { sgn='-'; min*=-1; }
    else sgn='+';

  if(min<=99) sprintf(string,"%c0%3.1f",sgn,min/10.0);
    else sprintf(string,"%c%4.1f",sgn,min/10.0);

  return string;
}

char *min2s(double Min, char *string)

{ 
  if(Min<9.95) sprintf(string,"0%3.1f",Min);
    else sprintf(string,"%4.1f",Min);

  string[2]=39;

  return string;
}

/* -------------------------------------------------------------------------------------------------------------- */
/* 
 * gct2s() converts the Greenwich culmination time into a "hh:mm" string               
 * The argument oGha[][6] contains the Gha values for 6 objects through the year with one hour increment
 * (24*365 = xxx samples). The argument "obj" [0:5] selects the object and "k" [0:364] selects the day of the 
 * year for which the Greenwich culmination time will be evaluated.
 */

char *gct2s(double oGha[][6], int k, int obj, char *string)

{ int    u,m;

  strcpy(string,"--:--");

  u=0;
  while((u<24)&&(oGha[u + k*24][obj] < oGha[u+1 + k*24][obj])) u++;

  if(u<24)
  { m=(int)(0.5 + 60.0*( (360 - oGha[u + k*24][obj])/(360.0 - oGha[u + k*24][obj] + oGha[u+1 + k*24][obj]) ));

    if(m==60) 
    { m=0;
      u=(u+1)%24;
    }
    
    if((u< 10) && (m< 10)) sprintf(string,"0%d:0%d",u,m);
    if((u< 10) && (m>=10)) sprintf(string,"0%d:%d",u,m);
    if((u>=10) && (m< 10)) sprintf(string,"%d:0%d",u,m);
    if((u>=10) && (m>=10)) sprintf(string,"%d:%d",u,m);
  } 

  return string;
}




/* -------------------------------------------------------------------------------------------------------------- */

double ra2gha(double JD, double RA)

{ double    Gst,Gha;
  double    mobl,tobl,ee,dpsi,deps;


  earthtilt(JD,&mobl,&tobl,&ee,&dpsi,&deps);
  sidereal_time(JD,0.0,ee,&Gst);

  Gha=15.0*(Gst-RA);
  if(Gha<  0.0) Gha+=360.0;
  if(Gha>360.0) Gha-=360.0;

  return Gha;
}


/* -------------------------------------------------------------------------------------------------------------- */

double gha2ra(double JD, double Gha)

{ double    Gst,RA;
  double    mobl,tobl,ee,dpsi,deps;


  earthtilt(JD,&mobl,&tobl,&ee,&dpsi,&deps);
  sidereal_time(JD,0.0,ee,&Gst);

  RA=Gst-Gha/15.0;
  if(RA< 0.0) RA+=24.0;
  if(RA>24.0) RA-=24.0;

  return RA;
}


/* -------------------------------------------------------------------------------------------------------------- */

char *ut2s(double UT,char *string)

{
  if(UT<9.95) sprintf(string,"0%4.2f",UT);
    else sprintf(string,"%4.2f",UT);

  string[2]=':';

  return string;
}


/* -------------------------------------------------------------------------------------------------------------- */

char *time2s(double time, char *times)

{ int hh,mm;

  hh=floor(time+0.5/60.0);
  mm=floor((time+0.5/60.0-hh)*60.0);

  sprintf(times,"%2d:%2d",hh,mm);
  if(times[0]==' ') times[0]='0';
  if(times[3]==' ') times[3]='0';

  return times;
}


/* -------------------------------------------------------------------------------------------------------------- */

char *times2s(double time, char *times)

{ int hh,mm,ss;

  hh=floor(time);
  time=(time-hh)*60.0;
  mm=floor(time);
  time=(time-mm)*60.0;
  ss=floor(time);

  sprintf(times,"%2d:%2d:%2d",hh,mm,ss);
  if(times[0]==' ') times[0]='0';
  if(times[3]==' ') times[3]='0';
  if(times[6]==' ') times[6]='0';

  return times;
}


