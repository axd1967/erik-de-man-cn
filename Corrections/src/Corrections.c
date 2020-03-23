
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>



#define PI       3.141592654


/* -------------------------------------------------------------------------------------------------------------------------- */
double Cos(double alpha)

{
  return cos(alpha*0.017453292);
}

/* -------------------------------------------------------------------------------------------------------------------------- */
double Sin(double alpha)

{
  return sin(alpha*0.017453292);
}

/* -------------------------------------------------------------------------------------------------------------------------- */
double aSin(double s)

{
  return asin(s)/0.017453292;
}

/* -------------------------------------------------------------------------------------------------------------------------- */
char *FormatDegMin(double Angle, char *string)

{ int    deg,min;

  deg=floor(Angle);
  min=(int)(60.0*(Angle-deg));

  if(min<9) sprintf(string,"%2d\260 0%d'",deg,min);
    else    sprintf(string,"%2d\260 %2d'",deg,min);

  return string;
}

/* -------------------------------------------------------------------------------------------------------------------------- */
char *FormatMin(double min, char *string)

{
  if(min<9.95) sprintf(string,"0%3.1f",min);
    else sprintf(string,"%4.1f",min);
  
  string[2]='\'';

  return string;
}








/* -------------------------------------------------------------------------------------------------------------------------- */
void PrintHeader(FILE *fp)

{
  fprintf(fp,"%%!PS-Adobe-3.0\n");
  fprintf(fp,"%%%%BeginProlog\n");
  fprintf(fp,"%%%%DocumentData: Clean7Bit\n");
  fprintf(fp,"%%%%Orientation: Portrait\n");
  fprintf(fp,"%%%%DocumentMedia: A4 595 842 0 () ()\n");
  fprintf(fp,"%%%%BeginDefaults\n");
  fprintf(fp,"%%%%PageMedia: A4\n");
  fprintf(fp,"%%%%EndDefaults\n");
  fprintf(fp,"%%%%BeginSetup\n");
  fprintf(fp,"%%%%PaperSize: A4\n");
  fprintf(fp,"%%%%EndSetup\n");
  fprintf(fp,"%%%%EndComments\n");
  fprintf(fp,"%%%%BeginProlog\n");
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
  fprintf(fp,"54 72 translate\n");
  fprintf(fp,"newpath 0 0 moveto 500 0 rlineto 0 700 rlineto -500 0 rlineto  closepath clip newpath\n");
  fprintf(fp,"0.5 setgray\n1.0 setlinewidth\n");
  fprintf(fp,"-40 685 moveto 24 f0 ( he Horizon  Dip of the Horizon  Dip of the Horizon  Dip of the Horizon) show\n");
  fprintf(fp,"-40 655 moveto 36 f3 ( Refraction  Refraction  Refraction  Refraction) show\n");
  fprintf(fp,"-100 630 moveto 24 f7 ( Corrections  Corrections  Corrections  Corrections) show\n");
  fprintf(fp,"-40 590 moveto 48 f2 ( Corrections  Corrections  Corrections  Corrections) show\n");
  fprintf(fp,"-200 555 moveto 36 f6 ( rallax Parallax Parallax Parallax) show\n");
  fprintf(fp,"-40 530 moveto 24 f0 ( Corrections  Corrections  Corrections  Corrections) show\n");
  fprintf(fp,"-30 490 moveto 48 f4 ( tion Refraction Refraction Refraction) show\n");
  fprintf(fp,"-40 465 moveto 24 f3 ( Interpolation  Interpolation  Interpolation  Interpolation) show\n");
  fprintf(fp,"-48 435 moveto 36 f5 ( on  Dip of the Horizon  Dip of the Horizon  Dip of the Horizon) show\n");
  fprintf(fp,"-80 410 moveto 24 f0 ( Corrections  Corrections  Corrections  Corrections  Corrections) show\n");
  fprintf(fp,"-40 370 moveto 48 f0 ( polation  Interpolation  Interpolation  Interpolation) show\n");
  fprintf(fp,"-40 335 moveto 36 f4 ( lax  Parallax  Parallax  Parallax) show\n");
  fprintf(fp,"-40 310 moveto 24 f3 ( Corrections  Corrections  Corrections  Corrections) show\n");
  fprintf(fp,"-20 285 moveto 24 f7 ( orizon  Dip of the Horizon  Dip of the Horizon  Dip of the Horizon) show\n");
  fprintf(fp,"-40 255 moveto 36 f0 ( Corrections  Corrections  Corrections  Corrections) show\n");
  fprintf(fp,"-90 230 moveto 24 f5 ( Interpolation  Interpolation  Interpolation  Interpolation) show\n");
  fprintf(fp,"-40 210 moveto 24 f4 ( Corrections  Corrections  Corrections  Corrections) show\n");
  fprintf(fp,"-40 170 moveto 48 f1 ( f the Horizon  Dip of the Horizon  Dip of the Horizon  Dip of the Horizon) show\n");
  fprintf(fp,"-40 140 moveto 24 f0 ( Corrections  Corrections  Corrections  Corrections) show\n");
  fprintf(fp,"-40 110 moveto 36 f6 ( Interpolation  Interpolation  Interpolation  Interpolation) show\n");
  fprintf(fp,"-40  85 moveto 24 f2 ( Refraction  Refraction  Refraction  Refraction  Refraction) show\n");
  fprintf(fp,"-80  45 moveto 48 f3 ( Corrections  Corrections  Corrections  Corrections) show\n");
  fprintf(fp,"-10  25 moveto 24 f4 ( Parallax  Parallax  Parallax  Parallax) show\n");
  fprintf(fp,"-40   0 moveto 36 f5 ( Corrections  Corrections  Corrections  Corrections) show\n");
  fprintf(fp,"showpage\n");


  return;
}


/* -------------------------------------------------------------------------------------------------------------------------- */
void InsertBlankPage(FILE *fp, int *page)

{
  fprintf(fp,"%%%%Page: %d %d\n",*page,*page);
  fprintf(fp,"0.95 setgray\n");
  fprintf(fp,"36 f0\n");
  fprintf(fp,"300 400 moveto (Blank Page) Cshow\n");
  fprintf(fp,"showpage\n");

  *page = (*page)+1;

  return;
}




