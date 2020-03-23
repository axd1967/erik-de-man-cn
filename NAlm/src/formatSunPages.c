#include <stdio.h>
#include <math.h>
#include "../novas/novas.h"
#include "dimensions.h"
#include "primitives.h"


#define MAXPATHS           8
#define MAXPOINTS         24
#define PPH             3600              /* points per hour during fine scan for eclipses */


/* the debug file is available for all functions in this context ... */
FILE      *dbg;




/* Note on the definitions "moment of maximum eclipse" and "moment of greatest eclipse":
 * Both terms are used here to mark the moment at which, the geocentric distance between the center of the 
 * Moon and the center of the Sun are minimal. In the liturature, the "moment of greatest eclipse" is 
 * defined as the moment at which the center of the penumbral cone is closest to the center of the Earth.
 * However, both definitions are very similar and we will not distinguish between both terms!  
 */


typedef struct
{
  int    eclipse_type;                    /* initialized to 0, partial=1, annular=2, full=3                */
  int    path_number; 

  double P1;                              /* times of contacts P1, U1, greatest eclipse, contacts U4 and P4 */
  double U1;
  double Ge;
  double U4;
  double P4;    

  double P1sGHA,P1sDec;                  /* Subsolar point coordinates at P1                          */
  double P1mGHA,P1mDec;                  /* Sublunar point coordinates at P1                          */
  double GeSSpGHA,GeSSpDec;              /* Subsolar point coordinates at moment of greatest eclipse  */
  double GeSLpGHA,GeSLpDec;              /* Sublunar point coordinates at moment of greatest eclipse  */
  double P4sGHA,P4sDec;                  /* Subsolar point coordinates at P4                          */
  double P4mGHA,P4mDec;                  /* Sublunar point coordinates at P4                          */
  
  double lon_P1,lat_P1;                  /* location of first (outer) contact                         */
  double lon_Ge,lat_Ge;                  /* location of greatest eclipse (Moon closest to the Sun)    */
  double lon_P4,lat_P4;                  /* location of last (outer) contact                          */

  double P1MEdist;                       /* Earth-Moon distance at P1                         in km   */
  double GeMEdist;                       /* Earth-Moon distance at moment of greatest eclipse  in km  */
  double P4MEdist;                       /* Earth-Moon distance at P4                         in km   */

  double mSD_Ge;                         /* Moon SD (topographic) at moment of GE                     */          
  double sSD_Ge;                         /* Sun  SD (topographic) at moment of GE                     */ 
  double aDis_Ge;                        /* (topogr.) angular distance between Sun and Moon at GE     */

  double MapCenterLongitude;             /* for partial eclipses close to the poles, the map center
                                            may be different from the GE_longitude ! */
} 

EclipseStruct;


/* ---------------------------------------------------------------------------------------------------------------- */
/* define the celestial object  structures as global varables */

body             Sun,Moon,Earth;
static site_info localpoint;

/* ---------------------------------------------------------------------------------------------------------------- */







void PrintSunIntro(int *page, FILE *fp)
{ double y,y0;

  y0=13.3;
  y=715.2;

  fprintf(fp,"%%%%Page: %d %d\n",*page,*page);
  fprintf(fp,"54 0 translate\n");
  fprintf(fp,"  0.0 744.1 moveto 18 f1 (Solar Eclipses) show\n");

  fprintf(fp,"  0.0 %.1f  moveto 10 f0 (An eclipse of the Sun - or solar eclipse - can only occur) show\n",y);
  fprintf(fp,"475.0 %.1f  moveto 10 f0 (at New Moon, and only if the Earth passes through) Rshow\n",y);
  y-=y0;
  fprintf(fp,"  0.0 %.1f  moveto 10 f0 (some portion  of the Moon's shadow.) show\n",y);
  fprintf(fp,"475.0 %.1f  moveto 10 f0 (Seen  from the Earth,  the Moon passes  in front  of the Sun and thus) Rshow\n",y);
  y-=y0;
  fprintf(fp,"  0.0 %.1f  moveto 10 f0 (a part  - or all -  of  the  light  of  the Sun  is eclipsed.) show\n",y);
  fprintf(fp,"475.0 %.1f  moveto 10 f0 (The  shadow  cast by  the Moon  is composed  of two) Rshow\n",y);
  y-=y0;
  fprintf(fp,"  0.0 %.1f  moveto 10 f0 (concentric  cone-shaped  components.) show\n",y);
  fprintf(fp,"475.0 %.1f  moveto 10 f0 (The outer  or                      shadow  zone  is the  region  where the) Rshow\n",y);
  fprintf(fp,"246.0 %.1f  moveto 10 f2 (penumbral) show\n",y);
  y-=y0;
  fprintf(fp,"  0.0 %.1f  moveto 10 f0 (Moon blocks  a part  of the  sunlight.) show\n",y);
  fprintf(fp,"475.0 %.1f  moveto 10 f0 (The inner or               shadow zone is a region where the Moon blocks) Rshow\n",y);
  fprintf(fp,"224.0 %.1f  moveto 10 f2 (umbral) show\n",y);
  y-=y0;
  fprintf(fp,"  0.0 %.1f  moveto 10 f0 (all sunlight. Based on this, three types of solar eclipes may be distinguised:) show\n",y);
  y-=y0;
  fprintf(fp,"  0.0 %.1f  moveto 10 f0 (1.) show\n",y);
  fprintf(fp," 10.0 %.1f  moveto 10 f0 (Total solar eclipse:  occurs when the umbra of the Moon's shadow) show\n",y);
  fprintf(fp,"475.0 %.1f  moveto 10 f0 (touches a region on the surface of the) Rshow\n",y);
  y-=y0;
  fprintf(fp," 10.0 %.1f  moveto 10 f0 (Earth.) show\n",y);
  y-=y0;
  fprintf(fp,"  0.0 %.1f  moveto 10 f0 (2.) show\n",y);
  fprintf(fp," 10.0 %.1f  moveto 10 f0 (Partial solar eclipse:  occurs  when  the  penumbra  of the  Moon's  shadow) show\n",y);
  fprintf(fp,"475.0 %.1f  moveto 10 f0 (passes  over a  region on the) Rshow\n",y);
  y-=y0;
  fprintf(fp," 10.0 %.1f  moveto 10 f0 (Earth's surface.) show\n",y);
  y-=y0;
  fprintf(fp,"  0.0 %.1f  moveto 10 f0 (3.) show\n",y);
  fprintf(fp," 10.0 %.1f  moveto 10 f0 (Annular solar eclipse:  occurs when  a region  on the  Earth's  surface) show\n",y);
  fprintf(fp,"475.0 %.1f  moveto 10 f0 (is  in  line  with  the umbra,  but the) Rshow\n",y);
  y-=y0;
  fprintf(fp," 10.0 %.1f  moveto 10 f0 (distances are such that the tip of the umbra does not reach the Earth's surface) show\n",y);
  y-=y0;
  y-=y0;
  fprintf(fp,"  0.0 %.1f  moveto 10 f0 (Because of the relative sizes of the Moon and Sun and  their) show\n",y);
  fprintf(fp,"475.0 %.1f  moveto 10 f0 (specific distances from the Earth,  only a small) Rshow\n",y);
  y-=y0;
  fprintf(fp,"  0.0 %.1f  moveto 10 f0 (part  of the Earth surface  is covered  by the Moon shadow) show\n",y);
  fprintf(fp,"475.0 %.1f  moveto 10 f0 (during  a solar eclipse.     Especially the path of) Rshow\n",y);
  y-=y0;
  fprintf(fp,"  0.0 %.1f  moveto 10 f0 (totality is usually very narrow \\(a few hundreds of kilometers across\\).) show\n",y);
  fprintf(fp,"475.0 %.1f  moveto 10 f0 (A much broader region  is covered by) Rshow\n",y);
  y-=y0;
  fprintf(fp,"  0.0 %.1f  moveto 10 f0 (the penumbral shadow of the Moon.) show\n",y);
  fprintf(fp,"475.0 %.1f  moveto 10 f0 (However, an observer in this region will see only a partial solar eclipse.) Rshow\n",y);
  y-=y0;
  y-=y0;
  fprintf(fp,"  0.0 %.1f  moveto 10 f0 (The appearance of a specific solar eclipse can be summarized conveniently) show\n",y);
  fprintf(fp,"475.0 %.1f  moveto 10 f0 (by mapping the path of totality) Rshow\n",y);
  y-=y0;
  fprintf(fp,"  0.0 %.1f  moveto 10 f0 (and the region  covered  by the penumbral shadow of the Moon  for the) show\n",y);
  fprintf(fp,"475.0 %.1f  moveto 10 f0 (complete duration the eclipse.  The) Rshow\n",y);
  y-=y0;
  fprintf(fp,"  0.0 %.1f  moveto 10 f0 (lines of constant time, included in the charts, indicate the instances of greatest eclipse.) show\n",y);
  y-=y0;
  y-=y0;
  y-=y0;
  fprintf(fp,"  0.0 %.1f  moveto 10 f0 (Warning:   never look directly at the Sun  without proper eye protection,) show\n",y);
  fprintf(fp,"475.0 %.1f  moveto 10 f0 (even during an eclipse.  Even when) Rshow\n",y);
  y-=y0;
  fprintf(fp,"  0.0 %.1f  moveto 10 f0 (the Sun is partially covered,  your eyes can be seriously damaged  by looking directly at it.) show\n",y);
  fprintf(fp,"475.0 %.1f  moveto 10 f0 (Sunglasses are) Rshow\n",y);
  y-=y0;
  fprintf(fp,"  0.0 %.1f  moveto 10 f0 (not an adequate eye protection for viewing the Sun.) show\n",y);
  fprintf(fp,"showpage\n");
  
  *page = (*page)+1;

  return;
}

/* ---------------------------------------------------------------------------------------------------------------- */
/* The "WorldMap" is stored in the local file "Maps/wmap.txt". This file consists of 470 lines of 1200 characters each.
 * The resolution is 0.3 degrees per pixel for both Latitude and Longitude. The Latidude range is from 70 degrees North
 * to 70 degrees South. This gives 141 degrees / 0.3 degrres/pixel = 470 pixel for the Latitude range. For the 
 * Longitude, only 225 degrees (750 pixel) of the available 360 degrees (1200 pixel) are used for plotting (the 
 * visible (daylight) fraction of the Earth during the Eclipse). The world map is read with the Longitude range of
 * 225 degrees centered along the "center_longitude" given in the argument. This "center_longitude" is normaly the
 * Longitude of the location where the greatest eclipse occurs.
 * The "pixels" in the *wmap array, are initialized with 0x0D for "sea-pixels" and 0x0F for "land-pixels".
 */

