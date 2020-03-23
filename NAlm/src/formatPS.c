#include <stdio.h>
#include <time.h>
#include "primitives.h"

#include "../novas/novas.h"





/* -------------------------------------------------------------------------------------------------------------- */

void FormatFrontPages(FILE *fp, int year)
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
  fprintf(fp,"/MakeFrame {\n");
  fprintf(fp,"  0.0 setgray\n");
  fprintf(fp,"  0.5 setlinewidth\n");
  fprintf(fp,"  newpath 0 0 moveto 504 0 rlineto 0 150 rlineto -504 0 rlineto closepath stroke\n");
  fprintf(fp,"  0.1 setlinewidth\n");
  fprintf(fp,"   0 42   504 { 0      moveto 0 150 rlineto stroke } for\n");
  fprintf(fp,"   0 25   150 { 0 exch moveto 504 0 rlineto stroke } for\n");
  fprintf(fp,"   0 2.8  504 {  0 moveto 0   1 rlineto stroke } for\n");
  fprintf(fp,"   0 2.8  504 {150 moveto 0  -1 rlineto stroke } for\n");
  fprintf(fp,"   0 14   504 {  0 moveto 0   2 rlineto stroke } for\n");
  fprintf(fp,"   0 14   504 {150 moveto 0  -2 rlineto stroke } for\n");
  fprintf(fp,"   0 2.5  150 {  0 exch moveto   1 0 rlineto stroke } for\n");
  fprintf(fp,"   0 2.5  150 {504 exch moveto  -1 0 rlineto stroke } for\n");
  fprintf(fp,"   0 12.5 150 {  0 exch moveto   2 0 rlineto stroke } for\n");
  fprintf(fp,"   0 12.5 150 {504 exch moveto  -2 0 rlineto stroke } for } def\n");
  fprintf(fp,"/MakeMap0 {\n");
  fprintf(fp,"  6 f4\n");
  fprintf(fp,"  0 10 40 { dup 2.5 mul 48 add -10 exch moveto (  ) cvs show } for\n");
  fprintf(fp,"  0 10 20 { dup 2.5 mul 48 exch sub -10 exch moveto (  ) cvs show } for\n");
  fprintf(fp,"  0 10 40 { dup 2.5 mul 48 add 507 exch moveto (  ) cvs show } for\n");
  fprintf(fp,"  0 10 20 { dup 2.5 mul 48 exch sub 507 exch moveto (  ) cvs show } for\n");
  fprintf(fp," -9 48 moveto ( \\260) show 507 48 moveto ( \\260) show\n");
  fprintf(fp," -9 138 moveto (N ) show 506 138 moveto ( N) show\n");
  fprintf(fp," -9  12 moveto (S ) show 506  12 moveto ( S) show\n");
  fprintf(fp,"  0  1 12 { dup 42 mul 6 add  -8 moveto 15 mul 180 add 360 exch sub (   ) cvs Rshow (\\260) show } for\n");
  fprintf(fp,"  0  1 12 { dup 42 mul 6 add 154 moveto 15 mul 180 add 360 exch sub (   ) cvs Rshow (\\260) show } for\n");
  fprintf(fp,"  254 163 moveto 7 f4 (Right Ascension) Cshow\n");
  fprintf(fp,"  DrawStars0 } def\n");
  fprintf(fp,"/MakeMap1 {\n");
  fprintf(fp,"  6 f4\n");
  fprintf(fp,"  0 10 20 { dup 2.5 mul 98 add -10 exch moveto (  ) cvs show } for\n");
  fprintf(fp,"  0 10 40 { dup 2.5 mul 98 exch sub -10 exch moveto (  ) cvs show } for\n");
  fprintf(fp,"  0 10 20 { dup 2.5 mul 98 add 507 exch moveto (  ) cvs show } for\n");
  fprintf(fp,"  0 10 40 { dup 2.5 mul 98 exch sub 507 exch moveto (  ) cvs show } for\n");
  fprintf(fp," -9 98 moveto ( \\260) show 507 98 moveto ( \\260) show\n");
  fprintf(fp," -9 138 moveto (N ) show 506 138 moveto ( N) show\n");
  fprintf(fp," -9  12 moveto (S ) show 506  12 moveto ( S) show\n");
  fprintf(fp,"  0  1 12 { dup 42 mul 6 add  -8 moveto 15 mul   0 add 360 exch sub (   ) cvs Rshow (\\260) show } for\n");
  fprintf(fp,"  0  1 12 { dup 42 mul 6 add 154 moveto 15 mul   0 add 360 exch sub (   ) cvs Rshow (\\260) show } for\n");
  fprintf(fp,"  DrawStars1 } def\n");
  fprintf(fp,"/DrawStars0 {\n");
  fprintf(fp,"  newpath 498.1 122.7   1.0 0 360 arc fill\n");
  fprintf(fp,"  newpath 494.7  88.0   0.8 0 360 arc fill\n");
  fprintf(fp,"  newpath 490.4  32.1   0.6 0 360 arc fill\n");
  fprintf(fp,"  newpath 483.0  44.9   0.1 0 360 arc fill\n");
  fprintf(fp,"  newpath 478.2 134.3   0.4 0 360 arc fill\n");
  fprintf(fp,"  newpath 477.0 123.3   0.4 0 360 arc fill\n");
  fprintf(fp,"  newpath 476.5 127.2   0.7 0 360 arc fill\n");
  fprintf(fp,"  newpath 473.5  10.0   1.0 0 360 arc fill\n");
  fprintf(fp,"  newpath 470.9 110.7   0.5 0 360 arc fill\n");
  fprintf(fp,"  newpath 469.9  69.0   0.4 0 360 arc fill\n");
  fprintf(fp,"  newpath 468.9  26.6   0.2 0 360 arc fill\n");
  fprintf(fp,"  newpath 464.3 146.2   0.5 0 360 arc fill\n");
  fprintf(fp,"  newpath 459.9  69.7   0.4 0 360 arc fill\n");
  fprintf(fp,"  newpath 456.0  25.5   0.6 0 360 arc fill\n");
  fprintf(fp,"  newpath 455.2 139.1   1.0 0 360 arc fill\n");
  fprintf(fp,"  newpath 453.8 125.2   0.4 0 360 arc fill\n");
  fprintf(fp,"  newpath 448.4 118.2   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath 445.2  30.5   0.6 0 360 arc fill\n");
  fprintf(fp,"  newpath 440.0  88.4   0.6 0 360 arc fill\n");
  fprintf(fp,"  newpath 433.0  63.7   0.4 0 360 arc fill\n");
  fprintf(fp,"  newpath 431.2  14.8   0.6 0 360 arc fill\n");
  fprintf(fp,"  newpath 430.2  72.9   0.4 0 360 arc fill\n");
  fprintf(fp,"  newpath 426.0  25.8   0.6 0 360 arc fill\n");
  fprintf(fp,"  newpath 424.8 123.9   0.6 0 360 arc fill\n");
  fprintf(fp,"  newpath 424.5  58.0   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath 423.8 102.0   0.8 0 360 arc fill\n");
  fprintf(fp,"  newpath 415.0 108.7   1.0 0 360 arc fill\n");
  fprintf(fp,"  newpath 413.3 137.5   0.8 0 360 arc fill\n");
  fprintf(fp,"  newpath 407.9 134.6   0.5 0 360 arc fill\n");
  fprintf(fp,"  newpath 408.1  36.1   0.1 0 360 arc fill\n");
  fprintf(fp,"  newpath 407.3  99.8   0.1 0 360 arc fill\n");
  fprintf(fp,"  newpath 400.3  71.2   0.4 0 360 arc fill\n");
  fprintf(fp,"  newpath 392.8 104.9   0.1 0 360 arc fill\n");
  fprintf(fp,"  newpath 392.4  50.8   0.5 0 360 arc fill\n");
  fprintf(fp,"  newpath 389.6 119.3   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath 389.1  19.6   0.4 0 360 arc fill\n");
  fprintf(fp,"  newpath 388.5  75.3   0.4 0 360 arc fill\n");
  fprintf(fp,"  newpath 385.0 118.2   0.6 0 360 arc fill\n");
  fprintf(fp,"  newpath 380.5  32.2   0.5 0 360 arc fill\n");
  fprintf(fp,"  newpath 376.4  60.2   0.9 0 360 arc fill\n");
  fprintf(fp,"  newpath 374.4 147.1   0.7 0 360 arc fill\n");
  fprintf(fp,"  newpath 369.9  99.3   0.4 0 360 arc fill\n");
  fprintf(fp,"  newpath 369.1  48.0   0.2 0 360 arc fill\n");
  fprintf(fp,"  newpath 360.6  72.6   0.6 0 360 arc fill\n");
  fprintf(fp,"  newpath 359.0  74.3   0.6 0 360 arc fill\n");
  fprintf(fp,"  newpath 356.4  82.3   0.5 0 360 arc fill\n");
  fprintf(fp,"  newpath 354.9  28.6   0.6 0 360 arc fill\n");
  fprintf(fp,"  newpath 347.7  29.4   0.6 0 360 arc fill\n");
  fprintf(fp,"  newpath 346.6 110.3   0.6 0 360 arc fill\n");
  fprintf(fp,"  newpath 346.8  47.9   0.2 0 360 arc fill\n");
  fprintf(fp,"  newpath 344.8 110.3   0.8 0 360 arc fill\n");
  fprintf(fp,"  newpath 343.6 110.1   0.6 0 360 arc fill\n");
  fprintf(fp,"  newpath 340.1 129.7   0.8 0 360 arc fill\n");
  fprintf(fp,"  newpath 336.7 139.5   0.5 0 360 arc fill\n");
  fprintf(fp,"  newpath 337.4  18.8   0.8 0 360 arc fill\n");
  fprintf(fp,"  newpath 335.5  81.2   0.6 0 360 arc fill\n");
  fprintf(fp,"  newpath 333.8  65.0   0.5 0 360 arc fill\n");
  fprintf(fp,"  newpath 327.7  37.1   0.5 0 360 arc fill\n");
  fprintf(fp,"  newpath 321.7 136.4   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath 322.1  89.1   0.6 0 360 arc fill\n");
  fprintf(fp,"  newpath 321.5   1.6   0.2 0 360 arc fill\n");
  fprintf(fp,"  newpath 319.9  93.9   0.6 0 360 arc fill\n");
  fprintf(fp,"  newpath 316.0  98.0   0.6 0 360 arc fill\n");
  fprintf(fp,"  newpath 310.9  91.3   1.3 0 360 arc fill\n");
  fprintf(fp,"  newpath 310.6  43.4   0.5 0 360 arc fill\n");
  fprintf(fp,"  newpath 309.3  15.8   0.5 0 360 arc fill\n");
  fprintf(fp,"  newpath 306.4 107.4   0.4 0 360 arc fill\n");
  fprintf(fp,"  newpath 304.1  43.1   0.5 0 360 arc fill\n");
  fprintf(fp,"  newpath 300.2  64.0   0.6 0 360 arc fill\n");
  fprintf(fp,"  newpath 298.0  56.1   0.6 0 360 arc fill\n");
  fprintf(fp,"  newpath 296.1 132.9   0.8 0 360 arc fill\n");
  fprintf(fp,"  newpath 291.8 104.0   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath 288.5  37.7   0.8 0 360 arc fill\n");
  fprintf(fp,"  newpath 287.6  31.9   0.4 0 360 arc fill\n");
  fprintf(fp,"  newpath 284.6 146.2   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath 283.8  30.5   1.5 0 360 arc fill\n");
  fprintf(fp,"  newpath 281.7  37.1   0.6 0 360 arc fill\n");
  fprintf(fp,"  newpath 276.4  65.9   1.1 0 360 arc fill\n");
  fprintf(fp,"  newpath 275.6 121.5   1.1 0 360 arc fill\n");
  fprintf(fp,"  newpath 274.2   1.9   0.8 0 360 arc fill\n");
  fprintf(fp,"  newpath 271.6  50.7   0.9 0 360 arc fill\n");
  fprintf(fp,"  newpath 271.1   9.6   0.9 0 360 arc fill\n");
  fprintf(fp,"  newpath 269.6  73.7   0.4 0 360 arc fill\n");
  fprintf(fp,"  newpath 269.2  39.8   0.8 0 360 arc fill\n");
  fprintf(fp,"  newpath 268.7  48.0   1.1 0 360 arc fill\n");
  fprintf(fp,"  newpath 267.6 102.9   0.8 0 360 arc fill\n");
  fprintf(fp,"  newpath 260.8  94.3   0.1 0 360 arc fill\n");
  fprintf(fp,"  newpath 261.1  17.1   0.6 0 360 arc fill\n");
  fprintf(fp,"  newpath 260.6  29.2   1.0 0 360 arc fill\n");
  fprintf(fp,"  newpath 258.0 147.9   0.5 0 360 arc fill\n");
  fprintf(fp,"  newpath 258.1   2.2   0.5 0 360 arc fill\n");
  fprintf(fp,"  newpath 255.4  68.5   1.4 0 360 arc fill\n");
  fprintf(fp,"  newpath 254.5  15.4   0.6 0 360 arc fill\n");
  fprintf(fp,"  newpath 248.5  60.4   0.1 0 360 arc fill\n");
  fprintf(fp,"  newpath 246.7  86.9   0.4 0 360 arc fill\n");
  fprintf(fp,"  newpath 235.9 106.3   0.8 0 360 arc fill\n");
  fprintf(fp,"  newpath 236.1   9.9   1.0 0 360 arc fill\n");
  fprintf(fp,"  newpath 235.4  61.5   0.4 0 360 arc fill\n");
  fprintf(fp,"  newpath 232.4  41.9   0.2 0 360 arc fill\n");
  fprintf(fp,"  newpath 224.9 148.5   0.1 0 360 arc fill\n");
  fprintf(fp,"  newpath 225.6  91.0   1.0 0 360 arc fill\n");
  fprintf(fp,"  newpath 221.2 112.8   0.8 0 360 arc fill\n");
  fprintf(fp,"  newpath 220.3  82.2   0.7 0 360 arc fill\n");
  fprintf(fp,"  newpath 220.4  11.8   1.9 0 360 arc fill\n");
  fprintf(fp,"  newpath 218.5  56.0   0.4 0 360 arc fill\n");
  fprintf(fp,"  newpath 215.0 134.9   0.6 0 360 arc fill\n");
  fprintf(fp,"  newpath 214.1  20.1   0.5 0 360 arc fill\n");
  fprintf(fp,"  newpath 207.1 101.4   0.6 0 360 arc fill\n");
  fprintf(fp,"  newpath 207.4  14.1   0.5 0 360 arc fill\n");
  fprintf(fp,"  newpath 201.8 148.3   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath 197.3  91.4   0.6 0 360 arc fill\n");
  fprintf(fp,"  newpath 195.9 105.0   0.6 0 360 arc fill\n");
  fprintf(fp,"  newpath 192.0 119.5   0.6 0 360 arc fill\n");
  fprintf(fp,"  newpath 191.0  70.7   0.8 0 360 arc fill\n");
  fprintf(fp,"  newpath 189.6 129.5   0.5 0 360 arc fill\n");
  fprintf(fp,"  newpath 185.8 129.7   1.0 0 360 arc fill\n");
  fprintf(fp,"  newpath 183.9  40.3   0.2 0 360 arc fill\n");
  fprintf(fp,"  newpath 182.5  63.1   1.4 0 360 arc fill\n");
  fprintf(fp,"  newpath 181.1  28.9   0.5 0 360 arc fill\n");
  fprintf(fp,"  newpath 178.9 111.0   0.6 0 360 arc fill\n");
  fprintf(fp,"  newpath 178.3 120.1   1.2 0 360 arc fill\n");
  fprintf(fp,"  newpath 176.7 133.5   0.2 0 360 arc fill\n");
  fprintf(fp,"  newpath 168.2  44.2   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath 165.5 119.5   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath 158.7  14.5   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath 156.4  73.0   0.6 0 360 arc fill\n");
  fprintf(fp,"  newpath 150.0  44.8   0.5 0 360 arc fill\n");
  fprintf(fp,"  newpath 145.0 145.0   0.0 0 360 arc fill\n");
  fprintf(fp,"  newpath 145.1 101.1   0.2 0 360 arc fill\n");
  fprintf(fp,"  newpath 140.0  21.2   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath 136.7  95.4   0.5 0 360 arc fill\n");
  fprintf(fp,"  newpath 135.3 121.9   0.5 0 360 arc fill\n");
  fprintf(fp,"  newpath 129.2  64.9   0.7 0 360 arc fill\n");
  fprintf(fp,"  newpath 127.1  79.6   0.4 0 360 arc fill\n");
  fprintf(fp,"  newpath 115.9  55.8   0.5 0 360 arc fill\n");
  fprintf(fp,"  newpath 111.3 136.0   0.7 0 360 arc fill\n");
  fprintf(fp,"  newpath 106.7  31.6   1.0 0 360 arc fill\n");
  fprintf(fp,"  newpath 102.0 141.0   0.4 0 360 arc fill\n");
  fprintf(fp,"  newpath  97.8  15.8   0.2 0 360 arc fill\n");
  fprintf(fp,"  newpath  97.2  74.7   0.6 0 360 arc fill\n");
  fprintf(fp,"  newpath  93.9 109.4   0.8 0 360 arc fill\n");
  fprintf(fp,"  newpath  89.1 115.0   0.5 0 360 arc fill\n");
  fprintf(fp,"  newpath  87.6   2.5   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath  83.9  70.1   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath  78.9  91.9   0.6 0 360 arc fill\n");
  fprintf(fp,"  newpath  78.1  79.9   1.2 0 360 arc fill\n");
  fprintf(fp,"  newpath  76.6  20.9   0.6 0 360 arc fill\n");
  fprintf(fp,"  newpath  72.3 108.5   0.6 0 360 arc fill\n");
  fprintf(fp,"  newpath  67.6  40.2   0.0 0 360 arc fill\n");
  fprintf(fp,"  newpath  65.7  12.1   0.5 0 360 arc fill\n");
  fprintf(fp,"  newpath  64.5 141.8   0.4 0 360 arc fill\n");
  fprintf(fp,"  newpath  61.0  73.3   0.5 0 360 arc fill\n");
  fprintf(fp,"  newpath  53.6 108.0   0.2 0 360 arc fill\n");
  fprintf(fp,"  newpath  51.9 126.7   0.2 0 360 arc fill\n");
  fprintf(fp,"  newpath  49.5  76.4   0.2 0 360 arc fill\n");
  fprintf(fp,"  newpath  49.3  10.5   0.7 0 360 arc fill\n");
  fprintf(fp,"  newpath  46.7 135.5   0.5 0 360 arc fill\n");
  fprintf(fp,"  newpath  38.5  68.3   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath  32.1 101.3   0.9 0 360 arc fill\n");
  fprintf(fp,"  newpath  32.0  88.6   0.7 0 360 arc fill\n");
  fprintf(fp,"  newpath  29.1 132.7   0.6 0 360 arc fill\n");
  fprintf(fp,"  newpath  28.5  16.9   0.6 0 360 arc fill\n");
  fprintf(fp,"  newpath  27.2  65.1   0.5 0 360 arc fill\n");
  fprintf(fp,"  newpath  24.6   9.2   0.5 0 360 arc fill\n");
  fprintf(fp,"  newpath  16.1  52.1   0.4 0 360 arc fill\n");
  fprintf(fp,"  newpath   7.7  86.4   1.0 0 360 arc fill\n");
  fprintf(fp,"  newpath   6.5  54.4   0.6 0 360 arc fill\n");
  fprintf(fp,"  newpath 501.4   8.3   0.4 0 360 arc fill\n");
  fprintf(fp,"  newpath 500.3  39.3   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath 493.8 100.5   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath 491.2 142.0   0.4 0 360 arc fill\n");
  fprintf(fp,"  newpath 491.0 128.8   0.0 0 360 arc fill\n");
  fprintf(fp,"  newpath 489.6  70.5   0.2 0 360 arc fill\n");
  fprintf(fp,"  newpath 489.2 144.9   0.2 0 360 arc fill\n");
  fprintf(fp,"  newpath 486.2  54.8   0.1 0 360 arc fill\n");
  fprintf(fp,"  newpath 470.1  63.2   0.1 0 360 arc fill\n");
  fprintf(fp,"  newpath 469.7  92.4   0.2 0 360 arc fill\n");
  fprintf(fp,"  newpath 466.9  47.9   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath 463.5 122.5   0.1 0 360 arc fill\n");
  fprintf(fp,"  newpath 458.4  87.4   0.1 0 360 arc fill\n");
  fprintf(fp,"  newpath 454.0 102.6   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath 452.4  68.9   0.2 0 360 arc fill\n");
  fprintf(fp,"  newpath 449.5  59.0   0.2 0 360 arc fill\n");
  fprintf(fp,"  newpath 443.3  98.1   0.1 0 360 arc fill\n");
  fprintf(fp,"  newpath 443.2  17.6   0.1 0 360 arc fill\n");
  fprintf(fp,"  newpath 436.0  80.4   0.1 0 360 arc fill\n");
  fprintf(fp,"  newpath 432.6 138.1   0.1 0 360 arc fill\n");
  fprintf(fp,"  newpath 432.1  44.2   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath 428.3  92.4   0.0 0 360 arc fill\n");
  fprintf(fp,"  newpath 427.3  26.7   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath 412.6  98.8   0.1 0 360 arc fill\n");
  fprintf(fp,"  newpath 410.9  88.2   0.1 0 360 arc fill\n");
  fprintf(fp,"  newpath 410.9  72.1   0.4 0 360 arc fill\n");
  fprintf(fp,"  newpath 409.0 112.6   0.1 0 360 arc fill\n");
  fprintf(fp,"  newpath 407.4  54.4   0.1 0 360 arc fill\n");
  fprintf(fp,"  newpath 404.5   9.2   0.0 0 360 arc fill\n");
  fprintf(fp,"  newpath 401.8  20.7   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath 400.3 124.2   0.2 0 360 arc fill\n");
  fprintf(fp,"  newpath 397.5 140.4   0.2 0 360 arc fill\n");
  fprintf(fp,"  newpath 397.5  13.1   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath 394.9  64.0   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath 394.7  67.2   0.0 0 360 arc fill\n");
  fprintf(fp,"  newpath 394.8  34.6   0.1 0 360 arc fill\n");
  fprintf(fp,"  newpath 384.0  87.7   0.1 0 360 arc fill\n");
  fprintf(fp,"  newpath 380.4  44.3   0.2 0 360 arc fill\n");
  fprintf(fp,"  newpath 379.3 101.7   0.0 0 360 arc fill\n");
  fprintf(fp,"  newpath 378.7 138.0   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath 378.2  72.3   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath 371.3 122.7   0.1 0 360 arc fill\n");
  fprintf(fp,"  newpath 367.6 102.6   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath 366.9  32.0   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath 364.4  58.4   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath 363.1 102.9   0.2 0 360 arc fill\n");
  fprintf(fp,"  newpath 356.6  37.7   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath 355.1 138.7   0.0 0 360 arc fill\n");
  fprintf(fp,"  newpath 352.6   8.7   0.2 0 360 arc fill\n");
  fprintf(fp,"  newpath 352.2  51.0   0.4 0 360 arc fill\n");
  fprintf(fp,"  newpath 346.0  65.1   0.2 0 360 arc fill\n");
  fprintf(fp,"  newpath 340.8  93.3   0.0 0 360 arc fill\n");
  fprintf(fp,"  newpath 334.9  48.9   0.2 0 360 arc fill\n");
  fprintf(fp,"  newpath 332.7 105.2   0.4 0 360 arc fill\n");
  fprintf(fp,"  newpath 329.6  99.0   0.1 0 360 arc fill\n");
  fprintf(fp,"  newpath 328.4 116.2   0.1 0 360 arc fill\n");
  fprintf(fp,"  newpath 325.1  72.2   0.4 0 360 arc fill\n");
  fprintf(fp,"  newpath 319.4  44.4   0.2 0 360 arc fill\n");
  fprintf(fp,"  newpath 316.0  53.5   0.1 0 360 arc fill\n");
  fprintf(fp,"  newpath 312.3  87.1   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath 307.1 121.5   0.1 0 360 arc fill\n");
  fprintf(fp,"  newpath 305.1  31.3   0.0 0 360 arc fill\n");
  fprintf(fp,"  newpath 301.1 143.7   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath 301.1  67.4   0.7 0 360 arc fill\n");
  fprintf(fp,"  newpath 300.0  97.1   0.2 0 360 arc fill\n");
  fprintf(fp,"  newpath 299.2  85.6   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath 290.8  88.5   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath 287.5  74.6   0.1 0 360 arc fill\n");
  fprintf(fp,"  newpath 284.9  10.5   0.7 0 360 arc fill\n");
  fprintf(fp,"  newpath 280.3  17.9   0.4 0 360 arc fill\n");
  fprintf(fp,"  newpath 278.8  51.0   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath 275.0  94.9   0.1 0 360 arc fill\n");
  fprintf(fp,"  newpath 271.1 130.5   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath 260.0  40.2   0.0 0 360 arc fill\n");
  fprintf(fp,"  newpath 256.7 119.0   0.4 0 360 arc fill\n");
  fprintf(fp,"  newpath 252.8  51.4   0.2 0 360 arc fill\n");
  fprintf(fp,"  newpath 249.1 108.2   0.5 0 360 arc fill\n");
  fprintf(fp,"  newpath 241.2 123.7   0.4 0 360 arc fill\n");
  fprintf(fp,"  newpath 240.5  80.7   0.2 0 360 arc fill\n");
  fprintf(fp,"  newpath 238.2  34.6   0.2 0 360 arc fill\n");
  fprintf(fp,"  newpath 235.1  23.8   0.2 0 360 arc fill\n");
  fprintf(fp,"  newpath 231.7 100.5   0.5 0 360 arc fill\n");
  fprintf(fp,"  newpath 229.0  68.3   0.4 0 360 arc fill\n");
  fprintf(fp,"  newpath 228.5  48.1   0.2 0 360 arc fill\n");
  fprintf(fp,"  newpath 219.4  71.5   0.0 0 360 arc fill\n");
  fprintf(fp,"  newpath 217.5  45.7   0.1 0 360 arc fill\n");
  fprintf(fp,"  newpath 209.7  31.0   0.0 0 360 arc fill\n");
  fprintf(fp,"  newpath 208.3 110.5   0.2 0 360 arc fill\n");
  fprintf(fp,"  newpath 204.5  68.7   0.1 0 360 arc fill\n");
  fprintf(fp,"  newpath 202.8  40.6   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath 201.7  51.2   0.5 0 360 arc fill\n");
  fprintf(fp,"  newpath 200.6  90.4   0.2 0 360 arc fill\n");
  fprintf(fp,"  newpath 192.4  19.4   0.1 0 360 arc fill\n");
  fprintf(fp,"  newpath 189.1  80.0   0.4 0 360 arc fill\n");
  fprintf(fp,"  newpath 184.9 117.2   0.5 0 360 arc fill\n");
  fprintf(fp,"  newpath 184.3   4.3   0.1 0 360 arc fill\n");
  fprintf(fp,"  newpath 177.3 143.8   0.2 0 360 arc fill\n");
  fprintf(fp,"  newpath 177.7  96.3   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath 177.6  76.9   0.2 0 360 arc fill\n");
  fprintf(fp,"  newpath 177.8  16.4   0.2 0 360 arc fill\n");
  fprintf(fp,"  newpath 173.8  54.4   0.2 0 360 arc fill\n");
  fprintf(fp,"  newpath 172.6 116.9   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath 170.1  89.5   0.1 0 360 arc fill\n");
  fprintf(fp,"  newpath 167.3 113.5   0.0 0 360 arc fill\n");
  fprintf(fp,"  newpath 168.1   6.0   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath 154.0 118.0   0.2 0 360 arc fill\n");
  fprintf(fp,"  newpath 151.6  95.8   0.0 0 360 arc fill\n");
  fprintf(fp,"  newpath 148.0  85.5   0.0 0 360 arc fill\n");
  fprintf(fp,"  newpath 141.6  64.3   0.5 0 360 arc fill\n");
  fprintf(fp,"  newpath 140.9  58.4   0.4 0 360 arc fill\n");
  fprintf(fp,"  newpath 137.7 103.7   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath 133.4  43.6   0.2 0 360 arc fill\n");
  fprintf(fp,"  newpath 129.4   5.6   0.1 0 360 arc fill\n");
  fprintf(fp,"  newpath 126.3 131.0   0.2 0 360 arc fill\n");
  fprintf(fp,"  newpath 124.6  51.2   0.1 0 360 arc fill\n");
  fprintf(fp,"  newpath 121.4 146.1   0.4 0 360 arc fill\n");
  fprintf(fp,"  newpath 120.6  76.7   0.2 0 360 arc fill\n");
  fprintf(fp,"  newpath 119.4 105.1   0.2 0 360 arc fill\n");
  fprintf(fp,"  newpath 119.6  20.9   0.1 0 360 arc fill\n");
  fprintf(fp,"  newpath 117.6   4.4   0.1 0 360 arc fill\n");
  fprintf(fp,"  newpath 108.7 115.5   0.4 0 360 arc fill\n");
  fprintf(fp,"  newpath 108.2  37.8   0.1 0 360 arc fill\n");
  fprintf(fp,"  newpath 103.6  78.2   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath  99.1  61.6   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath  98.1  47.9   0.5 0 360 arc fill\n");
  fprintf(fp,"  newpath  95.5 124.9   0.1 0 360 arc fill\n");
  fprintf(fp,"  newpath  95.4  85.1   0.2 0 360 arc fill\n");
  fprintf(fp,"  newpath  83.3 129.8   0.2 0 360 arc fill\n");
  fprintf(fp,"  newpath  80.4  17.7   0.4 0 360 arc fill\n");
  fprintf(fp,"  newpath  71.7  30.2   0.2 0 360 arc fill\n");
  fprintf(fp,"  newpath  67.8 134.8   0.0 0 360 arc fill\n");
  fprintf(fp,"  newpath  63.4  46.8   0.2 0 360 arc fill\n");
  fprintf(fp,"  newpath  61.5  85.3   0.1 0 360 arc fill\n");
  fprintf(fp,"  newpath  58.4  20.6   0.1 0 360 arc fill\n");
  fprintf(fp,"  newpath  56.9 129.9   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath  51.5  97.2   0.1 0 360 arc fill\n");
  fprintf(fp,"  newpath  48.8  32.2   0.1 0 360 arc fill\n");
  fprintf(fp,"  newpath  42.2   5.7   0.5 0 360 arc fill\n");
  fprintf(fp,"  newpath  41.6  59.0   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath  37.2  54.9   0.1 0 360 arc fill\n");
  fprintf(fp,"  newpath  30.3  44.1   0.4 0 360 arc fill\n");
  fprintf(fp,"  newpath  28.6 145.5   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath  22.4  57.1   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath  16.3  29.5   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath  13.3 135.5   0.2 0 360 arc fill\n");
  fprintf(fp,"  newpath  10.7   5.9   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath   9.9  66.3   0.5 0 360 arc fill\n");
  fprintf(fp,"  newpath   8.4 100.5   0.4 0 360 arc fill\n");
  fprintf(fp,"  newpath   6.3  38.3   0.1 0 360 arc fill\n");
  fprintf(fp,"  newpath   3.0  89.1   0.1 0 360 arc fill\n");
  fprintf(fp,"  newpath   2.8   7.9   0.2 0 360 arc fill\n");
  fprintf(fp,"  newpath 502.6  35.0   0.4 0 360 arc fill\n");
  fprintf(fp,"  5 f0\n");
  fprintf(fp,"  215   5 moveto (sirius) show\n");
  fprintf(fp,"  176  56 moveto (procyon) show\n");
  fprintf(fp,"  175 115 moveto (pollux) show\n");
  fprintf(fp,"  182 132 moveto (castor) show\n");
  fprintf(fp,"  285  25 moveto (rigel) show\n");
  fprintf(fp,"  251  63 moveto (beteigeuse) show\n");
  fprintf(fp,"  303  86 moveto (aldebaran) show\n");
  fprintf(fp,"  417 108 moveto (hamel) show\n");
  fprintf(fp,"   79  76 moveto (regulus) show\n");
  fprintf(fp,"    5  81 moveto (denebola) show\n");
  fprintf(fp,"  466   5 moveto (deneb kaitos) show\n");
  fprintf(fp,"  6 f1 0.5 setgray\n");
  fprintf(fp,"   23  91 moveto (LEO) show\n");
  fprintf(fp,"  195 111 moveto (GEMINI) show\n");
  fprintf(fp,"  301 103 moveto (TAURUS) show\n");
  fprintf(fp,"  413  94 moveto (ARIES) show } def\n");
  fprintf(fp,"/DrawStars1 {\n");
  fprintf(fp,"  newpath 500.4 121.8   0.5 0 360 arc fill\n");
  fprintf(fp,"  newpath 496.9  46.5   0.8 0 360 arc fill\n");
  fprintf(fp,"  newpath 492.9  58.9   0.9 0 360 arc fill\n");
  fprintf(fp,"  newpath 490.1 101.7   0.5 0 360 arc fill\n");
  fprintf(fp,"  newpath 485.2  22.1   0.1 0 360 arc fill\n");
  fprintf(fp,"  newpath 483.1  61.3   0.8 0 360 arc fill\n");
  fprintf(fp,"  newpath 479.9  43.5   0.8 0 360 arc fill\n");
  fprintf(fp,"  newpath 479.4 145.9   0.2 0 360 arc fill\n");
  fprintf(fp,"  newpath 476.5  85.0   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath 473.2  30.8   0.1 0 360 arc fill\n");
  fprintf(fp,"  newpath 466.6   0.4   0.4 0 360 arc fill\n");
  fprintf(fp,"  newpath 465.1 108.5   0.7 0 360 arc fill\n");
  fprintf(fp,"  newpath 460.5 127.4   0.8 0 360 arc fill\n");
  fprintf(fp,"  newpath 455.0  88.8   0.4 0 360 arc fill\n");
  fprintf(fp,"  newpath 448.8  42.9   0.8 0 360 arc fill\n");
  fprintf(fp,"  newpath 447.6  11.8   0.8 0 360 arc fill\n");
  fprintf(fp,"  newpath 444.4  72.9   1.3 0 360 arc fill\n");
  fprintf(fp,"  newpath 437.7 101.5   0.7 0 360 arc fill\n");
  fprintf(fp,"  newpath 430.0  17.6   0.4 0 360 arc fill\n");
  fprintf(fp,"  newpath 428.9 143.6   0.4 0 360 arc fill\n");
  fprintf(fp,"  newpath 427.1  55.3   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath 423.7 146.0   0.8 0 360 arc fill\n");
  fprintf(fp,"  newpath 421.0  42.4   0.2 0 360 arc fill\n");
  fprintf(fp,"  newpath 418.8 103.9   0.4 0 360 arc fill\n");
  fprintf(fp,"  newpath 415.5  36.7   0.7 0 360 arc fill\n");
  fprintf(fp,"  newpath 415.3  10.9   1.0 0 360 arc fill\n");
  fprintf(fp,"  newpath 411.0  75.7   0.5 0 360 arc fill\n");
  fprintf(fp,"  newpath 408.8  85.0   0.5 0 360 arc fill\n");
  fprintf(fp,"  newpath 409.0 148.0   1.5 0 360 arc fill\n");
  fprintf(fp,"  newpath 400.3  28.7   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath 400.3  95.6   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath 389.4  12.9   0.5 0 360 arc fill\n");
  fprintf(fp,"  newpath 389.9  89.1   0.5 0 360 arc fill\n");
  fprintf(fp,"  newpath 387.6 104.7   0.6 0 360 arc fill\n");
  fprintf(fp,"  newpath 384.4  60.1   0.8 0 360 arc fill\n");
  fprintf(fp,"  newpath 380.6 136.1   0.1 0 360 arc fill\n");
  fprintf(fp,"  newpath 375.2  38.2   0.7 0 360 arc fill\n");
  fprintf(fp,"  newpath 369.4  54.5   0.4 0 360 arc fill\n");
  fprintf(fp,"  newpath 367.4 112.3   0.2 0 360 arc fill\n");
  fprintf(fp,"  newpath 366.1  78.5   0.8 0 360 arc fill\n");
  fprintf(fp,"  newpath 362.7  10.7   0.6 0 360 arc fill\n");
  fprintf(fp,"  newpath 359.9 138.6   0.2 0 360 arc fill\n");
  fprintf(fp,"  newpath 353.1  67.0   0.5 0 360 arc fill\n");
  fprintf(fp,"  newpath 352.1  30.3   0.6 0 360 arc fill\n");
  fprintf(fp,"  newpath 347.0 116.1   0.8 0 360 arc fill\n");
  fprintf(fp,"  newpath 345.7 138.6   0.6 0 360 arc fill\n");
  fprintf(fp,"  newpath 343.9 145.4   0.5 0 360 arc fill\n");
  fprintf(fp,"  newpath 343.3  93.6   0.6 0 360 arc fill\n");
  fprintf(fp,"  newpath 342.3  19.1   0.5 0 360 arc fill\n");
  fprintf(fp,"  newpath 342.4 111.2   0.6 0 360 arc fill\n");
  fprintf(fp,"  newpath 338.5 139.2   0.5 0 360 arc fill\n");
  fprintf(fp,"  newpath 336.8  35.3   0.8 0 360 arc fill\n");
  fprintf(fp,"  newpath 335.8  46.6   0.9 0 360 arc fill\n");
  fprintf(fp,"  newpath 332.2  54.5   0.8 0 360 arc fill\n");
  fprintf(fp,"  newpath 331.4  12.0   0.4 0 360 arc fill\n");
  fprintf(fp,"  newpath 326.0  94.2   0.8 0 360 arc fill\n");
  fprintf(fp,"  newpath 323.2  91.7   0.7 0 360 arc fill\n");
  fprintf(fp,"  newpath 321.2  39.0   0.8 0 360 arc fill\n");
  fprintf(fp,"  newpath 320.7 147.9   0.6 0 360 arc fill\n");
  fprintf(fp,"  newpath 318.2 135.1   0.4 0 360 arc fill\n");
  fprintf(fp,"  newpath 315.4  36.1   1.3 0 360 arc fill\n");
  fprintf(fp,"  newpath 310.9  30.5   0.8 0 360 arc fill\n");
  fprintf(fp,"  newpath 310.0  76.4   0.9 0 360 arc fill\n");
  fprintf(fp,"  newpath 306.9  59.4   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath 300.9  15.7   0.9 0 360 arc fill\n");
  fprintf(fp,"  newpath 295.6 123.4   0.7 0 360 arc fill\n");
  fprintf(fp,"  newpath 290.2 131.9   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath 278.6  42.5   0.7 0 360 arc fill\n");
  fprintf(fp,"  newpath 274.9  29.7   0.4 0 360 arc fill\n");
  fprintf(fp,"  newpath 275.4  87.7   0.4 0 360 arc fill\n");
  fprintf(fp,"  newpath 272.5   8.2   0.8 0 360 arc fill\n");
  fprintf(fp,"  newpath 270.5   7.8   1.1 0 360 arc fill\n");
  fprintf(fp,"  newpath 269.5 131.4   1.0 0 360 arc fill\n");
  fprintf(fp,"  newpath 267.7  63.5   0.6 0 360 arc fill\n");
  fprintf(fp,"  newpath 264.3   2.6   0.9 0 360 arc fill\n");
  fprintf(fp,"  newpath 263.6 111.4   0.8 0 360 arc fill\n");
  fprintf(fp,"  newpath 260.7   0.3   0.7 0 360 arc fill\n");
  fprintf(fp,"  newpath 260.5 106.8   0.6 0 360 arc fill\n");
  fprintf(fp,"  newpath 259.1   7.6   0.7 0 360 arc fill\n");
  fprintf(fp,"  newpath 252.7  79.4   0.7 0 360 arc fill\n");
  fprintf(fp,"  newpath 251.5 107.3   0.5 0 360 arc fill\n");
  fprintf(fp,"  newpath 247.9  26.1   0.8 0 360 arc fill\n");
  fprintf(fp,"  newpath 246.9 123.9   0.6 0 360 arc fill\n");
  fprintf(fp,"  newpath 242.4  47.6   0.5 0 360 arc fill\n");
  fprintf(fp,"  newpath 239.7  11.9   0.7 0 360 arc fill\n");
  fprintf(fp,"  newpath 237.3  29.6   0.8 0 360 arc fill\n");
  fprintf(fp,"  newpath 237.1  97.2   0.7 0 360 arc fill\n");
  fprintf(fp,"  newpath 235.1  16.0   1.0 0 360 arc fill\n");
  fprintf(fp,"  newpath 232.4  38.6   0.8 0 360 arc fill\n");
  fprintf(fp,"  newpath 231.6  66.4   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath 221.5  80.7   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath 213.3  35.7   1.0 0 360 arc fill\n");
  fprintf(fp,"  newpath 212.6 110.5   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath 211.6  47.8   0.6 0 360 arc fill\n");
  fprintf(fp,"  newpath 210.3 137.7   0.5 0 360 arc fill\n");
  fprintf(fp,"  newpath 206.2 134.7   0.8 0 360 arc fill\n");
  fprintf(fp,"  newpath 205.6  92.2   0.6 0 360 arc fill\n");
  fprintf(fp,"  newpath 203.4   9.8   0.5 0 360 arc fill\n");
  fprintf(fp,"  newpath 203.2  47.6   0.8 0 360 arc fill\n");
  fprintf(fp,"  newpath 197.7  57.4   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath 197.5 129.0   0.2 0 360 arc fill\n");
  fprintf(fp,"  newpath 194.8  64.9   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath 193.3   1.5   0.5 0 360 arc fill\n");
  fprintf(fp,"  newpath 192.2 107.8   0.7 0 360 arc fill\n");
  fprintf(fp,"  newpath 191.1  29.4   0.1 0 360 arc fill\n");
  fprintf(fp,"  newpath 184.3  42.2   0.4 0 360 arc fill\n");
  fprintf(fp,"  newpath 184.2  82.6   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath 177.6 126.5   0.8 0 360 arc fill\n");
  fprintf(fp,"  newpath 176.8 146.3   0.5 0 360 arc fill\n");
  fprintf(fp,"  newpath 174.5  76.9   0.2 0 360 arc fill\n");
  fprintf(fp,"  newpath 174.5 122.2   1.3 0 360 arc fill\n");
  fprintf(fp,"  newpath 173.3 102.5   0.6 0 360 arc fill\n");
  fprintf(fp,"  newpath 171.3 116.0   0.6 0 360 arc fill\n");
  fprintf(fp,"  newpath 168.2  13.2   0.4 0 360 arc fill\n");
  fprintf(fp,"  newpath 168.9 148.7   0.6 0 360 arc fill\n");
  fprintf(fp,"  newpath 166.1  34.3   0.4 0 360 arc fill\n");
  fprintf(fp,"  newpath 160.1 102.1   0.7 0 360 arc fill\n");
  fprintf(fp,"  newpath 155.4  71.4   0.6 0 360 arc fill\n");
  fprintf(fp,"  newpath 153.3  67.0   0.7 0 360 arc fill\n");
  fprintf(fp,"  newpath 144.8 128.3   0.5 0 360 arc fill\n");
  fprintf(fp,"  newpath 140.6 125.2   0.2 0 360 arc fill\n");
  fprintf(fp,"  newpath 140.0  55.3   0.2 0 360 arc fill\n");
  fprintf(fp,"  newpath 140.3 139.8   0.6 0 360 arc fill\n");
  fprintf(fp,"  newpath 137.6 137.7   0.4 0 360 arc fill\n");
  fprintf(fp,"  newpath 135.7  38.2   0.5 0 360 arc fill\n");
  fprintf(fp,"  newpath 134.6  78.7   0.6 0 360 arc fill\n");
  fprintf(fp,"  newpath 123.9   6.6   0.2 0 360 arc fill\n");
  fprintf(fp,"  newpath 121.0  37.5   0.4 0 360 arc fill\n");
  fprintf(fp,"  newpath 119.3  73.4   0.4 0 360 arc fill\n");
  fprintf(fp,"  newpath 114.9 113.1   0.5 0 360 arc fill\n");
  fprintf(fp,"  newpath 113.4  20.4   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath 111.5   2.0   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath 110.5 149.5   0.5 0 360 arc fill\n");
  fprintf(fp,"  newpath 107.3  46.0   0.6 0 360 arc fill\n");
  fprintf(fp,"  newpath 103.9  88.9   0.8 0 360 arc fill\n");
  fprintf(fp,"  newpath  97.9  61.7   0.6 0 360 arc fill\n");
  fprintf(fp,"  newpath  94.5  17.6   0.4 0 360 arc fill\n");
  fprintf(fp,"  newpath  95.1 124.7   1.3 0 360 arc fill\n");
  fprintf(fp,"  newpath  93.4  73.4   0.1 0 360 arc fill\n");
  fprintf(fp,"  newpath  93.1  60.3   0.8 0 360 arc fill\n");
  fprintf(fp,"  newpath  88.2   8.4   0.7 0 360 arc fill\n");
  fprintf(fp,"  newpath  83.2 132.8   0.1 0 360 arc fill\n");
  fprintf(fp,"  newpath  80.0 100.8   0.8 0 360 arc fill\n");
  fprintf(fp,"  newpath  79.5  69.7   0.4 0 360 arc fill\n");
  fprintf(fp,"  newpath  78.1  22.5   0.4 0 360 arc fill\n");
  fprintf(fp,"  newpath  76.9 115.5   0.6 0 360 arc fill\n");
  fprintf(fp,"  newpath  74.0  34.4   0.1 0 360 arc fill\n");
  fprintf(fp,"  newpath  72.2  84.5   0.5 0 360 arc fill\n");
  fprintf(fp,"  newpath  68.8  98.5   0.5 0 360 arc fill\n");
  fprintf(fp,"  newpath  68.9 130.5   0.2 0 360 arc fill\n");
  fprintf(fp,"  newpath  63.9   2.8   0.1 0 360 arc fill\n");
  fprintf(fp,"  newpath  59.7  51.8   0.2 0 360 arc fill\n");
  fprintf(fp,"  newpath  59.3 100.3   0.5 0 360 arc fill\n");
  fprintf(fp,"  newpath  55.5  32.6   0.5 0 360 arc fill\n");
  fprintf(fp,"  newpath  55.0 127.1   0.6 0 360 arc fill\n");
  fprintf(fp,"  newpath  49.3  69.0   0.5 0 360 arc fill\n");
  fprintf(fp,"  newpath  47.2  83.9   0.6 0 360 arc fill\n");
  fprintf(fp,"  newpath  45.7  64.6   0.7 0 360 arc fill\n");
  fprintf(fp,"  newpath  43.6  29.1   1.2 0 360 arc fill\n");
  fprintf(fp,"  newpath  38.7 138.0   0.9 0 360 arc fill\n");
  fprintf(fp,"  newpath  35.4  47.9   0.6 0 360 arc fill\n");
  fprintf(fp,"  newpath  30.0 108.2   0.6 0 360 arc fill\n");
  fprintf(fp,"  newpath  28.8  21.3   0.4 0 360 arc fill\n");
  fprintf(fp,"  newpath  23.1 103.1   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath  21.6 131.9   0.4 0 360 arc fill\n");
  fprintf(fp,"  newpath  18.9   9.5   0.4 0 360 arc fill\n");
  fprintf(fp,"  newpath  14.0 114.1   0.5 0 360 arc fill\n");
  fprintf(fp,"  newpath  12.1  66.4   0.4 0 360 arc fill\n");
  fprintf(fp,"  newpath   7.8  30.3   0.4 0 360 arc fill\n");
  fprintf(fp,"  newpath   6.8  79.9   0.0 0 360 arc fill\n");
  fprintf(fp,"  newpath   5.3 147.8   0.2 0 360 arc fill\n");
  fprintf(fp,"  newpath   0.9  93.9   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath   0.5 117.2   0.5 0 360 arc fill\n");
  fprintf(fp,"  newpath 503.4 116.5   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath 489.8 108.3   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath 484.1   2.6   0.1 0 360 arc fill\n");
  fprintf(fp,"  newpath 480.5  72.1   0.1 0 360 arc fill\n");
  fprintf(fp,"  newpath 478.2  89.6   0.0 0 360 arc fill\n");
  fprintf(fp,"  newpath 474.7 125.6   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath 472.1 119.2   0.2 0 360 arc fill\n");
  fprintf(fp,"  newpath 468.5  20.0   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath 466.0  78.8   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath 462.2  94.5   0.1 0 360 arc fill\n");
  fprintf(fp,"  newpath 450.2  23.8   0.2 0 360 arc fill\n");
  fprintf(fp,"  newpath 449.7 113.7   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath 449.1  55.8   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath 443.3  71.8   0.2 0 360 arc fill\n");
  fprintf(fp,"  newpath 442.1 134.4   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath 438.1 109.1   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath 437.1  88.5   0.1 0 360 arc fill\n");
  fprintf(fp,"  newpath 432.9  81.8   0.2 0 360 arc fill\n");
  fprintf(fp,"  newpath 430.9  60.4   0.1 0 360 arc fill\n");
  fprintf(fp,"  newpath 420.0  37.5   0.1 0 360 arc fill\n");
  fprintf(fp,"  newpath 407.0  56.8   0.0 0 360 arc fill\n");
  fprintf(fp,"  newpath 406.6  68.4   0.4 0 360 arc fill\n");
  fprintf(fp,"  newpath 406.5 132.5   0.1 0 360 arc fill\n");
  fprintf(fp,"  newpath 405.6   9.7   0.5 0 360 arc fill\n");
  fprintf(fp,"  newpath 403.1 114.6   0.2 0 360 arc fill\n");
  fprintf(fp,"  newpath 402.6  42.0   0.2 0 360 arc fill\n");
  fprintf(fp,"  newpath 401.5 148.1   0.2 0 360 arc fill\n");
  fprintf(fp,"  newpath 390.8 129.2   0.1 0 360 arc fill\n");
  fprintf(fp,"  newpath 386.6  35.2   0.2 0 360 arc fill\n");
  fprintf(fp,"  newpath 384.5  65.0   0.2 0 360 arc fill\n");
  fprintf(fp,"  newpath 381.0  19.6   0.2 0 360 arc fill\n");
  fprintf(fp,"  newpath 380.3  73.5   0.1 0 360 arc fill\n");
  fprintf(fp,"  newpath 379.8  48.5   0.1 0 360 arc fill\n");
  fprintf(fp,"  newpath 379.7 100.4   0.1 0 360 arc fill\n");
  fprintf(fp,"  newpath 377.3  81.3   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath 367.8  23.8   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath 363.0   1.6   0.7 0 360 arc fill\n");
  fprintf(fp,"  newpath 361.8  12.1   0.4 0 360 arc fill\n");
  fprintf(fp,"  newpath 358.2  61.8   0.1 0 360 arc fill\n");
  fprintf(fp,"  newpath 354.1  75.2   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath 348.6  54.2   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath 340.7  50.4   0.2 0 360 arc fill\n");
  fprintf(fp,"  newpath 337.3  65.7   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath 335.8  61.3   0.1 0 360 arc fill\n");
  fprintf(fp,"  newpath 335.4  81.0   0.1 0 360 arc fill\n");
  fprintf(fp,"  newpath 330.3 142.6   0.2 0 360 arc fill\n");
  fprintf(fp,"  newpath 329.6 115.9   0.0 0 360 arc fill\n");
  fprintf(fp,"  newpath 322.3  27.3   0.1 0 360 arc fill\n");
  fprintf(fp,"  newpath 320.5 102.6   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath 319.1 117.4   0.0 0 360 arc fill\n");
  fprintf(fp,"  newpath 315.2  66.4   0.1 0 360 arc fill\n");
  fprintf(fp,"  newpath 314.0  16.8   0.4 0 360 arc fill\n");
  fprintf(fp,"  newpath 310.5  95.8   0.1 0 360 arc fill\n");
  fprintf(fp,"  newpath 301.1  77.0   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath 299.7   5.1   0.7 0 360 arc fill\n");
  fprintf(fp,"  newpath 298.2 125.4   0.4 0 360 arc fill\n");
  fprintf(fp,"  newpath 293.3  90.6   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath 288.2  59.0   0.0 0 360 arc fill\n");
  fprintf(fp,"  newpath 287.1  76.3   0.1 0 360 arc fill\n");
  fprintf(fp,"  newpath 282.1  21.7   0.1 0 360 arc fill\n");
  fprintf(fp,"  newpath 282.4 103.0   0.0 0 360 arc fill\n");
  fprintf(fp,"  newpath 279.8 145.1   0.2 0 360 arc fill\n");
  fprintf(fp,"  newpath 275.5  40.4   0.5 0 360 arc fill\n");
  fprintf(fp,"  newpath 275.4 110.4   0.4 0 360 arc fill\n");
  fprintf(fp,"  newpath 269.7  73.1   0.1 0 360 arc fill\n");
  fprintf(fp,"  newpath 263.6  49.2   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath 260.7  34.6   0.5 0 360 arc fill\n");
  fprintf(fp,"  newpath 252.0 141.9   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath 237.4 108.4   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath 234.0 120.1   0.1 0 360 arc fill\n");
  fprintf(fp,"  newpath 231.2 100.0   0.2 0 360 arc fill\n");
  fprintf(fp,"  newpath 230.2 142.3   0.1 0 360 arc fill\n");
  fprintf(fp,"  newpath 227.4  80.6   0.5 0 360 arc fill\n");
  fprintf(fp,"  newpath 226.5 122.8   0.2 0 360 arc fill\n");
  fprintf(fp,"  newpath 225.5  48.5   0.0 0 360 arc fill\n");
  fprintf(fp,"  newpath 222.4  77.6   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath 220.0  37.5   0.7 0 360 arc fill\n");
  fprintf(fp,"  newpath 219.0  91.9   0.4 0 360 arc fill\n");
  fprintf(fp,"  newpath 219.1 145.5   0.4 0 360 arc fill\n");
  fprintf(fp,"  newpath 213.1  60.9   0.1 0 360 arc fill\n");
  fprintf(fp,"  newpath 205.1  34.2   0.7 0 360 arc fill\n");
  fprintf(fp,"  newpath 201.1  84.8   0.2 0 360 arc fill\n");
  fprintf(fp,"  newpath 196.2  13.6   0.1 0 360 arc fill\n");
  fprintf(fp,"  newpath 192.5 129.9   0.2 0 360 arc fill\n");
  fprintf(fp,"  newpath 191.5 149.7   0.0 0 360 arc fill\n");
  fprintf(fp,"  newpath 188.5  97.0   0.2 0 360 arc fill\n");
  fprintf(fp,"  newpath 186.1 118.4   0.4 0 360 arc fill\n");
  fprintf(fp,"  newpath 181.5  60.7   0.2 0 360 arc fill\n");
  fprintf(fp,"  newpath 181.3 143.7   0.4 0 360 arc fill\n");
  fprintf(fp,"  newpath 180.2  60.3   0.2 0 360 arc fill\n");
  fprintf(fp,"  newpath 177.8  24.8   0.1 0 360 arc fill\n");
  fprintf(fp,"  newpath 177.5  54.4   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath 172.7  92.8   0.1 0 360 arc fill\n");
  fprintf(fp,"  newpath 169.4  63.7   0.2 0 360 arc fill\n");
  fprintf(fp,"  newpath 165.1 118.2   0.1 0 360 arc fill\n");
  fprintf(fp,"  newpath 158.0 138.0   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath 155.6  71.3   0.4 0 360 arc fill\n");
  fprintf(fp,"  newpath 155.4  49.5   0.0 0 360 arc fill\n");
  fprintf(fp,"  newpath 151.8 113.4   0.2 0 360 arc fill\n");
  fprintf(fp,"  newpath 150.2  31.7   0.0 0 360 arc fill\n");
  fprintf(fp,"  newpath 147.2  97.2   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath 145.3  79.6   0.1 0 360 arc fill\n");
  fprintf(fp,"  newpath 139.8  18.6   0.1 0 360 arc fill\n");
  fprintf(fp,"  newpath 135.3 140.3   0.4 0 360 arc fill\n");
  fprintf(fp,"  newpath 134.6  87.6   0.4 0 360 arc fill\n");
  fprintf(fp,"  newpath 131.7  37.3   0.5 0 360 arc fill\n");
  fprintf(fp,"  newpath 131.1  82.5   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath 127.6  60.1   0.0 0 360 arc fill\n");
  fprintf(fp,"  newpath 125.1  20.6   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath 121.8  58.1   0.5 0 360 arc fill\n");
  fprintf(fp,"  newpath 118.8 125.3   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath 116.7  34.0   0.1 0 360 arc fill\n");
  fprintf(fp,"  newpath 110.4  62.1   0.4 0 360 arc fill\n");
  fprintf(fp,"  newpath 109.1  72.2   0.1 0 360 arc fill\n");
  fprintf(fp,"  newpath 103.4  19.9   0.0 0 360 arc fill\n");
  fprintf(fp,"  newpath  99.6  84.6   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath  99.6 148.3   0.1 0 360 arc fill\n");
  fprintf(fp,"  newpath  92.9 106.7   0.1 0 360 arc fill\n");
  fprintf(fp,"  newpath  88.7  68.9   0.2 0 360 arc fill\n");
  fprintf(fp,"  newpath  79.7   3.9   0.4 0 360 arc fill\n");
  fprintf(fp,"  newpath  68.9  49.0   0.2 0 360 arc fill\n");
  fprintf(fp,"  newpath  66.3 103.4   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath  63.6 122.8   0.1 0 360 arc fill\n");
  fprintf(fp,"  newpath  62.5  76.7   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath  61.9  20.9   0.4 0 360 arc fill\n");
  fprintf(fp,"  newpath  57.6  90.6   0.2 0 360 arc fill\n");
  fprintf(fp,"  newpath  50.7  54.0   0.2 0 360 arc fill\n");
  fprintf(fp,"  newpath  48.3   2.9   0.1 0 360 arc fill\n");
  fprintf(fp,"  newpath  39.6  16.9   0.2 0 360 arc fill\n");
  fprintf(fp,"  newpath  39.3 109.6   0.4 0 360 arc fill\n");
  fprintf(fp,"  newpath  37.1 123.5   0.4 0 360 arc fill\n");
  fprintf(fp,"  newpath  33.8 121.8   0.2 0 360 arc fill\n");
  fprintf(fp,"  newpath  32.0  85.1   0.4 0 360 arc fill\n");
  fprintf(fp,"  newpath  30.9  77.7   0.4 0 360 arc fill\n");
  fprintf(fp,"  newpath  28.7  79.0   0.3 0 360 arc fill\n");
  fprintf(fp,"  newpath  27.1  37.5   0.1 0 360 arc fill\n");
  fprintf(fp,"  newpath  25.9  50.3   0.5 0 360 arc fill\n");
  fprintf(fp,"  newpath  22.4 115.9   0.4 0 360 arc fill\n");
  fprintf(fp,"  newpath  13.6  20.2   0.2 0 360 arc fill\n");
  fprintf(fp,"  newpath  12.6 104.5   0.4 0 360 arc fill\n");
  fprintf(fp,"  newpath  11.1  55.7   0.2 0 360 arc fill\n");
  fprintf(fp,"  newpath   8.4  96.9   0.1 0 360 arc fill\n");
  fprintf(fp,"  newpath   5.2 127.4   0.2 0 360 arc fill\n");
  fprintf(fp,"  5 f0\n");
  fprintf(fp,"  404 142 moveto (arctur) show\n");
  fprintf(fp,"  173 117 moveto (altair) show\n");
  fprintf(fp,"   90 119 moveto (enif) show\n");
  fprintf(fp,"  260 126 moveto (ras alhague) show\n");
  fprintf(fp,"   47  27 moveto (fomalhaut) show\n");
  fprintf(fp,"  309  38 moveto (antares) show\n");
  fprintf(fp,"  441  67 moveto (spica) show\n");
  fprintf(fp,"  350 115 moveto (unuk) show\n");
  fprintf(fp,"  6 f1 0.5 setgray\n");
  fprintf(fp,"  454  77 moveto (VIRGO) show\n");
  fprintf(fp,"  369  64 moveto (LIBRA) show\n");
  fprintf(fp,"  289  20 moveto (SCORPIO) show\n");
  fprintf(fp,"  216  28 moveto (SAGITTARIUS) show\n");
  fprintf(fp,"  118  63 moveto (CAPRICORN) show\n");
  fprintf(fp,"   69  83 moveto (AQUARIUS) show\n");
  fprintf(fp,"    5  67 moveto (PISCES) show } def\n");
  fprintf(fp,"%%%%EndProlog\n");
  fprintf(fp,"%%%%Page: 1 1\n");
  fprintf(fp,"newpath 50 70 moveto 500 0 rlineto 0 700 rlineto -500 0 rlineto  closepath clip newpath\n");
  fprintf(fp,"0.5 setgray\n1.0 setlinewidth\n");
  fprintf(fp,"  10 755 moveto 24 f0 ( Nautical Almanac  Nautical Almanac  Nautical Almanac  Nautical Almanac) show\n");
  fprintf(fp,"  10 725 moveto 36 f3 ( Nautical Almanac  Nautical Almanac  Nautical Almanac  Nautical Almanac) show\n");
  fprintf(fp," -50 700 moveto 24 f7 ( Nautical Almanac  Nautical Almanac  Nautical Almanac  Nautical Almanac) show\n");
  fprintf(fp,"  10 660 moveto 48 f2 ( Nautical Almanac  Nautical Almanac  Nautical Almanac  Nautical Almanac) show\n");
  fprintf(fp,"-120 625 moveto 36 f6 ( Nautical Almanac  Nautical Almanac  Nautical Almanac  Nautical Almanac) show\n");
  fprintf(fp,"  50 600 moveto 24 f0 ( Nautical Almanac  Nautical Almanac  Nautical Almanac  Nautical Almanac) show\n");
  fprintf(fp,"  40 560 moveto 48 f4 ( Nautical Almanac  Nautical Almanac  Nautical Almanac  Nautical Almanac) show\n");
  fprintf(fp,"  10 535 moveto 24 f3 ( Nautical Almanac  Nautical Almanac  Nautical Almanac  Nautical Almanac) show\n");
  fprintf(fp,"   0 505 moveto 36 f5 ( Nautical Almanac  Nautical Almanac  Nautical Almanac  Nautical Almanac) show\n");
  fprintf(fp," -20 480 moveto 24 f0 ( Nautical Almanac  Nautical Almanac  Nautical Almanac  Nautical Almanac) show\n");
  fprintf(fp,"  10 440 moveto 48 f0 ( Nautical Almanac  Nautical Almanac  Nautical Almanac  Nautical Almanac) show\n");
  fprintf(fp,"  10 405 moveto 36 f4 ( Nautical Almanac  Nautical Almanac  Nautical Almanac  Nautical Almanac) show\n");
  fprintf(fp,"  10 380 moveto 24 f3 ( Nautical Almanac  Nautical Almanac  Nautical Almanac  Nautical Almanac) show\n");
  fprintf(fp,"  40 355 moveto 24 f7 ( Nautical Almanac  Nautical Almanac  Nautical Almanac  Nautical Almanac) show\n");
  fprintf(fp,"  10 325 moveto 36 f0 ( Nautical Almanac  Nautical Almanac  Nautical Almanac  Nautical Almanac) show\n");
  fprintf(fp," -40 300 moveto 24 f5 ( Nautical Almanac  Nautical Almanac  Nautical Almanac  Nautical Almanac) show\n");
  fprintf(fp,"  10 280 moveto 24 f4 ( Nautical Almanac  Nautical Almanac  Nautical Almanac  Nautical Almanac) show\n");
  fprintf(fp,"  10 240 moveto 48 f1 ( Nautical Almanac  Nautical Almanac  Nautical Almanac  Nautical Almanac) show\n");
  fprintf(fp,"  10 210 moveto 24 f0 ( Nautical Almanac  Nautical Almanac  Nautical Almanac  Nautical Almanac) show\n");
  fprintf(fp,"  10 180 moveto 36 f6 ( Nautical Almanac  Nautical Almanac  Nautical Almanac  Nautical Almanac) show\n");
  fprintf(fp,"  10 155 moveto 24 f2 ( Nautical Almanac  Nautical Almanac  Nautical Almanac  Nautical Almanac) show\n");
  fprintf(fp," -30 115 moveto 48 f3 ( Nautical Almanac  Nautical Almanac  Nautical Almanac  Nautical Almanac) show\n");
  fprintf(fp,"  40  95 moveto 24 f4 ( Nautical Almanac  Nautical Almanac  Nautical Almanac  Nautical Almanac) show\n");
  fprintf(fp,"  10  70 moveto 36 f5 ( Nautical Almanac  Nautical Almanac  Nautical Almanac  Nautical Almanac) show\n");
  fprintf(fp,"gsave\n");
  fprintf(fp,"1.0 0.3 scale\n");
  fprintf(fp,"1.0 setgray\n");
  fprintf(fp,"newpath 300 900 228 0 360 arc fill\n");
  fprintf(fp,"0.0 setgray\n2.0 setlinewidth\n");
  fprintf(fp,"newpath 300 900 220 0 360 arc stroke\n");
  fprintf(fp,"grestore\n");
  fprintf(fp,"0.0 setgray\n");
  fprintf(fp,"300 290 moveto 16 f0 (Nautical Almanac) Cshow\n");
  fprintf(fp,"300 240 moveto 48 f0 (%d) Cshow\n",year);
  fprintf(fp,"showpage\n");

  return;
}