/* -------------------------------------------------------------------------------------------------------------------------- */
void PrintWarning(FILE *fp, int *page)
{
  int        i,j;
  char       timestring[64];
  struct tm *timeptr;
  time_t     now;

  now=time(NULL);
  timeptr=localtime(&now);
  strcpy(timestring,asctime(timeptr));
  for(i=0; i<64; i++) if(timestring[i]=='\n') timestring[i]='\0';

  fprintf(fp,"%%%%Page: %d %d\n",*page,*page);
  fprintf(fp,"54 0 translate\n");
  fprintf(fp,"  0.0 422.5 moveto 18 f1 (Sextant Correction Tables) show\n");
  fprintf(fp,"  0.0 398.5 moveto 18 f1 (Parallax Correction Tables) show\n");
  fprintf(fp,"  0.0 374.5 moveto 18 f1 (Interpolation Tables) show\n");
  fprintf(fp,"  0.0 350.5 moveto 18 f1 (Offset Correction Table) show\n");
  fprintf(fp,"  0.0 196.5 moveto 10 f0 (Warning and Terms of Usage:) show\n");
  fprintf(fp,"  0.0 169.9 moveto 10 f0 (The  following pages  have been generated  by a computer program.) show\n");
  fprintf(fp,"475.0 169.9 moveto 10 f0 (Complex computer programs usually) Rshow\n");
  fprintf(fp,"  0.0 156.6 moveto 10 f0 (have bugs and may produce wrong data.) show\n");
  fprintf(fp,"475.0 156.6 moveto 10 f0 (The data in this  Nautical Almanac  is believed to be accurate but) Rshow\n");
  fprintf(fp,"  0.0 143.3 moveto 10 f0 (no warranty is given for its correctness.) show\n");
  fprintf(fp,"  0.0 130.0 moveto 10 f0 (Use this Nautical Almanac only for training and exercising!) show\n");
  fprintf(fp,"  0.0  90.1 moveto 10 f0 (Compiled by Erik De Man  \\(erik.de.man@freenet.de\\)  on %s) show\n",timestring);
  fprintf(fp,"showpage\n");

  *page = (*page)+1;
  return;
}





/* -------------------------------------------------------------------------------------------------------------------------- */
void PrintIntro(FILE *fp, int *page)

{ double x,y,yincr;

  y=714.0;
  yincr=12.0;

  fprintf(fp,"%%%%Page: %d %d\n",*page,*page);

  fprintf(fp,"0.5 setlinewidth\n");
  fprintf(fp,"58 30 translate\n");
  fprintf(fp,"0 748.0 moveto 14 f1 (Correction Tables for Sextant Altitudes) show\n");

  fprintf(fp,"  0 %.1f moveto 10 f0 (The  Altitude-Intercept  method used in contemporary Celestial Navigation,) show\n",y);
  fprintf(fp,"480 %.1f moveto 10 f0 (is based on the comparison of an) Rshow\n",y);
  y-=yincr;
  fprintf(fp,"  0 %.1f moveto 10 f0 (\"observed altitude\"  with  a  related  \"computed altitude\".) show\n",y);
  fprintf(fp,"480 %.1f moveto 10 f0 (The \"computed altitude\" itself is based on a mathe-) Rshow\n",y);
  y-=yincr;
  fprintf(fp,"  0 %.1f moveto 10 f0 (matical model, which implies a number of conditions and assumptions some of which are:) show\n",y);
  y-=yincr;
  fprintf(fp,"newpath 10 %.1f 1.5 0.0 360.0 arc fill\n",y+yincr/4.0);
  fprintf(fp," 16 %.1f moveto 10 f0 (The  celestial bodies   have  no  physical  dimensions) show\n",y);
  fprintf(fp,"480 %.1f moveto 10 f0 (and  observations  are  made  from  the  center  of) Rshow\n",y);
  y-=yincr;
  fprintf(fp," 16 %.1f moveto 10 f0 (the Earth.) show\n",y);
  y-=yincr;
  fprintf(fp,"newpath 10 %.1f 1.5 0.0 360.0 arc fill\n",y+yincr/4.0);
  fprintf(fp," 16 %.1f moveto 10 f0 (Light  rays  from celestial bodies  come from  infinitely) show\n",y);
  fprintf(fp,"480 %.1f moveto 10 f0 (far  away and  hence  reach  the Earth  parallel  to) Rshow\n",y);
  y-=yincr;
  fprintf(fp," 16 %.1f moveto 10 f0 (one another.) show\n",y);
  y-=yincr;
  fprintf(fp,"newpath 10 %.1f 1.5 0.0 360.0 arc fill\n",y+yincr/4.0);
  fprintf(fp," 16 %.1f moveto 10 f0 (The Earth has no atmosphere and air has no index of refraction.) show\n",y);
  y-=yincr;
  y-=yincr;
  fprintf(fp,"  0 %.1f moveto 10 f0 (These  assumptions  are  not  fullfilled  for  observations  made  in the  real fysical  world.) show\n",y);
  fprintf(fp,"480 %.1f moveto 10 f0 (In order  to put  the) Rshow\n",y);
  y-=yincr;
  fprintf(fp,"  0 %.1f moveto 10 f0 (mathematically computed  altitude  and  the \"real world\") show\n",y);
  fprintf(fp,"480 %.1f moveto 10 f0 (observed altitude  on an  alike  basis of comparison,) Rshow\n",y);
  y-=yincr;
  fprintf(fp,"  0 %.1f moveto 10 f0 (some \"corrections\" must be applied to the measured Sextant Altitude.) show\n",y);
  y-=yincr;
  y-=yincr;
  fprintf(fp,"  0 %.1f moveto 10 f0 (These corrections  are  performed  on  the  observed altitude) show\n",y);
  fprintf(fp,"480 %.1f moveto 10 f0 (\\( measured Sextant Altitude \\)  according to the) Rshow\n",y);
  y-=yincr;
  fprintf(fp,"  0 %.1f moveto 10 f0 (following scheme:) show\n",y);

  
  fprintf(fp,"gsave\n");
  fprintf(fp,"0 96 translate\n");
  fprintf(fp,"0.0 setgray\n");
  fprintf(fp,"newpath 0 428 moveto 480 0 rlineto 0 -140 rlineto -480 0 rlineto closepath stroke\n");
  fprintf(fp,"  3.5 412.3 moveto 10 f4 (  Hs     __ \\260 __'_) show\n");
  fprintf(fp,"  187.5 412.3 moveto 8 f4 (Sextant Altitude) show\n");
  fprintf(fp,"  3.5 401.8 moveto 10 f4 (  IE   \\261      __'_) show\n");
  fprintf(fp,"  187.5 401.8 moveto 8 f4 (Index Error) show\n");
  fprintf(fp,"  3.5 391.3 moveto 10 f4 (  Dip  -      __'_) show\n");
  fprintf(fp,"  187.5 391.3 moveto 8 f4 (Dip Correction) show\n");
  fprintf(fp,"  3.5 380.8 moveto 10 f4 (       _____________) show\n");
  fprintf(fp,"  3.5 370.3 moveto 10 f4 (         __ \\260 __'_      ) show\n");
  fprintf(fp,"  187.5 370.3 moveto 8 f4 (Apparent Altitude of Upper/Lower Limb) show\n");
  fprintf(fp,"  3.5 359.8 moveto 10 f4 (  SD   \\261      __'_    SD __'_) show\n");
  fprintf(fp,"  187.5 359.8 moveto 8 f4 (Semi-Diameter \\(+ for lower limb; - for upper limb\\)) show\n");
  fprintf(fp,"  3.5 349.3 moveto 10 f4 (  Refr -      __'_      ) show\n");
  fprintf(fp,"  187.5 349.3 moveto 8 f4 (Refraction) show\n");
  fprintf(fp,"  3.5 338.8 moveto 10 f4 (       _____________) show\n");
  fprintf(fp,"  3.5 328.3 moveto 10 f4 (  Ha     __ \\260 __'_      ) show\n");
  fprintf(fp,"  187.5 328.3 moveto 8 f4 (Apparent Altitude) show\n");
  fprintf(fp,"  3.5 317.8 moveto 10 f4 (  Pllx + __ \\260 __'_    HP __\\260_ ) show\n");
  fprintf(fp,"  187.5 317.8 moveto 8 f4 (Parallax Correction) show\n");
  fprintf(fp,"  3.5 307.3 moveto 10 f4 (       _____________) show\n");
  fprintf(fp,"  3.5 296.8 moveto 10 f4 (  Ho     __ \\260 __'_      ) show\n");
  fprintf(fp,"  187.5 296.8 moveto 8 f4 (Observed Altitude \\(geocentrical\\)) show\n");
  fprintf(fp,"grestore\n");

  y=y-16.0*yincr;
  fprintf(fp,"  0 %.1f moveto 10 f0 (The values for semi-diameter \\(SD\\) and horizontal parallax) show\n",y);
  fprintf(fp,"480 %.1f moveto 10 f0 (\\(HP\\) must be obtained from the Nautical Almanac.) Rshow\n",y);
  y-=yincr;
  fprintf(fp,"  0 %.1f moveto 10 f0 (The values for dip, refraction \\(Refr\\) and parallax \\(Pllx\\) can be obtained from the following pages.) show\n",y);
  y-=8.0*yincr;
  fprintf(fp,"  0 %.1f moveto 10 f0 (On the next pages the Tables for Dip of the Horizon,  Refraction and  Parallax are presented.) show\n",y);
  fprintf(fp,"480 %.1f moveto 10 f0 (The Tables for) Rshow\n",y);
  y-=yincr;
  fprintf(fp,"  0 %.1f moveto 10 f0 (the Parallax values  are  splitted  in  two ranges.) show\n",y);
  fprintf(fp,"480 %.1f moveto 10 f0 (For the Sun and the Planets, the applicable range is 0.1' to) Rshow\n",y);
  y-=yincr;
  fprintf(fp,"  0 %.1f moveto 10 f0 (0.5'.  Since the Moon is much closer to the Earth,  the applicable) show\n",y);
  fprintf(fp,"480 %.1f moveto 10 f0 (Parallax values are considerable larger and) Rshow\n",y);
  y-=yincr;
  fprintf(fp,"  0 %.1f moveto 10 f0 (range from 54.0' to 63.0'.) show\n",y);
  
  fprintf(fp,"showpage\n");


  *page = (*page)+1;

  return;
}


