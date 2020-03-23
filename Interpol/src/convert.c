#include <math.h>

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

  if(min<9.95) sprintf(string,"%c0%3.1f",sgn,min);
    else sprintf(string,"%c%4.1f",sgn,min);

  return string;
}





char *dec2s(double Dec, char *string)

{ int    deg;
  char   NS='N';
  double min;

  if(Dec<0.0) { NS='S'; Dec=-Dec; }

  deg=floor(Dec);
  min=60*(Dec-deg);

  if(min<9.95) sprintf(string,"%c %2d 0%3.1f",NS,deg,min);
    else sprintf(string,"%c %2d %4.1f",NS,deg,min);

  return string;
}


char *ddec2s(double Dec0, double Dec1, char *string)

{ int    dec0,dec1;
  double min;
  char   sgn;

  dec0=floor(Dec0*600.0+0.5);
  dec1=floor(Dec1*600.0+0.5);

  min=0.1*(dec1-dec0);
  if(dec0<0.0) min*=-1.0;

  if(min<0.0) { sgn='-'; min*=-1.0; }
    else sgn='+';

  if(min<9.95) sprintf(string,"%c0%3.1f",sgn,min);
    else sprintf(string,"%c%4.1f",sgn,min);

  return string;
}

char *min2s(double Min, char *string)

{ 
  if(Min<9.95) sprintf(string,"0%3.1f",Min);
    else sprintf(string,"%4.1f",Min);

  string[2]=39;

  return string;
}

char *gct2s(double oGha[][6], int k, int obj, char *string)

{ int    u,m;

  strcpy(string,"--:--");

  u=0;
  while((u<24)&&(oGha[u + k*24][obj] < oGha[u+1 + k*24][obj])) u++;

  if(u<24)
  { m=(int)(0.5 + 60.0*( (360 - oGha[u + k*24][obj])/(360.0 - oGha[u + k*24][obj] + oGha[u+1 + k*24][obj]) ));
    
    if((u< 10) && (m< 10)) sprintf(string,"0%d:0%d",u,m);
    if((u< 10) && (m>=10)) sprintf(string,"0%d:%d",u,m);
    if((u>=10) && (m< 10)) sprintf(string,"%d:0%d",u,m);
    if((u>=10) && (m>=10)) sprintf(string,"%d:%d",u,m);
  } 

  return string;
}


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


char *ut2s(double UT,char *string)

{
  if(UT<9.95) sprintf(string,"0%4.2f",UT);
    else sprintf(string,"%4.2f",UT);

  string[2]=':';

  return string;
}


