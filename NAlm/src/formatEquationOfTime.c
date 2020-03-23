#include <stdio.h>
#include "../novas/novas.h"
#include "dimensions.h"
#include "primitives.h"




void formatEquationOfTime(FILE *fp, double *oJD, double oGha[][6], int *page)
{ short int year,month,day;
  int       n,ndays;
  char      mdays[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
  char     *months_short[12] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};

  double    now,hour;
  double    xc,yc,ys,yd;
  double    Graph_width,Graph_height;

  
  ys=715.2;
  yd=13.1;

  fprintf(fp,"%%%%Page: %d %d\n",*page,*page);
  fprintf(fp,"gsave\n");
  fprintf(fp,"54 0 translate\n");
  fprintf(fp,"  0.0 744.1 moveto 18 f1 (Equation of Time) show\n");
  fprintf(fp,"  0.0 %5.1f moveto 10 f0 (The \"Equation of Time\" is the difference between the) show\n",ys);
  fprintf(fp,"475.0 %5.1f moveto 10 f0 (Apparent Solar Time and the Mean Solar Time at the) Rshow\n",ys);
  ys-=yd;
  fprintf(fp,"  0.0 %5.1f moveto 10 f0 (Prime Meridian of Greenwich.  The value for the Equation of Time) show\n",ys);
  fprintf(fp,"475.0 %5.1f moveto 10 f0 (\\(EoT\\)  for a specific day can be obtained) Rshow\n",ys);
  ys-=yd;
  fprintf(fp,"  0.0 %5.1f moveto 10 f0 (from the Nautical Almanac. The section of the Sun records) show\n",ys);
  fprintf(fp,"475.0 %5.1f moveto 10 f0 (the \"Greenwich Culmination Time\" \\(GCT\\), which) Rshow\n",ys);
  ys-=yd;
  fprintf(fp,"  0.0 %5.1f moveto 10 f0 (is the UT time at which the Geographical Position of the) show\n",ys);
  fprintf(fp,"475.0 %5.1f moveto 10 f0 (Sun transits the Prime Meridian of Greenwich. This) Rshow\n",ys);
  ys-=yd;
  fprintf(fp,"  0.0 %5.1f moveto 10 f0 (is also the UT time of Local Apparent Noon for the Prime Meridian.) show\n",ys);
  fprintf(fp,"475.0 %5.1f moveto 10 f0 (Thus, the value for the Equation of Time) Rshow\n",ys);
  ys-=yd;
  fprintf(fp,"  0.0 %5.1f moveto 10 f0 (is obtained from:   EoT = 12:00:00 - GCT.) show\n",ys);
  ys-=yd; ys-=yd;
  fprintf(fp,"  0.0 %5.1f moveto 10 f0 (Examples:) show\n",ys);
  ys-=yd; ys-=yd;
  fprintf(fp,"  0.0 %5.1f moveto 10 f4 (GCT = 11:57:23                            GCT = 12:01:57) show\n",ys);
  ys-=yd;
  fprintf(fp,"  0.0 %5.1f moveto 10 f4 (EoT = 12:00:00 - 11:57:23 = +00:02:37     EoT = 12:00:00 - 12:01:57 = -00:01:57) show\n",ys);
  ys-=yd; ys-=yd;
  fprintf(fp,"  0.0 %5.1f moveto 10 f0 (Notice that EoT has a sign:  positive if the Sun \"culminates\") show\n",ys);
  fprintf(fp,"475.0 %5.1f moveto 10 f0 (before 12 UT  \\(then Apparent Time is \"leading\") Rshow\n",ys);
  ys-=yd;
  fprintf(fp,"  0.0 %5.1f moveto 10 f0 (Mean Time\\) and negative if the Sun \"culminates\" after 12 UT) show\n",ys);
  fprintf(fp,"475.0 %5.1f moveto 10 f0 (\\(then Apparent Time is \"lagging\" Mean Time\\).) Rshow\n",ys);

  ys-=5.0*yd;
  

  /* plot the graph with the values for the equation of time ... */
  now=oJD[0];
  cal_date(now,&year,&month,&day,&hour);

  if(year%4) ndays=365;
    else   { ndays=366; mdays[1]=29; }


  fprintf(fp,"  0.0 %5.1f moveto 10 f0 (The next graph shows the values for the \"Equation of Time\" (in Minutes) over the year %d.) show\n",ys,year);
  ys-=yd;

  /* the frame for plotting the graph of the Equation of Time is 460x200 PS units  ...                   */
  Graph_width=460.0;
  Graph_height=200.0;
  /* plot the outer frame ..                                                                                */
  fprintf(fp,"1.0 setlinewidth\n");
  fprintf(fp,"newpath 15.0 %.1f moveto %.1f 0 rlineto 0 %.1f rlineto -%.1f 0 rlineto closepath stroke\n",ys-Graph_height,Graph_width,Graph_height,Graph_width);
  fprintf(fp,"0.1 setlinewidth\n");
  /* plot the horizontal grid lines (4 minutes increment)                                                    */
  for(n=-16; n<=16; n+=4)
  { yc=ys-Graph_height/2.0 + Graph_height/40.0*(double)n;                   /* y-coordinate of the grid line */
    fprintf(fp,"newpath 15.0 +%.1f moveto %.1f 0 rlineto stroke\n",yc,Graph_width);
    fprintf(fp,"12.0 +%.1f moveto 8 f0 (%d) Rshow\n",yc-3.0,n);
  } 
  /* plot the vertical grid lines                                                                            */
  n = 0;
  for(month=0; month<12; month++)
  { xc=15.0+Graph_width*(double)n/(double)ndays;                            /* x-coordinate of the grid line */
    fprintf(fp,"newpath\n");
    fprintf(fp,"%.1f %.1f moveto 0 %.1f rlineto stroke\n",xc,ys-Graph_height,Graph_height);
    fprintf(fp,"%.1f %.1f moveto 10 f0 (%s) show\n",4.0+xc,ys-Graph_height-12.0,months_short[month]);
    n += mdays[month];
  }

  /* finally plot the graph with 365 segments ...                                                            */
  fprintf(fp,"1.0 setlinewidth\n");
  for(n=0; n<ndays; n++)
  { hour = oGha[24*n+12][0]/15.0;        /* convert the 12 o'clock GHA of the Sun to time ...                 */
    if(hour > 1.0) hour-=24.0;        
                                         /* plot the culmination time ..                                      */
    xc=15.0+Graph_width*(double)n/(double)(ndays-1);                       /* x-coordinate of the graph point */
    yc=ys-Graph_height/2.0 + Graph_height/40.0*(60*hour);                  /* y-coordinate of the graph point */
    if(n==0) fprintf(fp,"newpath %.1f %1.f moveto\n",xc,yc);
      else   fprintf(fp,"%.1f %.1f lineto\n",xc,yc);
  }
  fprintf(fp,"stroke\n\n");

  fprintf(fp,"grestore\n");
  fprintf(fp,"showpage\n");


  *page = (*page)+1;

  InsertBlankPage(fp,page);

  return;
}