/* -------------------------------------------------------------------------------------------------------------------------- */
void PrintDipPage(FILE *fp, int *page)

{ int    i,j;

  char   sAngle[12];
  double hEye;
  double dip;
  double x,y,dy;
  double col_width=180.0;
  double xoffset=180.0;


  fprintf(fp,"%%%%Page: %d %d\n",*page,*page);

  fprintf(fp,"30 20 translate\n");
  fprintf(fp,"0.5 setlinewidth\n");
  /* for debugging: print the "boundary frame" (0,0) to (540,800) within which the page will be formatted ... */
  /*
  fprintf(fp,"newpath 0 0 moveto 540 0 lineto 540 800 lineto 0 800 lineto closepath stroke\n");
   */
  fprintf(fp,"0 780.0 moveto 14 f1 (Correction Table for Dip of the Horizon) show\n");

  dy=11.0;

  for(i=0; i<3; i++)
  { y=734.0;
    x=32.0+col_width*i;

    fprintf(fp,"newpath %.1f 750.0 moveto %.1f 0 rlineto 0 -450.0 rlineto -%.1f 0 rlineto closepath stroke\n",col_width*i,col_width,col_width);
    fprintf(fp,"%.1f %.1f moveto 8 f0 (Height) Cshow\n",x,y);
    fprintf(fp,"%.1f %.1f moveto 8 f0 (Correction) Cshow\n",x+col_width/3.0,y);
    fprintf(fp,"%.1f %.1f moveto 8 f0 (Distance) Cshow\n",x+2.0*col_width/3.0,y);
    y-=dy;
    fprintf(fp,"%.1f %.1f moveto 8 f0 (above) Cshow\n",x,y);
    fprintf(fp,"%.1f %.1f moveto 8 f0 (on) Cshow\n",x+col_width/3.0,y);
    fprintf(fp,"%.1f %.1f moveto 8 f0 (to the) Cshow\n",x+2.0*col_width/3.0,y);
    y-=dy;
    fprintf(fp,"%.1f %.1f moveto 8 f0 (Horizon) Cshow\n",x,y);
    fprintf(fp,"%.1f %.1f moveto 8 f0 (Altitude) Cshow\n",x+col_width/3.0,y);
    fprintf(fp,"%.1f %.1f moveto 8 f0 (Horizon) Cshow\n",x+2.0*col_width/3.0,y);

    y-=2.0*dy;

    /* the basic formula for dip:    dip = 1.76 * SQRT(hEye) 
     * and for distance to horizon:    D = 2.07 * SQRT(hEye)
     * but the basic loop is over dip and not over hEye, so we calculate hEye from dip ...
     */
    for(j=0; j<30; j++)
    { dip  = (i*3.0+1.0) + j/10.0; 
      hEye = (dip*dip)/3.0976;                  /* dip = 1.76 * SQRT(hEye); so hEye = (dip/1.76)^2    */
      fprintf(fp,"%.1f %.1f moveto 9 f4 (%3.1f m) Rshow\n",x+12.0,y,hEye);
      fprintf(fp,"%.1f %.1f moveto 9 f5 (-%s) Rshow\n",x+col_width/3.0+12.0,y,FormatMin(1.76*sqrt(hEye),sAngle));
      fprintf(fp,"%.1f %.1f moveto 9 f4 (%3.1f nm) Rshow\n",x+2.0*col_width/3.0+12.0,y,2.07*sqrt(hEye));
      y-=dy;
      if(((j+1)%5)==0) y-=dy;
    }
  }

  x=0.0;
  y-=2.0*dy;
  fprintf(fp,"%.1f %.1f moveto 9 f1 (Height above Horizon:) show\n",x,y);
  fprintf(fp,"%.1f %.1f moveto 9 f0 (is the height above the sea level \\(in meters\\) at which the sextant is held during the celestial observation.) show\n",110.0,y);
  y-=dy;
  fprintf(fp,"%.1f %.1f moveto 9 f1 (Correction on Altitude:) show\n",x,y);
  fprintf(fp,"%.1f %.1f moveto 9 f0 (is the angle \\(in minutes of arc\\) by which the Altitude has to be corrected to account for the effect of Dip.) show\n",110.0,y);
  y-=dy;
  fprintf(fp,"%.1f %.1f moveto 9 f1 (Distance to the Horizon:) show\n",x,y);
  fprintf(fp,"%.1f %.1f moveto 9 f0 (is the distance \\(in nautical miles\\) to the apparent Horizon.) show\n",110.0,y);
  

  fprintf(fp,"  0 10 moveto 6 f0 (Warning:) show\n");
  fprintf(fp," 30 10 moveto 6 f0 (This page has been generated by a computer program.  Complex computer programs usually have bugs and may produce wrong data.) show\n");
  fprintf(fp,"538 10 moveto 6 f0 (The data on this page is believed to be accurate but no) Rshow\n");
  fprintf(fp," 30  2 moveto 6 f0 (warranty is given for its correctness. Use it only for training and exercising! ) show\n");

  fprintf(fp,"showpage\n");


  *page = (*page)+1;

  return;
}


