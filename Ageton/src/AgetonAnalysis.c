
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define deg2rad 1.0/57.29577951
#define rad2deg     57.29577951

#define LAT_MAX     70.0
#define DEC_MAX     30.0

#define PRINTTERM      0
#define ANGLE_MIN    3.0

#define MULT_FACTOR 100000.0

char LowResolution=0;

double A(double x)

{ double Ax;
 
  if(x< 0.0) x*=-1.0;
  if(x>90.0) x=180.0-x;
  if(x==0.0)  Ax = 9999999.0;
    else      Ax = floor(MULT_FACTOR*log10(1/sin(deg2rad*x))+0.5);

  if(x > 90.0-ANGLE_MIN)  LowResolution=1; 

  return Ax;
}

double Ainv(double y)

{ double s,t;

  s=y/MULT_FACTOR;
  t=1.0/pow(10,s);
  s=1/300.0*floor(300*rad2deg*asin(t)+0.5);  /* round to the nearest 0.2', which represents linear interpolation in the tables */

  return s;
}


double B(double x)

{ double Bx;

  if(x< 0.0) x*=-1.0;
  if(x>90.0) x=180.0-x;
  if(x==90.0) Bx = 9999999.0;
    else      Bx = floor(MULT_FACTOR*log10(1/cos(deg2rad*x))+0.5);

  if(x < ANGLE_MIN) LowResolution=1;

  return Bx;
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







int main(void)

{ int    i;
  long   ErrHcHis[101],ErrZcHis[101],n,l,k;

  double LatAP,Dec,GHA,t,LatQ,dLat,R,Hc,Z,Zc,Hc_c,Zc_c;
  double A_R,A_LatQ,A_Hc,A_Z;
  double ErrHc,ErrZc,inc;
  double ErrHc_max=0.0,ErrZc_max=0.0;

  FILE  *his;

  n=0;
  for(i=0; i<=100; i++) { ErrHcHis[i]=0; ErrZcHis[i]=0; }

  LatAP= 70.0;
  Dec= 30.0;
  t= 100.0;
  inc=0.01666;      /* this is a resolution of 1 minute of arc */

  inc=0.2;          /* this takes about 1 hour on a Celeron 2.4GHz processor */
  inc=0.5;          /* this takes about 3 min. on a Celeron 2.4GHz processor */
  inc=0.1;          /* this takes about  70 min.  on a Xeon 3.4GHz processor */
  inc=0.01666;      /* this takes about  10 days  on a Xeon 3.4GHz processor */

  inc=0.05;  

  if(PRINTTERM)
    printf("   LatAP       Dec        t          Hc          Zc          R         LatQ        dLat      HcA       ZA        ErrHc      ErrZc    \n");

  k=0;
  l=0;
  printf("# Starting Analysis with the following parameter:\n");
  printf("# Latitude:       [-%2.0f:+%2.0f] \n",LAT_MAX,LAT_MAX);
  printf("# Declination:    [-%2.0f:+%2.0f] \n",DEC_MAX,DEC_MAX);
  printf("# Angle Increment: %6.1f minutes\n",60.0*inc);
  printf("# %12ld combinations to be checked ...\n",(long)(LAT_MAX*DEC_MAX*1440/(inc*inc*inc)));

  for(LatAP=+LAT_MAX; LatAP> -LAT_MAX; LatAP-=inc)
    for(Dec=+DEC_MAX; Dec> -DEC_MAX; Dec-=inc)
      for(t=180.0-inc; t> -180.0+inc; t-=inc)
      { Hc_c=Altitude(LatAP,Dec,t);
        Zc_c=Azimuth(LatAP,Dec,t);

	k++;
        LowResolution=0;

        if(k==1) printf("progress:   0.0%%");

        if(Hc_c>2*ANGLE_MIN)
        { A_R    = A(t) + B(Dec);
          R      = Ainv(A_R); 
          A_LatQ = A(Dec) - B(R);
          LatQ   = Ainv(A_LatQ); 

          if(fabs(t)<90.0) { if(Dec<0) LatQ*=-1.0; }               /* if |t| < 90 LatQ has the same sign as Dec   */
            else           { if(Dec>0) LatQ*=-1.0; }               /* if |t| > 90 LatQ has opposite sign of Dec   */

          dLat=LatAP-LatQ;
  
          A_Hc   = B(R) + B(dLat);
          Hc     = Ainv(A_Hc);
  
          A_Z    = A(R) - B(Hc);
          Z      = Ainv(A_Z);      
                                                                   /*  select the supplementary angle if ...       */
          if(((fabs(t)<90.0)&&(dLat>0))||((fabs(t)>90.0)&&(dLat<0)))
            Z=180.0-Z;
                                                                   /* true azimuth depends on whether GP is east or
								    * west of AP (sign of t)                       */
          if(t<0.0) Zc=360.0-Z; else Zc=Z;
  

          if(LowResolution==0)                                             
          { ErrHc = fabs(Hc_c - Hc)*60.0;                                    /* get deviations (errors) in minutes */
            ErrZc = fabs(Zc_c - Zc)*60.0;
            if(ErrHc > ErrHc_max) ErrHc_max=ErrHc;
            if(ErrZc > ErrZc_max) ErrZc_max=ErrZc;

            i=(int)floor(100.0*ErrHc+0.5); if(i>100) i=100; ErrHcHis[i]++;    /* scale is 0.01 minutes per division */
            i=(int)floor( 10.0*ErrZc+0.5); if(i>100) i=100; ErrZcHis[i]++;    /* scale is 0.1  minutes per division */
  
            if(PRINTTERM && ((ErrHc> 2.0)||(ErrZc>50.0)))
              printf("\n%10.5f %10.5f %10.5f %10.5f %10.5f %10.5f %10.5f %10.5f %10.5f %10.5f %10.5f %10.5f\n",LatAP,Dec,t,Hc_c,Zc_c,R,LatQ,dLat,Hc,Zc,ErrHc,ErrZc);

            n++;
          }
	    else l++;           /* count the numer of combinations that are rejected because of low table resolution */

	  if((k%1024)==0) printf("\b\b\b\b\b\b%5.1f%%",100.0*k/(LAT_MAX*DEC_MAX*1440/(inc*inc*inc)));
        }
      }

  printf("\n\n");
  printf("# %12ld samples      in histogram\n",n);
  printf("# %12ld combinations rejected in total (low Hc or low resol.) (%4.1f%%)\n",k-n,100.0*(k-n)/(double)k);
  printf("# %12ld combinations rejected because of low table resolution (%4.1f%%)\n",l,100.0*l/(double)k);
  printf("#\n");
  printf("# ErrHc_max=%4.1f minutes (Altitude error)\n",ErrHc_max);
  printf("# ErrZc_max=%4.1f degrees (Azimuth  error)\n",ErrZc_max/60.0);
  printf("\n\n");

  if((his=fopen("Data/AgetonAnalysis.his","w"))!=NULL) 
  { n=0;
    for(i=0; i<=100; i++) n+=ErrHcHis[i]; 
    printf("# Making histogram (\"Data/AgetonAnalysis.his\") ...\n");
    printf("# %12ld samples      in histogram\n",n);

    for(i=0; i<=100; i++) 
    { if(i>0)
      { ErrHcHis[0]+=ErrHcHis[i];
        ErrZcHis[0]+=ErrZcHis[i];
      }
                            /* plotting X-axis is in fractions of one minute of arc (full scale is 1')
                             * the last value also contains all errors equal or larger than 1'
                             */

      fprintf(his,"%9.6f %9.6f %9.6f %9.6f %9.6f %9.6f\n",(double)i/100.0,(double)ErrHcHis[i]/(double)n,(double)ErrHcHis[0]/(double)n,(double)i/10.0,(double)ErrZcHis[i]/(double)n,(double)ErrZcHis[0]/(double)n);
    }

    fprintf(his,"# Parameter: MULT_FACTOR %.1f ANGLE_MIN %.1f   inc=%.4f\n",MULT_FACTOR,ANGLE_MIN,inc);
    fprintf(his,"# ErrHc_max=%f         ErrZc_max=%f\n",ErrHc_max,ErrZc_max);
    fprintf(his,"# %12ld samples      in histogram\n",n);
    fprintf(his,"# %12ld combinations rejected in total (low Hc or low resol.) (%4.1f%%)\n",k-n,100.0*(k-n)/(double)k);
    fprintf(his,"# %12ld combinations rejected because of low table resolution (%4.1f%%)\n",l,100.0*l/(double)k);
    fclose(his);
  }
    else printf(" Error: could not open file \"Data/AgetonAnalysis.his\" for writing!\n\n");


  return 0;
}
