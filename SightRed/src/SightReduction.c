
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PI      3.14159265358979323846




void PrintFrame(FILE *fp, double LHA, int c)

{ int    i,j,d,lha;
  double y;

  lha=(int)LHA;

  fprintf(fp,"gsave 0.7 setlinewidth\n");

  for(j=0; j<2; j++)
  { fprintf(fp," 0 %.1f  moveto 486.0 0 rlineto 0 -340.0 rlineto -486.0 0 rlineto closepath stroke\n",732.0-356.0*j);
  
    for(i=0; i<5; i++)
    { fprintf(fp,"%.1f %.1f moveto 92.0 0 rlineto 0 -18.0 rlineto -92.0 0 rlineto closepath  stroke\n",26.0+i*92.0,732.0-356.0*j);
      fprintf(fp,"%.1f %.1f moveto 92.0 0 rlineto 0 -322.0 rlineto -92.0 0 rlineto closepath  stroke\n",26.0+i*92.0,714.0-356.0*j);
      fprintf(fp,"%.1f %.1f moveto 10 f1 (LHA  %d\\260, %d\\260) show\n",32.0+i*92.0,718.0-356.0*j,lha+i+j*5,360-lha-(i+j*5));
      fprintf(fp,"8 f4\n");
      fprintf(fp,"%.1f %.1f moveto ( H ) show\n",26.0+i*92.0,700.0-356.0*j);
      fprintf(fp,"%.1f %.1f moveto (\\260  ') show\n",38.0+i*92.0,700.0-356.0*j);
      fprintf(fp,"%.1f %.1f moveto (dH ') show\n",67.0+i*92.0,700.0-356.0*j);
      fprintf(fp,"%.1f %.1f moveto ( Z  \\260) show\n",84.0+i*92.0,700.0-356.0*j);
    }

    fprintf(fp,"2.0 %.1f moveto 10 f1 (Dec) show\n",718.0-356.0*j);

    y=690.0-j*356.0;
    fprintf(fp,"8 f1\n");
    for(d=0; d<30; d++)
    { fprintf(fp,"20.0 %.1f moveto ( %d\\260) Rshow\n",y,d);
      if((d%5)==4) y-=16.8; else y-=8.4;
    }
  }

  fprintf(fp,"6 f0\n");
  fprintf(fp,"0 17.6 moveto (Warning:) show\n");
  fprintf(fp,"30 17.6 moveto (This page has been generated by a computer program. Complex computer programs usually have bugs and may produce wrong data.) show\n");
  fprintf(fp,"30 8.8 moveto (The data on this page is believed to be accurate but no warranty is given for it's correctness. Use it only for training and exercising! ) show\n");
  fprintf(fp,"grestore\n");

  return;
} 






void PrintHeader(FILE *fp, int lat, char *Titl)