/* -------------------------------------------------------------------------------------------------------------------------- */
void PrintRefractionPage(FILE *fp, int *page)

{ int    i,j;

  char   sAngle[12];

  double x,y;
  double col_width=270.0;
  double xincr;
  double dy=10.0;

  double altitude[118]= { 3.000, 3.125, 3.250, 3.375, 3.500, 3.625, 3.750, 3.875, 4.000, 4.125, 4.250, 4.375, 4.500, 4.625, 4.750, 4.875,
                          5.000, 5.125, 5.250, 5.375, 5.500, 5.625, 5.750, 5.875, 6.000, 6.250, 6.500, 6.750, 7.000, 7.250, 7.500, 7.750,
                          8.000, 8.250, 8.500, 8.750, 9.000, 9.250, 9.500, 9.750,10.000,10.250,10.500,10.750,11.000,11.250,11.500,11.750,
                         12.000,12.500,13.000,13.500,14.000,14.500,15.000,15.500,16.000,16.500,17.000,17.500,18.000,18.500,19.000,19.500,
                         20.000,20.500,21.000,21.500,22.000,22.500,23.000,23.500,24.000,25.000,26.000,27.000,28.000,29.000,30.000,31.000,
                         32.000,33.000,34.000,35.000,36.000,37.000,38.000,39.000,40.000,41.000,42.000,43.000,44.000,45.000,46.000,47.000,
                         48.000,50.000,52.000,54.000,56.000,58.000,60.000,62.000,64.000,66.000,68.000,70.000,72.000,74.000,76.000,78.000,
                         80.000,82.000,84.000,86.000,88.000,90.000};

  double refr0010[118]= {13.5,13.2,12.9,12.6,12.3,12.0,11.7,11.5,11.2,11.0,10.8,10.5,10.3,10.1, 9.9, 9.7, 9.5, 9.4, 9.2, 9.0, 8.9, 8.7,
                          8.5, 8.4, 8.3, 8.0, 7.7, 7.5, 7.3, 7.0, 6.8, 6.7, 6.5, 6.3, 6.1, 6.0, 5.8, 5.7, 5.5, 5.4, 5.3, 5.2, 5.1, 4.9,
                          4.8, 4.7, 4.6, 4.5, 4.5, 4.3, 4.1, 4.0, 3.8, 3.7, 3.6, 3.5, 3.3, 3.2, 3.1, 3.0, 2.9, 2.9, 2.8, 2.7, 2.6, 2.6,
                          2.5, 2.4, 2.4, 2.3, 2.3, 2.2, 2.2, 2.1, 2.0, 1.9, 1.8, 1.7, 1.7, 1.6, 1.5, 1.5, 1.4, 1.4, 1.3, 1.3, 1.2, 1.2,
                          1.1, 1.1, 1.1, 1.0, 1.0, 1.0, 0.9, 0.9, 0.9, 0.8, 0.7, 0.7, 0.6, 0.6, 0.6, 0.5, 0.5, 0.4, 0.4, 0.3, 0.3, 0.3,
                          0.2, 0.2, 0.2, 0.1, 0.1, 0.1, 0.0, 0.0};

  double refr2010[118]= {13.8,13.5,13.1,12.8,12.5,12.2,12.0,11.7,11.5,11.2,11.0,10.8,10.5,10.3,10.1, 9.9, 9.7, 9.6, 9.4, 9.2, 9.0, 8.9,
                          8.7, 8.6, 8.4, 8.2, 7.9, 7.7, 7.4, 7.2, 7.0, 6.8, 6.6, 6.4, 6.3, 6.1, 6.0, 5.8, 5.7, 5.5, 5.4, 5.3, 5.2, 5.1,
                          4.9, 4.8, 4.7, 4.6, 4.6, 4.4, 4.2, 4.1, 3.9, 3.8, 3.7, 3.5, 3.4, 3.3, 3.2, 3.1, 3.0, 2.9, 2.8, 2.8, 2.7, 2.6,
                          2.5, 2.5, 2.4, 2.4, 2.3, 2.2, 2.2, 2.1, 2.0, 1.9, 1.8, 1.8, 1.7, 1.6, 1.6, 1.5, 1.4, 1.4, 1.3, 1.3, 1.3, 1.2,
                          1.2, 1.1, 1.1, 1.0, 1.0, 1.0, 0.9, 0.9, 0.9, 0.8, 0.8, 0.7, 0.7, 0.6, 0.6, 0.5, 0.5, 0.4, 0.4, 0.4, 0.3, 0.3,
                          0.2, 0.2, 0.2, 0.1, 0.1, 0.1, 0.0, 0.0};

  double refr0030[118]= {12.5,12.2,11.9,11.6,11.4,11.1,10.9,10.6,10.4,10.2,10.0, 9.8, 9.6, 9.4, 9.2, 9.0, 8.9, 8.7, 8.5, 8.4, 8.2, 8.1,
                          8.0, 7.8, 7.7, 7.4, 7.2, 7.0, 6.8, 6.6, 6.4, 6.2, 6.0, 5.9, 5.7, 5.6, 5.4, 5.3, 5.2, 5.1, 4.9, 4.8, 4.7, 4.6,
                          4.5, 4.4, 4.3, 4.3, 4.2, 4.0, 3.9, 3.7, 3.6, 3.5, 3.4, 3.2, 3.1, 3.0, 2.9, 2.8, 2.8, 2.7, 2.6, 2.5, 2.5, 2.4,
                          2.3, 2.3, 2.2, 2.2, 2.1, 2.1, 2.0, 1.9, 1.8, 1.8, 1.7, 1.6, 1.6, 1.5, 1.4, 1.4, 1.3, 1.3, 1.2, 1.2, 1.1, 1.1,
                          1.1, 1.0, 1.0, 1.0, 0.9, 0.9, 0.9, 0.8, 0.8, 0.8, 0.7, 0.7, 0.6, 0.6, 0.5, 0.5, 0.4, 0.4, 0.4, 0.3, 0.3, 0.3,
                          0.2, 0.2, 0.2, 0.1, 0.1, 0.1, 0.0, 0.0};

  double refr2030[118]= {12.8,12.5,12.2,11.9,11.6,11.4,11.1,10.9,10.6,10.4,10.2,10.0, 9.8, 9.6, 9.4, 9.2, 9.0, 8.9, 8.7, 8.6, 8.4, 8.3,
                          8.1, 8.0, 7.9, 7.6, 7.4, 7.1, 6.9, 6.7, 6.5, 6.3, 6.2, 6.0, 5.8, 5.7, 5.6, 5.4, 5.3, 5.2, 5.0, 4.9, 4.8, 4.7,
                          4.6, 4.5, 4.4, 4.3, 4.3, 4.1, 3.9, 3.8, 3.7, 3.5, 3.4, 3.3, 3.2, 3.1, 3.0, 2.9, 2.8, 2.7, 2.7, 2.6, 2.5, 2.4,
                          2.4, 2.3, 2.3, 2.2, 2.2, 2.1, 2.1, 2.0, 1.9, 1.8, 1.7, 1.6, 1.6, 1.5, 1.5, 1.4, 1.4, 1.3, 1.3, 1.2, 1.2, 1.1,
                          1.1, 1.1, 1.0, 1.0, 0.9, 0.9, 0.9, 0.9, 0.8, 0.8, 0.7, 0.7, 0.6, 0.6, 0.5, 0.5, 0.4, 0.4, 0.4, 0.3, 0.3, 0.3,
                          0.2, 0.2, 0.2, 0.1, 0.1, 0.1, 0.0, 0.0};

  fprintf(fp,"%%%%Page: %d %d\n",*page,*page);

  fprintf(fp,"30 20 translate\n");
  fprintf(fp,"0.5 setlinewidth\n");
  /* for debugging: print the "boundary frame" (0,0) to (540,800) within which the page will be formatted ... */
  /*
  fprintf(fp,"newpath 0 0 moveto 540 0 lineto 540 800 lineto 0 800 lineto closepath stroke\n");
   */
  fprintf(fp,"0 780.0 moveto 14 f1 (Correction Table for Refraction) show\n");


  for(i=0; i<2; i++)
  { y=734.0;
    x=10.0+col_width*(double)i;
    xincr=col_width/11.0;

    fprintf(fp,"newpath %.1f 750.0 moveto %.1f 0 rlineto 0 -720.0 rlineto -%.1f 0 rlineto closepath stroke\n",col_width*i,col_width,col_width);
    fprintf(fp,"newpath %.1f 750.0 moveto %.1f 0 rlineto 0 -40.0 rlineto -%.1f 0 rlineto closepath stroke\n",col_width*i,col_width,col_width);

    fprintf(fp,"%.1f %.1f moveto 9 f0 (Pressure) show\n",x,y);
    fprintf(fp,"%.1f %.1f moveto 9 f0 (1000 HPa) Cshow\n",x+5*xincr-6,y);
    fprintf(fp,"%.1f %.1f moveto 9 f0 (1030 HPa) Cshow\n",x+9*xincr-6,y);
    y-=1.5*dy;
    fprintf(fp,"%.1f %.1f moveto 9 f0 (Temperature) show\n",x,y);
    fprintf(fp,"%.1f %.1f moveto 9 f0 (10\260C) Rshow\n",x+ 4.0*xincr,y);
    fprintf(fp,"%.1f %.1f moveto 9 f0 (30\260C) Rshow\n",x+ 6.0*xincr,y);
    fprintf(fp,"%.1f %.1f moveto 9 f0 (10\260C) Rshow\n",x+ 8.0*xincr,y);
    fprintf(fp,"%.1f %.1f moveto 9 f0 (30\260C) Rshow\n",x+10.0*xincr,y);
    y-=3.0*dy;
    fprintf(fp,"%.1f %.1f moveto 9 f1 (Altitude) show\n",x,y);

    y-=1.5*dy;
    for(j=0; j<59; j++)
    { fprintf(fp,"%.1f %.1f moveto 9 f5 (%s)   show\n",x           ,y,FormatDegMin(altitude[j+i*59],sAngle));
      fprintf(fp,"%.1f %.1f moveto 9 f4 (-%s) Rshow\n",x+ 4.0*xincr,y,FormatMin(refr0010[j+i*59],sAngle));
      fprintf(fp,"%.1f %.1f moveto 9 f4 (-%s) Rshow\n",x+ 6.0*xincr,y,FormatMin(refr0030[j+i*59],sAngle));
      fprintf(fp,"%.1f %.1f moveto 9 f4 (-%s) Rshow\n",x+ 8.0*xincr,y,FormatMin(refr2010[j+i*59],sAngle));
      fprintf(fp,"%.1f %.1f moveto 9 f4 (-%s) Rshow\n",x+10.0*xincr,y,FormatMin(refr2030[j+i*59],sAngle));

      if(((j+1)%5) == 0) y-=1.5*dy;
        else             y-=dy;
    }
  }


  fprintf(fp,"  0 10 moveto 6 f0 (Warning:) show\n");
  fprintf(fp," 30 10 moveto 6 f0 (This page has been generated by a computer program.  Complex computer programs usually have bugs and may produce wrong data.) show\n");
  fprintf(fp,"538 10 moveto 6 f0 (The data on this page is believed to be accurate but no) Rshow\n");
  fprintf(fp," 30  2 moveto 6 f0 (warranty is given for its correctness. Use it only for training and exercising! ) show\n");

  fprintf(fp,"showpage\n");
  
  *page = (*page)+1;

  return;
}


