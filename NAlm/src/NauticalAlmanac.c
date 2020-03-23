
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../novas/novas.h"
#include "dimensions.h"
#include "primitives.h"




int main(int argc, char **argv)

{ 
  short int  year,month,day,error,ndays;
  int        k,obj,page;

  double     oJD[367];  
  double     hour,jd,ut,JD,JD_frac,now,UT;
  double     ear_radius,obj_radius=0.0;
  double     HP,SD;

  double     RA,Dec,Dist;
  double     GHA;
  double     oRA[24*367][6],oGHA[24*367][6],oDec[24*367][6],oHP[24*367][6],oSD[24*367][6],oDist[24*367][6];
 
  char       filename[32];
  char       sDec[16],sGHA[16],sUT[16];
  char      *planets[6] = {"sun","venus","moon","mars","jupiter","saturn"};
  char      *days[7] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
  char      *months[12] = {"January","February","March","April","May","June","July","August","September","October","November","December"};

  time_t     t0,t1;
 
  body       object,earth;

  FILE      *fp,*fpA;

  char      *gha2s(), *dgha2s(), *dec2s(), *ddec2s(), *min2s(), *gct2s(), *ut2s();
  double     ra2gha(), deltaT();
  void       FormatFrontPages(), InsertIntro0(), InsertIntro1(), InsertIntro2();
  void       FormatMapPages(), InsertBlankPage(),  FormatAlmanacPages(), GenerateJS();
  void       FormatMoonPhases(), FormatMoonEclipse(), FormatSunEclipse();


  printf(" \nNauticalAlmanac Version: V1.4 \n\n");
  time(&t0);

  if(argc!=2)
  { printf(" Usage : NauticalAlmanac <year [e.g. 2000]>\n");
    exit(-1);
  }


  year=atoi(argv[1]);
  if((year<2000)||(year>2040))
  { printf(" Error (nautab) year out of range \"%s\"!\n",argv[1]);
    exit(-1);
  }
  
  if(year%4) ndays=365;
    else ndays=366;

  sprintf(filename,"Data/Almanac%d.dat",year);
  if((fpA=fopen(filename,"w"))==NULL)
  { printf(" Error (nautab) could not open file \"%s\" for writing!\n",filename);
    exit(-1);
  }


  /* get the position/distance data for the 6 objects "sun","venus","moon","mars","jupiter" and "saturn" ... */
  for(obj=0; obj<6; obj++)
  {
    year=atoi(argv[1]);
    month=1; day=1; hour=0.0;

    JD_frac=0.0;
    JD=julian_date(year,month,day,hour);             /* almanac time starts at 01-Jan-xxxx 00:00:00 UTC  */
  
    error=0;
                                            { error+=set_body(0, 3,"Earth",  &earth);  ear_radius=(REARTH/AU); }
    if(strcmp(planets[obj],"sun") == 0)     { error+=set_body(0,10,"Sun",    &object); obj_radius=(RSUN/AU); }
    if(strcmp(planets[obj],"venus") == 0)   { error+=set_body(0, 2,"Venus",  &object); obj_radius=(RVENUS/AU); }
    if(strcmp(planets[obj],"moon") == 0)    { error+=set_body(0,11,"Moon",   &object); obj_radius=(RMOON/AU); }
    if(strcmp(planets[obj],"mars") == 0)    { error+=set_body(0, 4,"Mars",   &object); obj_radius=(RMARS/AU); }
    if(strcmp(planets[obj],"jupiter") == 0) { error+=set_body(0, 5,"Jupiter",&object); obj_radius=(RJUPITER/AU); }
    if(strcmp(planets[obj],"saturn") == 0)  { error+=set_body(0, 6,"Saturn", &object); obj_radius=(RSATURN/AU); }
  
    if(error)
    { printf("\n Error (nautab) error from set_body() \n");
      exit(-1);
    }

    
    fprintf(fpA,"##########################################################################\n");
    fprintf(fpA,"## Calculating the \"%-9s\" ephemerides for the year %4d\n",planets[obj],year);
     printf(    "## Calculating the \"%-9s\" ephemerides for the year %4d\n",planets[obj],year);
    fprintf(fpA,"##########################################################################\n");
  
  
    k=0;
    for(now=JD; now<JD+ndays+1; now=now+1.0)
    {
      cal_date(now,&year,&month,&day,&hour);
      oJD[k/24]=now;
  
      fprintf(fpA,"#  %4d %8s %2d  %-9s\n",year,months[month-1],day,days[((int)now+2)%7]);

      for(UT=0.0; UT<24.0; UT=UT+1.0)
      { JD_frac=(UT + deltaT(now)/3600.0) / 24.0;
  
        jd=now+JD_frac;
        ut=now+UT/24.0;
  
        error=app_planet(jd,&object,&earth,&RA,&Dec,&Dist);
        if(error)
        { printf("\n Error (nautab) error from app_planet() \n                error code=%d \n",error);
          exit(-1);
        }

  
        HP=60.0 * aSin(ear_radius/Dist);              /* Horizontal parallax  in arcmin  */
        SD=60.0 * aSin(obj_radius/Dist);              /* semi-diameter        in arcmin  */
  
        GHA=ra2gha(ut,RA);

        fprintf(fpA," %s   %s   %s   %4.1f  %4.1f \n",ut2s(UT,sUT),gha2s(GHA,sGHA),dec2s(Dec,sDec),HP,SD);

        oRA[k][obj]=RA;                 /* in hours   */
        oGHA[k][obj]=GHA;               /* in degrees */
        oDec[k][obj]=Dec;               /* in degrees */
        oHP[k][obj]=HP;                 /* in minutes */
        oSD[k][obj]=SD;                 /* in minutes */
        oDist[k][obj]=Dist;             /* in AU      */
        k++;
      }
    }
  }
  fclose(fpA);

  time(&t1);
  printf("                                              CPU time     %5.1f seconds\n",difftime(t1,t0));

  year=atoi(argv[1]);
  printf("\n\n## PostScript formatting of the Nautical Almanac for  %d\n",year);

  sprintf(filename,"Data/NAlm%s.ps",argv[1]);
  if((fp=fopen(filename,"w"))==NULL)
  { printf(" Error (nautab) could not open file \"%s\" for writing!\n",filename);
    exit(-1);
  }

  FormatFrontPages(fp,year);
  page=2;
  InsertIntro0(fp,&page,year);
  FormatMapPages(oJD,oRA,oDec,&page,fp);
  InsertBlankPage(fp,&page);

  printf("##            calculating Moon Phases ...\n");
  FormatMoonPhases(oJD,oGHA,oDec,&page,fp);

  printf(    "##            calculating Lunar Eclipses ...\n");
  FormatMoonEclipse(oJD,oRA,oDec,oDist,oSD,&page,fp);

  time(&t1);
  printf("                                              CPU time     %5.1f seconds\n",difftime(t1,t0));

/*
*/
  printf("##            calculating Solar Eclipses ...\n");
  FormatSunEclipse(oJD,oGHA,oDec,oDist,&page,fp);

  time(&t1);
  printf("                                              CPU time     %5.1f seconds\n",difftime(t1,t0));

  if(!(page%2)) InsertBlankPage(fp,&page);

  printf("##            calculating Equation of Time ...\n");
  formatEquationOfTime(fp,oJD,oGHA,&page);
  time(&t1);
  printf("                                              CPU time     %5.1f seconds\n",difftime(t1,t0));


  InsertIntro1(fp,&page);

  printf("##            formatting Almanac Pages  ...\n");
  FormatAlmanacPages(oJD,oGHA,oDec,oHP,oSD,&page,fp);
  if(!(page%2)) InsertBlankPage(fp,&page);
  InsertBlankPage(fp,&page);
  InsertBlankPage(fp,&page);
/*
*/

  fprintf(fp,"%%%%EOF\n");
  fclose(fp);


/*
*/
  printf(    "\n\n## generating JavaScript of the Nautical Almanac for  %d\n",year);
  /*
  GenerateJS(oJD,oGHA,oDec,oHP,oSD);
   */
  GenerateJScompactEph(oJD,oGHA,oDec,oDist);

  printf(    "\n\n## finished !\n");
  time(&t1);
  printf("                                              CPU time     %5.1f seconds\n",difftime(t1,t0));


  return 0;
}
