
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PI       3.141592654



/* ---------------------------------------------------------------------------------------------------------------------------------------- */
/* PrintFrame() generates the basic table elements for the Ageton Tables.
 * Postscript uses a coordinate system that is device independent, that is, it doesn't rely on the resolution,
 * paper size, etc of the final output device. The initial coordinate system has the x axis to the right and
 * y axis upwards, the origin is located at the bottom left hand corner of the page. The units are of "points",
 * which are 1/72 of an inch long. The size of "DIN A4" paper is (210 × 297 mm) or (8.3 × 11.7 inch). In Postscript
 * points the size is approximately (596 x 824 points)!
 *
 * Here are the basic frame lines and their coordinates (without initial translate!):
 *
 *   680      +-+----+----+----+----+----+----+-+    y_top
 *            | |    |    |    |    |    |    | |
 *   650      +-+----+----+----+----+----+----+-+    y_top - 28
 *            | |    |    |    |    |    |    | |
 *            | |    |    |    |    |    |    | |
 *            | |    |    |    |    |    |    | |
 *            | |    |    |    |    |    |    | |
 *    30      +-+----+----+----+----+----+----+-+    y_top - 312
 *            | |    |    |    |    |    |    | |
 *     0      +-+----+----+----+----+----+----+-+    y_top - 680      y_frame = 680
 *            0 0    1    1    2    3    4    5 5
 *            0 2    0    8    7    5    3    1 3
 *            0 7    8    9    0    1    2    3 8
 *                                                   x_offset = 40.5 
 */


void PrintFrame(FILE *fp, int a, double x_offset, double y_top, double y_offset, int *page)

{ int    d,i;
  double y,y_frame;

  fprintf(fp,"%%%%Page: %d %d\n\n",*page,*page);
  fprintf(fp,"%%%%BeginPageSetup\n");
  fprintf(fp,"30 20 translate\n");
  fprintf(fp,"%%%%EndPageSetup\n");
  fprintf(fp,"1.2 setlinewidth\n");
 
  y_frame = 712.0;
  fprintf(fp,"0.0 %.1f  moveto 538.0 0 rlineto 0 -%.1f rlineto -538.0 0 rlineto closepath stroke\n",y_top,y_frame);
  fprintf(fp,"0.0 %.1f  moveto 538.0 0 rlineto 0 -%.1f rlineto -538.0 0 rlineto closepath stroke\n",y_top - 30.0,y_frame - 60.0);

  /* plot the angled arrows ... */
  fprintf(fp," 21.0 %.1f moveto -10 0 rlineto 0 -12 rlineto stroke\n",y_top - 38.0);
  fprintf(fp," 11.0 %.1f moveto   2  6 rlineto -4 0 rlineto closepath fill\n",y_top - 50.0);
  fprintf(fp,"518.0 %.1f moveto  10 0 rlineto 0  12 rlineto stroke\n",y_top - y_frame + 38.0);
  fprintf(fp,"528.0 %.1f moveto   2 -6 rlineto -4 0 rlineto closepath fill\n",y_top - y_frame + 50.0);

  fprintf(fp,"0.7 setlinewidth\n");

  /* plot the integral angle values in the top/bottom headers ... */
  fprintf(fp," 269 %.1f  moveto 22 f1 (%d\\260) Cshow\n",y_top - 25.0,             a);
  fprintf(fp," 269 %.1f  moveto 22 f1 (%d\\260) Cshow\n",y_top - y_frame + 5.0,179-a);

  /* plot the frames ... */
  for(i=0; i<12; i++)
  { if((i%2)==0)
    { if(a < 3)                            /* grey-out the low-resolution parts of the tables */
      { fprintf(fp,"0.9 setgray\n");
        fprintf(fp,"%.1f %.1f moveto %.1f 0 rlineto 0 -%.1f rlineto -%.1f 0 rlineto closepath fill\n",27.0+(i+1)*x_offset,y_top-42.0,x_offset,y_frame-84.0,x_offset);
        fprintf(fp,"0.0 setgray\n");
      }
      if(a > 86)                           /* grey-out the low-resolution parts of the tables */
      { fprintf(fp,"0.9 setgray\n");
        fprintf(fp,"%.1f %.1f moveto %.1f 0 rlineto 0 -%.1f rlineto -%.1f 0 rlineto closepath fill\n",27.0+i*x_offset,y_top-42.0,x_offset,y_frame-84.0,x_offset);
        fprintf(fp,"0.0 setgray\n");
      }

      fprintf(fp,"%.1f %.1f moveto %.1f 0 rlineto 0 -%.1f rlineto -%.1f 0 rlineto closepath  stroke\n",27.0+i*x_offset,y_top - 30.0,2.0*x_offset,y_frame - 60.0,2.0*x_offset);
                                          /* plot the minutes and A/B lables ... */
      fprintf(fp,"%.1f %.1f moveto 10 f1 (%02d') Cshow\n",7.0+(i+1.5)*x_offset,y_top-        40.0,    i*5 );
      fprintf(fp,"%.1f %.1f moveto 10 f1 (%02d') Cshow\n",7.0+(i+1.5)*x_offset,y_top-y_frame+32.0,50-(i*5));

      fprintf(fp,"%.1f %.1f moveto  9 f1 (A\\(x\\)) Cshow\n",27.0+(i+0.5)*x_offset,y_top-        52.0,50.0-(i*5));
      fprintf(fp,"%.1f %.1f moveto  9 f1 (B\\(x\\)) Cshow\n",27.0+(i+1.5)*x_offset,y_top-        52.0,50.0-(i*5));
      fprintf(fp,"%.1f %.1f moveto  9 f1 (A\\(x\\)) Cshow\n",27.0+(i+0.5)*x_offset,y_top-y_frame+46.0,50.0-(i*5));
      fprintf(fp,"%.1f %.1f moveto  9 f1 (B\\(x\\)) Cshow\n",27.0+(i+1.5)*x_offset,y_top-y_frame+46.0,50.0-(i*5));
    }
    fprintf(fp,"%.1f %.1f moveto %.1f 0 rlineto 0 -%.1f rlineto -%.1f 0 rlineto closepath  stroke\n",27.0+i*x_offset,y_top-42.0,x_offset,y_frame-84.0,x_offset);
  }
  fprintf(fp," 27 %.1f  moveto 486.0 0 rlineto 0 -%.1f rlineto -486.0 0 rlineto closepath stroke\n",y_top-56.0,y_frame-112.0);

  /* plot the fractional minute values ... */
  y=y_top - 70.0;
  fprintf(fp,"9 f1\n");
  for(d=0; d<=50; d++)
  { fprintf(fp," 21.0 %.1f moveto (%04.1f) Rshow\n",y,     d/5.0);
    fprintf(fp,"518.0 %.1f moveto (%04.1f)  show\n",y,10.0-d/5.0);
    if((d%3)==2) y-=15.0; else y-=10.0;
  }

  fprintf(fp,"  0 10 moveto 6 f0 (Warning:) show\n");
  fprintf(fp," 30 10 moveto 6 f0 (This page has been generated by a computer program.  Complex computer programs usually have bugs and may produce wrong data.) show\n");
  fprintf(fp,"538 10 moveto 6 f0 (The data on this page is believed to be accurate but no) Rshow\n");
  fprintf(fp," 30  2 moveto 6 f0 (warranty is given for its correctness. Use it only for training and exercising! ) show\n");
 
  return;
} 


