
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define deg2rad 1.0/57.29577951
#define rad2deg     57.29577951
#define ANGLE_MIN    5.0
#define MULT_FACTOR 100000.0


double A(double x)

{ 
  if(x<0) x*=-1.0;
  if(x>90) x=180.0-x;
  if(x==0.0)  return 9999999.0;
    else      return floor(MULT_FACTOR*log10(1/sin(deg2rad*x))+0.5);
}

double Ainv(double y)

{ double s,t;

  s=y/MULT_FACTOR;
  t=1.0/pow(10,s);
  s=1/300.0*floor(300*rad2deg*asin(t)+0.5);  /* round to the nearest 0.2', which represents linear interpolation in the tables */

  return s;
}


double B(double x)

{
  if(x<0) x*=-1.0;
  if(x>90) x=180.0-x;
  if(x==90.0) return 9999999.0;
    else      return floor(MULT_FACTOR*log10(1/cos(deg2rad*x))+0.5);
}



double Altitude(double LatAP, double Dec, double LHA)

{
  return rad2deg*asin(sin(deg2rad*LatAP)*sin(deg2rad*Dec) + cos(deg2rad*LatAP)*cos(deg2rad*Dec)*cos(deg2rad*LHA));
} 


double Azimuth(double LatAP, double Dec, double LHA)

{ double z;

  z=rad2deg*atan2(sin(deg2rad*LHA),(cos(deg2rad*LatAP)*tan(deg2rad*Dec) - sin(deg2rad*LatAP)*cos(deg2rad*LHA)));
  if(z<0) z+=360.0;

  return z;
} 







int main(int argc, char **argv)