void ReadWorldMap(char *wmap, int center_longitude)
{ int   i,j;
  int   pixel_lon_offset,pixel_value;

  char  line[1200];

  FILE *wmap_fp;

  if((wmap_fp=fopen("Maps/wmap.txt","r"))==NULL)
  { printf(" ERROR (ReadWorldMap) could not open file \"Maps/wmap.txt\" for reading!\n");
    exit(-1);
  }

  pixel_lon_offset=(int)(10.0/3.0*(180+center_longitude)+0.5) - 375;
  if(pixel_lon_offset<0) pixel_lon_offset+=1200;

  for(i=0; i<470; i++)
  { j=0;
    while(j<1200) if((line[j]=fgetc(wmap_fp)) != '\n') j++;

    for(j=0; j<750; j++)
    { pixel_value=line[(pixel_lon_offset+j)%1200]-'0';
      wmap[i*750+j]=0x0F - (pixel_value<<1);             /* this gives 0x0F or 0x0D for the pixel values */
    }
  }

  return;
}
    


/* ---------------------------------------------------------------------------------------------------------------- */
void WriteWorldMap(FILE *nalm_fp, char *wmap, double yoffset, double *timelines, double *timeline_labels, EclipseStruct *EclipseData)

{ int    i,j,n,m,t,max_lines;
  int    ps_rs,ps_ls,ps,pd_rs,pd_ls,pd;
  int    b0,b1;
  int    chart_offset;
  char   tmpstring[16];
  
  double tic_offset;
  double timeline_index,utc;
  double lon_Ge,lat_Ge;
  double x,y;

  chart_offset = EclipseData->MapCenterLongitude;
  lat_Ge = EclipseData->lat_Ge;
  lon_Ge = EclipseData->lon_Ge;

  /* ======================== PLOT THE BITMAP ====================================================== */
  /* 4 Bit Grey Scale images in PostScript:
   * The simplest method that is applicable to small images is the postscript command image.
   * This take 5 arguments: the width and height of the image, the bits per pixel, a transformation matrix (6 numbers)
   * and finally a procedure for acquiring the image data.
   * In this code, the grey scale (8 bit) image is 750 pixels wide by 470 pixels high. Since in postscript an image is
   * defined from the lower left corner, and the image is defined from its top left corner, the transformation matrix
   * used here does the appropriate vertical flipping.
   * Due to line length and other restrictions, turning 'large" bitmaps into postscript requires a modification to the
   * methods discussed above. The bitmap cannot be contained in a single hex-string, but must be defined as "internal"
   * file and linked to the image command: "{ currentfile 750 string readhexstring pop } image" followed by the bitmap.
   */

  fprintf(nalm_fp,"%% here comes the world map data in 4-bit grey-scale image ...\n");
  fprintf(nalm_fp,"gsave\n");
  fprintf(nalm_fp,"0 %5.1f translate\n440 240 scale\n",yoffset);
  fprintf(nalm_fp,"750 470 4 [750 0 0 470 0 0]\n");
  fprintf(nalm_fp,"  { currentfile 750 string readhexstring pop } bind\n image\n");

  n=0;
  for(i=469; i>=0; i--)
    for(j=0; j<750; j++)
    { b1=wmap[i*750+j];

      fprintf(nalm_fp,"%x",b1);
      if(++n == 75)
      { fprintf(nalm_fp,"\n");
        n=0;
      }
    }
  fprintf(nalm_fp,"\n");
  fprintf(nalm_fp,"grestore\n");



  /* ======================== NOTICE ON COORDINATES OVER BITMAP ==================================== */
  /* NOTICE for plotting over the bitmap:
   * the PostScript coordinates (  0.0,yoffset)       corresponds to (center_longitude - 112.5 degrees, -70.5 degrees Latitude)
   * the PostScript coordinates (440.0,yoffset+240.0) corresponds to (center_longitude + 112.5 degrees, +70.5 degrees Latitude)
   *
   *            yoffset+240.0      +----------------+
   *                               |                |
   *                               |                |
   *            yoffset            +----------------+
   *                               0                440
   * To plot a point with coordinates (Lat,Lon) the corresponding postscript coordinates are:
   *    Lon   ->    x = (Lon - center_longitude) * 440/225 + 220   with 440/225 = 1.956
   *    Lat   ->    y = yoffset + ( Lat * 240/141) + 120.0         with 240/141 = 1.702
   */


  /* ======================== PLOT THE TICS AND LABELS ============================================= */
  fprintf(nalm_fp,"\n%% here come the tics and the labels ...\n");

  fprintf(nalm_fp,"0.1 setlinewidth\n");
  fprintf(nalm_fp,"newpath 0 %.1f moveto 440 0 rlineto 0 240 rlineto -440 0 rlineto closepath stroke\n",yoffset);
  
                                       /* add latitude  tics and labels ... */
  for(n=-60; n<=60; n+=15)                          
  { 
    if(n!=0)
    { fprintf(nalm_fp,"newpath   0 %.1f moveto 4 0 rlineto stroke\n",yoffset+(double)n*1.702+120.0);
      fprintf(nalm_fp,"newpath 436 %.1f moveto 4 0 rlineto stroke\n",yoffset+(double)n*1.702+120.0);
    } else fprintf(nalm_fp,"newpath   0 %.1f moveto 440 0 rlineto stroke\n",yoffset+(double)n*1.702+120.0);
      
    fprintf(nalm_fp,"458 %.1f moveto 8 f0 (%2d\\260) Rshow\n",yoffset+(double)n*1.702+117.6,abs(n));
  }
  fprintf(nalm_fp,"450 %.1f moveto 8 f0 (N) Rshow\n",yoffset+233.6);
  fprintf(nalm_fp,"450 %.1f moveto 8 f0 (S) Rshow\n",yoffset);

                                       /* add longitude tics and labels ... */
  for(n=-360; n<360; n+=15)
  { tic_offset=((double)n-chart_offset)*1.956 + 220.0;
    m=n;
    if(m>+180) m-=360;
    if(m<-180) m+=360;
    if((tic_offset>10) && (tic_offset<430))
    { if((abs(m)!=0)&&(abs(m)!=180))
      { fprintf(nalm_fp,"newpath %.1f %.1f moveto 0 4 rlineto stroke\n",tic_offset,yoffset);
        fprintf(nalm_fp,"newpath %.1f %.1f moveto 0 4 rlineto stroke\n",tic_offset,yoffset+236.0);
      }
        else fprintf(nalm_fp,"newpath %.1f %.1f moveto 0 240 rlineto stroke\n",tic_offset,yoffset);
      sprintf(tmpstring,"%3d",abs(m));
      if(tmpstring[0]==' ') tmpstring[0]='0';
      if(tmpstring[1]==' ') tmpstring[1]='0';
      fprintf(nalm_fp,"newpath %.1f %.1f moveto (%s\\260) Cshow\n",tic_offset,yoffset-8.0,tmpstring);
    }
  }


  /* ======================== PLOT THE MARK ON LOCATION OF GE ====================================== */
  /* for partial eclipses close to the poles, the map center may differ from the GE longitude        */

  if(fabs((double)(chart_offset-lon_Ge)) < 2.0)
  { fprintf(nalm_fp,"\n%% here comes the mark on GE location\n");
    fprintf(nalm_fp,"gsave\n"); 
    fprintf(nalm_fp,"1.0 setgray\n");      /* set RGB to "white" */
    fprintf(nalm_fp,"0.5 setlinewidth\n"); 
    fprintf(nalm_fp,"%.1f %.1f translate\n",220.0,yoffset+120.0+1.702*(double)lat_Ge); 
    fprintf(nalm_fp,"newpath 0.0 0.0 moveto 2.0 0.0 lineto -2.0  0.0 lineto 0.0 0.0 lineto  0.0 1.4 lineto 0.0 -1.4 lineto stroke\n"); 
    fprintf(nalm_fp,"newpath 0.0 0.0 moveto 1.0 1.0 lineto -1.0 -1.0 lineto 0.0 0.0 lineto -1.0 1.0 lineto 1.0 -1.0 lineto stroke\n"); 
    fprintf(nalm_fp,"grestore\n");
  }

  /* ======================== PLOT THE POSITIONS of the P1/P4 contacts ================================ */
  x=(EclipseData->lon_P1-chart_offset)*1.956+220.0;
  y=yoffset+120.0+1.702*EclipseData->lat_P1-3.0;
  if((x>=0)&&(x<440)) fprintf(nalm_fp,"%.1f %.1f moveto 8 f0 (P1) Cshow\n",x,y);
  x=(EclipseData->lon_P4-chart_offset)*1.956+220.0;
  y=yoffset+120.0+1.702*EclipseData->lat_P4-3.0;
  if((x>=0)&&(x<440)) fprintf(nalm_fp,"%.1f %.1f moveto 8 f0 (P4) Cshow\n",x,y);
  fprintf(dbg,"  lat_P1=%6.1f  lon_P1=%6.1f   lat_P4=%6.1f  lon_P1=%6.1f\n", EclipseData->lat_P1,EclipseData->lon_P1,EclipseData->lat_P4,EclipseData->lon_P4);  


  /* ======================== PLOT THE TIMELINES AND LABELS ======================================== */

  fprintf(nalm_fp,"\n%% here come the timelines and their labels ...\n");
  /* timelines are stored in two segments obtained from a "right-scan" and a "left-scan" of the "GEmagnitudes[]" field            */
  max_lines=0;
  for(t=0; t<24; t+=2)               /* check how many timelines are available   */
    if(timeline_labels[t] >= 0.0) max_lines=t;

  for(t=0; t <= max_lines; t+=2)
  {                                   /* find the correct starting point of the timeline   */

                                      /* search for a xxx -> -3 transition in the timeline array indicating a possible
                                       * start point for the timeline curve */
    ps_rs=0; ps_ls=0;
    pd_rs=0; pd_ls=0;
    for(n=0; n<470; n++)
    { m=t*470+n;                      /* this is the line to be checked (right-scan) ... */
      if(timelines[m] > 0)
      { if(timelines[m+1] == -3) { ps_rs=n; pd_rs=-1; }
        if(timelines[m-1] == -3) { ps_rs=n; pd_rs=+1; }
      }
      m=(t+1)*470+n;                  /* this is the line to be checked (left-scan)  ... */
      if(timelines[m] > 0)
      { if(timelines[m+1] == -3) { ps_ls=n; pd_ls=-1; }
        if(timelines[m-1] == -3) { ps_ls=n; pd_ls=+1; }
      }
    }

    if((ps_rs == 0)&&(ps_ls == 0))    /* then check for one segment in the left-scan timeline ... */
      for(n=0; n<470; n++)
      { m=(t+1)*470+n;                  /* this is the line to be checked (left-scan)  ... */
        if(timelines[m] > 0)
        { if(timelines[m+1] == -1) { ps_ls=n; pd_ls=-1; }
          if(timelines[m-1] == -1) { ps_ls=n; pd_ls=+1; }
        }
      }
                                      /* select the starting point, plot direction and segment (i)  */
    ps=0; pd=1; i=0;
    if(ps_rs > 0) { ps=ps_rs; pd=pd_rs; i=0; } 
      else if(ps_ls > 0) { ps=ps_ls; pd=pd_ls; i=1; }

    n=0;
    if(ps > 0)
    { utc=-1;
      utc=timeline_labels[t];
      if(utc>24.0) utc-=24.0;

      fprintf(nalm_fp,"%% ------------------- here starts the %s UTC timeline ! ----------------------------------\n",time2s(utc,tmpstring));
      fprintf(nalm_fp,"0.1 setlinewidth\n");

      b0=b1=ps;                                         /* b0 and b1 will store the min/max index within the timeline ... */
      timeline_index=timelines[ps + (t+i)*470];
      m=(int)(timeline_index/750.0);
      timeline_index-=m*750.0;
      fprintf(nalm_fp,"newpath %.1f %.1f moveto \n",timeline_index*0.586667,240+yoffset-m*0.51063);
      n+=pd;                                             /* move index according to plot direction (pd = +/- 1) ... */
      while((timeline_index=timelines[ps+n+(t+i)*470]) > 0)
      { m=(int)(timeline_index/750.0);
        timeline_index-=m*750.0;
        fprintf(nalm_fp,"%.1f %.1f lineto \n",timeline_index*0.586667,240+yoffset-m*0.51063);
        n+=pd;                                
        if(ps+n > b1) b1=ps+n;
        if(ps+n < b0) b0=ps+n;
      }
      i=(i+1)%2;  n-=pd; pd*=-1;                         /* switch to the second segment     ... */
      while((timeline_index=timelines[ps+n+(t+i)*470]) > 0)
      { m=(int)(timeline_index/750.0);
        timeline_index-=m*750.0;
        fprintf(nalm_fp,"%.1f %.1f lineto \n",timeline_index*0.586667,240+yoffset-m*0.51063);
        n+=pd;
        if(ps+n > b1) b1=ps+n;
        if(ps+n < b0) b0=ps+n;
      }
      i=(i+1)%2;  n-=pd; pd*=-1;                         /* switch to the first segment again ... */
      pd*=-1;
      while((timeline_index=timelines[ps+n+(t+i)*470]) > 0)
      { m=(int)(timeline_index/750.0);
        timeline_index-=m*750.0;
        fprintf(nalm_fp,"%.1f %.1f lineto \n",timeline_index*0.586667,240+yoffset-m*0.51063);
        n+=pd;
        if(ps+n > b1) b1=ps+n;
        if(ps+n < b0) b0=ps+n;
      }
      fprintf(nalm_fp,"stroke\n\n");
                                                  /* plot the UTC time along the timeline ... */
      timeline_index=timelines[t*470+(b0+b1)/2];  /* one of these this is the index of the "midpoint" of the time line range */
      if(timeline_index < 0) timeline_index=timelines[(t+1)*470+(b0+b1)/2];
      m=(int)(timeline_index/750.0);
      timeline_index-=m*750.0;
      fprintf(nalm_fp,"1.0 setlinewidth\n 1.0 setgray\n %.1f %.1f moveto 6 f0 (%s) false charpath stroke\n",timeline_index*0.586667-8.0,240+yoffset-m*0.51063,time2s(utc,tmpstring));
      fprintf(nalm_fp,"0.1 setlinewidth\n 0.0 setgray\n %.1f %.1f moveto 6 f0 (%s) show\n",timeline_index*0.586667-8.0,240+yoffset-m*0.51063,time2s(utc,tmpstring));
    }
      else 
      { if((timelines[t*470] < -500) || (timelines[t*470+469] < -500))
          printf(" ERROR: (WriteWorldMap) no START point found for timeline %d\n",t>>1);
      }
  } 

  fprintf(nalm_fp,"%% ------------------- here ends the eclipse plot!   ----------------------------------\n");

  return;
}







