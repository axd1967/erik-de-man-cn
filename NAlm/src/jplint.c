
#include <stdlib.h>
#include <math.h>
#include "jplint.h"


int InitEphem( char *fileName )

{ int headerID;
  
  if((EphemFile=fopen(fileName,"r"))==NULL)
  { printf("\n Error (InitEphem) could not open file \"%s\" for reading!\n",fileName);
    exit(-1);
  }


  fread(&H1,sizeof(double),ARRAY_SIZE,EphemFile);
  fread(&H2,sizeof(double),ARRAY_SIZE,EphemFile);
  fread(&Coeff_Array,sizeof(double),ARRAY_SIZE,EphemFile);

  R1 = H1.data;

  JD0  = Coeff_Array[0];
  JD1  = Coeff_Array[1];

  headerID = (int) R1.DENUM;
  AU       =       R1.AU;
  EMRAT    =       R1.EMRAT;

  if ( headerID != EPHEMERIS )
  { printf("\n Error (InitEphem) wrong ephemeris file: \"%s\" for %d (headerID read: %d).\n",fileName,EPHEMERIS,headerID);
    return 0;
  }

  return 1;
}




void ReadCoeff( double jd )

{
  int     offset=0;
  double  Ts;
  double  Td = 0.0;

  if((jd>=JD0)&&(jd<=JD1))
  { printf("\n Warning (ReadCoeff) unnecessary call to this function!\n");
    return;
  }

  Ts=JD1-JD0;

  if( jd < JD0 )                    /* Compute backwards location offset */
  { Td = JD0 - jd;
    offset  = (int) -ceil(Td/Ts);
  }

  if( jd > JD1 )                    /* Compute forewards location offset */
  { Td = jd - JD1;
    offset  = (int) ceil(Td/Ts);
  }

                                    /*  Retrieve ephemeris data from new record.    */

  fseek(EphemFile,(offset-1)*ARRAY_SIZE*sizeof(double),SEEK_CUR);
  fread(&Coeff_Array,sizeof(double),ARRAY_SIZE,EphemFile);

  JD0  = Coeff_Array[0];
  JD1  = Coeff_Array[1];


  if((jd<JD0)||(jd>JD1))
    printf("\n Warning (ReadCoeff) read pointer not moved correctly (jd out of range)!\n");
  
  return;
}









/* InterpEphem() returns the position[3] and velocities[3] of the "target"
 * object. Position origin is the barycentrum of the solar system. 
 *
 * Target object is given by an interger number from 0 - 10:
 *
 *    0 = "Mercury"    1 = "Venus"    2 = "Earth-Moon" 3 = "Mars"
 *    4 = "Jupiter"    5 = "Saturn"   6 = "Uranus"     7 = "Neptune"
 *    8 = "Pluto"      9 = "Moon"    10 = "Sun" 
 * 
 * Special "targets" for Liberation and Nutation:
 *
 *   11 = "Nutations"                12 = "Librations"
 */


void InterpEphem(double tjd, int target, double PV[])

{ int       i, j;
  long int  C, G, N, offset=0;
  double    A[50], Cp[50], P_Sum[3], V_Sum[3], Up[50], Tbr, Tsg, Tsb, Tc;



  if( target >= 11 )                               /* protect against weird input errors */
  { printf("\n This function does not compute nutations or librations.\n");
    return;
  }

  for ( i=0 ; i<50 ; i++ ) A[i] = 0.0;

                                                    /* Determine if a new record needs to be input. */
  if (tjd < JD0 || tjd > JD1)  ReadCoeff(tjd);

  C = R1.coeffPtr[target][0] - 1;               /*    Coeff array entry point */
  N = R1.coeffPtr[target][1];                   /*          Number of coeff's */
  G = R1.coeffPtr[target][2];                   /* Granules in current record */


  /*  Compute the normalized time, then load the Tchebeyshev coefficients into array A[].
   *  If (JD1-JD0) is covered by a single granule this is easy. 
   *  If not, the granule that contains the interpolation time is found, and an offset from
   *  the array entry point for the ephemeris body is used to load the coefficients.                                               
   */

  Tc=0.0;

  if( G == 1 )
  { Tc = 2.0*(tjd - JD0) / (JD1-JD0) - 1.0;
    for (i=C ; i<(C+3*N) ; i++)
      A[i-C] = Coeff_Array[i];
  }

  Tsg=0.0;
  
  if( G > 1 )
  { Tsb = (JD1-JD0) / ((double) G);          /* Compute subgranule interval */

    for(j=G; j>0; j--)
    { Tbr = JD0 + ((double) j-1) * Tsb;

      if( tjd > Tbr )
      { Tsg  = Tbr;
        offset = j-1;
        break;
      }
    }

    Tc = 2.0*(tjd - Tsg) / Tsb - 1.0;
    C  = C + 3 * offset * N;

    for (i=C ; i<(C+3*N) ; i++)
      A[i-C] = Coeff_Array[i];
  }

  if(G<1)
    printf("\n Error (InterpEphem) Number of granules must be >= 1! Check header data.\n\n");



  /* Compute the interpolated position & velocity                             */

  for ( i=0 ; i<3 ; i++ )                /* Compute interpolating polynomials */
  { Cp[0] = 1.0;
    Cp[1] = Tc;
    Cp[2] = 2.0 * Tc*Tc - 1.0;

    Up[0] = 0.0;
    Up[1] = 1.0;
    Up[2] = 4.0 * Tc;

    for ( j=3 ; j<N ; j++ )
    { Cp[j] = 2.0 * Tc * Cp[j-1] - Cp[j-2];
      Up[j] = 2.0 * Tc * Up[j-1] + 2.0 * Cp[j-1] - Up[j-2];
    }

    P_Sum[i] = 0.0;           /* Compute interpolated position & velocity */
    V_Sum[i] = 0.0;

    for ( j=N-1 ; j>-1 ; j-- )  P_Sum[i] = P_Sum[i] + A[j+i*N] * Cp[j];
    for ( j=N-1 ; j>0  ; j-- )  V_Sum[i] = V_Sum[i] + A[j+i*N] * Up[j];

    PV[i]   = P_Sum[i];
/*
    PV[i+3] = V_Sum[i] * 2.0 * ((double) G) / ((JD1-JD0) * 86400.0);
*/
    PV[i+3] = V_Sum[i] * 2.0 * ((double) G) / (JD1-JD0);

                              /* scale to AU ...                         */
    PV[i]  /=AU;
    PV[i+3]/=AU;
  }

  return;
}