void InsertBlankPage(FILE *fp, int *page)
{ 
  fprintf(fp,"%%%%Page: %d %d\n",*page,*page);
  fprintf(fp,"0.99 setgray 300 400 moveto 36 f0 (Blank Page) Cshow\n");
  fprintf(fp,"showpage\n");

  *page = (*page)+1;

  return;
}





/* -------------------------------------------------------------------------------------------------------------- */


void InsertIntro0(FILE *fp, int *page, int year)
{
  int        i,j;
  char       timestring[64];
  struct tm *timeptr;
  time_t     now;
  
  double     delta_t[12];
  double     JD;
  double     deltaT();

  for(i=0; i<12; i++)
  { JD=julian_date((short int)year,(short int)i+1,15,0.0);
    delta_t[i]=deltaT(JD);
  }
  

  now=time(NULL);
  timeptr=localtime(&now);
  strcpy(timestring,asctime(timeptr));
  for(i=0; i<64; i++) if(timestring[i]=='\n') timestring[i]='\0';

  InsertBlankPage(fp,page);

  fprintf(fp,"%%%%Page: %d %d\n",*page,*page);
  fprintf(fp,"gsave\n");
  fprintf(fp,"54 0 translate\n");
  fprintf(fp,"  0.0 422.5 moveto 18 f1 (The Nautical Almanac %d) show\n",year);
  fprintf(fp,"  0.0 196.5 moveto 10 f0 (Warning and Terms of Usage:) show\n");
  fprintf(fp,"  0.0 169.9 moveto 10 f0 (The  following pages  have been generated  by a computer program.) show\n");
  fprintf(fp,"475.0 169.9 moveto 10 f0 (Complex computer programs usually) Rshow\n");
  fprintf(fp,"  0.0 156.6 moveto 10 f0 (have bugs and may produce wrong data.) show\n");
  fprintf(fp,"475.0 156.6 moveto 10 f0 (The data in this  Nautical Almanac  is believed to be accurate but) Rshow\n");
  fprintf(fp,"  0.0 143.3 moveto 10 f0 (no warranty is given for its correctness.) show\n");
  fprintf(fp,"  0.0 130.0 moveto 10 f0 (Use this Nautical Almanac only for training and exercising!) show\n");
  fprintf(fp,"  0.0  90.1 moveto 10 f0 (Compiled by Erik De Man  \\(erik.de.man@freenet.de\\)  on %s) show\n",timestring);

  fprintf(fp,"grestore\n");
  fprintf(fp,"showpage\n");

  *page = (*page)+1;

  InsertBlankPage(fp,page);

  fprintf(fp,"%%%%Page: %d %d\n",*page,*page);
  fprintf(fp,"gsave\n");
  fprintf(fp,"54 0 translate\n");
  fprintf(fp,"  0.0 744.1 moveto 18 f1 (Introduction) show\n");
  fprintf(fp,"  0.0 715.2 moveto 10 f0 (This  Nautical Almanac  contains  the Ephemerides of) show\n");
  fprintf(fp,"475.0 715.2 moveto 10 f0 (the Sun, the Moon, Venus, Mars, Jupiter and Saturn.) Rshow\n");
  fprintf(fp,"  0.0 701.9 moveto 10 f0 (It  is  designed  for  determination  of  Position) show\n");
  fprintf(fp,"475.0 701.9 moveto 10 f0 (\\(geographical  Latitude  and  Longitude\\)  from  astronomical) Rshow\n");
  fprintf(fp,"  0.0 688.6 moveto 10 f0 (observations \\(Altitude of Celestial Objects\\). ) show\n");
  fprintf(fp,"  0.0 662.0 moveto 10 f0 (The  data  compiled  in  this  Nautical Almanac  is  based on  calculations) show\n");
  fprintf(fp,"475.0 662.0 moveto 10 f0 (done  with  the  software package) Rshow\n");
  fprintf(fp,"  0.0 648.7 moveto 10 f0 (\"NOVAS\"  from the U.S. Naval Observatory \\(http://aa.usno.navy.mil/AA/software\\).) show\n");
  fprintf(fp,"475.0 648.7 moveto 10 f0 (The basic ephemerides) Rshow\n");
  fprintf(fp,"  0.0 635.4 moveto 10 f0 (are taken from the \"DE405\" files published by the Jet Propulsion Laboratory \\(http://ssd.jpl.nasa.gov\\). ) show\n");

  fprintf(fp,"  0.0 608.8 moveto 10 f0 (For the  astrodynamical  calculations, the following values for  \"delta T\") show\n");
  fprintf(fp,"475.0 608.8 moveto 10 f0 (\\(the  difference  between  terrestrial) Rshow\n");
  fprintf(fp,"  0.0 595.5 moveto 10 f0 (time realized by atomic clocks and UT defined by the irregular rotation of the Earth\\)  have been used:) show\n");
  fprintf(fp,"  5.0 582.2 moveto 10 f0 (Jan) show\n");
  fprintf(fp,"  5.0 568.9 moveto 10 f0 (Feb) show\n");
  fprintf(fp,"  5.0 555.6 moveto 10 f0 (Mar) show\n");
  fprintf(fp," 85.0 582.2 moveto 10 f0 (Apr) show\n");
  fprintf(fp," 85.0 568.9 moveto 10 f0 (May) show\n");
  fprintf(fp," 85.0 555.6 moveto 10 f0 (Jun) show\n");
  fprintf(fp,"165.0 582.2 moveto 10 f0 (Jul) show\n");
  fprintf(fp,"165.0 568.9 moveto 10 f0 (Aug) show\n");
  fprintf(fp,"165.0 555.6 moveto 10 f0 (Sep) show\n");
  fprintf(fp,"245.0 582.2 moveto 10 f0 (Oct) show\n");
  fprintf(fp,"245.0 568.9 moveto 10 f0 (Nov) show\n");
  fprintf(fp,"245.0 555.6 moveto 10 f0 (Dec) show\n");

  for(i=0; i<4; i++)
    for(j=0; j<3; j++) fprintf(fp,"%5.1f %5.1f moveto 10 f4 (:%5.1f) show\n",24.0+80.0*i,582.2-j*13.3,delta_t[i*3+j]);

  for(i=0; i<4; i++)
    for(j=0; j<3; j++) fprintf(fp,"%5.1f %5.1f moveto 10 f4 (s) show\n",64.0+80.0*i,582.2-j*13.3);

  fprintf(fp,"  0.0 502.4 moveto 10 f0 (NOTICE: ) show\n");
  fprintf(fp,"  0.0 489.1 moveto 10 f0 (This Nautical Almanac  uses a slightly different approach for the) show\n");
  fprintf(fp,"475.0 489.1 moveto 10 f0 (interpolation  of the integral-hour values of) Rshow\n");
  fprintf(fp,"  0.0 475.8 moveto 10 f0 (Greenwhich Hour Angle and Declination,  compared) show\n");
  fprintf(fp,"475.0 475.8 moveto 10 f0 (to the techniques used in most commercially available) Rshow\n");
  fprintf(fp,"  0.0 462.5 moveto 10 f0 (Almanacs.) show\n");
  fprintf(fp,"  0.0 449.2 moveto 10 f0 (For more information please refer to the following web site:) show\n");
  fprintf(fp,"264.0 449.2 moveto 10 f2 (\"http://www.erikdeman.de/\" ) show\n");

  fprintf(fp,"grestore\n");
  fprintf(fp,"showpage\n");

  *page = (*page)+1;


   InsertBlankPage(fp,page);

  fprintf(fp,"%%%%Page: %d %d\n",*page,*page);
  fprintf(fp,"gsave\n");
  fprintf(fp,"54 0 translate\n");
  fprintf(fp,"  0.0 744.1 moveto 18 f1 (Positions of the Celestial Objects) show\n");
  fprintf(fp,"  0.0 715.2 moveto 10 f0 (The charts on the following pages  show the position of  the Celestial Objects) show\n");
  fprintf(fp,"475.0 715.2 moveto 10 f0 (used in this Nautical Almanac) Rshow\n");
  fprintf(fp,"  0.0 701.9 moveto 10 f0 (relative to the stars \\(celestial background\\).) show\n");
  fprintf(fp,"475.0 701.9 moveto 10 f0 (The charts  can be used to find  the location of the planets  and) Rshow\n");
  fprintf(fp,"  0.0 688.6 moveto 10 f0 (also for the planning of astronomical observations.) show\n");
  fprintf(fp,"  0.0 662.0 moveto 10 f0 (The charts are available for each month of the year.) show\n");
  fprintf(fp,"475.0 662.0 moveto 10 f0 (Each chart has two parts showing a part of the celestial) Rshow\n");
  fprintf(fp,"  0.0 648.7 moveto 10 f0 (sphere around the ecliptic.) show\n");
  fprintf(fp,"475.0 648.7 moveto 10 f0 (Notice that the position of  the Celestial Equator \\(Declination = 0\\260\\) is shifted  in) Rshow\n");
  fprintf(fp,"  0.0 635.4 moveto 10 f0 (the two different parts of a chart.) show\n");
  fprintf(fp,"  0.0 608.8 moveto 10 f0 (The changing position  of a Celestial Object  through the  month is drawn) show\n");
  fprintf(fp,"475.0 608.8 moveto 10 f0 (as a solid  line \\(not for the Moon\\).) Rshow\n");
  fprintf(fp,"  0.0 595.5 moveto 10 f0 (Marker tics are shown to indicate the 1st, 8th 15th, 22nd and 29th day of the month \\(at 12:00 UT\\).) show\n");
  fprintf(fp,"  0.0 582.2 moveto 10 f0 (For  Jupiter  and  Saturn  only the  first  day of the month  is marked) show\n");
  fprintf(fp,"475.0 582.2 moveto 10 f0 (since  their  apparent positions  do not) Rshow\n");
  fprintf(fp,"  0.0 568.9 moveto 10 f0 (change significantly over the period of one month.) show\n");
  fprintf(fp,"  0.0 555.6 moveto 10 f0 (The position of the Moon  is shown  by a small circle  for each  individual day  of the month.) show\n");
  fprintf(fp,"475.0 555.6 moveto 10 f0 (Notice  that the) Rshow\n");
  fprintf(fp,"  0.0 542.3 moveto 10 f0 (circles are much larger than the apparent size of the Moon.) show\n");
  fprintf(fp,"grestore\n");
  fprintf(fp,"showpage\n");

  *page = (*page)+1;
  
  InsertBlankPage(fp,page);

  return;
}