/* ---------------------------------------------------------------------------------------------------------------- */
void GetLocalSunMoonParameter(double  lat,  double  lon, double  JD,
                              double *aDis, double *sRA, double *sDec, double *sSD, double *mRA, double *mDec, double *mSD)

{ short int error=0;
  double    sRA_l,mRA_l,sDec_l,mDec_l,sDis_l,mDis_l;

  localpoint.latitude =lat;
  localpoint.longitude=lon;

  error+=topo_planet(JD, &Sun,  &Earth, 0.0, &localpoint,&sRA_l,&sDec_l,&sDis_l);
  error+=topo_planet(JD, &Moon, &Earth, 0.0, &localpoint,&mRA_l,&mDec_l,&mDis_l);
  if(error)
  { printf("\n ERROR (GetLocalSunMoonParameter) error from topo_planet() \n");
    exit(-1);
  }

  *aDis=calDistance(sDec_l,15.0*sRA_l,mDec_l,15.0*mRA_l);     /* in degrees ! */

  *mSD=aSin(RMOON/(mDis_l*AU));       /* in degrees ! */
  *sSD=aSin(RSUN /(sDis_l*AU));       /* in degrees ! */

  *sRA=sRA_l;
  *mRA=mRA_l;
  *sDec=sDec_l;
  *mDec=mDec_l;

  return;
}





/* ---------------------------------------------------------------------------------------------------------------- */
/* FindMapCenter() tries to find a solution for the Longitude on which the trajectory map will be centered.
 * For TOTAL eclipses, this is the Longitude of the location in which the greatest eclipse occurs. In some cases of
 * NON-TOTAL, the Longitude of the Sub-Solar point at the moment of the greatest eclipse is used.
 * In some cases where the eclipses occur near the poles, the location in which the greatest eclipse occurs may
 * "flip over" the pole but the larger part of the moon shadow will at the "other side" of the pole. In this case,
 * the Longitude of the Sub-Solar point at the moment of the greatest eclipse is used as Longitude for the center of
 * the trajectory map.
 */

double FindMapCenter(EclipseStruct *EclipseData)

{ double aDis,latSLp,lonSLp,distSLpGe,azimSLpGe;
  double latSSp,lonSSp;
  double latGe,lonGe;
  double HPmoonGe;
  double SDmoonLocal;
  double MapCenterLon=0.0;
  double sRA,sDec,sSD,mRA,mDec,mSD;

  fprintf(dbg,"\n");
  fprintf(dbg," ---------------- data from FindMapCenter() ------ n=%2d ---------------------\n",EclipseData->path_number);


  aDis=calDistance(EclipseData->GeSSpDec,EclipseData->GeSSpGHA,EclipseData->GeSLpDec,EclipseData->GeSLpGHA);
  HPmoonGe = aSin(REARTH/EclipseData->GeMEdist);

  /* for non-total eclipses, there will be no location where the apparent coordinates for Sun and Moon coincide !! */
  /* so the required aDis cannot be larger than the HP of the moon at the moment of GE ("HPmoonGe")                */
  if(aDis > HPmoonGe) 
  { aDis = HPmoonGe*0.999;
    fprintf(dbg," WARNING: Reduced the required parallax distance to make Sun and Moon coincide\n");
    fprintf(dbg," because it is larger than the HP. The stored eclipse type on this moment is:\n");
    fprintf(dbg," eclipse_type=%d\n\n",EclipseData->eclipse_type);
  }

  /* get the distance and direction to travel in order to make the Moon-center coincide with the Sun-center        */
  /* for the direction: go in the "opposite" bearing in which the SSp lies as seen from the SLp !!                 */
  distSLpGe=ParallaxToDistance(EclipseData->GeMEdist,aDis,&SDmoonLocal);
  azimSLpGe=180.0 + calAzimuth(EclipseData->GeSLpDec,EclipseData->GeSLpGHA,EclipseData->GeSSpDec,EclipseData->GeSSpGHA);
  if(azimSLpGe > 360.0) azimSLpGe-=360.0;

  /* get the Latitude and Longitude of the Sub-Solar Point at moment of greatest eclipse                            */
  latSSp=EclipseData->GeSSpDec;
  lonSSp=GHA2Lon(EclipseData->GeSSpGHA);

  /* get the Latitude and Longitude of the Sub-Lunar Point at moment of greatest eclipse                            */
  latSLp=EclipseData->GeSLpDec;
  lonSLp=GHA2Lon(EclipseData->GeSLpGHA);
  


  fprintf(dbg," Locations of the Geographical Points of Sun and Moon at the Moment of Greatest Eclipse:\n");
  fprintf(dbg," Sub-Solar Pnt :  Lat=%9.4f           Lon=%9.4f        GHA=%9.4f\n",latSSp,lonSSp,EclipseData->GeSSpGHA);
  fprintf(dbg," Sub-Lunar Pnt :  Lat=%9.4f           Lon=%9.4f        GHA=%9.4f\n",latSLp,lonSLp,EclipseData->GeSLpGHA);
  fprintf(dbg," Distance and Bearing to the location of the GE:\n");
  fprintf(dbg," Distance      :                    distSLpGe=%10.5f\n",distSLpGe);
  fprintf(dbg," Azimuth       :                    azimSLpGe=%10.5f\n",azimSLpGe);



  /* calculate the coordinates of the location of the greatest eclipse starting from the Sub-Lunar Point            */
  calDestination(latSLp,lonSLp,distSLpGe,azimSLpGe,&latGe,&lonGe);

  if(lonGe> +180.0) lonGe-=360.0;
  if(lonGe< -180.0) lonGe+=360.0;

  EclipseData->lat_Ge=latGe;
  EclipseData->lon_Ge=lonGe;

  /* first set the "MapCenterLon" to the Sub-Solar point Longitude (convert GHA to Longitude)                     */
  MapCenterLon = GHA2Lon(EclipseData->GeSSpGHA);          
  /* if the "lonGe" is close enough to the current "MapCenterLon" use it as the better alternative ...            */
  if(fabs(lonGe - MapCenterLon) < 90.0) MapCenterLon = lonGe; 

    
  /* adjust sun and moon SD to topographical conditions                                                           */
  GetLocalSunMoonParameter(latGe,lonGe,EclipseData->Ge,&aDis,&sRA,&sDec,&sSD,&mRA,&mDec,&mSD);
  EclipseData->mSD_Ge=mSD;
  EclipseData->sSD_Ge=sSD;

  EclipseData->MapCenterLongitude=MapCenterLon;

  fprintf(dbg," Calculated location of the GE:\n");
  fprintf(dbg," GE location   :  Lat=%9.4f           Lon=%9.4f\n",latGe,lonGe);
  fprintf(dbg," Map center Lon:                          Lon=%9.4f\n",MapCenterLon);
  fprintf(dbg," ----------------------------------------------------------------------------\n");

  return MapCenterLon;
} 