/* jplint() interfaces to the JPL Ephemerides and returns the Position[3]
 * and Velocity[3] of the *center / *target vector in the PosVel[6] array.
 * Numbering convention for *target and *center are:
 *
 *               1 = MERCURY           8 = NEPTUNE
 *               2 = VENUS             9 = PLUTO
 *               3 = EARTH            10 = GEO-CENTRIC MOON
 *               4 = MARS             11 = SUN
 *               5 = JUPITER          12 = SOLAR-SYSTEM BARYCENTER
 *               6 = SATURN           13 = EARTH-MOON BARYCENTER
 *               7 = URANUS           14 = NUTATIONS (LONGITUDE AND OBLIQ)
 *                                    15 = LIBRATIONS, IF ON EPH FILE
 *
 *  IF NUTATIONS ARE WANTED, SET NTARG = 14. SET NCENT=12. 
 *  FOR LIBRATIONS,          SET NTARG = 15. SET NCENT=12. 
 *
 */

void jplint( double *tjd, int *target, int *center, double PosVel[], int *error)

{ int        i; 
  char      *ephemFileName="JPLephemDE405.bin";
  double     PVgeo_moon[6],PVobject[6],PVcenter[6];

  static int        first=1;


  for(i=0; i<6; i++)
  {  PosVel[i]=0.0;
     PVcenter[i]=0.0;
  }

  if(first)
  {  if(InitEphem(ephemFileName) == 0)
    { printf(" Error (jplint) error initializing Ephemerides file \"%s\" !\n\n",ephemFileName);
      *error=1;
      return;
    }
    first=0;
  }

  if(((*center<11)||(*center>12))||((*target<1)||(*target>11)))
  { printf(" Error (jplint) Range?? center=%d\n",*center);
    printf("                        target=%d\n",*target);
    *error=1;
    return;
  }

/*
  printf("  center=%d   ",*center);
  printf("  target=%d\n",*target);
*/


  if(*target==13)   
  if(*target==14)




  *error = 0;

  switch (*target)
  { case   1:  InterpEphem( *tjd, 0, PVobject);
               break;

    case   2:  InterpEphem( *tjd, 1, PVobject);
               break;

    case   3:  InterpEphem( *tjd, 2, PVobject);
               InterpEphem( *tjd, 9, PVgeo_moon);
                                                    /* do correction on earth-moon barycentrum to get real earth ... */
               for(i=0; i<6; i++)
                 PVobject[i]=PVobject[i]-PVgeo_moon[i]/(1.0+EMRAT);
               break;

    case   4:  InterpEphem( *tjd, 3, PVobject);
               break;

    case   5:  InterpEphem( *tjd, 4, PVobject);
               break;

    case   6:  InterpEphem( *tjd, 5, PVobject);
               break;

    case   7:  InterpEphem( *tjd, 6, PVobject);
               break;

    case   8:  InterpEphem( *tjd, 7, PVobject);
               break;

    case   9:  InterpEphem( *tjd, 8, PVobject);
               break;

    case  10:  InterpEphem( *tjd, 2, PVobject);
               InterpEphem( *tjd, 9, PVgeo_moon);
                                                    /* get ss-barycenrtic moon coordinates ...................... */
               for(i=0; i<6; i++)
                 PVobject[i]=PVobject[i]+PVgeo_moon[i]*EMRAT/(1.0+EMRAT);
               break;

    case  11:  InterpEphem( *tjd, 10, PosVel);
               return;
               break;

    case  12:  InterpEphem( *tjd, 10, PVobject);
               for(i=0; i<6; i++)
                 PosVel[i]=-PVobject[i];
               return;
               break;

    case  13:  InterpEphem( *tjd, 3, PVobject);
               break;

    case  14:  exit(-1);
               break;

    case  15:  exit(-1);
               break;

  }

  if(*center==11) InterpEphem( *tjd, 10, PVcenter);
  
  for(i=0; i<6; i++)
    PosVel[i]=PVobject[i]-PVcenter[i];

  *error=0;

  return;
}
