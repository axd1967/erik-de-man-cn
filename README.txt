This code archive has been generated on 
Thu Mar 15 12:26:26 CET 2012

========================================================================
This directory contains the different components for generating
the manuals required for traditional celestial navigation. 

Ageton:
contains the code to generate simplified tables suited for the process
of sight-reduction

Corrections: 
here is the code for generating the tables used to "correct" the
sextant altitude and convert it to a geo-centric comparable value.

Interpol:
the tables for perfoming interpolation required to obtain the 
correct values for GHA and Declination from the Nautical Almanac
as well as for interpolating the calculated Altitude obtained
from pre-calculated sight-reduction tables.

JPL: 
this directory contains the basic ephemerides. Read the HOWTO/README
files to find out how to download and generate the required files!

NAlm:
contains the code to generate the NAutical Almanac for a specified
year. The compiled code needs the basic ephemerides data of the 
JPL/ directory!

Novas:
here is the original code of the novas software package. It contains
some interesting background information on the available functions.

Scripts:
has some sripts for c-shell and bash shells

SightRed:
this contains the code for generating the pre-computed tables for
the sight-reduction process.


Each of the above sub-directories containing C-code are organized
as follows:
A subdirectory "src" comtains the source code, which can be compiled
by typing "make" in the directory in which the "Makefile" is available.
This will result in an executable file. The generated data are saved
in the "Data" subdirectory.


In case of trouble with the above stuff, please send an email to:
'erik.de.man@freenet.de'