{
  fprintf(fp,"%%!PS-Adobe-3.0\n");
  fprintf(fp,"%%%%BeginProlog\n");
  fprintf(fp,"%%%%DocumentData: Clean7Bit\n");
  fprintf(fp,"%%%%Orientation: Portrait\n");
  fprintf(fp,"[ /.notdef /.notdef /.notdef /.notdef /.notdef /.notdef /.notdef /.notdef /.notdef /.notdef\n");
  fprintf(fp," /.notdef /.notdef /.notdef /.notdef /.notdef /.notdef /.notdef /.notdef /.notdef /.notdef\n");
  fprintf(fp," /.notdef /.notdef /.notdef /.notdef /.notdef /.notdef /.notdef /.notdef /.notdef /.notdef\n");
  fprintf(fp," /.notdef /.notdef /space /exclam /quotedbl /numbersign /dollar /percent /ampersand /quoteright\n");
  fprintf(fp," /parenleft /parenright /asterisk /plus /comma /hyphen /period /slash /zero /one\n");
  fprintf(fp," /two /three /four /five /six /seven /eight /nine /colon /semicolon\n");
  fprintf(fp," /less /equal /greater /question /at\n");
  fprintf(fp," /A /B /C /D /E /F /G /H /I /J /K /L /M /N /O /P /Q /R /S /T /U /V /W /X /Y /Z\n");
  fprintf(fp," /bracketleft /backslash /bracketright /asciicircum /underscore /quoteleft\n");
  fprintf(fp," /a /b /c /d /e /f /g /h /i /j /k /l /m /n /o /p /q /r /s /t /u /v /w /x /y /z\n");
  fprintf(fp," /braceleft /bar /braceright /asciitilde /.notdef /.notdef /.notdef\n");
  fprintf(fp," /.notdef /.notdef /.notdef /.notdef /.notdef /.notdef /.notdef /.notdef /.notdef /.notdef\n");
  fprintf(fp," /.notdef /.notdef /.notdef /.notdef /.notdef /.notdef /.notdef /.notdef /.notdef /.notdef\n");
  fprintf(fp," /.notdef /.notdef /.notdef /.notdef /.notdef /.notdef /.notdef /.notdef /.notdef /.notdef\n");
  fprintf(fp," /space /exclamdown /cent /sterling /currency /yen /brokenbar /section /dieresis /copyright\n");
  fprintf(fp," /ordfeminine /guillemotleft /logicalnot /hyphen /registered /macron /degree /plusminus\n");
  fprintf(fp," /twosuperior /threesuperior /acute /mu /paragraph /periodcentered /cedilla /onesuperior\n");
  fprintf(fp," /ordmasculine /guillemotright /onequarter /onehalf\n");
  fprintf(fp," /threequarters /questiondown /Agrave /Aacute /Acircumflex /Atilde /Adieresis /Aring /AE /Ccedilla\n");
  fprintf(fp," /Egrave /Eacute /Ecircumflex /Edieresis /Igrave /Iacute /Icircumflex /Idieresis /Eth /Ntilde\n");
  fprintf(fp," /Ograve /Oacute /Ocircumflex /Otilde /Odieresis /multiply /Oslash /Ugrave /Uacute /Ucircumflex\n");
  fprintf(fp," /Udieresis /Yacute /Thorn /germandbls /agrave /aacute /acircumflex /atilde /adieresis /aring\n");
  fprintf(fp," /ae /ccedilla /egrave /eacute /ecircumflex /edieresis /igrave /iacute /icircumflex /idieresis\n");
  fprintf(fp," /eth /ntilde /ograve /oacute /ocircumflex /otilde /odieresis /divide /oslash /ugrave\n");
  fprintf(fp," /uacute /ucircumflex /udieresis /yacute /thorn /ydieresis] /isolatin1encoding exch def\n");
  fprintf(fp,"/F0\n");
  fprintf(fp,"    /Helvetica findfont\n");
  fprintf(fp,"    dup length dict begin\n");
  fprintf(fp,"	{1 index /FID ne {def} {pop pop} ifelse} forall\n");
  fprintf(fp,"	/Encoding isolatin1encoding def\n");
  fprintf(fp,"    currentdict end\n");
  fprintf(fp,"definefont pop\n");
  fprintf(fp,"/f0 { /F0 findfont exch scalefont setfont } bind def\n");
  fprintf(fp,"/F1\n");
  fprintf(fp,"    /Helvetica-Bold findfont\n");
  fprintf(fp,"    dup length dict begin\n");
  fprintf(fp,"	{1 index /FID ne {def} {pop pop} ifelse} forall\n");
  fprintf(fp,"	/Encoding isolatin1encoding def\n");
  fprintf(fp,"    currentdict end\n");
  fprintf(fp,"definefont pop\n");
  fprintf(fp,"/f1 { /F1 findfont exch scalefont setfont } bind def\n");
  fprintf(fp,"/F2\n");
  fprintf(fp,"    /Helvetica-Italic findfont\n");
  fprintf(fp,"    dup length dict begin\n");
  fprintf(fp,"	{1 index /FID ne {def} {pop pop} ifelse} forall\n");
  fprintf(fp,"	/Encoding isolatin1encoding def\n");
  fprintf(fp,"    currentdict end\n");
  fprintf(fp,"definefont pop\n");
  fprintf(fp,"/f2 { /F2 findfont exch scalefont setfont } bind def\n");
  fprintf(fp,"/F3\n");
  fprintf(fp,"    /Helvetica-BoldItalic findfont\n");
  fprintf(fp,"    dup length dict begin\n");
  fprintf(fp,"	{1 index /FID ne {def} {pop pop} ifelse} forall\n");
  fprintf(fp,"	/Encoding isolatin1encoding def\n");
  fprintf(fp,"    currentdict end\n");
  fprintf(fp,"definefont pop\n");
  fprintf(fp,"/f3 { /F3 findfont exch scalefont setfont } bind def\n");
  fprintf(fp,"/F4\n");
  fprintf(fp,"    /Courier findfont\n");
  fprintf(fp,"    dup length dict begin\n");
  fprintf(fp,"	{1 index /FID ne {def} {pop pop} ifelse} forall\n");
  fprintf(fp,"	/Encoding isolatin1encoding def\n");
  fprintf(fp,"    currentdict end\n");
  fprintf(fp,"definefont pop\n");
  fprintf(fp,"/f4 { /F4 findfont exch scalefont setfont } bind def\n");
  fprintf(fp,"/F5\n");
  fprintf(fp,"    /Courier-Bold findfont\n");
  fprintf(fp,"    dup length dict begin\n");
  fprintf(fp,"	{1 index /FID ne {def} {pop pop} ifelse} forall\n");
  fprintf(fp,"	/Encoding isolatin1encoding def\n");
  fprintf(fp,"    currentdict end\n");
  fprintf(fp,"definefont pop\n");
  fprintf(fp,"/f5 { /F5 findfont exch scalefont setfont } bind def\n");
  fprintf(fp,"/F6\n");
  fprintf(fp,"    /Courier-Oblique findfont\n");
  fprintf(fp,"    dup length dict begin\n");
  fprintf(fp,"	{1 index /FID ne {def} {pop pop} ifelse} forall\n");
  fprintf(fp,"	/Encoding isolatin1encoding def\n");
  fprintf(fp,"    currentdict end\n");
  fprintf(fp,"definefont pop\n");
  fprintf(fp,"/f6 { /F6 findfont exch scalefont setfont } bind def\n");
  fprintf(fp,"/F7\n");
  fprintf(fp,"    /Courier-BoldOblique findfont\n");
  fprintf(fp,"    dup length dict begin\n");
  fprintf(fp,"	{1 index /FID ne {def} {pop pop} ifelse} forall\n");
  fprintf(fp,"	/Encoding isolatin1encoding def\n");
  fprintf(fp,"    currentdict end\n");
  fprintf(fp,"definefont pop\n");
  fprintf(fp,"/f7 { /F7 findfont exch scalefont setfont } bind def\n");
  fprintf(fp,"/Cshow { dup stringwidth pop -2 div 0 rmoveto show } def\n");
  fprintf(fp,"/Rshow { dup stringwidth pop neg 0 rmoveto show } def\n");
  fprintf(fp,"%%%%EndProlog\n");
  fprintf(fp,"%%%%Page: 1 1\n");
  fprintf(fp,"%%%%BeginPageSetup\n");
  fprintf(fp,"54 72 translate\n");
  fprintf(fp,"%%%%EndPageSetup\n");
  fprintf(fp,"newpath 0 0 moveto 500 0 rlineto 0 700 rlineto -500 0 rlineto  closepath clip newpath\n");
  fprintf(fp,"0.5 setgray\n1.0 setlinewidth\n");
  fprintf(fp,"-40 685 moveto 24 f0 ( Sight Reduction  Sight Reduction  Sight Reduction  Sight Reduction) show\n");
  fprintf(fp,"-40 655 moveto 36 f3 ( Sight Reduction  Sight Reduction  Sight Reduction  Sight Reduction) show\n");
  fprintf(fp,"-100 630 moveto 24 f7 ( Sight Reduction  Sight Reduction  Sight Reduction  Sight Reduction) show\n");
  fprintf(fp,"-40 590 moveto 48 f2 ( Sight Reduction  Sight Reduction  Sight Reduction  Sight Reduction) show\n");
  fprintf(fp,"-200 555 moveto 36 f6 ( Sight Reduction  Sight Reduction  Sight Reduction  Sight Reduction) show\n");
  fprintf(fp,"-40 530 moveto 24 f0 ( Sight Reduction  Sight Reduction  Sight Reduction  Sight Reduction) show\n");
  fprintf(fp,"-10 490 moveto 48 f4 ( Sight Reduction  Sight Reduction  Sight Reduction  Sight Reduction) show\n");
  fprintf(fp,"-40 465 moveto 24 f3 ( Sight Reduction  Sight Reduction  Sight Reduction  Sight Reduction) show\n");
  fprintf(fp,"-40 435 moveto 36 f5 ( Sight Reduction  Sight Reduction  Sight Reduction  Sight Reduction) show\n");
  fprintf(fp,"-80 410 moveto 24 f0 ( Sight Reduction  Sight Reduction  Sight Reduction  Sight Reduction) show\n");
  fprintf(fp,"-40 370 moveto 48 f0 ( Sight Reduction  Sight Reduction  Sight Reduction  Sight Reduction) show\n");
  fprintf(fp,"-40 335 moveto 36 f4 ( Sight Reduction  Sight Reduction  Sight Reduction  Sight Reduction) show\n");
  fprintf(fp,"-40 310 moveto 24 f3 ( Sight Reduction  Sight Reduction  Sight Reduction  Sight Reduction) show\n");
  fprintf(fp,"-10 285 moveto 24 f7 ( Sight Reduction  Sight Reduction  Sight Reduction  Sight Reduction) show\n");
  fprintf(fp,"-40 255 moveto 36 f0 ( Sight Reduction  Sight Reduction  Sight Reduction  Sight Reduction) show\n");
  fprintf(fp,"-90 230 moveto 24 f5 ( Sight Reduction  Sight Reduction  Sight Reduction  Sight Reduction) show\n");
  fprintf(fp,"-40 210 moveto 24 f4 ( Sight Reduction  Sight Reduction  Sight Reduction  Sight Reduction) show\n");
  fprintf(fp,"-40 170 moveto 48 f1 ( Sight Reduction  Sight Reduction  Sight Reduction  Sight Reduction) show\n");
  fprintf(fp,"-40 140 moveto 24 f0 ( Sight Reduction  Sight Reduction  Sight Reduction  Sight Reduction) show\n");
  fprintf(fp,"-40 110 moveto 36 f6 ( Sight Reduction  Sight Reduction  Sight Reduction  Sight Reduction) show\n");
  fprintf(fp,"-40  85 moveto 24 f2 ( Sight Reduction  Sight Reduction  Sight Reduction  Sight Reduction) show\n");
  fprintf(fp,"-80  45 moveto 48 f3 ( Sight Reduction  Sight Reduction  Sight Reduction  Sight Reduction) show\n");
  fprintf(fp,"-10  25 moveto 24 f4 ( Sight Reduction  Sight Reduction  Sight Reduction  Sight Reduction) show\n");
  fprintf(fp,"-40   0 moveto 36 f5 ( Sight Reduction  Sight Reduction  Sight Reduction  Sight Reduction) show\n");
  fprintf(fp,"gsave\n");
  fprintf(fp,"1.0 setgray\n");
  fprintf(fp,"1.0 0.3 scale\n");
  fprintf(fp,"newpath 250 690 228 0 360 arc fill\n");
  fprintf(fp,"0.0 setgray\n2.0 setlinewidth\n");
  fprintf(fp,"newpath 250 690 220 0 360 arc stroke\n");
  fprintf(fp,"grestore\n");
  fprintf(fp,"0.0 setgray\n");
  fprintf(fp,"250 214 moveto 32 f0 (Latitude  %2d\\260 - %2d\\260 ) Cshow\n",lat,lat+9);
  fprintf(fp,"250 184 moveto 16 f0 (%s) Cshow\n",Titl);
  fprintf(fp,"showpage\n");

  return;
}



