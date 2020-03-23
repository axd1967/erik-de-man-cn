
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define PI       3.141592654






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
  fprintf(fp,"%%%%BeginPageSetup\n");
  fprintf(fp,"54 72 translate\n");
  fprintf(fp,"%%%%EndPageSetup\n");
  fprintf(fp,"newpath 0 0 moveto 500 0 rlineto 0 700 rlineto -500 0 rlineto  closepath clip newpath\n");
  fprintf(fp,"0.5 setgray\n1.0 setlinewidth\n");
  fprintf(fp,"-40 685 moveto 24 f0 ( Interpolation Tables  Interpolation Tables  Interpolation Tables  Interpolation Tables) show\n");
  fprintf(fp,"-40 655 moveto 36 f3 ( Interpolation Tables  Interpolation Tables  Interpolation Tables  Interpolation Tables) show\n");
  fprintf(fp,"-100 630 moveto 24 f7 ( Interpolation Tables  Interpolation Tables  Interpolation Tables  Interpolation Tables) show\n");
  fprintf(fp,"-40 590 moveto 48 f2 ( Interpolation Tables  Interpolation Tables  Interpolation Tables  Interpolation Tables) show\n");
  fprintf(fp,"-200 555 moveto 36 f6 ( Interpolation Tables  Interpolation Tables  Interpolation Tables  Interpolation Tables) show\n");
  fprintf(fp,"-40 530 moveto 24 f0 ( Interpolation Tables  Interpolation Tables  Interpolation Tables  Interpolation Tables) show\n");
  fprintf(fp,"-10 490 moveto 48 f4 ( Interpolation Tables  Interpolation Tables  Interpolation Tables  Interpolation Tables) show\n");
  fprintf(fp,"-40 465 moveto 24 f3 ( Interpolation Tables  Interpolation Tables  Interpolation Tables  Interpolation Tables) show\n");
  fprintf(fp,"-40 435 moveto 36 f5 ( Interpolation Tables  Interpolation Tables  Interpolation Tables  Interpolation Tables) show\n");
  fprintf(fp,"-80 410 moveto 24 f0 ( Interpolation Tables  Interpolation Tables  Interpolation Tables  Interpolation Tables) show\n");
  fprintf(fp,"-40 370 moveto 48 f0 ( Interpolation Tables  Interpolation Tables  Interpolation Tables  Interpolation Tables) show\n");
  fprintf(fp,"-40 335 moveto 36 f4 ( Interpolation Tables  Interpolation Tables  Interpolation Tables  Interpolation Tables) show\n");
  fprintf(fp,"-40 310 moveto 24 f3 ( Interpolation Tables  Interpolation Tables  Interpolation Tables  Interpolation Tables) show\n");
  fprintf(fp,"-10 285 moveto 24 f7 ( Interpolation Tables  Interpolation Tables  Interpolation Tables  Interpolation Tables) show\n");
  fprintf(fp,"-40 255 moveto 36 f0 ( Interpolation Tables  Interpolation Tables  Interpolation Tables  Interpolation Tables) show\n");
  fprintf(fp,"-90 230 moveto 24 f5 ( Interpolation Tables  Interpolation Tables  Interpolation Tables  Interpolation Tables) show\n");
  fprintf(fp,"-40 210 moveto 24 f4 ( Interpolation Tables  Interpolation Tables  Interpolation Tables  Interpolation Tables) show\n");
  fprintf(fp,"-40 170 moveto 48 f1 ( Interpolation Tables  Interpolation Tables  Interpolation Tables  Interpolation Tables) show\n");
  fprintf(fp,"-40 140 moveto 24 f0 ( Interpolation Tables  Interpolation Tables  Interpolation Tables  Interpolation Tables) show\n");
  fprintf(fp,"-40 110 moveto 36 f6 ( Interpolation Tables  Interpolation Tables  Interpolation Tables  Interpolation Tables) show\n");
  fprintf(fp,"-40  85 moveto 24 f2 ( Interpolation Tables  Interpolation Tables  Interpolation Tables  Interpolation Tables) show\n");
  fprintf(fp,"-80  45 moveto 48 f3 ( Interpolation Tables  Interpolation Tables  Interpolation Tables  Interpolation Tables) show\n");
  fprintf(fp,"-10  25 moveto 24 f4 ( Interpolation Tables  Interpolation Tables  Interpolation Tables  Interpolation Tables) show\n");
  fprintf(fp,"-40   0 moveto 36 f5 ( Interpolation Tables  Interpolation Tables  Interpolation Tables  Interpolation Tables) show\n");
  fprintf(fp,"showpage\n");

  return;
}




/* -------------------------------------------------------------------------------------------------------------------------- */
void InsertBlankPage(FILE *fp, int *page)

