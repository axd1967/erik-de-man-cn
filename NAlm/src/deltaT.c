#include <stdlib.h>
#include <stdio.h>

#define MAX_DELTA_T 58

double deltaT(double JD)

{ int        i;
  static int t=0;





                           /* source: "ftp://maia.usno.navy.mil/ser7/deltat.preds"   */
            
/*                            "ftp://maia.usno.navy.mil/ser7/readme"      (23-Aug-2002)
Discontinued files
------------------
tpmdat.dat - These low-accuracy Earth orientation prediction coefficients
  are no longer distributed.

deltat.data - Delta T (=TT-UT1) values are no longer distributed.  Users
  can compute Delta T by:
     Delta T = 32.184 s + (TAI - UTC) - (UT1 - UTC)
  where
     (TAI - UTC) is the cumulative number of leap seconds available in
     the file "tai-utc.dat"
  and
     (UT1 - UTC) is a standard Earth orientation product available in
     the standard/daily product files above.

deltat.preds - Predictions of Delta T are no longer distributed.       
---------------------------------------------------------------------------------------------

Delta T is now calculated from the files "finals.data" and "tai-utc.dat"   (23-Aug-2002)

*/

  double DeltaT[MAX_DELTA_T][2] = 
                         {  { 2000.00,     63.83 },
                            { 2000.25,     63.91 },
                            { 2000.50,     63.98 },
                            { 2000.75,     64.01 },
                            { 2001.00,     64.09 },
                            { 2001.25,     64.16 },
                            { 2001.50,     64.21 },
                            { 2001.75,     64.22 },
                            { 2002.00,     64.30 },
                            { 2002.25,     64.37 },
                            { 2002.50,     64.41 },
                            { 2002.75,     64.42 },
                            { 2003.00,     64.47 },
                            { 2003.25,     64.53 },
                            { 2003.50,     64.55 },
                            { 2003.75,     64.54 },
                            { 2004.00,     64.57 },
                            { 2004.25,     64.62 },
                            { 2004.50,     64.65 },
                            { 2004.75,     64.64 },
                            { 2005.00,     64.69 },
                            { 2005.25,     64.76 },
                            { 2005.50,     64.80 },
                            { 2005.75,     64.79 },
                            { 2006.00,     64.85 },
                            { 2006.25,     64.92 },
                            { 2006.50,     64.99 },
                            { 2006.75,     65.04 },
                            { 2007.00,     65.15 },
                            { 2007.25,     65.25 },
                            { 2007.50,     65.34 },
                            { 2007.75,     65.37 },
                            { 2008.00,     65.46 },
                            { 2008.25,     65.54 },
                            { 2008.50,     65.61 },
                            { 2008.75,     65.64 },
                            { 2009.00,     65.78 }, /* updated up to here - Nov 2009 */
                            { 2009.25,     65.86 },
                            { 2009.50,     65.95 },
                            { 2009.75,     65.98 },
                            { 2010.00,     66.07 }, /* updated up to here - Dec 2010 */
                            { 2010.25,     66.17 },
                            { 2010.50,     66.24 },
                            { 2010.75,     66.24 },
                            { 2011.00,     66.32 },
                            { 2011.25,     66.39 },
                            { 2011.50,     66.47 }, /* updated up to here - Jul 2011 */
                            { 2011.75,     66.50 },
                            { 2012.00,     66.60 },
                            { 2012.25,     66.71 },
                            { 2012.50,     66.79 },
                            { 2012.75,     66.83 },
                            { 2013.00,     66.92 }, /* updated up to here - Feb 2012 */
                            { 2013.25,     66.98 },
                            { 2013.50,     67.03 },
                            { 2013.75,     67.12 },
                            { 2014.00,     67.15 },
                            { 2014.25,     67.18 },  };

                            

  double y,dt;
  

  y=JD/365.25-4711.96;
                              /* polynomial expression for deltaT valid from 2005 to 2050 
                               * taken from "Five Millennium Canon of Solar Eclipses" F. Espenak and J. Meeus
                               */
  dt = 62.92 + 0.32217 * (y-2000.0) + 0.005589 * (y-2000.0) * (y-2000.0);

  if((y < DeltaT[0][0])||(y > DeltaT[MAX_DELTA_T - 1][0]))
  { if(t==0)
    { printf("\n Warning (deltaT) requested year (%7.2f) is out of range [%7.2f,%7.2f] \n",y,DeltaT[0][0],DeltaT[MAX_DELTA_T-1][0]);
      printf("                    Update the DeltaT table from FTP-server and recompile the project!\n\n");
      printf("                    A DEFAULT VALUE FOR deltaT WILL BE USED NOW (deltaT = %.2f)!\n\n",dt);
      t=1;
    }
    return dt;
  }

                                      /* do linear interpolation in DeltaT table ... */
  i=0;
  while(DeltaT[i][0] <  y) i++;
  
  dt=DeltaT[i-1][1] + (DeltaT[i][1]-DeltaT[i-1][1])/(DeltaT[i][0]-DeltaT[i-1][0]) * (y - DeltaT[i-1][0]);

  return dt;
}