/* -------------------------------------------------------------------------------------------------------------- */

void InsertIntro1(FILE *fp, int *page)
{ 

  fprintf(fp,"%%%%Page: %d %d\n",*page,*page);
  fprintf(fp,"gsave\n");
  fprintf(fp,"54 0 translate\n");
  fprintf(fp,"  0.0 744.1 moveto 18 f1 (Nautical Almanac) show\n");
  fprintf(fp,"  0.0 715.2 moveto 10 f0 (The following pages  contain  the coordinates of  the Geographical Position) show\n");
  fprintf(fp,"475.0 715.2 moveto 10 f0 (\\(in Greenwich Hour Angle  and) Rshow\n");
  fprintf(fp,"  0.0 701.9 moveto 10 f0 (Declination\\)  for each integral hour of the year for the recorded celestial objects.) show\n");
  fprintf(fp,"475.0 701.9 moveto 10 f0 (Each  page  compiles  the) Rshow\n");
  fprintf(fp,"  0.0 688.6 moveto 10 f0 (complete Almanac data for one day of the year. The time used in this Almanac is Universal Time \\(UT\\). ) show\n");

  fprintf(fp,"  0.0 622.1 moveto 10 f0 (NOTICE: ) show\n");
  fprintf(fp,"  0.0 608.8 moveto 10 f0 (This Nautical Almanac  uses a slightly different approach for the) show\n");
  fprintf(fp,"475.0 608.8 moveto 10 f0 (interpolation  of the integral-hour values of) Rshow\n");
  fprintf(fp,"  0.0 595.5 moveto 10 f0 (Greenwhich Hour Angle and Declination,  compared) show\n");
  fprintf(fp,"475.0 595.5 moveto 10 f0 (to the techniques used in most commercially available) Rshow\n");
  fprintf(fp,"  0.0 582.2 moveto 10 f0 (Almanacs.) show\n");
  fprintf(fp,"  0.0 568.9 moveto 10 f0 (For more information please refer to the following web site:) show\n");
  fprintf(fp,"264.0 568.9 moveto 10 f2 (\"http://www.erikdeman.de/\" ) show\n");

  fprintf(fp,"  0.0 489.1 moveto 10 f1 (Abbreviations used in the Almanac tables:) show\n");

  fprintf(fp,"  2.8 462.5 moveto 10 f0 (UT) show\n");
  fprintf(fp," 51.5 462.5 moveto 10 f0 (Universal Time) show\n");
  fprintf(fp,"  2.8 442.5 moveto 10 f0 (GHA) show\n");
  fprintf(fp," 51.5 442.5 moveto 10 f0 (Greenwich Hour Angle) show\n");
  fprintf(fp,"366.1 442.5 moveto 12 f0 (\\260) show\n");
  fprintf(fp,"385.9 442.5 moveto 10 f0 ([degrees]) show\n");
  fprintf(fp,"  2.8 422.5 moveto 10 f0 (Dec) show\n");
  fprintf(fp," 51.5 422.5 moveto 10 f0 (Declination) show\n");
  fprintf(fp,"366.1 422.5 moveto 12 f0 (\\260) show\n");
  fprintf(fp,"385.9 422.5 moveto 10 f0 ([degrees]) show\n");
  fprintf(fp,"  2.8 402.5 moveto 10 f0 (ddGHA) show\n");
  fprintf(fp," 51.5 402.5 moveto 10 f0 (the increment of the GHA value for the next hour of time,  ) show\n");
  fprintf(fp," 51.5 389.2 moveto 10 f0 (additional to the \"linear\" increment of 15\\260/h ) show\n");
  fprintf(fp,"366.1 402.5 moveto 12 f0 (') show\n");
  fprintf(fp,"385.9 402.5 moveto 10 f0 ([minutes of arc]) show\n");
  fprintf(fp,"  2.8 369.2 moveto 10 f0 (dDec) show\n");
  fprintf(fp," 51.5 369.2 moveto 10 f0 (the increment of the Dec value for the next hour of time) show\n");
  fprintf(fp,"366.1 369.2 moveto 12 f0 (') show\n");
  fprintf(fp,"385.9 369.2 moveto 10 f0 ([minutes of arc]) show\n");
  fprintf(fp,"  2.8 349.2 moveto 10 f0 (SD) show\n");
  fprintf(fp," 51.5 349.2 moveto 10 f0 (Semi-Diameter of the celestial object) show\n");
  fprintf(fp,"366.1 349.2 moveto 12 f0 (') show\n");
  fprintf(fp,"385.9 349.2 moveto 10 f0 ([minutes of arc]) show\n");
  fprintf(fp,"  2.8 329.2 moveto 10 f0 (HP) show\n");
  fprintf(fp," 51.5 329.2 moveto 10 f0 (Horizontal Parallax) show\n");
  fprintf(fp,"366.1 329.2 moveto 12 f0 (') show\n");
  fprintf(fp,"385.9 329.2 moveto 10 f0 ([minutes of arc]) show\n");

  fprintf(fp,"  2.8 309.2 moveto 10 f0 (a) show\n");
  fprintf(fp," 51.5 309.2 moveto 10 f0 (the \"age\" of the Moon, according to the following scheme:) show\n");
  fprintf(fp,"366.1 309.2 moveto 10 f0 (a = 0.00 : new moon) show\n");
  fprintf(fp,"366.1 295.9 moveto 10 f0 (a = 0.25 : first quarter) show\n");
  fprintf(fp,"366.1 282.6 moveto 10 f0 (a = 0.50 : full moon) show\n");
  fprintf(fp,"366.1 269.3 moveto 10 f0 (a = 0.75 : last quarter) show\n");

  fprintf(fp,"grestore\n");
  fprintf(fp,"showpage\n");

  *page = (*page)+1;

  InsertBlankPage(fp,page);

  return;
}