/* ---------------------------------------------------------------------------------------------------------------- */
void FindContactLocations(EclipseStruct *EclipseData)

{ 
  double SLpDec,SLpGHA,SSpDec,SSpGHA,MEdist;
  double latSLp,lonSLp,distSLpX,azimSLpX;
  double latX,lonX;

  
  fprintf(dbg," ------------------ FindContactLocations -------------------- \n"); 
  /* get "P1" contact location ...         */
  SLpDec=EclipseData->P1mDec;
  SLpGHA=EclipseData->P1mGHA;
  SSpDec=EclipseData->P1sDec; 
  SSpGHA=EclipseData->P1sGHA;
  MEdist=EclipseData->P1MEdist;

  distSLpX=aSin(sqrt(MEdist*MEdist-REARTH*REARTH)/MEdist);   /* this is the "alpha" for horizontal parallax */
  azimSLpX=180.0+calAzimuth(SLpDec,SLpGHA,SSpDec,SSpGHA);
  
  latSLp=SLpDec;
  lonSLp=GHA2Lon(SLpGHA);
  calDestination(latSLp,lonSLp,distSLpX,azimSLpX,&latX,&lonX);

  if(lonX> +180.0) lonX-=360.0;
  if(lonX< -180.0) lonX+=360.0;
  fprintf(dbg," Contact Location for P1: Lat=%8.3f   Lon=%8.3f\n",latX,lonX);
  EclipseData->lat_P1=latX;
  EclipseData->lon_P1=lonX; 


  /* get "P4" contact location ...         */
  SLpDec=EclipseData->P4mDec;
  SLpGHA=EclipseData->P4mGHA;
  SSpDec=EclipseData->P4sDec;
  SSpGHA=EclipseData->P4sGHA;
  MEdist=EclipseData->P4MEdist;

  distSLpX=aSin(sqrt(MEdist*MEdist-REARTH*REARTH)/MEdist);   /* this is the "alpha" for horizontal parallax */
  azimSLpX=180.0+calAzimuth(SLpDec,SLpGHA,SSpDec,SSpGHA);
  
  latSLp=SLpDec;
  lonSLp=GHA2Lon(SLpGHA);
  calDestination(latSLp,lonSLp,distSLpX,azimSLpX,&latX,&lonX);

  if(lonX> +180.0) lonX-=360.0;
  if(lonX< -180.0) lonX+=360.0;
  fprintf(dbg," Contact Location for P4: Lat=%8.3f   Lon=%8.3f\n",latX,lonX);
  EclipseData->lat_P4=latX;
  EclipseData->lon_P4=lonX; 


  fprintf(dbg,"  lat_P1=%6.1f  lon_P1=%6.1f   lat_P4=%6.1f  lon_P1=%6.1f\n", EclipseData->lat_P1,EclipseData->lon_P1,EclipseData->lat_P4,EclipseData->lon_P4); 
  fprintf(dbg," -------------------------------------------------------------- \n"); 

  return;
}







/* ---------------------------------------------------------------------------------------------------------------- */
void FindDurationAtLocation(EclipseStruct *Eclipses, int n, int type, double *duration_in_minutes)

{ 
  double    lat,lon,JD_ge;
  double    JD,JD_begin,JD_end;
  double    JDstep,JDstep_min;
  double    aDis,sRA,mRA,sDec,mDec,sSD,mSD;
  double    aMin;

  
/* check whether there is an eclipse at this location at JD_ge ... */

  lat=Eclipses[n].lat_Ge;
  lon=Eclipses[n].lon_Ge;
  JD_ge=Eclipses[n].Ge;

  GetLocalSunMoonParameter(lat,lon,JD_ge,&aDis,&sRA,&sDec,&sSD,&mRA,&mDec,&mSD);

  if(aDis > fabs(mSD-sSD))
  { printf(" WARNING: (FindDurationAtLocation) no eclipse at location [lat,lon]=[%9.5f,%10.5f] at time %14.5f\n",lat,lon,JD_ge);
    printf("                                   This may be due to the parallax effect, which affects the value for \"aDis\".\n");
    printf("                                   geocentral parameters: aDis(geo)=%9.6f    sSD=%9.6f    mSD=%9.6f\n",Eclipses[n].aDis_Ge,Eclipses[n].sSD_Ge,Eclipses[n].mSD_Ge);
    printf("                                   local      parameters: aDis(loc)=%9.6f    sSD=%9.6f    mSD=%9.6f\n",aDis,sSD,mSD);

    *duration_in_minutes=0.0;
    return;
  }


/* then find the begining of the total eclipse ... */

  JD        =  JD_ge;
  JDstep_min=  1.0/86400.0;                 /* 1 second = 1/86400     of a day ... */
  JDstep    = -1.0/1440.0;                  /* 1 minute = 1/1440      of a day ... */       
  JD_begin  =  0.0;

  while(JD_begin<120.0)
  { JD_begin+=1.0;
    GetLocalSunMoonParameter(lat,lon,JD,&aDis,&sRA,&sDec,&sSD,&mRA,&mDec,&mSD);

    if(type) aMin=fabs(mSD-sSD);
      else   aMin=fabs(mSD+sSD);

    if(aDis > aMin)
    { JD-=JDstep;
      JDstep/=5.0;
      if(fabs(JDstep)<JDstep_min) JD_begin=JD;
    }

    JD+=JDstep;
  }

  printf(" begin  eclipse in location [lat,lon]=[%9.5f,%10.5f]: %12.5f\n",lat,lon,JD_begin);

  
/* now find the ending of the total eclipse ... */

  JD        =  JD_ge;
  JDstep_min=  1.0/86400.0;                 /* 1 second = 1/86400     of a day ... */
  JDstep    =  1.0/1440.0;                  /* 1 minute = 1/1440      of a day ... */       
  JD_end    =  0.0;

  while(JD_end<120.0)
  { JD_end+=1.0;
    GetLocalSunMoonParameter(lat,lon,JD,&aDis,&sRA,&sDec,&sSD,&mRA,&mDec,&mSD);

    if(type) aMin=fabs(mSD-sSD);
      else   aMin=fabs(mSD+sSD);

    if(aDis > aMin)
    { JD-=JDstep;
      JDstep/=5.0;
      if(fabs(JDstep)<JDstep_min) JD_end=JD;
    }

    JD+=JDstep;
  }

  printf(" end    eclipse in location [lat,lon]=[%9.5f,%10.5f]: %12.5f\n\n",lat,lon,JD_end);
  
  *duration_in_minutes=60.0*24.0*(JD_end-JD_begin);
  return;
}












/* ---------------------------------------------------------------------------------------------------------------- */
void MakeEclipseOverlay(EclipseStruct *EclipseData, double *GEmagnitudes, double *GEtimes)

