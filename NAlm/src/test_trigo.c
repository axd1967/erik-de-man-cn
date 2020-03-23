/* This is a test for the functions "calDistance", "calAzimuth" and "calDestination"
 * defined in the file "src/trigo.c". 
 *
 * There are two tests available.
 * Test '1' is done as follows: first a random position is defined for (Lat0,Lon0),
 * then the destination (Lat1,Lon1) is calcutated for a random Distance and Azimuth.
 * These Distance and Azimuth values are then checked with the functions "calDistance"
 * and "calAzimuth". 
 * Test '2' is done as follows: two random locations are defined (Lat0,Lon0) and
 * (Lat1,Lon1) and the Distance and Azimuth are calculated. Then the location 
 * (Lat1,Lon1) is calculated from (Lat0,Lon0) and checked against the reference value.
 *
 * The tests will run until the first error is found or can be interupted with ^c
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trigo.c"



#define  A      16807
#define  M 2147483647
#define  Q     127773
#define  R       2836


double Randoms()

{ static long random_seed=663366; 
  static long number;

  if(random_seed!=0)
  { number=(random_seed&M)+1;
    random_seed=0;
  }

  number=A*(number%Q)-R*(number/Q);
  if(number<=0) number+=M;
  return (((double)(number-1))/((double)M));
}




int main(int argc, char **argv)
{ int    output_enabled=0;
  double Lat0,Lat1,Lat_r;
  double Lon0,Lon1,Lon_r;

  double Dis_r,Az_r;
  double Dis_c,Az_c;
  double Dis_s;
  long   count_0=0;
  long   count_1=0;


  if(argc != 3) 
  { printf(" Usage: %s <1|2>  (test selection) <0|1> (enable output)\n",argv[0]);
    return 0;
  }

  if(argv[2][0] == '1') output_enabled=1;

  while(1)
  { 
    if(argv[1][0] == '1')
    { Lat0 = 180.0 * (Randoms() - 0.5);
      Lon0 = 360.0 * (Randoms() - 0.5);
      Dis_r= 150.0 * Randoms() + 0.5;
      Az_r = 360.0 * Randoms();
  
      calDestination(Lat0, Lon0, Dis_r, Az_r, &Lat1, &Lon1);
    
      Dis_c = calDistance(Lat0, Lon2GHA(Lon0), Lat1, Lon2GHA(Lon1));
      Az_c  = calAzimuth(Lat0, Lon2GHA(Lon0), Lat1, Lon2GHA(Lon1));

      if(output_enabled) printf("Lat0=%12.7f  Lon0=%12.7f  Dis_r=%12.7f  Az_r=%12.7f  Lat1=%12.7f  Lon1=%12.7f  Dis_c=%12.7f  Az_c=%12.7f\n",Lat0,Lon0,Dis_r,Az_r,Lat1,Lon1,Dis_c,Az_c);
   
      if((fabs(1.0-Dis_r/Dis_c) > 0.00001) || (fabs(1.0-Az_r/Az_c) > 0.00001)) 
      { if(argv[2][0] == '0') printf("Lat0=%12.7f  Lon0=%12.7f  Dis_r=%12.7f  Az_r=%12.7f  Lat1=%12.7f  Lon1=%12.7f  Dis_c=%12.7f  Az_c=%12.7f\n",Lat0,Lon0,Dis_r,Az_r,Lat1,Lon1,Dis_c,Az_c);
        printf(" ERROR in above line !!\n");
        return 0;
      }
    }

    if(argv[1][0] == '2')
    { Lat0 =  80.0 * (Randoms() - 0.5);
      Lon0 =  60.0 * (Randoms() - 0.5);
      Lat1 =  80.0 * (Randoms() - 0.5);
      Lon1 =  60.0 * (Randoms() - 0.5);

      Dis_c = calDistance(Lat0, Lon2GHA(Lon0), Lat1, Lon2GHA(Lon1));
      Az_c  = calAzimuth(Lat0, Lon2GHA(Lon0), Lat1, Lon2GHA(Lon1));

      calDestination(Lat0, Lon0, Dis_c, Az_c, &Lat_r, &Lon_r);

      if(output_enabled) printf("Lat0=%12.7f  Lon0=%12.7f  Lat1=%12.7f  Lon1=%12.7f  Dis_c=%12.7f  Az_c=%12.7f  Lat_r=%12.7f  Lon_r=%12.7f\n",Lat0,Lon0,Lat1,Lon1,Dis_c,Az_c,Lat_r,Lon_r);

      if((fabs(1.0 - Lat_r/Lat1) > 0.00001) || (fabs(1.0 - Lon_r/Lon1) > 0.00001))
      { if(argv[2][0] == '0') printf("Lat0=%12.7f  Lon0=%12.7f  Lat1=%12.7f  Lon1=%12.7f  Dis_c=%12.7f  Az_c=%12.7f  Lat_r=%12.7f  Lon_r=%12.7f\n",Lat0,Lon0,Lat1,Lon1,Dis_c,Az_c,Lat_r,Lon_r);
        printf(" ERROR in above line !!\n");
        return 0;
      }
    }

    if(argv[2][0] == '0')
    { count_0++;
      if(count_0 == 1000000) 
      { count_1++;
        count_0 = 0;
        printf(" %12ld million samples successfuly tested\n",count_1);
      }
    }
  }
}