/* ---------------------------------------------------------------------------------------------------------------------------------------- */
void MakeTable(FILE *fp, int a, int *page)

{ int    d;
  double m,p,q,x,y;
  double x_offset=40.5;
  double y_offset=394.0;
  double y_top=762.0;

  PrintFrame(fp,a,x_offset,y_top,y_offset,page);

  fprintf(fp,"9 f4\n");          /* table info is plotted with 9-points font ... */

  for(m=0.0; m<60; m+=10.0)                   /* minutes range [0:59]            */
  { y=y_top - 70.0;
    x=64.0+m*x_offset/5.0;

    for(d=0; d<=50; d++)                      /* plot in 0.2 minutes per line */
    { p=(double)a+(m+d/5.0)/60.0;
                                              /* calculate the A(x) function */
      if(p>0.0)     
      { q=log10(1/sin(PI/180.0*p));
        fprintf(fp," %.1f %.1f moveto (%d) Rshow\n",x,y,(int)floor(100000.0*q+0.5));
      }
        else fprintf(fp," %.1f %.1f moveto (-) Rshow\n",x,y);

                                              /* calculate the B(x) function */
      if(p<90.0)
      { q=log10(1/cos(PI/180.0*p));
        fprintf(fp," %.1f %.1f moveto (%d) Rshow\n",x_offset+x,y,(int)floor(100000.0*q+0.5));
      }
        else fprintf(fp," %.1f %.1f moveto (-) Rshow\n",36.0+x,y);

      if((d%3)==2) y-=15.0; else y-=10.0;
    }
  }

  fprintf(fp,"showpage\n");

  *page = (*page)+1;

  return;
}



/* ---------------------------------------------------------------------------------------------------------------------------------------- */

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
  fprintf(fp,"250 214 moveto 32 f0 (Sight Reduction Tables) Cshow\n");
  fprintf(fp,"250 184 moveto 22 f0 (according to A. A. Ageton) Cshow\n");
  fprintf(fp,"showpage\n");

  return;
}



/* ---------------------------------------------------------------------------------------------------------------------------------------- */
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





/* ---------------------------------------------------------------------------------------------------------------------------------------- */
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
  fprintf(fp,"  0.0 422.5 moveto 18 f1 (Tables  for  performing  Sight Reduction  according  to) show\n");
  fprintf(fp,"  0.0 397.5 moveto 18 f1 (the Method developed by Arthur A. Ageton) show\n");
  fprintf(fp,"  0.0 196.5 moveto 10 f0 (Warning and Terms of Usage:) show\n");
  fprintf(fp,"  0.0 169.9 moveto 10 f0 (The  following  pages  have been generated  by a computer program.) show\n");
  fprintf(fp,"475.0 169.9 moveto 10 f0 (Complex computer programs usually) Rshow\n");
  fprintf(fp,"  0.0 156.6 moveto 10 f0 (have  bugs  and may  produce  wrong  data.) show\n");
  fprintf(fp,"475.0 156.6 moveto 10 f0 (The  data  in these  Tables  is believed to be  accurate  but no) Rshow\n");
  fprintf(fp,"  0.0 143.3 moveto 10 f0 (warranty  is given  for its correctness.) show\n");
  fprintf(fp,"  0.0 130.0 moveto 10 f0 (Use these Tables only for training and exercising!) show\n");
  fprintf(fp,"  0.0  90.1 moveto 10 f0 (Compiled by Erik De Man  \\(erik.de.man@freenet.de\\)  on %s) show\n",timestring);
  fprintf(fp,"grestore\n");
  fprintf(fp,"showpage\n");

  *page = (*page)+1;

  return;
}



/* ---------------------------------------------------------------------------------------------------------------------------------------- */
void PrintIntro1Page(FILE *fp, int *page)