{
  int       k,l,index,indexGE;
  int       fast_mode;                            /* if in fast mode the longitude scan step is increased ! */
  int       eclipse_in_line;

  double    aDis,mSD,sSD,aDisGE,jdGE;
  double    sRA,sDec,mRA,mDec;
  double    sAZ,sZD,equRA,equDec;
  double    lon_start;
  double    lat,lon;
  double    m,n,dGHA0,dGHA1,dDec0,dDec1,JD0,JD1;
  double    geJD,geGHA,geDec;
  double    a,d,r,R,d2,r2,R2;


  /* Find the starting coordinates in the view of the world map used ... */
  lon_start=EclipseData->MapCenterLongitude - 112.5;
  if(lon_start<-180) lon_start+=360;

  aDis    =0.0;
  aDisGE  =9.9;
  jdGE    =0.0;
  indexGE =0;
  fast_mode=0;                                  /* start scan with "fast_mode" off */

  printf("\nMakeEclipseOverlay()\n");
  printf(" - progress:     ");

  for(k=0; k<470; k++)                            /* scan latitudes ...              */
  { lat      =70.5 - (double)k*0.3;
    eclipse_in_line=0;

    for(l=0; l<750; l++)                          /* scan longitudes ...             */
    { lon=lon_start + (double)l*0.3;
      if(lon>180.0) lon-=360.0;
      index=k*750+l;

      if(GEmagnitudes[index]==0.0)
      {                                           /* do 1st iteration: linear interpolation between P1 and P4 */
        JD0=EclipseData->P1;
        JD1=EclipseData->P4;
          
        GetLocalSunMoonParameter(lat,lon,JD0,&aDis,&sRA,&sDec,&sSD,&mRA,&mDec,&mSD);
        dGHA0=ra2gha(JD0,mRA)-ra2gha(JD0,sRA); if(dGHA0 >  180.0) dGHA0-=360.0; if(dGHA0 < -180.0) dGHA0+=360.0;
        dDec0=mDec-sDec;
        GetLocalSunMoonParameter(lat,lon,JD1,&aDis,&sRA,&sDec,&sSD,&mRA,&mDec,&mSD);
        dGHA1=ra2gha(JD1,mRA)-ra2gha(JD1,sRA); if(dGHA1 >  180.0) dGHA1-=360.0; if(dGHA1 < -180.0) dGHA1+=360.0;
        dDec1=mDec-sDec;

        /* Calculate the "point" of greatest eclipse in this location ...  
         * This is the point on the line connecting both moon positions on JD0 and JD1, which has a orthogonal 
         * connection to the center of the Sun. The position of the Sun is taken as reference and thus is 
         * in the (0,0) position. This point is the point on the line closest to the "origin" (the position   
         * of the Sun)! 
         * With the position of the Sun as reference (0,0) the two positions of the Moon at JD0 and JD1
         * define a line in the cartesian plane that can be described as y = m*x + n.
         * This line intersects with the y-axis (x=0) in the point y=n and with the x-axis (y=0) in the point 
         * x=-n/m. These two points together with the origin form an orthogonal triange: (0,0)-(0,n)-(-n/m,0).
         * The line through the origin and orthogonal to the oblique "Moonline" has a distance h to the 
         * "Moonline", and defines a point on this line with the minimum distance to the origin.
         * Solving the involved triangles: h = n/sqrt(1+m*m)
         * The coordinates of this point are [x=-h*sin(atan(m)) , y=h*cos(atan(m))]
         * Another way to calculate the coordinates of the point on the line y=m*x+n is to minimize
         * the distance function d(x) = sqrt( x^2 + (m*x+n)^2).
         * Differentiating d(x) and setting it to zero gives the following solution for x (minimum d(x)):
         * x = -m*n/(1+m^2) and the correspondig y value on the line is y = m*x+n = n/(1+m^2).
         * The latter solution is implemented here because it requires less computations:
         */ 

        m=(dDec1-dDec0)/(dGHA1-dGHA0);           /* this is the "slope" of the "Moon-line"                   */
        n=dDec0-m*dGHA0;
        geDec= n/(1.0+m*m);
        geGHA=-m*geDec;
        /* geJD can be calculated from either dGHA or dDec. Or we can take the average of both methods ...   */
        geJD=0.5*(JD0+(JD1-JD0)*(geGHA-dGHA0)/(dGHA1-dGHA0)) + 0.5*(JD0+(JD1-JD0)*(geDec-dDec0)/(dDec1-dDec0));

                                                  /* do 2nd iteration 5 Min around geJD ....                 */
        JD0=geJD-0.0035;
        JD1=geJD+0.0035;
       
        GetLocalSunMoonParameter(lat,lon,JD0,&aDis,&sRA,&sDec,&sSD,&mRA,&mDec,&mSD);
        dGHA0=ra2gha(JD0,mRA)-ra2gha(JD0,sRA); if(dGHA0 >  180.0) dGHA0-=360.0; if(dGHA0 < -180.0) dGHA0+=360.0;
        dDec0=mDec-sDec;
        GetLocalSunMoonParameter(lat,lon,JD1,&aDis,&sRA,&sDec,&sSD,&mRA,&mDec,&mSD);
        dGHA1=ra2gha(JD1,mRA)-ra2gha(JD1,sRA); if(dGHA1 >  180.0) dGHA1-=360.0; if(dGHA1 < -180.0) dGHA1+=360.0;
        dDec1=mDec-sDec;
  
                                                  /* calculate point of greatest eclipse in this location ... */
        m=(dDec1-dDec0)/(dGHA1-dGHA0);
        n=dDec0-m*dGHA0;
        geDec= n/(1.0+m*m);
        geGHA=-m*geDec;
        /* geJD can be calculated from either dGHA or dDec. Or we can take the average of both methods ...   */
        geJD=0.5*(JD0+(JD1-JD0)*(geGHA-dGHA0)/(dGHA1-dGHA0)) + 0.5*(JD0+(JD1-JD0)*(geDec-dDec0)/(dDec1-dDec0));
        

        if((geJD<=EclipseData->P4)&&(geJD>=EclipseData->P1))
        { 
          GEtimes[index]=geJD;

          GetLocalSunMoonParameter(lat,lon,geJD,&aDis,&sRA,&sDec,&sSD,&mRA,&mDec,&mSD);
          equ2hor(geJD,0.0,0.0,0.0,&localpoint,sRA,sDec,0,&sZD,&sAZ,&equRA,&equDec);

                                      /* store the JD of the moment of greatest eclipse for local conditions! */
          if(aDis<aDisGE) { aDisGE = aDis;  jdGE=geJD; indexGE=index; }

          if(sZD <90.0)                                /* plot GE_shadow only if sun is above the horizon ... */
          { if(aDis < (mSD+sSD)) 
            { r=sSD;  r2=r*r;
              R=mSD;  R2=R*R;
              d=aDis; d2=d*d;
              /* the following is the area of intersecting circles with radii r and R with their centers d apart
               * and the resulting area normalized to the area of the Sun (PI*SDsun^2)
               */
              if(d>fabs(r-R))
               a=(r2*acos((d2+r2-R2)/(2*d*r)) + R2*acos((d2+R2-r2)/(2*d*R)) - 0.5*sqrt((-d+r+R)*(d+r-R)*(d-r+R)*(d+r+R)))/(r2*3.14159);
               else
                 if(r>=R) a=R2/r2;
                   else   a=1.0;
              GEmagnitudes[index]=a;
            }
            if(aDis < fabs(sSD-mSD)) GEmagnitudes[index]=1.0;
          }
        }
          else 
          { GEmagnitudes[index]=0.0;
/*         fprintf(dbg," Warning: geJD (%12.3f) out of range [%12.3f:%12.3f] !!\n",geJD,EclipseData->P1,EclipseData->P4);
*/        }

        if(GEmagnitudes[index] > 0.0) eclipse_in_line = 1;
      } 
    }

    if(eclipse_in_line == 0) fast_mode++;
      else { if(fast_mode > 0) k-=10; fast_mode = -10; }
    if(fast_mode > 0) k+=9;

    if(k>470) k=470;
    printf("\b\b\b\b%3.0f%%",(double)k/4.70);
    fflush(stdout);
  }

  /* calculate the GE position from the index where the GE occurred in the above overlay scan ... */
  lat=70.5-(indexGE/750)*0.3;
  lon=lon_start + (double)(indexGE%750)*0.3;
  while(lon > 180.0) lon-=360.0;

  fprintf(dbg,"\n------------ GE data from EclipseOverlay() --------------- \n");
  fprintf(dbg," GE: indexGE=%9d\n",indexGE);
  fprintf(dbg,"        Lat =%9.3f   Lon=%11.3f\n",lat,lon);
  fprintf(dbg,"        aDis=%9.7f    JD=%11.5f\n\n",aDisGE,jdGE);

                                                /* store the local GE position over the geocentral position */
/*
  EclipseData->lat_Ge=lat;
  EclipseData->lon_Ge=lon;
*/

  printf(" finished solar eclipse scan !\n\n");

  return;
}




/* ---------------------------------------------------------------------------------------------------------------- */
void AddGEmagnitudesToMap(char *wmap, double *GEmagnitudes)

{ int    index;

  for(index=0; index<470*750; index++)
  { if(GEmagnitudes[index]< 0.0) wmap[index]=wmap[index]-6;            /* this is the twilight region        */
    if(GEmagnitudes[index]> 0.0) wmap[index]=wmap[index]-2;            /* this is the partial eclipse region */
    if(GEmagnitudes[index]> 0.5) wmap[index]=wmap[index]-1;            /* this is the partial eclipse region */
    if(GEmagnitudes[index]>=1.0) wmap[index]=1;                        /* this is the total eclipse region   */
  }

  return;
}





/* ---------------------------------------------------------------------------------------------------------------- */
void AddTimelinesToMap(int pn, double *GEtimes, double *GEmagnitudes, double *timelines, double *timeline_labels)