{
  fprintf(fp,"%%%%Page: %d %d\n",*page,*page);
  fprintf(fp,"gsave 0.95 setgray\n");
  fprintf(fp,"36 f0\n");
  fprintf(fp,"300 400 moveto (Blank Page) Cshow\n");
  fprintf(fp,"grestore\n");
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
  fprintf(fp,"  0.0 422.5 moveto 18 f1 (Interpolation Tables) show\n");
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
void PrintPurpose(FILE *fp, int *page)

{ double y,yincr;


  y=714.0;
  yincr=12.0;

  fprintf(fp,"%%%%Page: %d %d\n",*page,*page);
  fprintf(fp,"0.7 setlinewidth\n");
  fprintf(fp,"58 30 translate\n");
  fprintf(fp,"0 748.0 moveto 14 f1 (Purpose and Scope) show\n");

  fprintf(fp,"  0 %.1f moveto 10 f0 (The Interpolation and Conversion Tables presented on the) show\n",y); 
  fprintf(fp,"480 %.1f moveto 10 f0 (following pages, are designed to be  used  for the) Rshow\n",y); 
  y-=yincr;
  fprintf(fp,"  0 %.1f moveto 10 f0 (interpolation  of the  Nautical Almanac data \\(GHA and Declination\\)) show\n",y);
  fprintf(fp,"480 %.1f moveto 10 f0 (as well as  for the interpolation of the data) Rshow\n",y);
  y-=yincr;
  fprintf(fp,"  0 %.1f moveto 10 f0 (from the Sight Reduction Tables \\(calculated Altitude\\).) show\n",y);
  y-=yincr;
  y-=yincr;
  fprintf(fp,"  0 %.1f moveto 10 f0 (In order to obtain the  highest possible  accuracy  an  interpolation) show\n",y);
  fprintf(fp,"480 %.1f moveto 10 f0 (scheme based on logarithmic arithmetic is) Rshow\n",y);
  y-=yincr;
  fprintf(fp,"  0 %.1f moveto 10 f0 (used. The use of this scheme will be shown in some examples.) show\n",y);
  y-=yincr;
  y-=yincr;
  fprintf(fp,"  0 %.1f moveto 10 f0 (The  calculation  of a linear interpolation  with the presented tables) show\n",y);
  fprintf(fp,"480 %.1f moveto 10 f0 (requirs only one addition  and three table) Rshow\n",y);
  y-=yincr;
  fprintf(fp,"  0 %.1f moveto 10 f0 (lookups. The interpolated values have an accuracy) show\n",y);
  fprintf(fp,"480 %.1f moveto 10 f0 (better than  ±0.05  minutes of arc  compared to the same) Rshow\n",y);
  y-=yincr;
  fprintf(fp,"  0 %.1f moveto 10 f0 (results calculated with full precision.) show\n",y);

  fprintf(fp,"showpage\n");

  *page = (*page)+1;

  return;
}




/* -------------------------------------------------------------------------------------------------------------------------- */
void PrintArrangement(FILE *fp, int *page)

{ double y,yincr;


  y=714.0;
  yincr=12.0;

  fprintf(fp,"%%%%Page: %d %d\n",*page,*page);
  fprintf(fp,"0.7 setlinewidth\n");
  fprintf(fp,"58 30 translate\n");

  fprintf(fp,"0 748.0 moveto 14 f1 (Arrangement) show\n");
  fprintf(fp,"  0 %.1f moveto 10 f0 (The  Interpolation Tables  have an entry  for each  Second  through the Hour.) show\n",y);
  fprintf(fp,"480 %.1f moveto 10 f0 (Each entry  corresponds  to a) Rshow\n",y);
  y-=yincr;
  fprintf(fp,"  0 %.1f moveto 10 f0 (specific  Minute:Second  combination \\(from 00:00 through 59:59\\) representing a  fraction of the Hour.) show\n",y);
  y-=yincr;
  y-=yincr;
  fprintf(fp,"  0 %.1f moveto 10 f0 (For each entry  four  data values  are given  arranged in  two subtables.) show\n",y);
  fprintf(fp,"480 %.1f moveto 10 f0 (The  following excerpt  gives the  first) Rshow\n",y);
  y-=yincr;
  fprintf(fp,"  0 %.1f moveto 10 f0 (entries of the \"16 Min\" data:) show\n",y);
  y-=yincr;

  fprintf(fp,"gsave\n");
  fprintf(fp," 0.7 setlinewidth\n");
  fprintf(fp," 1.2 1.2 scale\n");
  fprintf(fp," -162 -232 translate\n");
  fprintf(fp," 0.0 setgray\n");

/*
  fprintf(fp," 162 772 moveto 163 0 rlineto 0 -240 rlineto -163 0 rlineto closepath stroke\n");
 */
  fprintf(fp," 163 771 moveto 161 0 rlineto 0 -238 rlineto -161 0 rlineto closepath stroke\n");
  fprintf(fp," 163 741 moveto 161  0 rlineto stroke\n");
  fprintf(fp," 254 741 moveto 0 -208 rlineto stroke\n");

  fprintf(fp," 232 750 moveto 14 f1 (16) Rshow\n");
  fprintf(fp," 236 750 moveto 12 f1 (Min) show\n");
  fprintf(fp," 166 728 moveto 8 f1 (Sec) show\n");
  fprintf(fp," 188 728 moveto 8 f1 (fMin) show\n");
  fprintf(fp," 222 728 moveto 8 f1 (d) show\n");
  fprintf(fp," 227 726 moveto 6 f1 (HA) show\n");
  fprintf(fp," 265 728 moveto 8 f1 (p) show\n");
  fprintf(fp," 298 728 moveto 8 f1 (s) show\n");
  fprintf(fp," 198 716 moveto 8 f1 (') show\n");
  fprintf(fp," 222 716 moveto 8 f1 (\260) show\n");
  fprintf(fp," 241 716 moveto 8 f1 (') show\n");
  fprintf(fp," 170.0 706.0 moveto 8 f5 (00) show\n");
  fprintf(fp," 188.0 706.0 moveto 8 f4 (16.0) show\n");
  fprintf(fp," 216.0 706.0 moveto 8 f4 (04) show\n");
  fprintf(fp," 230.0 706.0 moveto 8 f4 (00.0) show\n");
  fprintf(fp," 260.0 706.0 moveto 7 f4 ( 29823   65386) show\n");
  fprintf(fp," 170.0 696.4 moveto 8 f5 (01) show\n");
  fprintf(fp," 188.0 696.4 moveto 8 f4 (    ) show\n");
  fprintf(fp," 216.0 696.4 moveto 8 f4 (04) show\n");
  fprintf(fp," 230.0 696.4 moveto 8 f4 (00.2) show\n");
  fprintf(fp," 260.0 696.4 moveto 7 f4 ( 29827   65390) show\n");
  fprintf(fp," 170.0 686.8 moveto 8 f5 (02) show\n");
  fprintf(fp," 188.0 686.8 moveto 8 f4 (    ) show\n");
  fprintf(fp," 216.0 686.8 moveto 8 f4 (04) show\n");
  fprintf(fp," 230.0 686.8 moveto 8 f4 (00.5) show\n");
  fprintf(fp," 260.0 686.8 moveto 7 f4 ( 29832   65395) show\n");
  fprintf(fp," 170.0 677.2 moveto 8 f5 (03) show\n");
  fprintf(fp," 188.0 677.2 moveto 8 f4 (    ) show\n");
  fprintf(fp," 216.0 677.2 moveto 8 f4 (04) show\n");
  fprintf(fp," 230.0 677.2 moveto 8 f4 (00.8) show\n");
  fprintf(fp," 260.0 677.2 moveto 7 f4 ( 29836   65399) show\n");
  fprintf(fp," 170.0 667.6 moveto 8 f5 (04) show\n");
  fprintf(fp," 188.0 667.6 moveto 8 f4 (    ) show\n");
  fprintf(fp," 216.0 667.6 moveto 8 f4 (04) show\n");
  fprintf(fp," 230.0 667.6 moveto 8 f4 (01.0) show\n");
  fprintf(fp," 260.0 667.6 moveto 7 f4 ( 29841   65404) show\n");
  fprintf(fp," 170.0 658.0 moveto 8 f5 (05) show\n");
  fprintf(fp," 188.0 658.0 moveto 8 f4 (    ) show\n");
  fprintf(fp," 216.0 658.0 moveto 8 f4 (04) show\n");
  fprintf(fp," 230.0 658.0 moveto 8 f4 (01.2) show\n");
  fprintf(fp," 260.0 658.0 moveto 7 f4 ( 29845   65408) show\n");
  fprintf(fp," 170.0 638.8 moveto 8 f5 (06) show\n");
  fprintf(fp," 188.0 638.8 moveto 8 f4 (16.1) show\n");
  fprintf(fp," 216.0 638.8 moveto 8 f4 (04) show\n");
  fprintf(fp," 230.0 638.8 moveto 8 f4 (01.5) show\n");
  fprintf(fp," 260.0 638.8 moveto 7 f4 ( 29850   65413) show\n");
  fprintf(fp," 170.0 629.2 moveto 8 f5 (07) show\n");
  fprintf(fp," 188.0 629.2 moveto 8 f4 (    ) show\n");
  fprintf(fp," 216.0 629.2 moveto 8 f4 (04) show\n");
  fprintf(fp," 230.0 629.2 moveto 8 f4 (01.8) show\n");
  fprintf(fp," 260.0 629.2 moveto 7 f4 ( 29854   65417) show\n");
  fprintf(fp," 170.0 619.6 moveto 8 f5 (08) show\n");
  fprintf(fp," 188.0 619.6 moveto 8 f4 (    ) show\n");
  fprintf(fp," 216.0 619.6 moveto 8 f4 (04) show\n");
  fprintf(fp," 230.0 619.6 moveto 8 f4 (02.0) show\n");
  fprintf(fp," 260.0 619.6 moveto 7 f4 ( 29859   65422) show\n");
  fprintf(fp," 170.0 610.0 moveto 8 f5 (09) show\n");
  fprintf(fp," 188.0 610.0 moveto 8 f4 (    ) show\n");
  fprintf(fp," 216.0 610.0 moveto 8 f4 (04) show\n");
  fprintf(fp," 230.0 610.0 moveto 8 f4 (02.2) show\n");
  fprintf(fp," 260.0 610.0 moveto 7 f4 ( 29863   65426) show\n");
  fprintf(fp," 170.0 600.4 moveto 8 f5 (10) show\n");
  fprintf(fp," 188.0 600.4 moveto 8 f4 (    ) show\n");
  fprintf(fp," 216.0 600.4 moveto 8 f4 (04) show\n");
  fprintf(fp," 230.0 600.4 moveto 8 f4 (02.5) show\n");
  fprintf(fp," 260.0 600.4 moveto 7 f4 ( 29868   65431) show\n");
  fprintf(fp," 170.0 590.8 moveto 8 f5 (11) show\n");
  fprintf(fp," 188.0 590.8 moveto 8 f4 (    ) show\n");
  fprintf(fp," 216.0 590.8 moveto 8 f4 (04) show\n");
  fprintf(fp," 230.0 590.8 moveto 8 f4 (02.8) show\n");
  fprintf(fp," 260.0 590.8 moveto 7 f4 ( 29872   65435) show\n");
  fprintf(fp," 170.0 571.6 moveto 8 f5 (12) show\n");
  fprintf(fp," 188.0 571.6 moveto 8 f4 (16.2) show\n");
  fprintf(fp," 216.0 571.6 moveto 8 f4 (04) show\n");
  fprintf(fp," 230.0 571.6 moveto 8 f4 (03.0) show\n");
  fprintf(fp," 260.0 571.6 moveto 7 f4 ( 29877   65440) show\n");
  fprintf(fp," 170.0 562.0 moveto 8 f5 (13) show\n");
  fprintf(fp," 188.0 562.0 moveto 8 f4 (    ) show\n");
  fprintf(fp," 216.0 562.0 moveto 8 f4 (04) show\n");
  fprintf(fp," 230.0 562.0 moveto 8 f4 (03.2) show\n");
  fprintf(fp," 260.0 562.0 moveto 7 f4 ( 29881   65444) show\n");
  fprintf(fp," 170.0 552.4 moveto 8 f5 (14) show\n");
  fprintf(fp," 188.0 552.4 moveto 8 f4 (    ) show\n");
  fprintf(fp," 216.0 552.4 moveto 8 f4 (04) show\n");
  fprintf(fp," 230.0 552.4 moveto 8 f4 (03.5) show\n");
  fprintf(fp," 260.0 552.4 moveto 7 f4 ( 29886   65449) show\n");
  fprintf(fp," 188.0 542.8 moveto 8 f4 (...) show\n");
  fprintf(fp,"grestore\n");

  y-=27.0*yincr;
  fprintf(fp,"  0 %.1f moveto 10 f0 (The table is entered with a  Min:Sec combination.) show\n",y);
  fprintf(fp,"480 %.1f moveto 10 f0 (For each of these combinations, the following data values) Rshow\n",y);
  y-=yincr;
  fprintf(fp,"  0 %.1f moveto 10 f0 (are compiled:) show\n",y);
  y-=yincr;
  y-=yincr;
  fprintf(fp,"  6 %.1f moveto 10 f1 (fMin) show\n",y);
  fprintf(fp," 40 %.1f moveto 10 f0 (is the decimal (fractional) representation in minutes of the  Min:Sec  combination.) show\n",y);
  fprintf(fp,"480 %.1f moveto 10 f0 (These values are) Rshow\n",y);
  y-=yincr;
  fprintf(fp," 40 %.1f moveto 10 f0 (recorded only for each 6th Second entry.) show\n",y);
  fprintf(fp,"480 %.1f moveto 10 f0 (For the other seconds, the nearest value of fMin should be) Rshow\n",y);
  y-=yincr;
  fprintf(fp," 40 %.1f moveto 10 f0 (chosen.) show\n",y);
  y-=yincr;
  y-=yincr;
  fprintf(fp,"  6 %.1f moveto 10 f1 (dHA) show\n",y);
  fprintf(fp," 40 %.1f moveto 10 f0 (is the value of the increase of the  Hour Angle,) show\n",y);
  fprintf(fp,"480 %.1f moveto 10 f0 (interpolated according to the  Min:Sec  combination.) Rshow\n",y);
  y-=yincr;
  fprintf(fp," 40 %.1f moveto 10 f0 (This  is  calculated  as  follows:     dHA = 15\\260 * 3600 / \\(60*Min + Sec\\).) show\n",y);
  fprintf(fp,"480 %.1f moveto 10 f0 (The  result  is  expressed  in) Rshow\n",y);
  y-=yincr;
  fprintf(fp," 40 %.1f moveto 10 f0 (degrees \\(\\260\\)  and fractional minutes \\('\\).) show\n",y);
  y-=yincr;
  y-=yincr;
  fprintf(fp,"  6 %.1f moveto 10 f1 (p) show\n",y);
  fprintf(fp," 40 %.1f moveto 10 f0 (is the logarithm of the hour fraction expressed in seconds: 10000*log   \\(60*Min + Sec\\).) show\n",y);
  fprintf(fp,"476 %.1f moveto 10 f0 (The multi-) Rshow\n",y);
  fprintf(fp,"344 %.1f moveto  7 f0 (10) show\n",y-3.0);
  y-=yincr;
  fprintf(fp," 40 %.1f moveto 10 f0 (plication factor of  10000  as well as  the  scaling  on  Seconds,) show\n",y);
  fprintf(fp,"476 %.1f moveto 10 f0 (is used  to obtain  positive integral) Rshow\n",y);
  y-=yincr;
  fprintf(fp," 40 %.1f moveto 10 f0 (numbers for the logarithmic representations. This simplifies the calculations.) show\n",y);
  y-=yincr;
  y-=yincr;
  fprintf(fp,"  6 %.1f moveto 10 f1 (s) show\n",y);
  fprintf(fp," 40 %.1f moveto 10 f0 (is  the  logarithm  of  the  hour fraction  expressed in  seconds  and) show\n",y);
  fprintf(fp,"480 %.1f moveto 10 f0 (additionally  multiplied with  60:) Rshow\n",y);
  y-=yincr;
  fprintf(fp," 40 %.1f moveto 10 f0 (10000*log   \\(60*\\(60*Min + Sec\\)\\).) show\n",y);
  fprintf(fp," 84 %.1f moveto  7 f0 (10) show\n",y-3.0);
  fprintf(fp,"480 %.1f moveto 10 f0 (This value is used  for the backward transformation  to obtain the) Rshow\n",y);
  y-=yincr;
  fprintf(fp," 40 %.1f moveto 10 f0 (final interpolation result \\(taken from the nearest value in the \"fMin\" column\\).) show\n",y);

  fprintf(fp,"showpage\n");

  *page = (*page)+1;

  return;
}



/* -------------------------------------------------------------------------------------------------------------------------- */
void PrintUsage(FILE *fp, int *page)

{ double y,yincr;


  fprintf(fp,"%%%%Page: %d %d\n",*page,*page);

  fprintf(fp,"gsave 0.7 setlinewidth\n");
  fprintf(fp,"58 30 translate\n");

  fprintf(fp,"0 748.0 moveto 14 f1 (Use and Application of the Interpolation Tables) show\n");

  y=714.0;
  yincr=12.0;
  fprintf(fp,"  0 %.1f moveto 10 f0 (The tables presented here are designed for solving the following two problems:) show\n",y);
  y-=yincr;
  y-=yincr;
  fprintf(fp," 12 %.1f moveto 10 f0 (1.) Rshow\n",y);
  fprintf(fp," 14 %.1f moveto 10 f0 (Find the principe interpolation correction for the GHA of a celestial object) show\n",y);
  fprintf(fp,"480 %.1f moveto 10 f0 (for a given time of observation. ) Rshow\n",y);
  y-=yincr;
  y-=yincr;
  fprintf(fp," 12 %.1f moveto 10 f0 (2.) Rshow\n",y);
  fprintf(fp," 14 %.1f moveto 10 f0 (Given  a  fraction  of  the  hour \\(or degree\\)  and  given  an  increment) show\n",y);
  fprintf(fp,"480 %.1f moveto 10 f0 (of  a  value  over  an  integral  hour) Rshow\n",y);
  y-=yincr;
  fprintf(fp," 14 %.1f moveto 10 f0 (\\(or degree\\) interval,  find  the  fraction  of  the increment) show\n",y);
  fprintf(fp,"480 %.1f moveto 10 f0 (corresponding  to  the given  fraction  of the hour) Rshow\n",y);
  y-=yincr;
  fprintf(fp," 14 %.1f moveto 10 f0 (\\(or the given fraction of a degree\\).) show\n",y);
  y-=yincr;
  y-=yincr;
  y-=yincr;
  fprintf(fp,"  0 %.1f moveto 10 f0 (The first problem,  finding  the  interpolated  Hour Angle of a celestial) show\n",y);
  fprintf(fp,"480 %.1f moveto 10 f0 (body according to a fraction of the hour) Rshow\n",y);
  y-=yincr;
  fprintf(fp,"  0 %.1f moveto 10 f0 (\\(obtained from the time of observation\\), is directly implemented) show\n",y);
  fprintf(fp,"480 %.1f moveto 10 f0 (in the Interpolation Tables. The result for any) Rshow\n",y);
  y-=yincr;
  fprintf(fp,"  0 %.1f moveto 10 f0 (fraction of the hour can be read directly from the data column \"dHA\".) show\n",y);
  y-=yincr;
  y-=yincr;
  fprintf(fp,"  0 %.1f moveto 10 f0 (The second problem  is the typical (linear) interpolation  problem  of determining) show\n",y);
  fprintf(fp,"480 %.1f moveto 10 f0 (a  new data pair  from  two) Rshow\n",y);
  y-=yincr;
  fprintf(fp,"  0 %.1f moveto 10 f0 (known pairs  of values.) show\n",y);
  y-=yincr;
  y-=yincr;
  fprintf(fp,"  0 %.1f moveto 10 f0 (For this problem the logaritmic tables are used with the following calculation scheme:) show\n",y);

  fprintf(fp,"gsave\n");
  fprintf(fp,"0 -40 translate\n");
  fprintf(fp,"%%%%0.1 setlinewidth\n");
  fprintf(fp,"0.0 setgray\n");
  fprintf(fp,"newpath 0 546.0 moveto 480 0 rlineto 0 -110 rlineto -480 0 rlineto closepath stroke\n");
  fprintf(fp,"3.5 521.1 moveto 10 f4 (                 d   ____'__    -->  p\\(d\\)   ___________ ) show\n");
  fprintf(fp,"3.5 500.1 moveto 10 f4 ( f  ___m __s     f   ____'__    -->  p\\(f\\)   ___________ ) show\n");
  fprintf(fp,"3.5 479.1 moveto 10 f4 (                                           ______________) show\n");
  fprintf(fp,"3.5 458.1 moveto 10 f4 (          c=d*f/60   ____'__    <--  s\\( \\)   ___________ ) show\n");
  fprintf(fp,"grestore\n");

  y-=12*yincr;
  fprintf(fp,"  0 %.1f moveto 10 f0 (Where p\\(\\) and s\\(\\) stand for the p and s values as recorded in the Tables.) show\n",y);
  y-=yincr;
  y-=yincr;
  fprintf(fp,"  0 %.1f moveto 10 f0 (In the first line the increment/decrement for one hour interval \\(Nautical Almanac\\) or) show\n",y);
  fprintf(fp,"480 %.1f moveto 10 f0 (one degree of declination) Rshow\n",y);
  y-=yincr;
  fprintf(fp,"  0 %.1f moveto 10 f0 (\\(Sight Reduction Tables\\)  is  recorded \\(\"d\"\\).) show\n",y);
  fprintf(fp,"480 %.1f moveto 10 f0 (In both,  the Nautical Almanac  and  the Sight Reduction Tables) Rshow\n",y);
  y-=yincr;
  fprintf(fp,"  0 %.1f moveto 10 f0 (this increment/decrement is given in decimal minutes.) show\n",y);
  y-=yincr;
  y-=yincr;
  fprintf(fp,"  0 %.1f moveto 10 f0 (In the second line the fraction of the hour or degree is entered as Minutes / Seconds) show\n",y);
  fprintf(fp,"480 %.1f moveto 10 f0 (combination in the first) Rshow\n",y);
  y-=yincr;
  fprintf(fp,"  0 %.1f moveto 10 f0 (column \\(\"m\",\"s\"\\) or in decimal minutes \\(less accurate\\) in the second column \\(\"f\"\\).) show\n",y);
  y-=yincr;
  y-=yincr;
  fprintf(fp,"  0 %.1f moveto 10 f0 (Both \"d\" and \"f\" are converted to \"log(d)\" and \"log(f)\" using the \"p\" column of) show\n",y);
  fprintf(fp,"480 %.1f moveto 10 f0 (the Interpolation Tables.  Then) Rshow\n",y);
  y-=yincr;
  fprintf(fp,"  0 %.1f moveto 10 f0 (both  logarithmic values  are added.  Finally, the resulting logarithmic value is) show\n",y);
  fprintf(fp,"480 %.1f moveto 10 f0 (converted back to the fraction) Rshow\n",y);
  y-=yincr;
  fprintf(fp,"  0 %.1f moveto 10 f0 (\"c=d*f/60\" expressed in minutes or minutes of arc, using the \"s\" data column of the Interpolation Tables.) show\n",y);
  y-=yincr;
  y-=yincr;
  fprintf(fp,"  0 %.1f moveto 10 f0 (NOTICE:) show\n",y);
  y-=yincr;
  fprintf(fp,"  0 %.1f moveto 10 f0 (The increment/decrement value \"d\" has an algebraic sign.) show\n",y);
  fprintf(fp,"480 %.1f moveto 10 f0 (This sign  is disregarded  in the logarithmic part of) Rshow\n",y);
  y-=yincr;
  fprintf(fp,"  0 %.1f moveto 10 f0 (the calculation. At the end of the calculation scheme, the sign of \"d\" is assigned to the result \"c\".) show\n",y);
  y-=yincr;
  fprintf(fp,"  0 %.1f moveto 10 f0 (The fraction value \"f\" is always positive.) show\n",y);


  fprintf(fp,"grestore\n");
  fprintf(fp,"showpage\n");

  *page = (*page)+1;

  return;
}





/* -------------------------------------------------------------------------------------------------------------------------- */
void PrintExamples(FILE *fp, int *page)

{ double y,yincr;

  y=714.0;
  yincr=12.0;

  fprintf(fp,"%%%%Page: %d %d\n",*page,*page);
  fprintf(fp,"0.7 setlinewidth\n");
  fprintf(fp,"58 30 translate\n");

  /* EXAMPLE 1 */
  fprintf(fp,"0 748.0 moveto 10 f1 (Example 1) show\n");
  fprintf(fp,"  0 %.1f moveto 10 f0 (From  the  Nautical Almanac,  the  increase  of  Declination  for  the next) show\n",y);
  fprintf(fp,"480 %.1f moveto 10 f0 (hour interval  is  given as  d=+44.3') Rshow\n",y);
  y-=yincr;
  fprintf(fp,"  0 %.1f moveto 10 f0 (and the  fraction of the hour  is  f=\\(34m 56s\\).) show\n",y);
  y-=yincr;
  y-=yincr;
  fprintf(fp,"  0 %.1f moveto 10 f0 (With an electronic calculator the increment of Declination for the hour fraction of 34m 56s would yield: ) show\n",y);

  fprintf(fp,"gsave\n");
  fprintf(fp,"0 530 translate\n");
  fprintf(fp,"newpath 0 140.0 moveto 480 0 rlineto 0 -30 rlineto -480 0 rlineto closepath stroke\n");
  fprintf(fp,"0.0 setgray\n");
  fprintf(fp,"3.5 120.0 moveto 10 f4 (  c= \\(44.3\\) * \\(34 + 56/60\\) / 60 = ) show\n");
  fprintf(fp,"207.5 120.0 moveto 10 f5 (25.8) show\n");
  fprintf(fp,"grestore\n");

  y-=6.0*yincr;
  fprintf(fp,"  0 %.1f moveto 10 f0 (Using the Interpolation Tables the calculation scheme would be as follows: ) show\n",y);

  fprintf(fp,"gsave\n");
  fprintf(fp,"0.0 -160.0 translate\n");
  fprintf(fp,"newpath 0 756.8 moveto 480 0 rlineto 0 -110 rlineto -480 0 rlineto closepath stroke\n");
  fprintf(fp,"0.0 setgray\n");
  fprintf(fp,"3.5 731.9 moveto 10 f4 (                 d    +44'3     -->  p\\(d\\)   34246   ) show\n");
  fprintf(fp,"3.5 713.0 moveto 10 f4 ( f   34m 56s     f   ____'__    -->  p\\(f\\)   33214   ) show\n");
  fprintf(fp,"3.5 702.5 moveto 10 f4 (                                          _________) show\n");
  fprintf(fp,"3.5 681.5 moveto 10 f4 (          c=d*f/60     ) show\n");
  fprintf(fp,"136.5 681.5 moveto 10 f5 (+25'8) show\n");
  fprintf(fp,"165.5 681.5 moveto 10 f4 (     <--  s\\(c\\)   67460   ) show\n");
  fprintf(fp,"324.5 731.9 moveto 8 f4 (from the 44Min page: 18Sec line ) show\n");
  fprintf(fp,"324.5 713.0 moveto 8 f4 (from the 34Min page: 56Sec line ) show\n");
  fprintf(fp,"324.5 681.5 moveto 8 f4 (from the 25Min page: 48Sec line ) show\n");
  fprintf(fp,"grestore\n");

  y-=12*yincr;
  fprintf(fp,"  0 %.1f moveto 10 f0 (Since  the  increment \"d\"  for the  hour interval  is positive,) show\n",y);
  fprintf(fp,"480 %.1f moveto 10 f0 (also the  resulting  fractional  increase  \"c\" for the) Rshow\n",y);
  y-=yincr;
  fprintf(fp,"  0 %.1f moveto 10 f0 (Declination is positive.) show\n",y);


  /* EXAMPLE 2 */
  y-=5.0*yincr;
  fprintf(fp,"0 %.1f moveto 10 f1 (Example 2) show\n",y-10.0);
  y-=2.0*yincr;
  fprintf(fp,"  0 %.1f moveto 10 f0 (From Sight-Reduction Tables  the increase of  Altitude \\(Hc\\)) show\n",y);
  fprintf(fp,"480 %.1f moveto 10 f0 (for the next Declination interval of one degree is) Rshow\n",y);
  y-=yincr;
  fprintf(fp,"  0 %.1f moveto 10 f0 (obtained as d=-16.2' and the required fraction of the Declination is f=\\(24.8'\\).) show\n",y);
  y-=yincr;
  y-=yincr;
  fprintf(fp,"  0 %.1f moveto 10 f0 (With an electronic calculator the increment of Altitude for the Declination fraction of 24.8' would yield: ) show\n",y);

  fprintf(fp,"gsave\n");
  fprintf(fp,"0 180 translate\n");
  fprintf(fp,"newpath 0 140.0 moveto 480 0 rlineto 0 -30 rlineto -480 0 rlineto closepath stroke\n");
  fprintf(fp,"0.0 setgray\n");
  fprintf(fp,"3.5 120.0 moveto 10 f4 (  c= \\(-16.2\\) * \\(24.8\\) / 60 = ) show\n");
  fprintf(fp,"207.5 120.0 moveto 10 f5 (-06.7) show\n");
  fprintf(fp,"grestore\n");

  y-=6.0*yincr;
  fprintf(fp,"  0 %.1f moveto 10 f0 (Using the Interpolation Tables the calculation scheme would be as follows: ) show\n",y);

  fprintf(fp,"gsave\n");
  fprintf(fp,"0.0 -506.0 translate\n");
  fprintf(fp,"newpath 0 756.8 moveto 480 0 rlineto 0 -110 rlineto -480 0 rlineto closepath stroke\n");
  fprintf(fp,"0.0 setgray\n");
  fprintf(fp,"3.5 731.9 moveto 10 f4 (                 d    -16'2     -->  p\\(d\\)   29876   ) show\n");
  fprintf(fp,"3.5 713.0 moveto 10 f4 ( f   __m __s     f     24'8     -->  p\\(f\\)   31726   ) show\n");
  fprintf(fp,"3.5 702.5 moveto 10 f4 (                                          _________) show\n");
  fprintf(fp,"3.5 681.5 moveto 10 f4 (          c=d*f/60     ) show\n");
  fprintf(fp,"136.5 681.5 moveto 10 f5 (-06'7) show\n");
  fprintf(fp,"165.5 681.5 moveto 10 f4 (     <--  s\\(c\\)   61602   ) show\n");
  fprintf(fp,"324.5 731.9 moveto 8 f4 (from the 16Min page: 12Sec line ) show\n");
  fprintf(fp,"324.5 713.0 moveto 8 f4 (from the 24Min page: 48Sec line ) show\n");
  fprintf(fp,"324.5 681.5 moveto 8 f4 (from the 06Min page: 42Sec line ) show\n");
  fprintf(fp,"grestore\n");

  y-=12*yincr;
  fprintf(fp,"  0 %.1f moveto 10 f0 (Since the increment \"d\" for the Declination interval is negative,) show\n",y);
  fprintf(fp,"480 %.1f moveto 10 f0 (also the resulting fractional increase \"c\" of the) Rshow\n",y);
  y-=yincr;
  fprintf(fp,"  0 %.1f moveto 10 f0 (Altitude is negative.) show\n",y);

  fprintf(fp,"showpage\n");

  *page = (*page)+1;

  return;
}




/* -------------------------------------------------------------------------------------------------------------------------- */
void PrintTimeHAPurpose(FILE *fp, int *page)

{ double y,yincr;


  y=714.0;
  yincr=12.0;


  fprintf(fp,"%%%%Page: %d %d\n",*page,*page);
  fprintf(fp,"54 0 translate\n");
  fprintf(fp,"  0.0 422.5 moveto 18 f1 (Time - Hour-Angle Conversion Table) show\n");
  fprintf(fp,"showpage\n");
  *page = (*page)+1;


  fprintf(fp,"%%%%Page: %d %d\n",*page,*page);
  fprintf(fp,"0.7 setlinewidth\n");
  fprintf(fp,"58 30 translate\n");

  fprintf(fp,"0 748.0 moveto 14 f1 (Purpose and Arrangement) show\n");
  fprintf(fp,"  0 %.1f moveto 10 f0 (Longitude as part of our geographical coordinate system may be given both as) show\n",y);
  y-=yincr;  
  fprintf(fp,"newpath 10 %.1f 1.5 0.0 360.0 arc fill\n",y+yincr/4.0);
  fprintf(fp," 16 %.1f moveto 10 f0 (the intersecting angle  between  the Local Meridian  and  the Prime Meridian  of Greenwich) show\n",y);
  fprintf(fp,"480 %.1f moveto 10 f0 (expressed  in) Rshow\n",y);
  y-=yincr;
  fprintf(fp," 16 %.1f moveto 10 f0 (Degrees and Minutes-of-Arc,) show\n",y);
  fprintf(fp,"480 %.1f moveto 10 f0 () Rshow\n",y);
  y-=yincr;
  fprintf(fp,"newpath 10 %.1f 1.5 0.0 360.0 arc fill\n",y+yincr/4.0);
  fprintf(fp," 16 %.1f moveto 10 f0 (or  as  a  time  difference  between  the  Local Time  and  the Time  at  the  Prime Meridian) show\n",y);
  fprintf(fp,"480 %.1f moveto 10 f0 (of  Greenwich) Rshow\n",y);
  y-=yincr;
  fprintf(fp," 16 %.1f moveto 10 f0 (expressed in Hours, Minutes and Seconds.) show\n",y);
  fprintf(fp,"480 %.1f moveto 10 f0 () Rshow\n",y);
  y-=2.0*yincr;
  fprintf(fp,"  0 %.1f moveto 10 f0 (Time is related to the rotation of the Earth.) show\n",y);
  fprintf(fp,"480 %.1f moveto 10 f0 (Over the time span of 24 hours, the Greenwich Hour Angle of the) Rshow\n",y);
  y-=yincr;
  fprintf(fp,"  0 %.1f moveto 10 f0 (Sun increases by 360\\260.  This implies  an increase of 15\\260  per hour.) show\n",y);
  fprintf(fp,"480 %.1f moveto 10 f0 (Since local time  is based on mean solar) Rshow\n",y);
  y-=yincr;
  fprintf(fp,"  0 %.1f moveto 10 f0 (time,  locations with a Longitude difference of 15\\260, will have a difference in \\(local\\) time of exactly one hour.) show\n",y);
  fprintf(fp,"480 %.1f moveto 10 f0 () Rshow\n",y);
  y-=2.0*yincr;
  fprintf(fp,"  0 %.1f moveto 10 f0 (This relation  between Time  and  Longitude  allows  to translate  differences) show\n",y);
  fprintf(fp,"480 %.1f moveto 10 f0 (in local time  into  differences of) Rshow\n",y);
  y-=yincr;
  fprintf(fp,"  0 %.1f moveto 10 f0 (Longitude and vice versa.   The \"Time - Hour-Angle Conversion Table\") show\n",y);
  fprintf(fp,"480 %.1f moveto 10 f0 (gives this relation for integral values) Rshow\n",y);
  y-=yincr;
  fprintf(fp,"  0 %.1f moveto 10 f0 (of the Hour-Angle. Accordingly Time is given in 4-minute intervals.) show\n",y);
  fprintf(fp,"480 %.1f moveto 10 f0 (The information for the fractional values of) Rshow\n",y);
  y-=yincr;
  fprintf(fp,"  0 %.1f moveto 10 f0 (Time and Hour-Angle can be obtained from the first part of the) show\n",y);
  fprintf(fp,"480 %.1f moveto 10 f0 (\\(pages \"0Min\"-\"3Min\"\\).) Rshow\n",y);
  fprintf(fp,"280 %.1f moveto 10 f1 (Interpolation Tables) show\n",y);
  y-=yincr;
  fprintf(fp,"  0 %.1f moveto 10 f0 (The column  \"dHA\"  of these pages  gives  the increment of the Hour-Angle of the Sun,) show\n",y);
  fprintf(fp,"480 %.1f moveto 10 f0 (corresponding  to the) Rshow\n",y);
  y-=yincr;
  fprintf(fp,"  0 %.1f moveto 10 f0 (Time entry.) show\n",y);
  fprintf(fp,"480 %.1f moveto 10 f0 () Rshow\n",y);
  y-=yincr;


  fprintf(fp,"showpage\n");

  *page = (*page)+1;

  return;
}






/* -------------------------------------------------------------------------------------------------------------------------- */
/* PrintTimeHA() generates the Postscript code for the translation between Time and GHA on a "DIN A4" printer format.
 * Postscript uses a coordinate system that is device independent, that is, it doesn't rely on the resolution,
 * paper size, etc of the final output device. The initial coordinate system has the x axis to the right and
 * y axis upwards, the origin is located at the bottom left hand corner of the page. The units are of "points",
 * which are 1/72 of an inch long. The size of "DIN A4" paper is (210 × 297 mm) or (8.3 × 11.7 inch). In Postscript
 * points the size is approximately (596 x 824 points)!
 *
 * Here are the basic frame lines and their coordinates (without initial translate!):
 *
 *   800      +---------+--------+----------+ 
 *            |         |        |          |
 *   770      |---------+--------+----------|
 *            |         |        |          |
 *            |         |        |          |
 *            |         |        |          |
 *            |         |        |          |
 *            |         |        |          |
 *            |         |        |          |
 *            |         |        |          |
 *            |         |        |          |
 *            |         |        |          |
 *            |         |        |          |
 *            |         |        |          |
 *    24      +---------+--------+----------+
 *            0         1        3          5
 *            0         8        6          4
 *            0         0        0          0
 */
  



/* -------------------------------------------------------------------------------------------------------------------------- */
void PrintTimeHA(FILE *fp, int *page)

{ int    i,j,hh,mm;
  double col_width,y;
  char   hstr[4];
  char   mstr[4];

  fprintf(fp,"%%%%Page: %d %d\n",*page,*page);

  fprintf(fp,"0.5 setlinewidth\n");
  fprintf(fp,"30 20 translate\n");
/*
  fprintf(fp,"newpath 0 0 moveto 540 0 lineto 540 800 lineto 0 800 lineto closepath stroke\n");
 */
  fprintf(fp,"0 780.0 moveto 14 f1 (Time - Hour-Angle Conversion) show\n");

  col_width= 90.0;

  for(i=0; i<6; i++)
  { fprintf(fp,"newpath %.1f 750.0 moveto %.1f 0.0 rlineto 0.0 -726.0 rlineto -%.1f 0.0 rlineto closepath stroke\n",i*col_width, col_width, col_width);

    y=734.0;

    for(j=0; j<60; j++)
    { mm=(i*60+j)*4;
      hh=mm/60;
      sprintf(hstr,"%02d",hh);
      
      mm=mm%60;
      sprintf(mstr,"%02d",mm);
      
      fprintf(fp," %.1f %.1f moveto 9 f5 (%s:%s) show\n",10.0+i*col_width,y,hstr,mstr);
      fprintf(fp," %.1f %.1f moveto 9 f4 (%3d\\260) Rshow\n",78.0+i*col_width,y,i*60+j);

      y-=11.0;
      if(!((j+1)%6)) y-=5.5;
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
/* PrintTablePage() generates the Postscript code for the individual interpolation pages on a "DIN A4" printer format.
 * Postscript uses a coordinate system that is device independent, that is, it doesn't rely on the resolution,
 * paper size, etc of the final output device. The initial coordinate system has the x axis to the right and
 * y axis upwards, the origin is located at the bottom left hand corner of the page. The units are of "points",
 * which are 1/72 of an inch long. The size of "DIN A4" paper is (210 × 297 mm) or (8.3 × 11.7 inch). In Postscript
 * points the size is approximately (596 x 824 points)!
 *
 * Here are the basic frame lines and their coordinates (without initial translate!):
 *
 *   800      +---------+--------+----------+ 
 *            |         |        |          |
 *   770      |---------+--------+----------|
 *            |         |        |          |
 *            |         |        |          |
 *            |         |        |          |
 *            |         |        |          |
 *            |         |        |          |
 *            |         |        |          |
 *            |         |        |          |
 *            |         |        |          |
 *            |         |        |          |
 *            |         |        |          |
 *            |         |        |          |
 *    24      +---------+--------+----------+
 *            0         1        3          5
 *            0         8        6          4
 *            0         0        0          0
 */
  


void PrintTablePage(FILE *fp, int min_start, int *page)

{ int    i,j,mf,cf,min,sec;
  double x,y,grd,mn,min_f;
  double col_width=180.0;
  double x_offset_1= 18.0;
  double x_offset_2= 50.0;
  double x_offset_3=104.0;


  fprintf(fp,"%%%%Page: %d %d\n",*page,*page);

  fprintf(fp,"30 20 translate\n");
  fprintf(fp,"0.5 setlinewidth\n");
  /* for debugging: print the "boundary frame" (0,0) to (540,800) within which the page will be formatted ... */
  /*
  fprintf(fp,"newpath 0 0 moveto 540 0 lineto 540 800 lineto 0 800 lineto closepath stroke\n");
   */


  for(i=0; i<3; i++)
  { min = min_start+i;       /* "min" is current integral minutes value;  "i" ist the column number */

                             /* print the frame with header space and 3 columns                     */
    fprintf(fp," %.1f 800.0 moveto %.1f 0.0 rlineto 0 -776.0 rlineto -%.1f 0.0 rlineto closepath stroke\n",(double)i*col_width,col_width,col_width);
    fprintf(fp," %.1f 770.0 moveto %.1f 0.0 rlineto stroke\n",(double)i*col_width,col_width);
    fprintf(fp," %.1f 770.0 moveto 0 -746.0 rlineto stroke\n",(double)i*col_width+104.0);

    fprintf(fp," %.1f 780.0 moveto 14 f1 (%02d) Rshow\n",(double)i*col_width+col_width/2.0,min);
    fprintf(fp," %.1f 780.0 moveto 12 f1 (Min) show\n",(double)i*col_width+col_width/2.0+4.0);

    fprintf(fp," %.1f 758.0 moveto  9 f1 (Sec) show\n",(double)i*col_width+4.0);
    fprintf(fp," %.1f 758.0 moveto  9 f1 (fMin) show\n",(double)i*col_width+x_offset_1+10.0);
    fprintf(fp," %.1f 758.0 moveto  9 f1 (dHA) show\n",(double)i*col_width+x_offset_2+10.0);
    fprintf(fp," %.1f 758.0 moveto  9 f1 (p) show\n",(double)i*col_width+x_offset_3+10.0);
    fprintf(fp," %.1f 758.0 moveto  9 f1 (s) show\n",(double)i*col_width+x_offset_3+42.0);

    fprintf(fp," %.1f 746.0 moveto  9 f4 (   ') show\n",(double)i*col_width+x_offset_1);
    fprintf(fp," %.1f 746.0 moveto  9 f4 (\\260   ') show\n",(double)i*col_width+x_offset_2+13.0);

    x=(double)i*col_width+8.0;
    y=734.0;
    for(sec=0; sec<60; sec++)
    { fprintf(fp," %.1f %.1f moveto 9 f5 (%02d) show\n",x,y,sec);

      /* the following is the fraction of minutes corresponding to the min/sec entry */
      min_f = (double)((min_start+i) * 60 + sec)/60.0;
      if((sec%6) == 0) fprintf(fp," %.1f %.1f moveto 9 f4 (%04.1f) show\n",x+x_offset_1,y,min_f);

      /* the following is dHA: the increment of GHA for the fraction of the hour */
      grd=((double)min+(double)sec/60.0)/4.0;
      mf=(int)floor(grd);
      mn=(grd-(double)mf)*60.0;
      fprintf(fp," %.1f %.1f moveto 9 f4 (%02d %04.1f) show\n",x+x_offset_2,y,mf,mn);
      
      if((min+sec)>0)
      { grd=log10(60.0*min+(double)sec);
        fprintf(fp," %.1f %.1f moveto 8 f4 (%05d  %05d) show\n",x+x_offset_3,y,(int)(10000.0*grd),(int)(10000.0*(grd+3.556302501)));
      }

      y-=11.0;
      if(!((sec+1)%6)) y-=5.5;
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
int main(int argc, char **argv)

{ int    i,j,min,sec,m,f;
  int    font,page;
  char   nam,sgn,Titl[64];

  char   filename[32];
  FILE  *fp;


  
  sprintf(filename,"Data/Interpol.ps");
  printf("\n Generating Interpolation Tables: \"%s\" ...\n\n",filename);

  if((fp=fopen(filename,"w"))==NULL)
  { printf(" Error (%s) could not open file \"%s\" for reading!\n",argv[0],filename);
    exit(-1);
  }
  
  printf("                     writing data file : \"%s\"\n",filename);

  page=2;
  PrintHeader(fp);
  InsertBlankPage(fp,&page);
  PrintWarning(fp,&page);
  InsertBlankPage(fp,&page);

  PrintPurpose(fp,&page);
  PrintArrangement(fp,&page);
  PrintUsage(fp,&page);
  PrintExamples(fp,&page);

  InsertBlankPage(fp,&page);

  for(min=0; min<60; min+=3) PrintTablePage(fp,min,&page);
  InsertBlankPage(fp,&page);
  InsertBlankPage(fp,&page);
  InsertBlankPage(fp,&page);
  
  PrintTimeHAPurpose(fp,&page);
  PrintTimeHA(fp,&page);
  InsertBlankPage(fp,&page);

  fprintf(fp,"%%%%EOF\n");
  fclose(fp);

  return 0;
}