void InsertBlankPage(FILE *fp, int *page)

{
  fprintf(fp,"%%%%Page: %d %d\n",*page,*page);
  fprintf(fp,"gsave 0.98 setgray\n");
  fprintf(fp,"36 f0\n");
  fprintf(fp,"300 400 moveto (Blank Page) Cshow\n");
  fprintf(fp,"grestore\n");
  fprintf(fp,"showpage\n");

  *page = (*page)+1;

  return;
}





#include <time.h>

void PrintIntro0Page(FILE *fp, int *page)

{ int        i,j;
  char       timestring[64];
  struct tm *timeptr;
  time_t     now;

  now=time(NULL);
  timeptr=localtime(&now);
  strcpy(timestring,asctime(timeptr));
  for(i=0; i<64; i++) if(timestring[i]=='\n') timestring[i]='\0';

  fprintf(fp,"%%%%Page: %d %d\n",*page,*page);
  fprintf(fp,"gsave\n");
  fprintf(fp,"54 0 translate\n");
  fprintf(fp,"  0.0  90.1 moveto 10 f0 (Compiled by Erik De Man  \\(erik.de.man@freenet.de\\)  on %s) show\n",timestring);
  fprintf(fp,"grestore\n");
  fprintf(fp,"showpage\n");

  *page = (*page)+1;

  return;
}