{ int       index;
  int       t,l,n,sc,rs;
  double    delta,delta_max_r,delta_max_l;
  double    timeline_l[471];      /* scanned timeline for UTC found by left to right scan */
  double    timeline_r[471];      /* scanned timeline for UTC found by right to left scan */

  short int year,m,d;
  char      filename[128];

  double    JDmin,JDmax;
  double    UTC,UTCmin,UTCmax;

  FILE     *fp;

                                  /* scan the GEtimes[] (time of greatest eclipse) for min/max values */
  JDmin=99999999.99;
  JDmax=0.0;
  for(index=0; index<470*750; index++)
  { if(GEtimes[index]>0.0)
    { if(GEtimes[index]<JDmin) JDmin=GEtimes[index];
      if(GEtimes[index]>JDmax) JDmax=GEtimes[index];
    }
  }
                                  /* convert the JDmin/JDmax to the corresponding UTC values          */
  cal_date(JDmin,&year,&m,&d,&UTCmin);
  cal_date(JDmax,&year,&m,&d,&UTCmax);

                                  /* prevent "flipping" by checking that UTCmin < UTCmax              */
  if(UTCmax<UTCmin) UTCmax+=24.0;




  fprintf(dbg,"\n\n---------------- AddTimelinesToMap() ------------------- path_num=%d ----------------------------------- \n",pn);
  fprintf(dbg," JDmin =%15.5f    JDmax =%15.5f\n",JDmin,JDmax);
  fprintf(dbg," UTCmin=%15.5f    UTCmax=%15.5f\n",UTCmin,UTCmax);
  
                                  /* get the full and half hour min/max ...  */
  UTCmin=0.5*ceil(2.0*UTCmin);
  UTCmax=0.5*floor(2.0*UTCmax);

  fprintf(dbg," UTCmin=%15.5f    UTCmax=%15.5f   (for plotting the timelines)\n",UTCmin,UTCmax);




  /* remove the JD day from the GEtimes[] array and convert to UTC hour ...         */
  JDmin=(double)floor(JDmin+0.5);

  for(index=0; index<470*750; index++) GEtimes[index]=12.0 + 24.0*(GEtimes[index] - JDmin);


/* In the following, the GEmagnitudes array of 470x750 points is scanned for "timelines" ...
 * Timelines are identified for full- or half-hour  UTC times in the range UTCmin to UTCmax.
 * Scanning is performed along the lines (l) and columns (n).
 * First scan is from line 0 to line 469 (top to bottom) and from column sc to 749 (left to right).
 * Then a scan is performed from line 469 to line 0 (bottom to top) and from column sc downto 0 (right to left)
 * "sc" is the start column from which the next scan is started and depends on the current scan result!
 */

/* Scanning the "GEmagnitudes array" : ...
 *                 0                   "n"             749
 *                |||||||||||||||||||| ... ||||||||||||
 *             0 -++++++++++++++*+++++ ... ++++++++++++       * = interpolated position of UTC-timeline 
 *             1 -++++++++++++++*+++++ ... ++++++++++++           in the corresponding line!
 *             2 -+++++++++++++*++++++ ... ++++++++++++
 *             3 -+++++++++++++*++++++ ... ++++++++++++
 *             4 -++++++++++++*+++++++ ... ++++++++++++       l,n = the variables used to scan the array
 *                ....................................
 *           "l"  ....................................
 *                ....................................
 *           469 -++++*+++++++++++++++ ... ++++++++++++
 *
 * timeline[][] is an array of max 12 "timelines" in which a pair of coordinates are stored (one obtained 
 * by "rightscan" and one obtained by "leftscan") corresponding to a specific UTC time (half- or full-hour).
 */ 



  t=0;        /* t is the index to the current "timeline"-vector in the timeline array */

  for(UTC=UTCmin; UTC<=UTCmax; UTC+=0.5)
  { sc=0;                     
    for(l=0; l<470; l++)              /* "right_scan" for the begining of the timeline for UTC ... */
    { timeline_l[l]=-1;               /* initial value indicating no timepoint found at line l !   */
      for(n=sc; n<749; n++)           /* limit n from [0:748] to prevent flipping into the next line !! */
      { index = l*750 + n;
        if((GEmagnitudes[index] > 0.0) && (GEmagnitudes[index+1] > 0.0))
        {                  /* time can increases OR decrease from left to right with increasing index    */
          if(((GEtimes[index]<=UTC)&&(GEtimes[index+1]>UTC))||((GEtimes[index]>=UTC)&&(GEtimes[index+1]<UTC)))
          {                /* store the (interpolated) index of the GEmagnitudes array at which the UTC time is found  */
            timeline_l[l]=(double)index + (UTC-GEtimes[index])/(GEtimes[index+1]-GEtimes[index]);  
                           /* start scan in the next line in a column not too far away from the one just found ...  */
            if((sc=n-100) < 0) sc=0; 
            n=750;
          }
        }
      }
    }

    sc=749;  
    for(l=469; l>=0; l--)             /* "left_scan"  for the begining of the timeline for UTC ...*/
    { timeline_r[l]=-1;
      for(n=sc; n>0; n--)             /* limit n to [1:749] to prevent flipping into the previous line !!! */
      { index=l*750+n;
        if((GEmagnitudes[index-1] > 0.0) && (GEmagnitudes[index] > 0.0))
        {               /* time can increases OR decrease from left to right with increasing index              */
          if(((GEtimes[index-1]<=UTC)&&(GEtimes[index]>UTC))||((GEtimes[index-1]>=UTC)&&(GEtimes[index]<UTC)))
          {             /* store the (interpolated) index of the GEmagnitudes array at which the UTC time is found */
            timeline_r[l]=(double)(index-1) + (UTC-GEtimes[index-1])/(GEtimes[index]-GEtimes[index-1]);
                        /* start scan in the next line not too far away from the just found one  */
            if((sc=n+100) > 749) sc=749;
            n=-1;
          }
        }
      }
    }

                                      /* copy scanned lines into timelines[] array                  */
    for(l=0; l<470; l++)
    { timelines[ t   *470+l]=timeline_l[l];
      timelines[(t+1)*470+l]=timeline_r[l];
    }
                                      /* store UTC time label  ...   */
    timeline_labels[t  ] = UTC;
    timeline_labels[t+1] = UTC;
                                      /* process next timeline ... */
    if((t=t+2) > 22) 
    { printf(" Error (AddTimelinesToMap) timeline array overflow !!\n");
      exit(-1);
    }
  }

  /* remove the "false" paths from the timelines, which occur if the timeline is strongly curved and
   * has two segments generated by left- and right-scan, but which may "merge" as soon as one
   * segment ends. 
   *
   *                            rl                           r = point found by right-scan
   *                           r  l                          l = point found by left-scan
   *                          r    l
   *                          r     l
   *                                rl
   *                                rl
   */

  for(n=0; n<t; n+=2) 
  { sc=0; 
                         /* check whether l- and r-paths are identical */
    for(l=0; l<470; l++) if(fabs(timelines[n*470+l] - timelines[(n+1)*470+l]) > 2.0)  sc=1;
    if(sc == 1)          /* then the l- and r-paths are NOT identical and there are two different segments */
    {                    /* search for the "short" path, which will contain a part of the "long" path      */
      delta_max_r=0.0; 
      for(l=0; l<470; l++)
       if((timelines[n*470+l] > 0)&&(timelines[n*470+l+1] > 0))          /* ignore the inactive lines marked with '-1' */
       { delta=fabs(timelines[n*470+l] - timelines[n*470+l+1] + 750.0);
         if(delta > delta_max_r) delta_max_r = delta;
       }
      delta_max_l=0.0;
      for(l=0; l<470; l++)
       if((timelines[(n+1)*470+l] > 0)&&(timelines[(n+1)*470+l+1]>0))    /* ignore the inactive lines marked with '-1' */
       { delta=fabs(timelines[(n+1)*470+l] - timelines[(n+1)*470+l+1] + 750.0);
         if(delta > delta_max_l) delta_max_l = delta;
       }
       
       rs=0;                         /* this will shorten the right-scan path */
       if(delta_max_l>delta_max_r)   /* then shorten the left-scan path ...   */
         rs=1;

                                     /* now remove the "false" segment of the selected path (left: rs=1 / or right: rs=0) */
                                     /* the "false" segment is the part that is identical to the other scan path ...      */
       for(l=0; l<470; l++)
         if((fabs(timelines[n*470+l] - timelines[(n+1)*470+l]) < 2.0) && (timelines[(n+rs)*470+l] > 0))
           timelines[(n+rs)*470+l] = -3;     /* use the value -3 to mark the removed part of the path ! */

      
    }
      else               /* then the l- and r-paths are identical and the l-path is cleared  (set to "-2") */  
        for(l=0; l<470; l++) if(timelines[n*470+l] > 0.0) timelines[n*470+l] = -2;
  } 

  
  /* ================================================================================== */
  /* the following is for debugging: it will write the detected timelines to a file ... */
  sprintf(filename,"./Data/Timelines_%02d.dat",pn);
  if((fp=fopen(filename,"w"))==NULL)
  { printf(" ERROR (AddTimelinesToMap): could not open \"./Data/Timelines.dat\" for writing!\n\n");
    exit(-1);
  }
                                          /* print the labels ... */
  fprintf(fp,"#   ");
  for(n=0; n<t; n++) fprintf(fp," %6.1f",timeline_labels[n]);
  fprintf(fp,"\n");
                                          /* print the timelines   */
  for(l=0; l<470; l++)
  { fprintf(fp,"%03d ",l);
    for(n=0; n<t; n++)
    { if(timelines[n*470+l] > 0.0) fprintf(fp," %6.1f",timelines[n*470+l]-750.0*l); 
        else                       fprintf(fp," %6.1f",timelines[n*470+l]);
    }
    fprintf(fp,"\n");
  }
  fclose(fp);
  /* ================================================================================== */
  

  fprintf(dbg,"---------------- leaving AddTimelinesToMap() ----------------------------------------- \n");

  return;
}









/* ---------------------------------------------------------------------------------------------------------------- */
void RecordEclipse(EclipseStruct *Eclipses, int n, FILE *nalm_fp, double *yPos)

