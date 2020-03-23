#include <stdio.h>
#include "trigo.c"

int main(int argc, char **argv)
{ double Dec0,GHA0,Lat1,Lon1; 
  double a_r,a_c;

  Dec0 = 0;
  GHA0 = 0;

  for(a_r=0.0; a_r < 360.0; a_r+=45.0)
  { Lat1 = Dec0          + 8.0*Cos(a_r);
    Lon1 = GHA2Lon(GHA0) + 8.0*Sin(a_r);
    a_c  = calAzimuth(Dec0,GHA0,Lat1,Lon2GHA(Lon1));

    printf(" Lat1=%5.1f   Lon1=%5.1f   a_r=%5.1f   a_c=%5.1f\n",Lat1,Lon1,a_r,a_c);
  }


  return 0;
}