void PrintIntro1Page(FILE *fp, int *page)

{ double y,dy;

  dy=13.3;

  fprintf(fp,"%%%%Page: %d %d\n",*page,*page);
  fprintf(fp,"gsave 0.2 setlinewidth\n");
  fprintf(fp,"54 0 translate\n");
  fprintf(fp,"  0.0 744.1 moveto 18 f1 (Purpose and Scope) show\n");
  fprintf(fp,"  0.0 715.2 moveto 10 f0 (The following tables are designed to determine) show\n");
  fprintf(fp,"475.0 715.2 moveto 10 f0 (Altitude and Azimuth of a celestial object, given the position) Rshow\n");
  fprintf(fp,"  0.0 701.9 moveto 10 f0 (of the observer \\(Latitude - Longitude\\) and the coordinates of the celestial object \\(Declination - GHA\\).) show\n");
  fprintf(fp,"  0.0 688.6 moveto 10 f0 (Using the Altitude-Intercept Method,  the calculated Altitude  Hc  and Azimuth  Zc) show\n");
  fprintf(fp,"475.0 688.6 moveto 10 f0 (may be used to refine the) Rshow\n");
  fprintf(fp,"  0.0 675.3 moveto 10 f0 (observer's  position  by comparing  the calculated  Altitude Hc  with) show\n");
  fprintf(fp,"475.0 675.6 moveto 10 f0 (the observed Altitude Ho.  The observed) Rshow\n");
  fprintf(fp,"  0.0 662.0 moveto 10 f0 (Altitude is obtained by sextant measurements.) show\n");
  fprintf(fp,"  0.0 635.4 moveto 10 f0 (The tables on the following pages were calculated according to:) show\n");
  fprintf(fp,"  8.0 608.8 moveto 10 f2 (Hc = asin \\( sin\\(Latitude\\)*sin\\(Declination\\) + cos\\(Latitude\\)*cos\\(Declinaton\\)*cos\\(LHA\\) \\)) show\n");
  fprintf(fp," 88.0 595.5 moveto 10 f2 (cos\\(Declinaton\\)*sin\\(LHA\\)) show\n");
  fprintf(fp,"  8.0 588.5 moveto 10 f2 (Z   = atan \\() show\n");
  fprintf(fp,"366.0 588.5 moveto 10 f2 (\\)) show\n");
  fprintf(fp,"newpath 57.0 592.7 moveto 308 0 rlineto stroke\n");
  fprintf(fp," 60.0 582.2 moveto 10 f2 (cos\\(Latitude\\)*sin\\(Declinaton\\)-sin\\(Latitude\\)*cos\\(Declinaton\\)*cos\\(LHA\\)) show\n");

  y=582.2-2*dy;
  fprintf(fp,"  0.0 %.1f moveto 10 f0 (The Local Hour Angle \\(LHA\\) is the angular difference between the) show\n",y);
  fprintf(fp,"475.0 %.1f moveto 10 f0 (Longitude of the observer's position and) Rshow\n",y);
  y-=dy;
  fprintf(fp,"  0.0 %.1f moveto 10 f0 (the GHA of the observed celestial object: LHA = GHA + Longitude.) show\n",y);
  
  y-=2.0*dy;
  fprintf(fp,"  0.0 %.1f moveto 10 f0 (The tables are organized with the Latitude value as primary parameter.) show\n",y);
  fprintf(fp,"475.0 %.1f moveto 10 f0 (The Latitude value is printed on the) Rshow\n",y);
  y-=dy;
  fprintf(fp,"  0.0 %.1f moveto 10 f0 (fist line of each page.  The particular values for  Declination \\(Dec\\)) show\n",y);
  fprintf(fp,"475.0 %.1f moveto 10 f0 (and  LHA  are read from the vertical and) Rshow\n",y);
  y-=dy;
  fprintf(fp,"  0.0 %.1f moveto 10 f0 (horizontal labels  of the tables  respectively.) show\n",y);
  fprintf(fp,"475.0 %.1f moveto 10 f0 (Notice  that each table entry  is valid for  two different values of) Rshow\n",y);
  y-=dy;
  fprintf(fp,"  0.0 %.1f moveto 10 f0 (LHA related by LHA   = 360\\260 - LHA   .) show\n",y);
  fprintf(fp," 89.0 %.1f moveto  8 f0 (1) show\n",y-2.0);
  fprintf(fp,"157.0 %.1f moveto  8 f0 (2) show\n",y-2.0);
  y-=dy;
  fprintf(fp,"  0.0 %.1f moveto 10 f0 (The covered range  of the Declination values  is limited from 0\\260 to 29\\260,) show\n",y);
  fprintf(fp,"475.0 %.1f moveto 10 f0 (which applies  to the Declination of) Rshow\n",y);
  y-=dy;
  fprintf(fp,"  0.0 %.1f moveto 10 f0 (the Sun, the Moon  and the planets  used for celestial navigation.) show\n",y);
  fprintf(fp,"475.0 %.1f moveto 10 f0 (The LHA range  is such that  the resulting) Rshow\n",y);
  y-=dy;
  fprintf(fp,"  0.0 %.1f moveto 10 f0 (Altitude is positive \\(object above the local horizon\\).) show\n",y);
  y-=2.0*dy;
  fprintf(fp,"  0.0 %.1f moveto 10 f0 (For practical Sight Reduction this manual is used as follows:) show\n",y);
  y-=dy;
  fprintf(fp,"  4.0 %.1f moveto 10 f0 (1. select the correct part of the manual \\(Declination \"SAME as\" / \"CONTRARY to\" Latitude\\),) show\n",y);
  y-=dy;
  fprintf(fp,"  4.0 %.1f moveto 10 f0 (2. select the correct Latitude page,) show\n",y);
  y-=dy;
  fprintf(fp,"  4.0 %.1f moveto 10 f0 (3. select the correct LHA column from one of the sub-tables,) show\n",y);
  y-=dy;
  fprintf(fp,"  4.0 %.1f moveto 10 f0 (4. read the H, dH and Z values from the correct Declination \\(integral value\\) line.) show\n",y);
  y-=2.0*dy;
  fprintf(fp,"  0.0 %.1f moveto 10 f0 (Further steps include  interpolation for the specific  \\(fractional\\)) show\n",y);
  fprintf(fp,"475.0 %.1f moveto 10 f0 (value of Declination and determination of the) Rshow\n",y); 
  y-=dy;
  fprintf(fp,"  0.0 %.1f moveto 10 f0 (true Azimuth value Zc according to the following rules:) show\n",y);
  y-=dy;
  fprintf(fp," 16.0 %.1f moveto  8 f4 (Latitude > 0  LHA>180\\260: Zc=Z) show\n",y);
  y-=dy*0.80;
  fprintf(fp," 16.0 %.1f moveto  8 f4 (              LHA<180\\260: Zc=360\\260-Z) show\n",y);
  y-=dy*0.80;
  fprintf(fp," 16.0 %.1f moveto  8 f4 (Latitude < 0  LHA>180\\260: Zc=180\\260-Z) show\n",y);
  y-=dy*0.80;
  fprintf(fp," 16.0 %.1f moveto  8 f4 (              LHA<180\\260: Zc=180\\260+Z) show\n",y);
  fprintf(fp,"grestore\n");
  fprintf(fp,"showpage\n");

  *page = (*page)+1;

  return;
}