{ int       index;
  int       path_width;
 
  short int m0,m1,d0,d1;
  short int year;
  short int error;

  char      tmpstring[32];
  char     *months[12] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
  char     *months_short[12] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
  char      s0[8],s1[8];
  char      NS,EW;

  char      wmap[750*470];     /* wmap has a Longitude range of 225 degrees (750 pix) and Latitude range of 141 degrees (470 pix) */

  double    h0,h1;
  double    y,y0;
  double    Dist_ObsM;
  double    aDis,dDis,pw0,pw1,dSD;
  double    MapCenterLongitude=0.0;

  double   *GEmagnitudes;         /* eclipse magitude map overlay for plotting the eclipse region */
  double   *GEtimes;              /* eclipse times map overlay for generating timelines           */
  double    timelines[24*470];    /* eclipse timearray for plotting on map grid                   */
  double    timeline_labels[24];  /* they hold the "header" info for the 24 possible timelines    */

  y = *yPos;
                                                                    /* allocate the memory for the arrays ... */
  if((GEmagnitudes=(double *)malloc(750*470*sizeof(double))) == NULL) 
  { printf(" ERROR (RecordEclipse) could not allocate memory for \"GEmagnitudes\" (%d Bytes)\n",750*470);
    exit(-1);
  }

  if((GEtimes=(double *)malloc(750*470*sizeof(double))) == NULL) 
  { printf(" ERROR (RecordEclipse) could not allocate memory for \"GEtimes\" (%d Bytes)\n",750*470);
    exit(-1);
  }

  fprintf(dbg,"\n\n---------------- RecordEclipse() ------------------- path_num=%d ----------------------------------- \n",n);

  y0=13.3;

  localpoint.latitude=0.0;
  localpoint.longitude=0.0;
  localpoint.height=0.0;
  localpoint.temperature=20.0;
  localpoint.pressure=1014.0;

                                  /* initialize overlays ... */
  for(index=0; index<750*470; index++)
  { GEmagnitudes[index]= 0.0;
    GEtimes[index]  = 0.0;
  }

  for(index=0; index<24; index++) timeline_labels[index]=-1.0;

  error=0;

  error+=set_body(0, 3,"Earth",&Earth);
  error+=set_body(0,10,"Sun",  &Sun  );
  error+=set_body(0,11,"Moon", &Moon );
  if(error)
  { printf("\n ERROR (RecordEclipse): error from set_body() \n");
    exit(-1);
  }

  if((n>=MAXPATHS)||(Eclipses[n].eclipse_type == 0)||(Eclipses[n].Ge < 1.0))
  { printf(" ERROR (RecordEclipse): no Eclipse path available for this index (n=%d)\n",n);
    return;
  }

  /* find the center of the map: the longitude at the moment of greatest eclipse ... */
  MapCenterLongitude = FindMapCenter(&Eclipses[n]);

  fprintf(dbg,"------------------- back in RecordEclipse() ------------------------------- \n");
  fprintf(dbg," Conditions at Greatest Eclipse: Ge_JD = %f\n",Eclipses[n].Ge);
  fprintf(dbg," Sub-Solar Point (SSp) GeSSpDec=%10.5f   GeSSpGHA=%10.5f\n", Eclipses[n].GeSSpDec,Eclipses[n].GeSSpGHA);
  fprintf(dbg," Sub-Lunar Point (SLp) GeSLpDec=%10.5f   GeSLpGHA=%10.5f\n", Eclipses[n].GeSLpDec,Eclipses[n].GeSLpGHA);
  fprintf(dbg," distance between SSp and SLp (@ GE)            aDis=%9.7f\n",calDistance(Eclipses[n].GeSSpDec,Eclipses[n].GeSSpGHA,Eclipses[n].GeSLpDec,Eclipses[n].GeSLpGHA));
  fprintf(dbg,"                                             Ge_aDis=%9.7f\n",Eclipses[n].aDis_Ge);
  fprintf(dbg," GeMEdist=%f\n",Eclipses[n].GeMEdist);
  fprintf(dbg," mSD_Ge=%9.7f              sSD_Ge=%9.7f \n",Eclipses[n].mSD_Ge,Eclipses[n].sSD_Ge);
  fprintf(dbg," k=%9.7f\n",RMOON/REARTH);
  fprintf(dbg," Location of GE: lat_Ge=%10.5f    lon_Ge=%10.5f\n",Eclipses[n].lat_Ge,Eclipses[n].lon_Ge);
  fprintf(dbg," Map Center    :                      lonMap=%10.5f\n",MapCenterLongitude);


  /* print HEADER for next eclipse data (type, start/end time) ...                                                */
  y-=y0;
  cal_date(Eclipses[n].Ge,&year,&m0,&d0,&h0);
  fprintf(nalm_fp,"0.0 %.1f moveto 10 f1 (%s %d :) show\n",y,months[m0-1],d0);
  cal_date(Eclipses[n].P1,&year,&m0,&d0,&h0);
  cal_date(Eclipses[n].P4,&year,&m1,&d1,&h1);
  if(Eclipses[n].eclipse_type==1)  fprintf(nalm_fp,"74.0 %.1f moveto 10 f1 (  partial solar eclipse) show\n",y);
  if(Eclipses[n].eclipse_type==2)  fprintf(nalm_fp,"74.0 %.1f moveto 10 f1 (  annular solar eclipse) show\n",y);
  if(Eclipses[n].eclipse_type==3)  fprintf(nalm_fp,"74.0 %.1f moveto 10 f1 (  total solar eclipse) show\n",y);
  fprintf(nalm_fp,"475.0 %.1f moveto 10 f0 (begin [ %s %d,  %s UTC ] /  end [ %s %d,  %s UTC ]) Rshow\n",y,months_short[m0-1],d0,time2s(h0,s0),months_short[m1-1],d1,time2s(h1,s1));

  y-=2.0*y0;


/* then read the world map centered around the location (longitude) with the greatest eclipse ... */
  ReadWorldMap(wmap, MapCenterLongitude);

  MakeEclipseOverlay(&Eclipses[n],GEmagnitudes,GEtimes);
  AddGEmagnitudesToMap(wmap,GEmagnitudes);
  AddTimelinesToMap(n,GEtimes,GEmagnitudes,timelines,timeline_labels);    

  FindContactLocations(&Eclipses[n]);
  WriteWorldMap(nalm_fp,wmap,y-220.0,timelines,timeline_labels,&Eclipses[n]);
/*
 */

/* print the summary information lines ...                                                      */

  y-=246;
  fprintf(nalm_fp,"0.1 setlinewidth\n 0.0 setgray\n");
  fprintf(nalm_fp,"  0.0 %.1f moveto 10 f0 (Circumstances at Moment of Greatest Eclipse) show\n",y);
  fprintf(nalm_fp,"240.0 %.1f moveto 10 f0 (Fist Contacts) show\n",y);
  fprintf(nalm_fp,"340.0 %.1f moveto 10 f0 (\\(P1/U1\\)) Rshow\n",y);
  fprintf(nalm_fp,"365.0 %.1f moveto 10 f0 (Last Contacts) show\n",y);
  fprintf(nalm_fp,"465.0 %.1f moveto 10 f0 (\\(U4/P4\\)) Rshow\n",y);

  y-=y0;
  cal_date(Eclipses[n].Ge,&year,&m0,&d0,&h0);
  fprintf(nalm_fp,"  0.0 %.1f moveto 8 f0 (Time:) show\n",y);
  fprintf(nalm_fp," 95.0 %.1f moveto 8 f0 (%10s UTC) Rshow\n",y,time2s(h0,tmpstring));

  if(Eclipses[n].eclipse_type==3)        /* total eclipse */
  { fprintf(nalm_fp,"110.0 %.1f moveto 8 f0 (Duration \\(full\\):) show\n",y);
    FindDurationAtLocation(Eclipses,n,1,&h0);
    fprintf(nalm_fp,"200.0 %.1f moveto 8 f0 (%4.1f min) Rshow\n",y,h0);
  }

  fprintf(nalm_fp,"240.0 %.1f moveto 8 f0 (Penumbra)  show\n",y);

  if(Eclipses[n].eclipse_type==3)       /* total eclipse */
  { fprintf(nalm_fp,"340.0 %.1f moveto 8 f0 (Umbra) Rshow\n",y);
    fprintf(nalm_fp,"365.0 %.1f moveto 8 f0 (Umbra)  show\n",y);
  }

  fprintf(nalm_fp,"465.0 %.1f moveto 8 f0 (Penumbra) Rshow\n",y);


  y-=y0;
  fprintf(nalm_fp,"  0.0 %.1f moveto 8 f0 (Location:) show\n",y);
  NS='N'; if(Eclipses[n].lat_Ge<0) NS='S';
  EW='E'; if(Eclipses[n].lon_Ge<0) EW='W';
  sprintf(tmpstring,"%c %4.1f  %c %5.1f",NS,fabs(Eclipses[n].lat_Ge),EW,fabs(Eclipses[n].lon_Ge));
  if(tmpstring[ 2]==' ') tmpstring[ 2]='0';
  if(tmpstring[10]==' ') tmpstring[10]='0';
  if(tmpstring[11]==' ') tmpstring[11]='0';
  fprintf(nalm_fp," 95.0 %.1f moveto 8 f0 (%s) Rshow\n",y,tmpstring);

  /* ---------------------------------------------------------------------------------------------------------------------------- */
  /* the following procedure to evaluate the path width for total eclipses has been checked for the following eclipses:
   * 2010, 2012, ...
   */
  if(Eclipses[n].eclipse_type==3)    /* total eclipse */
  { 
    fprintf(nalm_fp,"110.0 %.1f moveto 8 f0 (Path Width:) show\n",y);

    /* dSD  is the difference in SD for the Sun and the Moon at the moment of GE 
     * aDis is the angular difference between the sub-solar and sub-lunar point 
     *      this is equal to the parallax angle required to make the Moon and Sun 
     *      to coincide at the location of GE
     */
    dSD =fabs(Eclipses[n].mSD_Ge-Eclipses[n].sSD_Ge);      
    aDis=calDistance(Eclipses[n].GeSSpDec,Eclipses[n].GeSSpGHA,Eclipses[n].GeSLpDec,Eclipses[n].GeSLpGHA);

    dDis=aDis+dSD;                                     /* width left  of path */
    pw0 =ParallaxToDistance(Eclipses[n].GeMEdist,dDis,&Dist_ObsM);

    dDis=aDis-dSD;                                     /* width right of path */
    pw1 =ParallaxToDistance(Eclipses[n].GeMEdist,dDis,&Dist_ObsM);

    path_width=(int)(111.11*fabs(pw0-pw1));
    fprintf(nalm_fp,"200.0 %.1f moveto 8 f0 (%3d km) Rshow\n",y,path_width);

    fprintf(dbg,"\n -- PATH WIDTH (for eclipse_type==3) ----- \n");
    fprintf(dbg,"  dDis0=%12.9f     pw0=%12.9f    dDis1=%12.9f     pw1=%12.9f      path_width=%6.1f Km\n",aDis+dSD,pw0,aDis-dSD,pw1,111.11*(pw0+pw1));
  }
  /* ---------------------------------------------------------------------------------------------------------------------------- */

  cal_date(Eclipses[n].P1,&year,&m0,&d0,&h0);
  fprintf(nalm_fp,"240.0 %.1f moveto 8 f0 (%5s UTC) show\n",y,time2s(h0,tmpstring));
  if(Eclipses[n].eclipse_type==3)       /* total eclipse */
  { cal_date(Eclipses[n].U1,&year,&m0,&d0,&h0);
    fprintf(nalm_fp,"340.0 %.1f moveto 8 f0 (%5s UTC) Rshow\n",y,time2s(h0,tmpstring));
    cal_date(Eclipses[n].U4,&year,&m0,&d0,&h0);
    fprintf(nalm_fp,"365.0 %.1f moveto 8 f0 (%5s UTC) show\n",y,time2s(h0,tmpstring));
  }
  cal_date(Eclipses[n].P4,&year,&m0,&d0,&h0);
  fprintf(nalm_fp,"465.0 %.1f moveto 8 f0 (%5s UTC) Rshow\n",y,time2s(h0,tmpstring));

  y-=y0;

  fprintf(nalm_fp,"%%%% ----------- here ends the eclipse record number %d\n",n);
  fprintf(dbg,"--------------------------------------------------------------------------------------------------- \n");

  *yPos = y;
  return;
}





/* ---------------------------------------------------------------------------------------------------------------- */
/* ---------------------------------------------------------------------------------------------------------------- */
void FormatSunEclipse(double *oJD, double oGHA[][6], double oDec[][6], double oDist[][6], int *page, FILE *fp)