/* -------------------------------------------------------------------------------------------------------------------------- */
void PrintOffsets(FILE *fp, int *page)

{ int    i,j;

  char   sAngle[12];

  double x,y,xincr,dy;
  double altitude[39]= { 0.0, 30.0, 40.0, 50.0, 55.0, 60.0, 62.0, 64.0, 66.0, 68.0, 70.0, 71.0, 72.0,
                        73.0, 74.0, 75.0, 76.0, 77.0, 78.0, 79.0, 80.0, 80.5, 81.0, 81.5, 82.0, 82.5,
                        83.0, 83.5, 84.0, 84.5, 85.0, 85.5, 86.0, 86.5, 87.0, 87.5, 88.0, 88.5, 89.0 };

  double toffset[39][10]= { {  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0},
                            {  0.0,  0.0,  0.0,  0.0,  0.0,  0.1,  0.1,  0.1,  0.1,  0.2},
                            {  0.0,  0.0,  0.0,  0.0,  0.1,  0.1,  0.1,  0.2,  0.2,  0.3},
                            {  0.0,  0.0,  0.0,  0.0,  0.1,  0.1,  0.2,  0.2,  0.3,  0.3},
                            {  0.0,  0.0,  0.0,  0.0,  0.1,  0.1,  0.2,  0.3,  0.3,  0.4},
                            {  0.0,  0.0,  0.0,  0.1,  0.1,  0.2,  0.2,  0.3,  0.4,  0.5},
                            {  0.0,  0.0,  0.0,  0.1,  0.1,  0.2,  0.2,  0.3,  0.4,  0.5},
                            {  0.0,  0.0,  0.0,  0.1,  0.1,  0.2,  0.3,  0.4,  0.5,  0.6},
                            {  0.0,  0.0,  0.0,  0.1,  0.1,  0.2,  0.3,  0.4,  0.5,  0.7},
                            {  0.0,  0.0,  0.0,  0.1,  0.1,  0.2,  0.3,  0.4,  0.5,  0.7},
                            {  0.0,  0.0,  0.0,  0.1,  0.2,  0.2,  0.4,  0.5,  0.6,  0.8},
                            {  0.0,  0.0,  0.0,  0.1,  0.2,  0.3,  0.4,  0.5,  0.7,  0.9},
                            {  0.0,  0.0,  0.0,  0.1,  0.2,  0.3,  0.4,  0.5,  0.7,  0.9},
                            {  0.0,  0.0,  0.0,  0.1,  0.2,  0.3,  0.4,  0.6,  0.8,  1.0},
                            {  0.0,  0.0,  0.1,  0.1,  0.2,  0.3,  0.5,  0.6,  0.8,  1.0},
                            {  0.0,  0.0,  0.1,  0.1,  0.2,  0.3,  0.5,  0.7,  0.9,  1.1},
                            {  0.0,  0.0,  0.1,  0.1,  0.2,  0.4,  0.5,  0.7,  0.9,  1.2},
                            {  0.0,  0.0,  0.1,  0.1,  0.3,  0.4,  0.6,  0.8,  1.0,  1.3},
                            {  0.0,  0.0,  0.1,  0.2,  0.3,  0.4,  0.6,  0.8,  1.1,  1.4},
                            {  0.0,  0.0,  0.1,  0.2,  0.3,  0.5,  0.7,  0.9,  1.2,  1.5},
                            {  0.0,  0.0,  0.1,  0.2,  0.3,  0.5,  0.7,  1.0,  1.3,  1.7},
                            {  0.0,  0.0,  0.1,  0.2,  0.3,  0.5,  0.8,  1.1,  1.4,  1.8},
                            {  0.0,  0.0,  0.1,  0.2,  0.4,  0.6,  0.8,  1.1,  1.5,  1.9},
                            {  0.0,  0.0,  0.1,  0.2,  0.4,  0.6,  0.9,  1.2,  1.6,  2.1},
                            {  0.0,  0.0,  0.1,  0.2,  0.4,  0.6,  0.9,  1.3,  1.7,  2.1},
                            {  0.0,  0.0,  0.1,  0.2,  0.4,  0.7,  1.0,  1.4,  1.8,  2.2},
                            {  0.0,  0.0,  0.1,  0.3,  0.5,  0.7,  1.1,  1.5,  1.9,  2.4},
                            {  0.0,  0.0,  0.1,  0.3,  0.5,  0.8,  1.2,  1.6,  2.0,  2.6},
                            {  0.0,  0.0,  0.1,  0.3,  0.5,  0.9,  1.2,  1.7,  2.2,  2.8},
                            {  0.0,  0.0,  0.2,  0.3,  0.6,  1.0,  1.4,  1.9,  2.4,  3.1},
                            {  0.0,  0.0,  0.2,  0.4,  0.7,  1.0,  1.5,  2.1,  2.7,  3.4},
                            {  0.0,  0.0,  0.2,  0.4,  0.7,  1.2,  1.7,  2.3,  3.0,  3.8},
                            {  0.0,  0.1,  0.2,  0.5,  0.8,  1.3,  1.9,  2.6,  3.4,  4.3},
                            {  0.0,  0.1,  0.2,  0.5,  1.0,  1.5,  2.2,  2.9,  3.8,  4.9},
                            {  0.0,  0.1,  0.3,  0.6,  1.1,  1.7,  2.5,  3.4,  4.5,  5.7},
                            {  0.0,  0.1,  0.3,  0.8,  1.3,  2.1,  3.0,  4.1,  5.4,  6.9},
                            {  0.0,  0.1,  0.4,  0.9,  1.7,  2.7,  3.8,  5.2,  6.9,  8.8},
                            {  0.0,  0.2,  0.6,  1.3,  2.3,  3.5,  5.1,  7.1,  9.4, 12.1},
                            {  0.0,  0.3,  0.8,  1.9,  3.4,  5.5,  8.0, 11.3, 15.3, 20.3} };


  dy=11.0;
  fprintf(fp,"%%%%Page: %d %d\n",*page,*page);

  fprintf(fp,"30 20 translate\n");
  fprintf(fp,"0.5 setlinewidth\n");
  /* for debugging: print the "boundary frame" (0,0) to (540,800) within which the page will be formatted ... */
  /*
  fprintf(fp,"newpath 0 0 moveto 540 0 lineto 540 800 lineto 0 800 lineto closepath stroke\n");
   */
  fprintf(fp,"0 780.0 moveto 14 f1 (Table of Offsets for Straight Line of Position) show\n");

  fprintf(fp,"newpath 0.0 750.0 moveto 540.0 0.0 rlineto 0.0 -544.0 rlineto -540.0 0.0 rlineto closepath stroke\n");
  fprintf(fp,"newpath 0.0 750.0 moveto 540.0 0.0 rlineto 0.0  -40.0 rlineto -540.0 0.0 rlineto closepath stroke\n");

  fprintf(fp,"270.0 734.0 moveto 9 f1 (Distance along the Line of Position from the intercept point) Cshow\n");


  x=6.0;
  y=734.0-1.5*dy;
  xincr=40.0;

  for(j=0; j<10; j++)
    fprintf(fp,"%.1f %.1f moveto 9 f0 (%2d nm) show\n",x+j*xincr+74,y,5*j);

  y-=2.0*dy;
  fprintf(fp,"%.1f %.1f moveto 9 f1 (Altitude) show\n",x,y);

  y-=1.5*dy;
  for(i=0; i<39; i++)
  { 
    fprintf(fp,"%.1f %.1f moveto 9 f5 (%s) show\n",x,y,FormatDegMin(altitude[i],sAngle));

    for(j=0; j<10; j++)
    { FormatMin(toffset[i][j],sAngle);
      sAngle[2]='.';
      fprintf(fp,"%.1f %.1f moveto 9 f4 (%s) show\n",x+j*xincr+74,y,sAngle);
    }
    
    if(((i+1)%4) == 0) y-=1.5*dy;
      else             y-=dy;
  }

  y-=dy;
  fprintf(fp,"%.1f %.1f moveto 9 f0 (The  above  Table of Offsets  gives corrections (in nautical miles)  to the straight) show\n",0.0,y);
  fprintf(fp,"%.1f %.1f moveto 9 f0 (Line of Position \\(LoP\\)  as drawn  on a plotting sheet  to) Rshow\n",540.0,y);
  y-=dy;  
  fprintf(fp,"%.1f %.1f moveto 9 f0 (provide a closer approximation of the arc of the \"circle of equal altitude\",) show\n",0.0,y);
  fprintf(fp,"%.1f %.1f moveto 9 f0 (a circle of radius equal to the zenith distance.   The corrections) Rshow\n",540.0,y);
  y-=dy;  
  fprintf(fp,"%.1f %.1f moveto 9 f0 (are offsets of points  on the LoP  and are drawn at right angles to the LoP) show\n",0.0,y);
  fprintf(fp,"%.1f %.1f moveto 9 f0 (in the direction of the observed object.   The offset points are) Rshow\n",540.0,y);
  y-=dy;  
  fprintf(fp,"%.1f %.1f moveto 9 f0 (joined  to  obtain  the arc of the  \"circle of equal altitude\".) show\n",0.0,y);
  fprintf(fp,"%.1f %.1f moveto 9 f0 (Usually,  the desired  approximation  of the arc  can be  obtained  by drawing a) Rshow\n",540.0,y);
  y-=dy;  
  fprintf(fp,"%.1f %.1f moveto 9 f0 (straight line through two offset points.) show\n",0.0,y);
  y-=dy;  
  fprintf(fp,"%.1f %.1f moveto 9 f0 (The magnitude of the  offsets  depend on  the observed Altitude and on the) show\n",0.0,y);
  fprintf(fp,"%.1f %.1f moveto 9 f0 (distance along the LoP  from the intercept point to the offset) Rshow\n",540.0,y);
  y-=dy;  
  fprintf(fp,"%.1f %.1f moveto 9 f0 (point.) show\n",0.0,y);

  fprintf(fp,"gsave\n 0.0 20.0 translate\n");
  fprintf(fp,"0.0 24.0 moveto 540.0 0.0 rlineto 0.0 100.0 rlineto -540.0 0.0 rlineto closepath clip\n");
  fprintf(fp,"newpath 270.0 -240.0 320.0  45.0 135.0 arc stroke\n");                            /* the "circle of equal altitude" */
  fprintf(fp,"newpath 270.0    0.0 moveto 0.0 100.0 rlineto stroke\n");                         /* the "azimuth line"             */
  fprintf(fp,"newpath 270.0   28.0 moveto 2.0 8.0 rlineto -4.0 0.0 rlineto closepath fill\n");  /* the "arrow" sign               */
  fprintf(fp,"newpath 270.0  80.0    2.0   0.0 360.0 arc fill\n");                              /* the bullet in the center       */
  fprintf(fp,"newpath 420.0  80.0    2.0   0.0 360.0 arc fill\n");                              /* the bullet on the upper right  */
  fprintf(fp,"newpath 420.0  43.0    2.0   0.0 360.0 arc fill\n");                              /* the bullet on the lower right  */
  fprintf(fp,"100.0   83.0 moveto 8 f0 (LoP) show\n");
  fprintf(fp,"110.0   30.0 moveto 8 f0 (circle of equal altitude) show\n");
  fprintf(fp,"274.0   30.0 moveto 8 f0 (direction to observed object) show\n");
  fprintf(fp,"268.0   83.0 moveto 8 f0 (intercept point) Rshow\n");
  fprintf(fp,"422.0   83.0 moveto 8 f0 (offset point) show\n");
  fprintf(fp,"436.0   60.0 moveto 8 f4 (correction) show\n");
  fprintf(fp,"345.0   94.0 moveto 8 f4 (distance along the LoP) Cshow\n");

  fprintf(fp,"0.2 setlinewidth\n");                                 /* draw accolada */
  fprintf(fp,"newpath 420.0   74.0 6.0   0.0  90.0 arc stroke\n");
  fprintf(fp,"newpath 426.0   74.0 moveto 426.0  68.0 lineto stroke\n");
  fprintf(fp,"newpath 432.0   68.0 6.0 180.0 270.0 arc stroke\n");
  fprintf(fp,"newpath 432.0   56.0 6.0  90.0 180.0 arc stroke\n");
  fprintf(fp,"newpath 426.0   56.0 moveto 426.0  49.0 lineto stroke\n");
  fprintf(fp,"newpath 420.0   49.0 6.0 270.0 360.0 arc stroke\n");
  fprintf(fp,"newpath 276.0   80.0 6.0  90.0 180.0 arc stroke\n");
  fprintf(fp,"newpath 276.0   86.0 moveto 339.0  86.0 lineto stroke\n");
  fprintf(fp,"newpath 339.0   92.0 6.0 270.0 360.0 arc stroke\n");
  fprintf(fp,"newpath 351.0   92.0 6.0 180.0 270.0 arc stroke\n");
  fprintf(fp,"newpath 351.0   86.0 moveto 414.0  86.0 lineto stroke\n");
  fprintf(fp,"newpath 414.0   80.0 6   0.0  90.0 arc stroke\n");
  
  fprintf(fp,"1.2 setlinewidth\n");
  fprintf(fp,"newpath 100.0   80.0 moveto 440.0  80.0 lineto stroke\n");                        /* the straight LoP */
  fprintf(fp,"grestore\n");



  fprintf(fp,"  0 10 moveto 6 f0 (Warning:) show\n");
  fprintf(fp," 30 10 moveto 6 f0 (This page has been generated by a computer program.  Complex computer programs usually have bugs and may produce wrong data.) show\n");
  fprintf(fp,"538 10 moveto 6 f0 (The data on this page is believed to be accurate but no) Rshow\n");
  fprintf(fp," 30  2 moveto 6 f0 (warranty is given for its correctness. Use it only for training and exercising! ) show\n");

  fprintf(fp,"showpage\n");

  *page = (*page)+1;

  return;
}