int main(int argc, char **argv)

{ int    i,j,k,h,n,cont;
  int    lat,dec,inc;
  int    font,page;
  char   nam,sgn,Titl[64];

  double r,s,y,m;
  double Dec,Lat,LHA,Zc[31],Hc[31],dH;

  double sinDec,cosDec;
  double sinLHA,cosLHA;
  double sinLat,cosLat;

  char   filename[32];
  FILE  *fp;

  r=PI/180.0;
  s=180.0/PI;


  if(argc!=2) 
  { printf("\n\n Usage: %s <Latitude>\n\n",argv[0]);
    exit(0);
  }

  lat=atoi(argv[1]);
  if((lat<0)||(lat>90))
  { printf(" Error (%s) Latitude out of range [0:90]: %d\n\n",argv[0],lat);
    exit(-1);
  }

  inc=10;
  lat=inc*(int)(lat/inc);

  printf("\n Generating Sight Reduction Tables for : Latitude  %2d\260 - %2d\260\n\n",lat,lat+inc-1);
  

  for(n=0; n<2; n++)                                               /* n=0: SAME;    n=1: CONTRARY                        */
  {
    if(n==0) { strcpy(Titl,"Declination SAME name as Latitude"); nam='s'; } 
      else   { strcpy(Titl,"Declination CONTRARY name to Latitude"); nam='c'; }

    if(lat<10) sprintf(filename,"Data/SiRed0%d%c.ps",lat,nam);
      else     sprintf(filename,"Data/SiRed%d%c.ps",lat,nam);
  
    if((fp=fopen(filename,"w"))==NULL)
    { printf(" Error (%s) could not open file \"%s\" for reading!\n",argv[0],filename);
      exit(-1);
    }
  
    printf("                     writing data file : \"%s\"\n",filename);

    PrintHeader(fp,lat,Titl);
    page=2;
    InsertBlankPage(fp,&page);
    PrintIntro0Page(fp,&page);
    InsertBlankPage(fp,&page);
    PrintIntro1Page(fp,&page);
    InsertBlankPage(fp,&page);

    for(Lat=(double)lat; Lat< (double)(lat+inc); Lat=Lat+1.00)
    {
      sinLat=sin(r*Lat);
      cosLat=cos(r*Lat);

      if(!(page%2)) InsertBlankPage(fp,&page);
      
      for(LHA=0.0; LHA<180.0; LHA+=10.0)
      { fprintf(fp,"%%%%Page: %d %d\n",page,page);
        fprintf(fp,"58 30 translate\n");
 
        if(page%2)
        { fprintf(fp,"485 748.0 moveto 14 f1 (Latitude %2d\\260) Rshow\n",(int)Lat);
          fprintf(fp,"0 748.0 moveto 12 f1 (%s) show\n",Titl);
        }
          else
          { fprintf(fp,"0 748.0 moveto 14 f1 (Latitude %2d\\260) show\n",(int)Lat);
            fprintf(fp,"485 748.0 moveto 12 f1 (%s) Rshow\n",Titl);
          }
              
        PrintFrame(fp,LHA,n);
  
        cont=1;

        for(j=0; j<2; j++)
          for(k=0; k<5; k++)
          { sinLHA=sin(r*(LHA+k+j*5.0));     
            cosLHA=cos(r*(LHA+k+j*5.0));     
          
            for(dec=0; dec<31; dec++)
            { if(n==0) Dec=(double)dec; else Dec=(double)-dec;

              sinDec=sin(r*Dec);
              cosDec=cos(r*Dec);
              Hc[dec]=s*asin(sinLat*sinDec + cosLat*cosDec*cosLHA);
              Hc[dec]=floor(Hc[dec]*600+0.5);
              Zc[dec]=s*atan2(cosDec*sinLHA,cosLat*sinDec - sinLat*cosDec*cosLHA);
            }     
          
            y=690.0-j*356.0;
            for(dec=0; dec<30; dec++)
            { dH=(Hc[dec+1]-Hc[dec])/10.0;
              if(dH<0.0) { sgn='-'; dH=fabs(dH); }
                else     { sgn='+';              }

              if(Hc[dec]>=0.0) font=4; else font=6;

              if((Hc[dec]>=0.0)&&(cont==1))
              { h=floor(Hc[dec]/600.0);
                m=(Hc[dec]-h*600.0)/10.0;
                if(m<0.0) m*=-1.0;

                fprintf(fp,"8 f%d\n",font);
                fprintf(fp,"%.1f %.1f moveto ( %2d) show\n",26.0+92.0*k,y,h); 
                fprintf(fp,"%.1f %.1f moveto ( %5.1f) show\n",84.0+92.0*k,y,Zc[dec]);

                if(m<10.0) fprintf(fp,"%.1f %.1f moveto ( 0%3.1f) show\n",38.0+92.0*k,y,m);
                  else     fprintf(fp,"%.1f %.1f moveto ( %4.1f) show\n",38.0+92.0*k,y,m);

                fprintf(fp,"6 f%d\n",font);
                if(dH<10.0) fprintf(fp,"%.1f %.1f moveto (%c0%3.1f) show\n",66.0+92.0*k,y,sgn,dH);
                  else      fprintf(fp,"%.1f %.1f moveto (%c%4.1f) show\n",66.0+92.0*k,y,sgn,dH);
              }

              if((Hc[dec]< 0.0)&&(cont==1))
              { h=floor(-Hc[dec]/600.0);
                m=(-Hc[dec]-h*600.0)/10.0;
                if(m<0.0) m*=-1.0;

                if(h<10)
                { fprintf(fp,"8 f%d\n",font);
                  fprintf(fp,"%.1f %.1f moveto ( -%1d) show\n",26.0+92.0*k,y,h);
                  if(m<10.0) fprintf(fp,"%.1f %.1f moveto ( 0%3.1f) show\n",38.0+92.0*k,y,m);
                    else     fprintf(fp,"%.1f %.1f moveto ( %4.1f) show\n",38.0+92.0*k,y,m);
 
                  fprintf(fp,"6 f%d\n",font);
                  if(dH<10.0) fprintf(fp,"%.1f %.1f moveto (%c0%3.1f) show\n",66.0+92.0*k,y,sgn,dH);
                    else      fprintf(fp,"%.1f %.1f moveto (%c%4.1f) show\n",66.0+92.0*k,y,sgn,dH);
                }
              }
              
              if((dec%5)==4) y-=16.8; else y-=8.4;
            }    
            if((Hc[0]<0.0)&&(Hc[29]<0.0)) cont=0;
          }

        fprintf(fp,"showpage\n");
        page++;

        if(cont==0) LHA=181.0;
      }
    }

    fprintf(fp,"%%%%EOF\n");
    fclose(fp);
  }
  
  printf("\n");
  return 0;
}