{ int       i,k,nhp;
  int       UT,ydays,path_num;
 
  short int eclipse_state;
  short int year,month,day;
  short int year_ge,month_ge,day_ge;

  char      tmpstring[32];
  char     *months[12] = {"January","February","March","April","May","June","July","August","September","October","November","December"};

  double    y,y0;
  double    JD,now,hour,fH,step,hour_ge;
  double    MoonCoverageAngle,aDis;
  double    minDis,minJD;
  double    mGHA,mDec,sGHA,sDec,dGHA;
  double    GHAcorr;
  double    SDsun,SDmoon;
  double    DTsun,DTmoon;
  double    gha2ra();

  EclipseStruct Eclipses[MAXPATHS];


  if((dbg=fopen("Data/formatSunEclipse_debug.log","w"))==NULL)
  { printf(" Error: (FormatSunEclipse) could not open \"Data/FormatSunEclipse_debug.log\" for writing!\n");
    exit(-1);
  }

  now=oJD[0];
  cal_date(now,&year,&month,&day,&hour);

  if(year%4) ydays=365;
    else     ydays=366;

  for(i=0; i<MAXPATHS; i++)
  { Eclipses[i].eclipse_type=0;
    Eclipses[i].path_number=i;
    Eclipses[i].P1=0.0;
    Eclipses[i].U1=0.0;
    Eclipses[i].Ge=0.0;
    Eclipses[i].U4=0.0;
    Eclipses[i].P4=0.0;
    Eclipses[i].GeSSpDec=0.0;
    Eclipses[i].GeSSpGHA=0.0;
    Eclipses[i].GeSLpDec=0.0;
    Eclipses[i].GeSLpGHA=0.0;

    Eclipses[i].lon_P1=0.0; Eclipses[i].lat_P1=0.0;
    Eclipses[i].lat_Ge=0.0; Eclipses[i].lon_Ge=0.0;
    Eclipses[i].lat_P4=0.0; Eclipses[i].lon_P4=0.0;
  }

  path_num=0;
  minDis=99.9;
  minJD=0.0;
  eclipse_state=0;
  step=1.0/PPH;

  for(i=0; i<ydays; i++)
  { now=oJD[i];
    cal_date(now,&year,&month,&day,&hour);

                                      /* calculate the GHA-difference between Sun and Moon at 00 UTC of each day ...      */
    dGHA=fabs(oGHA[i*24][0]-oGHA[i*24][2]);
    if(dGHA>180.0) dGHA=360.0-dGHA;

    if(dGHA<20.0)                     /* this is approximately new moon condition ... */
    {
      for(UT=0; UT<24; UT++)
      { k=i*24+UT;
                                      /* calculate the GHA-difference between Sun and Moon for each full hour ... */
        dGHA=fabs(oGHA[k][0]-oGHA[k][2]);
        if(dGHA>180.0) dGHA=360.0-dGHA;

        if(dGHA<3.0)                  /* this is close to new moon condition, so start fine scan in fraction of hours ... */
        {
          for(nhp=0; nhp<PPH; nhp++)                
          { fH=(double)nhp/(double)PPH;       /* this is fraction of one hour (0.000 ... 0.999) */
            hour=(double)UT+fH;
            JD=julian_date(year,month,day,hour);
  
            /* The "MoonCoverageAngle" is the area around the GP of the Moon, which the Moon can cover by it's size (SDmoon)
             * and also by the parallax effect, which results in the Moon moving against the Sun and the stars background
             * if an observer moves away from the GP of the Moon.
             */ 
                                                                     /* get GHA, Dec and SD for Moon ...                  */
            if(oGHA[k+1][2]<oGHA[k][2]) GHAcorr=360.0; else GHAcorr=0.0;
            mGHA= (oGHA[k][2]*(1.0-fH)+(oGHA[k+1][2]+GHAcorr)*fH);                  /* in degrees !! */
            mDec= (oDec[k][2]*(1.0-fH)+oDec[k+1][2]*fH);                            /* in degrees !! */

            DTmoon=AU*(oDist[k][2]*(1.0-fH)+oDist[k+1][2]*fH);       /* the interpolated value for the Distance Earth-Moon*/
            SDmoon=aSin(RMOON/DTmoon);                                              /* in degrees !! */
    
                                                                 /* get GHA, Dec and SD for Sun  ...     */
            if(oGHA[k+1][0]<oGHA[k][0]) GHAcorr=360.0; else GHAcorr=0.0;
            sGHA= (oGHA[k][0]*(1.0-fH)+(oGHA[k+1][0]+GHAcorr)*fH);                  /* in degrees !! */
            sDec= (oDec[k][0]*(1.0-fH)+oDec[k+1][0]*fH);                            /* in degrees !! */

            DTsun =AU*(oDist[k][0]*(1.0-fH)+oDist[k+1][0]*fH);       /* the interpolated value for the Distance Earth-Sun */
            SDsun=aSin(RSUN/DTsun);                                                 /* in degrees !! */

                                                                 /*  MoonCoverageAngle = SDmoon + HPmoon  */
            MoonCoverageAngle=SDmoon + aSin(REARTH/DTmoon);                         /* in degrees !! */   
    
                                                                 /* calculate distance between GPs ...  */
            aDis=calDistance(sDec,sGHA,mDec,mGHA);                                    /* in degrees !! */

            /* "aDis" is the angular distance between the center of the moon and the center of the sun;
             * comparing this distance with the SD of Sun and the coverage angle of the moon will give an
             * indication on the expected state of the eclipse. 
             * Notice, that the time is still approximate. This is because the parallax effect of the Sun 
             * is not yet taken into account!
             */
  
            if((aDis < (MoonCoverageAngle+SDsun))&&(eclipse_state==0))     /* Sun will now enter the zone of the MoonCoverageAngle */
            { fprintf(dbg,"\n ----- path_num=%d ------ \n",path_num);
              fprintf(dbg," ECLIPSE contact start   time (P1): %10s\n",time2s(hour,tmpstring));
              fprintf(dbg," DTmoon=%9.1f km\n",DTmoon);
              fprintf(dbg," Date=%9s %2d %5s UTC  esclipse_state=%d | MoonCoverageAngle=%9.6f SDsun=%9.6f SDmoon=%9.6f dGHA=%9.6f dDec=%9.6f SDratio=%9.6f\n",months[month-1],day,time2s(hour,tmpstring),eclipse_state,MoonCoverageAngle,SDsun,SDmoon,(sGHA-mGHA),(sDec-mDec),SDmoon/SDsun);
              fprintf(dbg," HPmoon = %11.7f\n",MoonCoverageAngle - SDmoon);

              Eclipses[path_num].P1=JD;
              Eclipses[path_num].P1sDec=sDec;
              Eclipses[path_num].P1sGHA=sGHA;
              Eclipses[path_num].P1mDec=mDec;
              Eclipses[path_num].P1mGHA=mGHA;
              Eclipses[path_num].P1MEdist=DTmoon;
              Eclipses[path_num].eclipse_type=1;            /* we have at least a partial eclipse now!  */
              eclipse_state=1;
            }
  
            if((aDis >= (MoonCoverageAngle+SDsun))&&(eclipse_state!=0))    /* Sun will now leave the zone of the MoonCoverageAngle */
            { fprintf(dbg," ECLIPSE contact end     time (P4): %10s\n",time2s(hour,tmpstring));
              fprintf(dbg," DTmoon=%9.1f km\n",DTmoon);
              fprintf(dbg," Date=%9s %2d %5s UTC  esclipse_state=%d | MoonCoverageAngle=%9.6f SDsun=%9.6f SDmoon=%9.6f dGHA=%9.6f dDec=%9.6f SDratio=%9.6f\n",months[month-1],day,time2s(hour,tmpstring),eclipse_state,MoonCoverageAngle,SDsun,SDmoon,(sGHA-mGHA),(sDec-mDec),SDmoon/SDsun);
              fprintf(dbg," HPmoon = %11.7f\n",MoonCoverageAngle - SDmoon);
              
              Eclipses[path_num].P4=JD;
              Eclipses[path_num].P4sDec=sDec;
              Eclipses[path_num].P4sGHA=sGHA;
              Eclipses[path_num].P4mDec=mDec;
              Eclipses[path_num].P4mGHA=mGHA;
              Eclipses[path_num].P4MEdist=DTmoon;

              fprintf(dbg," ----------------------------------- \n");
              fprintf(dbg," Conditions at greatest eclipse (geocentrical parameters):\n");
              cal_date(Eclipses[path_num].Ge,&year_ge,&month_ge,&day_ge,&hour_ge);
              fprintf(dbg," Date=%9s %2d %5s UTC",months[month_ge-1],day_ge,time2s(hour_ge,tmpstring));
              if(Eclipses[path_num].eclipse_type == 1) fprintf(dbg," PARTIAL ECLIPSE\n");
              if(Eclipses[path_num].eclipse_type == 2) fprintf(dbg," ANNULAR ECLIPSE\n");
              if(Eclipses[path_num].eclipse_type == 3) fprintf(dbg," TOTAL   ECLIPSE\n");
              fprintf(dbg," aDis(geo)=%9.6f    SDsun=%9.6f    SDmoon=%9.6f\n",Eclipses[path_num].aDis_Ge,Eclipses[path_num].sSD_Ge,Eclipses[path_num].mSD_Ge);

              minDis=99.9;
              eclipse_state=0;
              if(++path_num>=MAXPATHS)
              { printf(" Error:(formatSunPages) found more than %d Solar Eclipses (array overflow) [path_num=%d]!\n\n",MAXPATHS,path_num);
                exit(-1);
              }
            }
    
    
            if((aDis <= (MoonCoverageAngle-SDsun))&&(eclipse_state==1))    /* Sun will now completely enter the zone of the MoonCoverageAngle */
            { fprintf(dbg," ECLIPSE totality start  time (U1): %10s\n",time2s(hour,tmpstring));
              fprintf(dbg," Date=%9s %2d %5s UTC  esclipse_state=%d | MoonCoverageAngle=%9.6f SDsun=%9.6f SDmoon=%9.6f dGHA=%9.6f dDec=%9.6f SDratio=%9.6f\n",months[month-1],day,time2s(hour,tmpstring),eclipse_state,MoonCoverageAngle,SDsun,SDmoon,(sGHA-mGHA),(sDec-mDec),SDmoon/SDsun);

              Eclipses[path_num].U1=JD;
              Eclipses[path_num].eclipse_type=2;                                                              /* we have at least an annular eclipse */
              if(Eclipses[path_num].mSD_Ge > Eclipses[path_num].sSD_Ge) Eclipses[path_num].eclipse_type=3;    /* and maybe a         total   eclipse */

              eclipse_state=2;
            }
  

            if((aDis >= (MoonCoverageAngle-SDsun))&&(eclipse_state==2))    /* Sun will now not be completely in the zone of the MoonCoverageAngle */
            { fprintf(dbg," ECLIPSE totality end    time (U4): %10s\n",time2s(hour,tmpstring));
              fprintf(dbg," Date=%9s %2d %5s UTC  esclipse_state=%d | MoonCoverageAngle=%9.6f SDsun=%9.6f SDmoon=%9.6f dGHA=%9.6f dDec=%9.6f SDratio=%9.6f\n",months[month-1],day,time2s(hour,tmpstring),eclipse_state,MoonCoverageAngle,SDsun,SDmoon,(sGHA-mGHA),(sDec-mDec),SDmoon/SDsun);

              Eclipses[path_num].U4=JD;

              eclipse_state=3;
            }
    
            if(eclipse_state)
            { 
              if(fabs(aDis) < minDis)                   /* store the conditions on greatest eclpise */
              { minJD = JD;
                minDis= fabs(aDis);
                Eclipses[path_num].GeSLpGHA=mGHA;
                Eclipses[path_num].GeSLpDec=mDec;
                Eclipses[path_num].GeSSpGHA=sGHA;
                Eclipses[path_num].GeSSpDec=sDec;
                Eclipses[path_num].Ge=JD;
                Eclipses[path_num].GeMEdist=DTmoon;
                Eclipses[path_num].mSD_Ge=SDmoon;
                Eclipses[path_num].sSD_Ge=SDsun;
                Eclipses[path_num].aDis_Ge=aDis;
              }
            }
          }
        }
      }
    }
  }

  /* -------------------------------------------------------------------------------------------------------------------- */
  /* Now the basic eclipse information for the current year has been collected.
   * NOTICE that all this collected data is for a GEOCENTRICAL observer !!
   * Next the data has to be analyzed for an Earth-bound observer and then 
   * the different paths can be plotted into the Almanac pages.
   */


  y0=13.3;            /* this is the line spacing ! */

  /* print the intro page for solar eclipses ... */
  PrintSunIntro(page,fp);

  /* print the page(s) with the eclipse maps ... */
  fprintf(dbg,"\n\n\n ===================================== RecordEclipse() =========================================== \n");
  for(i=0; i<path_num; i++)
  {
    printf("\n Making trajectory map for path_num=%2d now ... \n\n",i);
  
    if((i%2)==0)     /* start a new page for each 2nd path ... */
    { if(i!=0) 
      { fprintf(fp,"showpage\n");
        *page = (*page)+1;
      }
    
      y=715.2;
      fprintf(fp,"%%%%Page: %d %d\n",*page,*page);
      fprintf(fp,"54 0 translate\n");
      if(i==0) fprintf(fp,"  0.0 %.1f  moveto 10 f0 (The following solar eclipses may be observed during the year %d:) show\n",y,year);
      y-=y0;
    }
    RecordEclipse(Eclipses,i,fp,&y);
  }
  fprintf(fp,"showpage\n");
  *page = (*page)+1;

  fclose(dbg);

  return;
}