/* -------------------------------------------------------------------------------------------------------------- */

void DrawOrbits(FILE *fp, double oRA[][6], double oDec[][6], short int k, short int offset, int month, int year)

{ 
  int       m,n,obj;
  char     *planets[6] = {"Sun","Venus","Moon","Mars","Jupiter","Saturn"};
  char      mdays[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
  double    x,y,ra,dec;

  if((year%4)==0) mdays[1]++;

                         /* first plot the moon ... */
  obj=2;
  for(m=k; m<k+mdays[month-1]; m++)             /* k is the current day of the year starting from 0 */
  { ra = 15.0*oRA[m*24+12][obj];
    dec=oDec[m*24+12][obj];
    
    x=-99.0; y=-99.0;

    if(m==k) fprintf(fp,"0.1 setlinewidth\n");
    if( (offset%2)&&(ra>=178)) { x=(360.0-ra)*2.8; y=2.5*dec+100.0; }
    if(!(offset%2)&&(ra<=182)) { x=(180.0-ra)*2.8; y=2.5*dec+ 50.0; }

    if(x>-20)
    { fprintf(fp,"1.0 setgray newpath %.1f %.1f 5.4 0 360 arc fill\n",x,y);
      fprintf(fp,"0.0 setgray newpath %.1f %.1f 5 0 360 arc stroke\n",x,y);
      fprintf(fp,"%.1f %.1f moveto 5 f1 (%d) Cshow\n",x,y-1.6,m-k+1);
    }
  }

                         /* then plot the rest ... */
  for(obj=0; obj<6; obj++)
    if(obj!=2)
    { n=0;
      fprintf(fp,"0.7 setlinewidth\n");
      for(m=k; m<k+mdays[month-1]; m++)
      { ra = 15.0*oRA[m*24+12][obj];
        dec=oDec[m*24+12][obj];
       
        x=-99.0; y=-99.0;
        
        if( (offset%2)&&(ra>=178)) { x=(360.0-ra)*2.8; y=2.5*dec+100.0; }
        if( (offset%2)&&(ra<=  2)) { x=(     -ra)*2.8; y=2.5*dec+100.0; }
        if(!(offset%2)&&(ra<=182)) { x=(180.0-ra)*2.8; y=2.5*dec+ 50.0; }
        if(!(offset%2)&&(ra>=358)) { x=(540.0-ra)*2.8; y=2.5*dec+ 50.0; }
    
        if(x>-10)
        { if(n==0) { fprintf(fp,"newpath %.1f %.1f moveto\n",x,y); n=1; }
          fprintf(fp,"%.1f %.1f lineto\n",x,y);
        }
          else { if(n>0) fprintf(fp,"stroke\n"); n=0; }
      }
      if(n>0) fprintf(fp,"stroke\n");
    }

                         /* finally plot the markers and labels ... */
  for(obj=0; obj<6; obj++)
    if(obj!=2)
    { 
      fprintf(fp,"0.1 setlinewidth\n");
      for(m=k; m<k+mdays[month-1]; m+=7)
      { ra = 15.0*oRA[m*24+12][obj];
        dec=oDec[m*24+12][obj];

        x=-99.0; y=-99.0;

        if( (offset%2)&&(ra>=178)) { x=(360.0-ra)*2.8; y=2.5*dec+100.0; }
        if( (offset%2)&&(ra<=  2)) { x=(     -ra)*2.8; y=2.5*dec+100.0; }
        if(!(offset%2)&&(ra<=182)) { x=(180.0-ra)*2.8; y=2.5*dec+ 50.0; }
        if(!(offset%2)&&(ra>=358)) { x=(540.0-ra)*2.8; y=2.5*dec+ 50.0; }
   
        if(x>-10)
        { n=m-k+1; 
          fprintf(fp,"newpath %.1f %.1f moveto  0  4 rlineto stroke\n",x,y-2); 
          if(n==1 ) fprintf(fp,"%.1f %.1f moveto 5 f1 (1) Cshow\n",x,y+3);
          if(obj<4) fprintf(fp,"%.1f %.1f moveto 5 f1 (%d) Cshow\n",x,y+3,n);
          if(n==15) fprintf(fp,"%.1f %.1f moveto 6 f1 (%s) Cshow\n",x,y-7,planets[obj]);
        }
      }
    }

  return;
}




/* -------------------------------------------------------------------------------------------------------------- */

void FormatMapPages(double *oJD, double oRA[][6], double oDec[][6], int *page, FILE *fp)

{ short int year,month,day;
  short int m,k,pp;
  char     *months[12] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
  char      mdays[14] = {31,28,31,30,31,30,31,31,30,31,30,31,255,255};
  double    now,hour;

  now=oJD[0];                      /* determine which year is beeing plotted ...         */
  cal_date(now,&year,&month,&day,&hour);
  if((year%4)==0) mdays[1]++;


  k=0;                             /* k  is the current   day of the year  0 <  k < 366  */
  m=0;                             /* m  is the current month of the year  0 <= m <  12  */
  for(pp=0; pp<6; pp++)            /* pp is the current map page (2 maps per page)       */
  {
    fprintf(fp,"%%%%Page: %d %d\n",*page,*page);
    *page = (*page)+1;

    now=oJD[k];
    cal_date(now,&year,&month,&day,&hour);

    fprintf(fp,"gsave\n");
    fprintf(fp,"46  0 translate\n");
    fprintf(fp,"0 450 translate MakeFrame MakeMap0\n");
    fprintf(fp,"0.0 setgray 252 360 moveto 14 f0\n");
    fprintf(fp,"(%-9s  %4d) Cshow\n",months[month-1],year);
    DrawOrbits(fp,oRA,oDec,k,0,month,(int)year);
    fprintf(fp,"0 180 translate MakeFrame MakeMap1\n");
    DrawOrbits(fp,oRA,oDec,k,1,month,(int)year);

    k+=mdays[m]; m++;
    now=oJD[k];
    cal_date(now,&year,&month,&day,&hour);

    fprintf(fp,"0 -590 translate MakeFrame MakeMap0\n");
    fprintf(fp,"0.0 setgray 252 360 moveto 14 f0\n");
    fprintf(fp,"(%-9s  %4d) Cshow\n",months[month-1],year);
    DrawOrbits(fp,oRA,oDec,k,2,month,(int)year);
    fprintf(fp,"0 180 translate MakeFrame MakeMap1\n");
    DrawOrbits(fp,oRA,oDec,k,3,month,(int)year);
    fprintf(fp,"grestore\n");
    fprintf(fp,"showpage\n");
  
    k+=mdays[m]; m++;
  }

  return;
}







/* ======== last updated on 14 Oct 2010 ================================================================================= */
/* FormatAlmanacPages() generates the Postscript code for the daily Almanac pages on a "DIN A4" printer format.
 * Postscript uses a coordinate system that is device independent, that is, it doesn't rely on the resolution,
 * paper size, etc of the final output device. The initial coordinate system has the x axis to the right and
 * y axis upwards, the origin is located at the bottom left hand corner of the page. The units are of "points",
 * which are 1/72 of an inch long. The size of "DIN A4" paper is (210 × 297 mm) or (8.3 × 11.7 inch). In Postscript
 * points the size is approximately (596 x 824 points)!
 *
 * Here are the basic frame lines and their coordinates (without initial translate!):
 *
 *   770      +-+--------+--------+---------+-+ 
 *            | |        |        |         | |
 *   744      | +--------+--------+---------+ |
 *            | |        |        |         | |
 *            | |        |        |         | |
 *            | |        |        |         | |
 *            | |        |        |         | |
 *            | |        |        |         | |
 *   400      +-+--------+--------+---------+-+
 *            | |        |        |         | |
 *   374      | +--------+--------+---------+ |
 *            | |        |        |         | |
 *            | |        |        |         | |
 *            | |        |        |         | |
 *            | |        |        |         | |
 *            | |        |        |         | |
 *    30      +-+--------+--------+---------+-+
 *            0 0        1        3         5 5
 *            0 2        8        5         1 3
 *            2 7        9        1         3 8
 */

void FormatAlmanacPages(double *oJD, double oGha[][6], double oDec[][6], double oHP[][6], double oSD[][6], int *page,FILE *fp)
{ short int year,month,day;
  int       k,m,n,u,obj,ndays;
  int       wide_header = 0;

  char     *days[7] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
  char     *months[12] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
  char     *planets[6] = {"Sun","Venus","Moon","Mars","Jupiter","Saturn"};  
  char      sGha[12],sDec[12],sMin[12];

  double    now,hour;
  double    linespacing=10.0;
  double    x,y,y0,y1;

  now=oJD[0];
  cal_date(now,&year,&month,&day,&hour);

  if(year%4) ndays=365;
    else ndays=366;


  for(k=0; k<ndays; k++)
  {
    now=oJD[k];
    cal_date(now,&year,&month,&day,&hour);
  
    fprintf(fp,"%%%%Page: %d %d\n",*page,*page);
    fprintf(fp,"30 20 translate\n");

    fprintf(fp,"0.5 setlinewidth\n");
    /* for debugging: print the "boundary frame" (0,0) to (540,800) within which the page will be formatted ... */
    /*
    fprintf(fp,"newpath 0 0 moveto 540 0 lineto 540 800 lineto 0 800 lineto closepath stroke\n");
     */
    
    if(wide_header)
    { fprintf(fp,"  0 785 moveto 14 f0 (%4d) show\n",year);
      fprintf(fp,"270 785 moveto 14 f0 (%-9s %2d) Cshow\n",months[month-1],day);
      fprintf(fp,"540 785 moveto 14 f0 (%-9s) Rshow\n",days[((int)now+2)%7]);
    }
      else
      { fprintf(fp,"192 785 moveto 14 f0\n");
        fprintf(fp,"(%4d   %-9s  %2d    %-9s)show\n",year,months[month-1],day,days[((int)now+2)%7]);
      }
  
    /* print the basic frame of the tables */
    fprintf(fp,"0.5 setlinewidth\n");
    fprintf(fp,"  1  29 moveto 538 0 rlineto 0 742 rlineto -538 0 rlineto closepath  stroke\n");
    fprintf(fp,"  2  30 moveto 536 0 rlineto 0 740 rlineto -536 0 rlineto closepath  stroke\n");
    fprintf(fp,"  2  30 moveto 536 0 rlineto 0 370 rlineto -536 0 rlineto closepath  stroke\n");
    fprintf(fp,"  2 400 moveto 536 0 rlineto 0 370 rlineto -536 0 rlineto closepath  stroke\n");
    fprintf(fp,"  2  30 moveto  25 0 rlineto 0 740 rlineto  -25 0 rlineto closepath  stroke\n");
    fprintf(fp,"538  30 moveto -25 0 rlineto 0 740 rlineto   25 0 rlineto closepath  stroke\n");
/*
    fprintf(fp," 27 744 moveto 486 0 rlineto 0  26 rlineto -486 0 rlineto closepath  stroke\n");
    fprintf(fp," 27 374 moveto 486 0 rlineto 0  26 rlineto -486 0 rlineto closepath  stroke\n");
 */

  
    y0=716.0;
    for(n=0; n<4; n++)
    { y=y0-(int)(n/2)*370.0;
  
      fprintf(fp,"9 f1\n");
      fprintf(fp,"%.1f %.1f moveto (UT) show\n", 11.0+(n%2)*508.0, y-y0+736.0);
  
      for(u=0; u<24; u++)
      { x=11.0+(n%2)*508.0;
        fprintf(fp,"%.1f %.1f moveto (%02d) show\n",x,y,u);
        y-=linespacing;
        if(((u+1)%4)==0) y-=linespacing*0.5;
      }
    }
  
    for(obj=0; obj<6; obj++)
    { x=30.0+162.0*(obj%3);
      y=y0-(int)(obj/3)*370.0;
  
      fprintf(fp,"%.1f %.1f moveto 12 f3 (%s) Cshow\n",70.0+x,y-y0+752.0,planets[obj]);
      fprintf(fp,"%.1f %.1f moveto 162 0 rlineto 0 370 rlineto -162 0 rlineto closepath stroke\n",x-3,y-y0+400.0);
  
      fprintf(fp,"%.1f %.1f moveto  9 f4 (  GHA) show\n", x+  4.0,y-y0+736.0);
      fprintf(fp,"%.1f %.1f moveto  9 f4 (   Dec) show\n",x+ 80.0,y-y0+736.0);
      fprintf(fp,"%.1f %.1f moveto  7 f4 (ddGHA) show\n", x+ 50.0,y-y0+736.0);
      fprintf(fp,"%.1f %.1f moveto  7 f4 (dDec) show\n",  x+132.0,y-y0+736.0);
  

      fprintf(fp,"%.1f %.1f moveto  9 f4 (  \\260   ') show\n", x+  4.0,y-y0+724.0);
      fprintf(fp,"%.1f %.1f moveto  9 f4 (   \\260   ') show\n",x+ 80.0,y-y0+724.0);
      fprintf(fp,"%.1f %.1f moveto  7 f4 (   ') show\n",        x+ 50.0,y-y0+724.0);
      fprintf(fp,"%.1f %.1f moveto  7 f4 (   ') show\n",        x+132.0,y-y0+724.0);
  
      for(u=0; u<24; u++)
      { fprintf(fp,"%.1f %.1f moveto 9 f4 (%s) show\n",x+  4.0,y,gha2s(oGha[k*24+u][obj],sGha));
        fprintf(fp,"%.1f %.1f moveto 9 f4 (%s) show\n",x+ 80.0,y,dec2s(oDec[k*24+u][obj],sDec));
        fprintf(fp,"%.1f %.1f moveto 7 f4 (%s) show\n",x+ 50.0,y,dgha2s(oGha[k*24+u][obj],oGha[k*24+u+1][obj],sGha));
        fprintf(fp,"%.1f %.1f moveto 7 f4 (%s) show\n",x+132.0,y,ddec2s(oDec[k*24+u][obj],oDec[k*24+u+1][obj],sDec));
        y-=linespacing;
        if(((u+1)%4)==0) y-=linespacing*0.5;
      }
  
      y1 = y - linespacing*0.5;
      fprintf(fp,"%.1f %.1f moveto 7 f5 (UT) show\n",x+4.0,y1);
      fprintf(fp,"%.1f %.1f moveto 7 f4 (SD) show\n",x+4.0,y1- 8.0);
      fprintf(fp,"%.1f %.1f moveto 7 f4 (HP) show\n",x+4.0,y1-16.0);
      fprintf(fp,"%.1f %.1f moveto 7 f4 (Greenwich Culmination Time: %s) show\n",x+4.0,y1-28.0,gct2s(oGha,k,obj,sGha));

      for(u=2; u<24; u+=4)
      { fprintf(fp,"%.1f %.1f moveto 7 f5 (%02d) show\n",x+u*5.6+8.0,y1,u);
        fprintf(fp,"%.1f %.1f moveto 7 f4 (%s) show\n",x+u*5.6+8.0,y1- 8.0,min2s(oSD[k*24+u][obj],sMin));
        fprintf(fp,"%.1f %.1f moveto 7 f4 (%s) show\n",x+u*5.6+8.0,y1-16.0,min2s(oHP[k*24+u][obj],sMin));
      }
  

      if(obj==2)
      { m=(int)(oGha[k*24+12][0]-oGha[k*24+12][2]);   /* GHA-difference between Moon and Sun */
        if(m<0) m+=360;
        fprintf(fp,"%.1f %.1f moveto 7 f1 (a = %4.2f) show\n",100.0+x, 752.0, m/360.0);
      }
    }
  
    fprintf(fp,"  0 10 moveto 6 f0 (Warning:) show\n");
    fprintf(fp," 30 10 moveto 6 f0 (This page has been generated by a computer program.  Complex computer programs usually have bugs and may produce wrong data.) show\n");
    fprintf(fp,"538 10 moveto 6 f0 (The data on this page is believed to be accurate but no) Rshow\n");
    fprintf(fp," 30  2 moveto 6 f0 (warranty is given for its correctness. Use it only for training and exercising! ) show\n");
  
    fprintf(fp,"showpage\n");
    *page = (*page) + 1;
  }
  
  return;
}