/* -------------------------------------------------------------------------------------------------------------------------- */
void PrintParallax_sun(FILE *fp, int *page)

{ int    n,i,j;

  char   sAngle[12];
  double hp,alt;
  double x,y,dy;
  double col_width=180.0;


  fprintf(fp,"%%%%Page: %d %d\n",*page,*page);

  fprintf(fp,"30 20 translate\n");
  fprintf(fp,"0.5 setlinewidth\n");
  /* for debugging: print the "boundary frame" (0,0) to (540,800) within which the page will be formatted ... */
  /*
  fprintf(fp,"newpath 0 0 moveto 540 0 lineto 540 800 lineto 0 800 lineto closepath stroke\n");
   */
  fprintf(fp,"0 780.0 moveto 14 f1 (Table for Parallax Correction  \\(Sun and Planets\\)) show\n");
  fprintf(fp,"540 780.0 moveto 14 f1 (HP  0.1'- 0.5') Rshow\n");

  dy=11.0;
  for(i=0; i<3; i++)
  { fprintf(fp,"newpath %.1f 750.0 moveto %.1f 0.0 rlineto 0 -430.0 rlineto -%.1f 0.0 rlineto closepath stroke\n",i*col_width,col_width,col_width);
    fprintf(fp,"newpath %.1f 750.0 moveto %.1f 0.0 rlineto 0  -40.0 rlineto -%.1f 0.0 rlineto closepath stroke\n",i*col_width,col_width,col_width);
    fprintf(fp,"%.1f 734.0 moveto 9 f1 (Horizontal Parallax) show\n",64.0+i*col_width);

    x=6.0+i*col_width;
    y=734.0-1.5*dy;
    for(hp=0.1; hp<=0.5; hp+=0.1)
    { FormatMin(hp,sAngle);
      sAngle[0]=' ';
      fprintf(fp,"%.1f %.1f moveto 9 f4 (%s) show\n",x+256.0*(hp-0.1)+40.0,y,sAngle);
    }
    
    y-=2.0*dy;
    fprintf(fp,"%.1f %.1f moveto 9 f1 (Altitude) show\n",x,y);

    y-=1.5*dy;
    n=0;
    for(alt=0.0+i*30.0; alt<30.0+i*30.0; alt+=1.0)
    { fprintf(fp,"%.1f %.1f moveto 9 f5 (%s) show\n",x,y,FormatDegMin(alt,sAngle));

      for(hp=0.1; hp<=0.5; hp+=0.1)
      { FormatMin(aSin(Sin(hp)*Cos(alt)),sAngle);
        sAngle[0]=' ';
        fprintf(fp,"%.1f %.1f moveto 9 f4 (%s) show\n",x+256.0*(hp-0.1)+40.0,y,sAngle);
      }

      n++;
      if((n%5) == 0) y-=1.5*dy;
        else         y-=dy;
    }
  }


  fprintf(fp,"  0 10 moveto 6 f0 (Warning:) show\n");
  fprintf(fp," 30 10 moveto 6 f0 (This page has been generated by a computer program.  Complex computer programs usually have bugs and may produce wrong data.) show\n");
  fprintf(fp,"538 10 moveto 6 f0 (The data on this page is believed to be accurate but no) Rshow\n");
  fprintf(fp," 30  2 moveto 6 f0 (warranty is given for its correctness. Use it only for training and exercising! ) show\n");

  fprintf(fp,"showpage\n");

  *page = (*page)+1;

  return;
}

