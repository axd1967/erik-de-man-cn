#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define PI      3.14159265358979323846
#define DEG2RAD PI/180.0
#define RAD2DEG 180.0/PI


int main(int argc, char **argv)

{
  double x,y;


  if(argc!=3)
  { printf(" Usage: %s <x> <y>\n",argv[0]);
    exit(-1);
  }


  x=atof(argv[1]);
  y=atof(argv[2]);

  printf("x=%5.1f  y=%5.1f   90-atan2(y,x)=%5.1f   atan2(x,y)=%5.1f\n",x,y,90.0 - RAD2DEG*atan2(y,x),RAD2DEG*atan2(x,y));

  return 0;
}
