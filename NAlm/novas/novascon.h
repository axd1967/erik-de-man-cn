/*
   NOVAS-C Version 2.0 (1 Nov 98)
   Header file for novascon.c

   Naval Observatory Vector Astrometry Subroutines
   C Version

   U. S. Naval Observatory
   Astronomical Applications Dept.
   3450 Massachusetts Ave., NW
   Washington, DC  20392-5420
*/

#ifndef _CONSTS_
   #define _CONSTS_

   extern const short int FN1;
   extern const short int FN0;

   extern const double T0;             /* TDB Julian date of epoch J2000.0.                             */

   extern const double KMAU;           /* Astronomical Unit in kilometers.                              */

   extern const double MAU;            /* Astronomical Unit in meters.                                  */

   extern const double C;              /* Speed of light in AU/Day.                                     */

   extern const double GS;             /* Heliocentric gravitational constant.                          */

   extern const double EARTHRAD;       /* Radius of Earth in kilometers.                                */

   extern const double F;              /* 'f' = Earth ellipsoid flattening                              */

   extern const double OMEGA;          /* 'omega' = rotational angular velocity of Earth in radians/sec */

   extern const double TWOPI;          /* Value of 2.0 * pi in radians.                                 */

   extern const double RAD2SEC;
   extern const double DEG2RAD;
   extern const double RAD2DEG;

#endif