/* -------------------------------------------------------------------------------------------------------------------------- */
void PrintParallax_moon(FILE *fp, int *page, double hp)

{ int    m,n,i,j;

  char   sAngle[12];
  double alt,hpl;
  double x,y,dy;

  dy=11.0;
  for(i=0; i<6; i++)                /* Altitude values are spread over 6 pages (15 deg per page)  */
  { 
    fprintf(fp,"%%%%Page: %d %d\n",*page,*page);
  
    fprintf(fp,"30 20 translate\n");
    fprintf(fp,"0.5 setlinewidth\n");
    /* for debugging: print the "boundary frame" (0,0) to (540,800) within which the page will be formatted ... */
    /*
    fprintf(fp,"newpath 0 0 moveto 540 0 lineto 540 800 lineto 0 800 lineto closepath stroke\n");
     */
    fprintf(fp,"0 780.0 moveto 14 f1 (Table for Parallax Correction  \\(Moon\\)) show\n");
    fprintf(fp,"540 780.0 moveto 14 f1 (HP  %4.1f'- %4.1f') Rshow\n",hp,hp+3.0);

    fprintf(fp,"newpath 0.0 750.0 moveto 540.0 0.0 rlineto 0.0 -732.0 rlineto -540.0 0.0 rlineto closepath stroke\n");
    fprintf(fp,"newpath 0.0 750.0 moveto 540.0 0.0 rlineto 0.0  -40.0 rlineto -540.0 0.0 rlineto closepath stroke\n");
    fprintf(fp,"270.0 734.0 moveto 8 f1 (Horizontal Parallax) Cshow\n");

    dy=11.0;
    x=58.0;
    y=734.0-1.5*dy;
    m=0;
    for(hpl=hp; hpl<hp+3.1; hpl+=0.2)
    { fprintf(fp,"%.1f %.1f moveto 9 f4 (%s) show\n",x,y,FormatMin(hpl,sAngle));
      if((++m%5) == 0) x+=38.0; else x+=28.0;
    }

    x=6.0;
    y-=2.0*dy;
    fprintf(fp,"%.1f %.1f moveto 9 f1 (Altitude) show\n",x,y);

    dy=10.0;
    y-=1.5*dy;
    n=0;
    for(alt=i*15.0; alt<(i+1.0)*15.0; alt+=0.25)
    { x=6.0;

      fprintf(fp,"%.1f %.1f moveto 9 f5 (%s) show\n",x,y,FormatDegMin(alt,sAngle));

      x=58.0;
      m=0;
      for(hpl=hp; hpl<hp+3.1; hpl+=0.2)
      { fprintf(fp,"%.1f %.1f moveto 9 f4 (%s) show\n",x,y,FormatMin(aSin(Sin(hpl)*Cos(alt)),sAngle));
        m++;
        if((++m%5) == 0) x+=38.0; else x+=28.0;
      }

      if((++n%4) == 0) y-=1.5*dy; else y-=dy;
    }

    fprintf(fp,"  0 10 moveto 6 f0 (Warning:) show\n");
    fprintf(fp," 30 10 moveto 6 f0 (This page has been generated by a computer program.  Complex computer programs usually have bugs and may produce wrong data.) show\n");
    fprintf(fp,"538 10 moveto 6 f0 (The data on this page is believed to be accurate but no) Rshow\n");
    fprintf(fp," 30  2 moveto 6 f0 (warranty is given for its correctness. Use it only for training and exercising! ) show\n");

     fprintf(fp,"showpage\n");
  
    *page = (*page)+1;
  }

  return;
}