{ double y,dy;

  dy=13.3;

  fprintf(fp,"%%%%Page: %d %d\n",*page,*page);
  fprintf(fp,"gsave 0.2 setlinewidth\n");
  fprintf(fp,"54 0 translate\n");
  fprintf(fp,"  0.0 744.1 moveto 18 f1 (Purpose and Scope) show\n");
  y=715.2;
  fprintf(fp,"  0.0 %.1f moveto 10 f0 (Sight Reduction is the process of  solving  the navigational triangle) show\n",y);
  fprintf(fp,"475.0 %.1f moveto 10 f0 (for an assumed position  of the observer) Rshow\n",y); y-=dy;
  fprintf(fp,"  0.0 %.1f moveto 10 f0 (and the position of an observed celestial object  in order to obtain) show\n",y);
  fprintf(fp,"475.0 %.1f moveto 10 f0 (a Line-of-Position.  In the beginning of the) Rshow\n",y); y-=dy;
  fprintf(fp,"  0.0 %.1f moveto 10 f0 (20th century,  Arthur A. Ageton developed a method of solving the oblique) show\n",y);
  fprintf(fp,"475.0 %.1f moveto 10 f0 (navigational triangle by dividing it) Rshow\n",y); y-=dy;
  fprintf(fp,"  0.0 %.1f moveto 10 f0 (into two right-angled spherical triangles, which can be solved with) show\n",y);
  fprintf(fp,"475.0 %.1f moveto 10 f0 (less complex trigonometric operations as) Rshow\n",y); y-=dy;
  fprintf(fp,"  0.0 %.1f moveto 10 f0 (compared to the computations required  to solve the oblique navigational triangle directly.) show\n",y);
  fprintf(fp,"475.0 %.1f moveto 10 f0 (Ageton's method) Rshow\n",y); y-=dy;
  fprintf(fp,"  0.0 %.1f moveto 10 f0 (for solving the right-angled  sperical triangles  is based on the  logarithmic form) show\n",y);
  fprintf(fp,"475.0 %.1f moveto 10 f0 (of the Cosecant and Secant) Rshow\n",y); y-=dy;
  fprintf(fp,"  0.0 %.1f moveto 10 f0 (functions \\(called \"A\" and \"B\" functions respectively\\).) show\n",y); y-=2.0*dy;
  fprintf(fp,"  0.0 %.1f moveto 10 f0 (The A\\(x\\) and B\\(x\\) functions tabulated on the following pages were calculated according to:) show\n",y); y-=dy;
  fprintf(fp,"  8.0 %.1f moveto 10 f2 (A\\(x\\) = 100 000 * log   \\( 1/ sin\\(x\\) \\) ) show\n",y);
  fprintf(fp," 96.0 %.1f moveto  6 f2 (10) show\n",y-3.0); y-=dy;
  fprintf(fp,"  8.0 %.1f moveto 10 f2 (B\\(x\\) = 100 000 * log   \\( 1/ cos\\(x\\) \\) ) show\n",y);
  fprintf(fp," 96.0 %.1f moveto  6 f2 (10) show\n",y-3.0); y-=2.0*dy;
  fprintf(fp,"  0.0 %.1f moveto 10 f0 (The  multiplication  factor  100 000  is  used  to  tabulate  the) show\n",y);
  fprintf(fp,"475.0 %.1f moveto 10 f0 (functions  with  integral  numbers,  simplifying) Rshow\n",y); y-=dy;
  fprintf(fp,"  0.0 %.1f moveto 10 f0 (artihmetic operations with these data values.) show\n",y); y-=2.0*dy;
  fprintf(fp,"  0.0 %.1f moveto 10 f0 (The tables  are organized in  90  subtables,  each of them) show\n",y);
  fprintf(fp,"475.0 %.1f moveto 10 f0 (containing the data of one degree interval. Since)  Rshow\n",y); y-=dy;
  fprintf(fp,"  0.0 %.1f moveto 10 f0 (the  logarithmic functions  A\\(x\\)  and  B\\(x\\)  can only  be) show\n",y);
  fprintf(fp,"475.0 %.1f moveto 10 f0 (used  for  positive values  for the  Sine  and  Cosine) Rshow\n",y); y-=dy;
  fprintf(fp,"  0.0 %.1f moveto 10 f0 (arguments,  the  table values  for the  supplementary angles) show\n",y);
  fprintf(fp,"475.0 %.1f moveto 10 f0 (x  and  180\\260-x  are  identical.  Therefore, each) Rshow\n",y); y-=dy;
  fprintf(fp,"  0.0 %.1f moveto 10 f0 (subtable entry is valid for two supplementary angle values.) show\n",y);
  fprintf(fp,"475.0 %.1f moveto 10 f0 (The angle values are plotted respectively on the) Rshow\n",y); y-=dy;
  fprintf(fp,"  0.0 %.1f moveto 10 f0 (top and bottom line  of each subtable.  If the top line argument) show\n",y);
  fprintf(fp,"475.0 %.1f moveto 10 f0 (is used  for the integral degree value, the  fist) Rshow\n",y); y-=dy;
  fprintf(fp,"  0.0 %.1f moveto 10 f0 (column  of  the  table  must  be  used  for  the  minutes  value.) show\n",y);
  fprintf(fp,"475.0 %.1f moveto 10 f0 (Similar,  the  last  column  must  be  used  in) Rshow\n",y); y-=dy;
  fprintf(fp,"  0.0 %.1f moveto 10 f0 (combination with the bottom line angle value.) show\n",y); y-=dy;
  fprintf(fp,"  0.0 %.1f moveto 10 f0 (The tables can be used to calculate the  Altitude \"Hc\" and Azimuth \"Zc\") show\n",y);
  fprintf(fp,"475.0 %.1f moveto 10 f0 (of a celestial object at an Assumed) Rshow\n",y); y-=dy;
  fprintf(fp,"  0.0 %.1f moveto 10 f0 (Position.  Using the Altitude-Intercept Method, the calculated Altitude \"Hc\") show\n",y);
  fprintf(fp,"475.0 %.1f moveto 10 f0 (and Azimuth \"Zc\" may be used to) Rshow\n",y); y-=dy;
  fprintf(fp,"  0.0 %.1f moveto 10 f0 (refine  the observer's position  by comparing  the calculated) show\n",y);
  fprintf(fp,"475.0 %.1f moveto 10 f0 (Altitude \"Hc\"  with  the observed Altitude \"Ho\",) Rshow\n",y); y-=dy;
  fprintf(fp,"  0.0 %.1f moveto 10 f0 (which is obtained by sextant measurements.) show\n",y); y-=3.0*dy;
  fprintf(fp,"  0.0 %.1f moveto 12 f1 (Note on Accuracy) show\n",y); y-=2.0*dy;
  fprintf(fp,"  0.0 %.1f moveto 10 f0 (The  resolution  of the  tabulated values  for the  A\\(x\\)  and  B\\(x\\)) show\n",y);
  fprintf(fp,"475.0 %.1f moveto 10 f0 (functions may be  insuffcient  in the ranges) Rshow\n",y); y-=dy;
  fprintf(fp,"  0.0 %.1f moveto 10 f0 ([0\\260-3\\260]  and  [87\\260-90\\260]  to obtain accurate results for the sight-reduction process.) show\n",y);
  fprintf(fp,"475.0 %.1f moveto 10 f0 (The involved table entries) Rshow\n",y); y-=dy;
  fprintf(fp,"  0.0 %.1f moveto 10 f0 (have been plotted on a grey-shaded background.) show\n",y); y-=dy;
  fprintf(fp,"  0.0 %.1f moveto 10 f0 (If these  table ranges  can be avoided  for the complete  sight-reduction process,) show\n",y);
  fprintf(fp,"475.0 %.1f moveto 10 f0 (the maximum error on the) Rshow\n",y); y-=dy;
  fprintf(fp,"  0.0 %.1f moveto 10 f0 (calculated Altitude \"Hc\" will be lower than \\2612.2' \\(2.2 minutes-of-arc\\)) show\n",y);
  fprintf(fp,"475.0 %.1f moveto 10 f0 (and lower than \\2610.3\\260 for the calculated) Rshow\n",y); y-=dy;
  fprintf(fp,"  0.0 %.1f moveto 10 f0 (Azimuth \"Zc\"  \\(provided also, the tables are used with appropriate interpolation\\).) show\n",y); y-=2.0*dy;
  fprintf(fp,"  0.0 %.1f moveto 10 f0 (For a detailed error analysis see:) show\n",y); 
  fprintf(fp,"150.0 %.1f moveto 10 f2 (\"http://www.erikdeman.de/\") show\n",y);
  fprintf(fp,"grestore\n");
  fprintf(fp,"showpage\n");

  *page = (*page)+1;
  
  fprintf(fp,"%%%%Page: %d %d\n",*page,*page);
  fprintf(fp,"gsave 0.2 setlinewidth\n");
  fprintf(fp,"54 0 translate\n");
  fprintf(fp,"  0.0 744.1 moveto 18 f1 (The divided Navigational Triangle) show\n");
  y=715.2;
  fprintf(fp,"  0.0 %.1f moveto 10 f0 (The general \\(oblique\\)  Navigational Triangle  between the  geographical North Pole \\(NP\\),) show\n",y);
  fprintf(fp,"475.0 %.1f moveto 10 f0 (the Geographical) Rshow\n",y); y-=dy;
  fprintf(fp,"  0.0 %.1f moveto 10 f0 (Point \\(GP\\) of the observed celestial object  and the  Assumed Position \\(AP\\)  of) show\n",y);
  fprintf(fp,"475.0 %.1f moveto 10 f0 (the observer can be divided) Rshow\n",y); y-=dy;
  fprintf(fp,"  0.0 %.1f moveto 10 f0 (in two right-angled triangles by a great-circle segment \"R\" starting in GP) show\n",y);
  fprintf(fp,"475.0 %.1f moveto 10 f0 (and intersecting the Meridian of AP) Rshow\n",y); y-=dy;
  fprintf(fp,"  0.0 %.1f moveto 10 f0 (at a right angle.  This defines a new triangle side \"R\" and a new) show\n",y);
  fprintf(fp,"475.0 %.1f moveto 10 f0 (triangle vertex point \"Q\". This point has the) Rshow\n",y); y-=dy;
  fprintf(fp,"  0.0 %.1f moveto 10 f0 (the same Longitude as AP and a Latitude \"LatQ\".) show\n",y);
  fprintf(fp,"475.0 %.1f moveto 10 f0 ( ) Rshow\n",y); y-=dy;
  y-=dy;
  fprintf(fp,"gsave\n");
  fprintf(fp,"120 %.1f translate 0.8 0.8 scale\n",y);
  fprintf(fp,"gsave\n");
  fprintf(fp,"-100 0 moveto 200 0 rlineto 0 -300 rlineto -200 0 rlineto closepath clip\n");
  fprintf(fp,"1.2 setlinewidth\n");
  fprintf(fp,"newpath  200.5 -220 300  90 180 arc stroke \n");
  fprintf(fp,"newpath -417.5 -280 500 270  90 arc stroke\n");
  fprintf(fp,"newpath  186  189 500 180 258 arc stroke\n");
  fprintf(fp,"gsave\n");
  fprintf(fp,"[8 4] 6 setdash\n");
  fprintf(fp,"newpath  -20  273 500 180 281.4 arc stroke\n");
  fprintf(fp,"grestore\n");
  fprintf(fp,"0.2 setlinewidth\n");
  fprintf(fp,"newpath -420.5 -280 500  7.6  9.2 arc stroke\n");
  fprintf(fp,"newpath -420.5 -280 500  5.1  6.7 arc stroke\n");
  fprintf(fp,"newpath  -20  276.5 500 279.4 281.0 arc stroke\n");
  fprintf(fp,"newpath  -20  269.7 500 279.5 281.1 arc stroke\n");
  fprintf(fp,"grestore\n");
  fprintf(fp,"gsave\n");
  fprintf(fp,"0.5 setgray\n");
  fprintf(fp,"newpath -3.3 0 40 227 300 arc stroke\n");
  fprintf(fp,"newpath  82 -293.3 40 175 88 arc stroke\n");
  fprintf(fp,"-19 -56 moveto 14 f1 (t) show\n");
  fprintf(fp,"-10 -54 moveto 10 f0 (\\(-\\)) show\n");
  fprintf(fp,"64 -320 moveto 14 f1 (Zc) show\n");
  fprintf(fp,"42.2 -289.8 translate\n");
  fprintf(fp,"275 rotate\n");
  fprintf(fp,"0 0 moveto 12 -4 rlineto 0 8 rlineto closepath fill\n");
  fprintf(fp,"grestore\n");
  fprintf(fp,"gsave\n");
  fprintf(fp,"60 -164 translate\n");
  fprintf(fp,"110 rotate\n");
  fprintf(fp,"0 0 moveto 14 f0 (90\\260-LatQ) show\n");
  fprintf(fp,"-8 rotate\n");
  fprintf(fp,"-40 -28 moveto 14 f0 (90\260-LatAP) show\n");
  fprintf(fp,"grestore\n");
  fprintf(fp,"gsave\n");
  fprintf(fp,"-70 -164 translate\n");
  fprintf(fp,"80 rotate\n");
  fprintf(fp,"0 0 moveto 14 f0 (90\\260-Dec) show\n");
  fprintf(fp,"grestore\n");
  fprintf(fp,"gsave\n");
  fprintf(fp,"76 -274 translate\n");
  fprintf(fp,"90 rotate\n");
  fprintf(fp,"0 0 moveto 14 f0 (dLat) show\n");
  fprintf(fp,"grestore\n");
  fprintf(fp,"gsave\n");
  fprintf(fp,"-26 -258 translate\n");
  fprintf(fp,"-20 rotate\n");
  fprintf(fp,"0 0 moveto 14 f0 (90\260-Hc) show\n");
  fprintf(fp,"grestore\n");
  fprintf(fp,"12 -10 moveto 14 f1 (NP) show\n");
  fprintf(fp,"84 -220 moveto 14 f1 (Q) show\n");
  fprintf(fp,"84 -300 moveto 14 f1 (AP) show\n");
  fprintf(fp,"-116 -240 moveto 14 f1 (GP) show\n");
  fprintf(fp,"-6 -220 moveto 14 f1 (R) show\n");
  fprintf(fp,"grestore\n");

  fprintf(fp,"gsave\n");
  fprintf(fp,"372 %.1f translate 0.8 0.8 scale\n",y);
  fprintf(fp,"gsave\n");
  fprintf(fp,"-100 0 moveto 200 0 rlineto 0 -300 rlineto -200 0 rlineto closepath clip\n");
  fprintf(fp,"0.2 setlinewidth\n");
  fprintf(fp,"newpath  200.5 -220 300  175 190 arc stroke\n");
  fprintf(fp,"newpath  203.6 -220 300  186.2 189.4 arc stroke\n");
  fprintf(fp,"1.2 setlinewidth\n");
  fprintf(fp,"newpath  200.5 -220 300  120  175 arc stroke\n");
  fprintf(fp,"newpath -417.5 -280 500   4.2  60 arc stroke\n");
  fprintf(fp,"newpath  124    254 500 243.5 265.1 arc stroke\n");
  fprintf(fp,"gsave\n");
  fprintf(fp,"[8 4] 1 setdash\n");
  fprintf(fp,"newpath  -80  228 500 268.3 288.6 arc stroke\n");
  fprintf(fp,"grestore\n");
  fprintf(fp,"0.2 setlinewidth\n");
  fprintf(fp,"newpath  -80  231 500 268.7 270.6 arc stroke\n");
  fprintf(fp,"0.5 setgray\n");
  fprintf(fp,"newpath -98 -194 40 335  80 arc stroke\n");
  fprintf(fp,"newpath -3.3 0 40 227 300 arc stroke\n");
  fprintf(fp,"-19 -56 moveto 14 f1 (t) show\n");
  fprintf(fp,"-10 -54 moveto 10 f0 (\\(+\\)) show\n");
  fprintf(fp,"-58 -180 moveto 14 f1 (Zc) show\n");
  fprintf(fp,"-61.7 -210.9 translate\n");
  fprintf(fp,"75 rotate\n");
  fprintf(fp,"0 0 moveto 12 -4 rlineto 0 8 rlineto closepath fill\n");
  fprintf(fp,"grestore\n");
  fprintf(fp,"gsave\n");
  fprintf(fp,"54 -144 translate\n");
  fprintf(fp,"110 rotate\n");
  fprintf(fp,"0 0 moveto 14 f0 (90\260-Dec) show\n");
  fprintf(fp,"grestore\n");
  fprintf(fp,"gsave\n");
  fprintf(fp,"-66 -144 translate\n");
  fprintf(fp,"69 rotate\n");
  fprintf(fp,"0 0 moveto 14 f0 (90\260-LatAP) show\n");
  fprintf(fp,"6 rotate\n");
  fprintf(fp,"-30 30 moveto 14 f0 (90\260-LatQ) show\n");
  fprintf(fp,"grestore\n");
  fprintf(fp,"gsave\n");
  fprintf(fp,"-26 -216 translate\n");
  fprintf(fp,"-15 rotate\n");
  fprintf(fp,"0 0 moveto 14 f0 (90\260-Hc) show\n");
  fprintf(fp,"grestore\n");
  fprintf(fp,"gsave\n");
  fprintf(fp,"-80 -254 translate\n");
  fprintf(fp,"92 rotate\n");
  fprintf(fp,"0 0 moveto 14 f0 (dLat) show\n");
  fprintf(fp,"grestore\n");
  fprintf(fp,"12 -10 moveto 14 f1 (NP) show\n");
  fprintf(fp,"-112 -280 moveto 14 f1 (Q) show\n");
  fprintf(fp,"84 -260 moveto 14 f1 (GP) show\n");
  fprintf(fp,"-122 -200 moveto 14 f1 (AP) show\n");
  fprintf(fp,"-6 -280 moveto 14 f1 (R) show\n");
  fprintf(fp,"grestore\n");

  y-=23.0*dy;
  fprintf(fp,"  0.0 %.1f moveto 12 f1 (Solving the divided Navigational Triangle) show\n",y); y-=2.0*dy;
  fprintf(fp,"  0.0 %.1f moveto 10 f0 (For the sight-reduction problem,  the  navigational triangle  has  to  be) show\n",y);
  fprintf(fp,"475.0 %.1f moveto 10 f0 (solved  to  obtain  the  values  of  the) Rshow\n",y); y-=dy;
  fprintf(fp,"  0.0 %.1f moveto 10 f0 (Altitude \"Hc\"  and  the Azimuth \"Zc\"  for an Assumed Position  specified by:) show\n",y);
  fprintf(fp,"475.0 %.1f moveto 10 f0 (assumed Latitude \\(LatAP\\)  and) Rshow\n",y); y-=dy;
  fprintf(fp,"  0.0 %.1f moveto 10 f0 (assumed Longitude \\(LonAP\\)  and  the  celestial coordinates  of) show\n",y);
  fprintf(fp,"475.0 %.1f moveto 10 f0 (the  observed body:  Declination \\(Dec\\) and) Rshow\n",y); y-=dy;
  fprintf(fp,"  0.0 %.1f moveto 10 f0 (Greenwich Hour Angle \\(GHA\\).     Ageton's  method  of  solving) show\n",y);
  fprintf(fp,"475.0 %.1f moveto 10 f0 (the   navigational  triangle,  introduces  two) Rshow\n",y); y-=dy;
  fprintf(fp,"  0.0 %.1f moveto 10 f0 (additional values to be solved:  the Latitude  of the  vertex point \"Q\" \\(LatQ\\)) show\n",y);
  fprintf(fp,"475.0 %.1f moveto 10 f0 (and  the length  of the side \"R\".) Rshow\n",y); y-=dy;
  fprintf(fp,"  0.0 %.1f moveto 10 f0 () show\n",y); y-=dy;
  fprintf(fp,"  0.0 %.1f moveto 10 f0 (Altitude \"Hc\" and Azimuth \"Zc\" are obtained through the following steps:) show\n",y);
  fprintf(fp,"475.0 %.1f moveto 10 f0 () Rshow\n",y); y-=dy;
  fprintf(fp,"  0.0 %.1f moveto 10 f4 (  LHA       = GHA + LonAP           t =      - LHA    if LHA < 180\\260) show\n",y); y-=dy;
  fprintf(fp,"  0.0 %.1f moveto 10 f4 (                                    t = 360\\260 - LHA    if LHA > 180\\260) show\n",y); y-=dy;
  fprintf(fp,"  0.0 %.1f moveto 10 f0 (Solve the sides of the first right-angled triangle \\(Law of Sines and Law of Cosines for Sides\\):) show\n",y); y-=dy;
  fprintf(fp,"  0.0 %.1f moveto 10 f4 (  sin\\(R\\)    = sin\\(t\\)*cos\\(Dec\\)) show\n",y); y-=dy;
  fprintf(fp,"  0.0 %.1f moveto 10 f4 (  sin\\(LatQ\\) = sin\\(Dec\\)/cos\\(R\\)) show\n",y); y-=dy;
  fprintf(fp,"  0.0 %.1f moveto 10 f0 (Solve the second right-angled triangle for Hc and Zc \\(Law of Sines and Law of Cosines for Sides\\):) show\n",y); y-=dy;
  fprintf(fp,"  0.0 %.1f moveto 10 f4 (  dLat      = LatAP - LatQ) show\n",y); y-=dy;
  fprintf(fp,"  0.0 %.1f moveto 10 f4 (  sin\\(Hc\\)   = cos\\(R\\)*cos\\(dLat\\)) show\n",y); y-=dy;
  fprintf(fp,"  0.0 %.1f moveto 10 f4 (  sin\\(Z\\)    = sin\\(R\\)/cos\\(Hc\\)) show\n",y); y-=dy;
  fprintf(fp,"  0.0 %.1f moveto 10 f0 (If the North Pole is systematicaly  used as reference  pole ) show\n",y);
  fprintf(fp,"475.0 %.1f moveto 10 f0 (\\(even if the elevated pole is the South Pole\\), the) Rshow\n",y); y-=dy;
  fprintf(fp,"  0.0 %.1f moveto 10 f0 (true Azimuth Zc is obtained from Z through the following rule:) show\n",y); y-=dy;
  fprintf(fp,"  0.0 %.1f moveto 10 f4 (  Zc =        Z     if LHA < 180\\260) show\n",y); y-=dy;
  fprintf(fp,"  0.0 %.1f moveto 10 f4 (  Zc = 360\\260 - Z     if LHA > 180\\260) show\n",y);
  fprintf(fp,"grestore\n");
  fprintf(fp,"showpage\n");

  *page = (*page)+1;
  
  fprintf(fp,"%%%%Page: %d %d\n",*page,*page);
  fprintf(fp,"gsave 0.2 setlinewidth\n");
  fprintf(fp,"54 0 translate\n");
  fprintf(fp,"  0.0 744.1 moveto 18 f1 (Sight Reduction on the divided Navigational Triangle) show\n");
  y=715.2;
  fprintf(fp,"  0.0 %.1f moveto 10 f0 (The following calculation scheme may be used to calculate) show\n",y);
  fprintf(fp,"475.0 %.1f moveto 10 f0 (the Altitude \"Hc\"  and the true Azimuth \"Zc\" of a) Rshow\n",y); y-=dy;
  fprintf(fp,"  0.0 %.1f moveto 10 f0 (celestial object from it's Geographical Position \\(GP\\) as will be observed at the Estimated Position \\(EP\\):) show\n",y);

  fprintf(fp,"12.0 0.0 translate\n");
  dy=11.0;

  fprintf(fp,"  0.0 %.1f moveto 9 f4 (                                                                          Remarks) show\n",y-=2.0*dy);
  fprintf(fp,"  0.0 %.1f moveto 9 f4 ( AP:  LatAP  =  \\261__\\260__'_ \\(N/S\\)           GP:    Dec =  \\261__\\260__'_ \\(N/S\\)       \\(0\\)) show\n",y-=dy);
  fprintf(fp,"  0.0 %.1f moveto 9 f4 (      LonAP  = \\261___\\260__'_ \\(E/W\\)                  GHA =  ___\\260__'_ ) show\n",y-=dy);
  fprintf(fp,"  0.0 %.1f moveto 9 f4 ( 1.   LHA    = GHA + LonAP   =  ___\\260__'_) show\n",y-=3.0*dy);
  fprintf(fp,"  0.0 %.1f moveto 9 f4 (        t    =     - LHA     = \\261___\\260__'_         if\\( LHA < 180\\260\\)            \\(1\\)) show\n",y-=dy);
  fprintf(fp,"  0.0 %.1f moveto 9 f4 (        t    = 360\\260- LHA     = \\261___\\260__'_         if\\( LHA > 180\\260\\)) show\n",y-=dy);
  fprintf(fp,"  0.0 %.1f moveto 9 f4 (      A\\(t\\)   = ________) show\n",y-=dy);
  fprintf(fp,"  0.0 %.1f moveto 9 f4 ( 2.   A\\(Dec\\) = ________                      B\\(Dec\\) = ________) show\n",y-=2.0*dy);
  fprintf(fp,"  0.0 %.1f moveto 9 f4 ( 3.   A\\(R\\)   = A\\(t\\) + B\\(Dec\\) = ________ + ________  = ________) show\n",y-=2.0*dy);
  fprintf(fp,"  0.0 %.1f moveto 9 f4 (        R    =  __\\260__'_                        B\\(R\\) = ________) show\n",y-=dy);
  fprintf(fp,"  0.0 %.1f moveto 9 f4 ( 4.   A\\(LatQ\\)= A\\(Dec\\) - B\\(R\\) = ________ - ________  = ________) show\n",y-=2.0*dy);
  fprintf(fp,"  0.0 %.1f moveto 9 f4 (        LatQ = \\261__\\260__'_ \\(N/S\\)                                               \\(4\\)) show\n",y-=dy);
  fprintf(fp,"  0.0 %.1f moveto 9 f4 ( 5.     dLat = LatAP - LatQ  = \\261__\\260__'_ - \\261__\\260__'_  = \\261___\\260__'_             \\(5\\)) show\n",y-=2.0*dy);
  fprintf(fp,"  0.0 %.1f moveto 9 f4 (      B\\(dLat\\)= ________) show\n",y-=dy);
  fprintf(fp,"  0.0 %.1f moveto 9 f4 ( 6.    A\\(Hc\\) = B\\(R\\) + B\\(dLat\\)= ________ + ________  = ________) show\n",y-=2.0*dy);
  fprintf(fp,"  0.0 %.1f moveto 9 f4 (         Hc  =  __\\260__'_                       B\\(Hc\\) = ________) show\n",y-=dy);
  fprintf(fp,"  0.0 %.1f moveto 9 f4 ( 7.    A\\(Z\\)  = A\\(R\\) - B\\(Hc\\)  = ________ - ________  = ________) show\n",y-=2.0*dy);
  fprintf(fp,"  0.0 %.1f moveto 9 f4 (         Z   =  __\\260__'_                                                     \\(7\\)) show\n",y-=dy);
  fprintf(fp,"  0.0 %.1f moveto 9 f4 ( 8.      Zc  = ___\\260__'_                                                     \\(8\\)) show\n",y-=2.0*dy);
  fprintf(fp,"  0.0 %.1f moveto 9 f4 (Remarks and Instructions) show\n",y-=3.0*dy);
  fprintf(fp,"  0.0 %.1f moveto 9 f4 (\\(0\\)  Use the appropriate signs for Latitude, Longitude and Declination: ) show\n",y-=dy);
  fprintf(fp,"  0.0 %.1f moveto 9 f4 (     positive for N and E, negative for S and W. ) show\n",y-=dy);
  fprintf(fp,"  0.0 %.1f moveto 9 f4 ( ) show\n",y-=dy);
  fprintf(fp,"  0.0 %.1f moveto 9 f4 (\\(1\\)  The meridian angle \"t\" is calculated from \"LHA\" according to the following rule:) show\n",y-=dy);
  fprintf(fp,"  0.0 %.1f moveto 9 f4 (     if LHA < 180\\260   t =      - LHA      ) show\n",y-=dy);
  fprintf(fp,"  0.0 %.1f moveto 9 f4 (     if LHA > 180\\260   t = 360\\260 - LHA     ) show\n",y-=dy);
  fprintf(fp,"  0.0 %.1f moveto 9 f4 ( ) show\n",y-=dy);
  fprintf(fp,"  0.0 %.1f moveto 9 f4 (\\(4\\)  The sign of the Latitude of \"Q\" \\(N/S\\) depends on the values of \"t\" and \"Dec\": ) show\n",y-=dy);
  fprintf(fp,"  0.0 %.1f moveto 9 f4 (     if |t| < 90\\260   LatQ has the     same sign as Dec) show\n",y-=dy);
  fprintf(fp,"  0.0 %.1f moveto 9 f4 (     if |t| > 90\\260   LatQ has the contrary sign of Dec) show\n",y-=dy);
  fprintf(fp,"  0.0 %.1f moveto 9 f4 (     Where |t| is the absolute value of \"t\") show\n",y-=dy);
  fprintf(fp,"  0.0 %.1f moveto 9 f4 () show\n",y-=dy);
  fprintf(fp,"  0.0 %.1f moveto 9 f4 (\\(5\\)  The value of \"dLat\" must be calculated taking the correct signs for \"LatAP\" and) show\n",y-=dy);
  fprintf(fp,"  0.0 %.1f moveto 9 f4 (     \"LatQ\" into account. The resulting sign of \"dLat\" should be recorded correcly) show\n",y-=dy);
  fprintf(fp,"  0.0 %.1f moveto 9 f4 (     \\(see remark 7\\).) show\n",y-=dy);
  fprintf(fp,"  0.0 %.1f moveto 9 f4 () show\n",y-=dy);
  fprintf(fp,"  0.0 %.1f moveto 9 f4 (\\(7\\)  Select one out of four cases, depending on the value of \"|t|\" and the sign of ) show\n",y-=dy);
  fprintf(fp,"  0.0 %.1f moveto 9 f4 (     \"dLat\" to determine how to select the value of \"Z\" from the Tables:) show\n",y-=dy);
  fprintf(fp,"  0.0 %.1f moveto 9 f4 (       |t|     |       |t| < 90\\260       |       |t| > 90\\260       |) show\n",y-=dy);
  fprintf(fp,"  0.0 %.1f moveto 9 f4 (       dLat    |      -    |     +     |     -     |     +     |) show\n",y-=dy);
  fprintf(fp,"  0.0 %.1f moveto 9 f4 (        Z      |   < 90\\260   |  > 90\\260    |   > 90\\260   |   < 90\\260   |) show\n",y-=dy);
  fprintf(fp,"  0.0 %.1f moveto 9 f4 (     if Z < 90\\260 select Z from the    top line - left  column of the Table) show\n",y-=dy);
  fprintf(fp,"  0.0 %.1f moveto 9 f4 (     if Z > 90\\260 select Z from the bottom line - right column of the Table) show\n",y-=dy);
  fprintf(fp,"  0.0 %.1f moveto 9 f4 () show\n",y-=dy);
  fprintf(fp,"  0.0 %.1f moveto 9 f4 (\\(8\\)  The true Azimuth \"Zc\" is obtained from \"Z\" depending on the sign of \"t\":) show\n",y-=dy);
  fprintf(fp,"  0.0 %.1f moveto 9 f4 (     if t > 0   Zc = Z            \\(GP is East of AP\\)) show\n",y-=dy);
  fprintf(fp,"  0.0 %.1f moveto 9 f4 (     if t < 0   Zc = 360\\260 - Z     \\(GP is West of AP\\)) show\n",y-=dy);

  dy=13.3;
  fprintf(fp,"grestore\n");
  fprintf(fp,"showpage\n");

  *page = (*page)+1;

  return;
}