{ int    i;
  int    LatAP_deg,Dec_deg,LonAP_deg,GHA_deg,Hc_deg,t_deg,LHA_deg,R_deg,LatQ_deg,dLat_deg,Z_deg,Zc_deg;
  double LatAP_min,Dec_min,LonAP_min,GHA_min,Hc_min,t_min,LHA_min,R_min,LatQ_min,dLat_min,Z_min,Zc_min;

  double LonAP,LatAP,Dec,GHA,t,LatQ,dLat,R,Hc,Z,Zc,Hc_c,Zc_c,LHA;
  double A_R,A_LatQ,A_Hc,A_Z;
  char   NS1[3],NS2[3],EW1[3],EW2[3];

  LatAP=  45.0;
  LonAP= -45.0;
  Dec=    10.0;
  GHA=   330.0;

  if(argc==5)
  { LatAP=atof(argv[1]);
    LonAP=atof(argv[2]);
    Dec  =atof(argv[3]);
    GHA  =atof(argv[4]);
  }

  LHA=LonAP+GHA; 
  if(LHA>180.0) t=360-LHA; else t=-LHA;

  LatAP_deg=(int)floor(fabs(LatAP));
  LatAP_min=60.0*(fabs(LatAP)-LatAP_deg);
  if(LatAP<0) LatAP_deg*=-1;

  Dec_deg=(int)floor(fabs(Dec));
  Dec_min=60.0*(fabs(Dec)-Dec_deg);
  if(Dec<0) Dec_deg*=-1;

  LHA_deg=(int)floor(fabs(LHA));
  LHA_min=60.0*(fabs(LHA)-LHA_deg);
  if(LHA<0)  LHA_deg*=-1;

  GHA_deg=(int)floor(fabs(GHA));
  GHA_min=60.0*(fabs(GHA)-GHA_deg);

  LonAP_deg=(int)floor(fabs(LonAP));
  LonAP_min=60.0*(fabs(LonAP)-LonAP_deg);
  if(LonAP<0) LonAP_deg*=-1;

  t_deg=(int)floor(fabs(t));
  t_min=60.0*(fabs(t)-t_deg);
  if(t<0) t_deg*=-1;

  Hc_c=Altitude(LatAP,Dec,t);
  Zc_c=Azimuth(LatAP,Dec,t);

  A_R    = A(t) + B(Dec);
  R      = Ainv(A_R); 
  A_LatQ = A(Dec) - B(R);
  LatQ   = Ainv(A_LatQ); 

  if(fabs(t)<90.0) { if(Dec<0) LatQ*=-1.0; }                       /* if t<90; give LatQ the same sign as Dec   */
    else           { if(Dec>0) LatQ*=-1.0; }                       /*   else   give LatQ the contrary sign as Dec   */

/*
  if(LatQ*LatAP<0) dLat=fabs(LatQ)+fabs(LatAP);
    else           dLat=fabs(fabs(LatQ)-fabs(LatAP));
 */
  dLat=LatAP-LatQ;
 
  A_Hc   = B(R) + B(dLat);
  Hc     = Ainv(A_Hc);

  A_Z    = A(R) - B(Hc);
  Z      = Ainv(A_Z);      
                                                               
  if(fabs(t)<90.0) { if(LatAP>LatQ) Z=180.0-Z;  } /* select the supplementary angle if Q is south of AP */
    else           { if(LatAP<LatQ) Z=180.0-Z;  } /* select the supplementary angle if Q is north of AP */

                                     /* true azimuth depends on whether GP is east or west of AP (= sign of t) */
  if(t<0.0) Zc=360.0-Z;
    else    Zc=Z;

  R_deg=(int)floor(fabs(R));
  R_min=60.0*(fabs(R)-R_deg);

  LatQ_deg=(int)floor(fabs(LatQ));
  LatQ_min=60.0*(fabs(LatQ)-LatQ_deg);
  if(LatQ<0) LatQ_deg*=-1;

  dLat_deg=(int)floor(fabs(dLat));
  dLat_min=60.0*(fabs(dLat)-dLat_deg);
  if(dLat<0) dLat_deg*=-1;

  Hc_deg=(int)floor(fabs(Hc));
  Hc_min=60.0*(fabs(Hc)-Hc_deg);

  Z_deg=(int)floor(fabs(Z));
  Z_min=60.0*(fabs(Z)-Z_deg);

  Zc_deg=(int)floor(fabs(Zc));
  Zc_min=60.0*(fabs(Zc)-Zc_deg);


  if(LatAP_deg<0) sprintf(NS1,"S"); else sprintf(NS1,"N");
  if(Dec_deg<0  ) sprintf(NS2,"S"); else sprintf(NS2,"N");
  if(LonAP_deg<0) sprintf(EW1,"W"); else sprintf(EW1,"E");
  if(GHA_deg<180) sprintf(EW2,"W"); else sprintf(EW2,"E");
  printf("                                                                               \n");
  printf("                                                                               \n");
  printf("     AP:  LatAP  = %3d-%04.1f (%s)             GP:    Dec = %3d-%04.1f (%s)    \n",LatAP_deg,LatAP_min,NS1,Dec_deg,Dec_min,NS2);
  printf("          LonAP  = %3d-%04.1f (%s)                    GHA = %3d-%04.1f (%s)        \n",LonAP_deg,LonAP_min,EW1,GHA_deg,GHA_min,EW2);
  printf("                                                                               \n");
  printf("     1.   LHA    = GHA + LonAP   = %3d-%04.1f                                    \n",LHA_deg,LHA_min);
  if(LHA < 180.0) 
    printf("            t    = -LHA          = %3d-%04.1f      [ because  LHA < 180         ]                \n",t_deg,t_min);
    else
    printf("            t    = 360 - LHA     = +%2d-%04.1f      [ because  LHA > 180         ]             \n",t_deg,t_min);
  printf("          A(t)   = %8d                                                    \n",(int)A(t));
  printf("                                                                               \n");
  printf("     2.   A(Dec) = %8d                      B(Dec) = %8d             \n",(int)A(Dec),(int)B(Dec));
  printf("                                                                               \n");
  printf("     3.   A(R)   = A(t) + B(Dec) = %8d + %8d  = %8d             \n",(int)A(t),(int)B(Dec),(int)A(t)+(int)B(Dec));
  printf("            R    = %3d-%04.1f                        B(R) = %8d             \n",R_deg,R_min,(int)B(R));
  printf("                                                                               \n");
  printf("     4.   A(LatQ)= A(Dec) - B(R) = %8d - %8d  = %8d             \n",(int)A(Dec),(int)B(R),(int)A(Dec)-(int)B(R));
  if(LatQ > 0.0)
    printf("            LatQ = +%2d-%04.1f (N) ",LatQ_deg,LatQ_min);
    else
    printf("            LatQ = %3d-%04.1f (S) ",LatQ_deg,LatQ_min);

  if(fabs(t)<90.0)
    printf("[ LatQ     same sign as Dec because |t| < 90  ]\n");
    else
    printf("[ LatQ contrary sign of Dec because |t| > 90  ]\n");
  printf("                                                                               \n");
  printf("     5.     dLat = LatAP - LatQ   = %3d-%04.1f - %3d-%04.1f  = %3d-%04.1f       \n",LatAP_deg,LatAP_min,LatQ_deg,LatQ_min,dLat_deg,dLat_min);
  printf("          B(dLat)= %8d                                                    \n",(int)B(dLat));
  printf("                                                                               \n");
  printf("     6.    A(Hc) = B(R) + B(dLat) = %8d + %8d  = %8d            \n",(int)B(R),(int)B(dLat),(int)B(R)+(int)B(dLat));
  printf("             Hc  = %3d-%04.1f                        B(Hc) = %8d            \n",Hc_deg,Hc_min,(int)B(Hc));
  printf("                                                                               \n");
  printf("     7.    A(Z)  = A(R) - B(Hc)   = %8d - %8d  = %8d            \n",(int)A(R),(int)B(Hc),(int)A(R)-(int)B(Hc));
  printf("             Z   = %3d-%04.1f    ",Z_deg,Z_min);
  if(fabs(t)<90.0)
  { if(dLat > 0)  printf(" [ select Z > 90 because |t| < 90 and dLat > 0 ]\n\n");
      else        printf(" [ select Z < 90 because |t| < 90 and dLat < 0 ]\n\n");
  }
    else
  { if(dLat < 0)  printf(" [ select Z > 90 because |t| > 90 and dLat < 0 ]\n\n");
      else        printf(" [ select Z < 90 because |t| > 90 and dLat > 0 ]\n\n");
  }

  if(t<0.0)
    printf("     8.      Zc  = %3d-%04.1f     [ Zc = 360 - Z  because t < 0                 ] \n",Zc_deg,Zc_min);
    else
    printf("     8.      Zc  = %3d-%04.1f     [ Zc = Z        because t > 0                 ] \n",Zc_deg,Zc_min);
  printf("  \n");
  printf("\n\n");

  printf("   LatAP       Dec        t          Hc          Zc          R         LatQ        dLat      HcA       ZA\n");
  printf("%10.5f %10.5f %10.5f %10.5f %10.5f %10.5f %10.5f %10.5f %10.5f %10.5f\n",LatAP,Dec,t,Hc_c,Zc_c,R,LatQ,dLat,Hc,Zc);

  return 0;
}