/* -------------------------------------------------------------------------------------------------------------------------- */
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


  strcpy(filename,"Data/Corrections.ps");
  printf("\n Generating Corrections Tables: \"%s\" ...\n\n",filename);

  if((fp=fopen(filename,"w")) == NULL)
  { printf(" Error (%s) could not open file \"%s\" for reading!\n",argv[0],filename);
    exit(-1);
  }

  printf("                     writing data file : \"%s\"\n",filename);


  page=2;
  PrintHeader(fp);
  InsertBlankPage(fp,&page);
  PrintWarning(fp,&page);
  InsertBlankPage(fp,&page);

  PrintIntro(fp,&page);
  PrintDipPage(fp,&page);
  PrintRefractionPage(fp,&page);
  InsertBlankPage(fp,&page);

  PrintParallax_sun(fp,&page);
  InsertBlankPage(fp,&page);
  PrintParallax_moon(fp,&page,54.0);
  PrintParallax_moon(fp,&page,57.0);
  PrintParallax_moon(fp,&page,60.0);
  InsertBlankPage(fp,&page);
  InsertBlankPage(fp,&page);

  PrintOffsets(fp,&page);
  InsertBlankPage(fp,&page);
  
  fprintf(fp,"%%EOF\n");
  fclose(fp); 
  
  printf("\n");
  return 0;
}
