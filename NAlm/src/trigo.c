#include <stdio.h>
#include <math.h>
#include "dimensions.h"

#define PI      3.14159265358979323846
#define DEG2RAD PI/180.0
#define RAD2DEG 180.0/PI




double Cos(double alpha) { return cos(alpha*DEG2RAD); }           /* alpha in degrees */
double Sin(double alpha) { return sin(alpha*DEG2RAD); }           /* alpha in degrees */
double Tan(double alpha) { return tan(alpha*DEG2RAD); }           /* alpha in degrees */

double aCos(double x) { return RAD2DEG*acos(x); }                 /* return value in degrees */
double aSin(double x) { return RAD2DEG*asin(x); }                 /* return value in degrees */
double aTan(double x) { return RAD2DEG*atan(x); }                 /* return value in degrees */
double aTan2(double y,double x) { return RAD2DEG*atan2(y,x); }    /* return value in degrees  as aTan(y/x) but with correct range */



/* ----------------------------------------------------------------------------------------------------------------------- */
double GHA2Lon(double GHA)
{ double Longitude;

  if((Longitude = -GHA) < -180.0) Longitude+=360.0;
  return Longitude;
}
   


/* ----------------------------------------------------------------------------------------------------------------------- */
double Lon2GHA(double Longitude)
{ double GHA;

  if((GHA = -Longitude) < 0.0) GHA+=360.0;
  return GHA;
}
   

/* ----------------------------------------------------------------------------------------------------------------------- */
/* calDistance() returns the shortest (along a great-circle) angular distance between two celestial bodies
 * with coordinates (Dec0,GHA0) and (Dec1,GHA1). All values (argument and returned value are in degrees).
 * NOTICE that there is a second solution for the aCos() result, which represents the complementary
 * great-circle segment between (Dec0,GHA0) and (Dec1,GHA1).
 */
double calDistance(double Dec0, double GHA0, double Dec1, double GHA1)   /* arguments and return value in degrees */
{ double LHA;

  LHA=GHA1-GHA0;

  return aCos(Sin(Dec0)*Sin(Dec1) + Cos(Dec0)*Cos(Dec1)*Cos(LHA));
}




/* ----------------------------------------------------------------------------------------------------------------------- */
/* The calAzimuth() function returns the great-circle direction from location "0" (Dec0,GHA0) to location "1" (Dec1,GHA1)
 * referring to true North (local meridian in location "0"). All values (argument and returned value are in degrees).
 * The aTan2() function should be used to calculate the Azimuth to obtain an unabigous range of 0 - 360 degrees!
 */
double calAzimuth(double Dec0, double GHA0, double Dec1, double GHA1) 

{ double Z,LHA;

  LHA=-(GHA1-GHA0);              /* this is important to obtain the correct results from the aTan2() function !! */
  Z=aTan2(Cos(Dec1)*Sin(LHA), Cos(Dec0)*Sin(Dec1) - Sin(Dec0)*Cos(Dec1)*Cos(LHA));

  if(Z < 0.0) Z+=360.0;
  return Z;
  
}





/* ----------------------------------------------------------------------------------------------------------------------- */
/* calDestination() calculates the location that is obtained from a starting point along a great-circle path
 * with an initial direction or azimuth "az" and a distance "dist" away.
 * Notice, that for calculating the LHA in the longitude calculation, the aTan2() function should be used to obtain
 * an unabigiuos range of 0..360 degrees!
 */

void calDestination(double lat, double lon, double dist, double az, double *lat_dest, double *lon_dest)

{ double lat_f, lon_f, LHA;

  /* get "az" th the range [0.0 ... 359.9] degrees ... */
  while(az <    0.0) az += 360.0;
  while(az >= 360.0) az -= 360.0;


  lat_f = aSin(Sin(lat)*Cos(dist) + Cos(lat)*Sin(dist)*Cos(az));

  LHA   = aTan2(Sin(dist)*Sin(az),Cos(dist)*Cos(lat) - Cos(az)*Sin(dist)*Sin(lat));
  lon_f = lon + LHA;

  *lat_dest=lat_f;
  *lon_dest=lon_f;

  return;
}
  


  

  


/* ----------------------------------------------------------------------------------------------------------------------- */
/* The ParallaxToDistance() function calcuates the distance an earth-bound observer
 * has to move away from the geographical point of the Moon (or any other celestial object) 
 * in order to obtain the required value of parallax.
 * - "GCdist"   is the geocentrical distance of the celestial object in kilometers
 * - "parallax" is the required parallax angle in degrees
 * the returned value "alpha" is an angular distance (on the surface of the Earth) 
 * in degrees
 * In order to calculate the required distance "PXdist", which is the angle measured
 * at the center of the Earth, an oblique triangle is solved with the vertices:
 * The center of the Earth, the center of the Moon and the location of the earth-bound
 * Observer. The sides of the triangle are:
 *  - the radius of the Earth beween the center of the Earth and the Observer,
 *  - the line between the center of the Earth and the center of the Moon (GCdist) and
 *  - the line from the Observer to the center of the Moon (OMdist)
 * First, the distance "OMdist" is calculated with the law of cosines for plane triangles:
 * the parallax angle at the center of the Moon is knowns and also the length of the 
 * side connecting the center of the Moon with the center of the Earth. The resulting
 * equation for "OMdist" is quadratic and has two solutions:
 * OMdist = GCdist*Cos(parallax) - sqrt(REARTH*REARTH - GCdist*GCdist*Sin(parallax)*Sin(parallax))
 * OMdist = GCdist*Cos(parallax) + sqrt(REARTH*REARTH - GCdist*GCdist*Sin(parallax)*Sin(parallax))
 * But the second solution can be discarted, because, the location of the observer has to be on the 
 * same side of the Earth as the Sub-Lunar point!
 * From the length of "OMdist", the angle "PXdist" can be easily obtained with the
 * Law of Sines for a plane oblique triangle.
 * The local value of "OMdist" is returned through the parameter "OCdist" (Observer-Centric distance) 
 * and can be used to calculate the Semi-Diameter of the celestial object in the location
 * of the observer.
 */

double ParallaxToDistance(double GCdist, double parallax, double *OCdist)
{ double PXdist;                 /* distance from the GP on the Earth to obtain a parallax angle "parallax" */
  double OMdist;                 /* distance between Earth-bound observer and center of the Moon */
  double hp;

  hp=aSin(REARTH/GCdist);           /* first check wether parallax is smaler than the horizontal parallax ... */
  if(parallax > hp)
  { printf(" WARNING: (ParallaxToDistance) required parallax (%12.9f) > horizontal parallax (%12.9f)\n",parallax, hp);
    printf("          (ParallaxToDistance) using horizontal parallax!)\n");
    parallax=hp;
  }

  OMdist = GCdist*Cos(parallax) - sqrt(REARTH*REARTH - GCdist*GCdist*Sin(parallax)*Sin(parallax));
  PXdist = aSin(OMdist*Sin(parallax)/REARTH);

/*
  printf(" GCdist= %f\n",GCdist);
  printf(" RE    = %f\n",REARTH);
  printf(" p     = %f\n",parallax);
  printf(" OMdist= %f\n",OMdist);
  printf(" PXdist= %f\n",PXdist);
 */

  *OCdist = OMdist;
  return PXdist;
}