/* ---------------------------------------------------------------------------------------------------------------------------------------- */
int main(int argc, char **argv)

{ int    a,m,i;
  int    font,page;

  double r,s,f;

  char   filename[32];
  FILE  *fp;

  r=PI/180.0;
  s=180.0/PI;


  if(argc!=1) 
  { printf("\n\n Usage: %s \n\n",argv[0]);
    exit(0);
  }

  printf("\n Generating Ageton Tables\n\n");
  

  sprintf(filename,"Data/AgetonTables.ps");
  if((fp=fopen(filename,"w"))==NULL)
  { printf(" Error (%s) could not open file \"%s\" for reading!\n",argv[0],filename);
    exit(-1);
  }
  
  printf("                     writing data file : \"%s\"\n",filename);

  PrintHeader(fp);
  page=2;
  InsertBlankPage(fp,&page);
  PrintIntro0Page(fp,&page);
  InsertBlankPage(fp,&page);
  PrintIntro1Page(fp,&page);
  InsertBlankPage(fp,&page);

  for(a=0; a<90; a++)
    MakeTable(fp,a,&page);

  InsertBlankPage(fp,&page);
  InsertBlankPage(fp,&page);
  fprintf(fp,"%%%%EOF\n");
  fclose(fp);
  return 0;

}
