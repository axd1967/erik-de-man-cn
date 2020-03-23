
Under a Unix/Linux operating system, executing 

> make

will compile the available modules according to the directives from the "Makefile"
and link an executable program called "NauticalAlmanac", which will be in the top
directory (where also this file is).



Executing 

> NauticalAlmanac <year e.g. 2001>

will generate the necessary data files in the subdirectory "Data" for the entered year.
These data files are : 

- a PostScript version of the Nautical Almanac for the year entered
- the JavaScript files containing the compressed data package for the epemerides.


Additional scripts in the "Data" directory allow to further process the generated PostScript
version of the Nautical Almanac. 

- SplitNAlm: will split the Nautical Almanac into 5 parts and convert each part into a PDF file
- MakeBook:  will generate a new PostScript file containing the Nautical Almanac resized to
             Din A5 size. This can then be printed double-sided on a normal Din A4 printer.



The subdirectory "deltaT" contains some data and script files to generate prediction
values for "delta T". "deltaT" is the difference between the terrestrial time used in
astrodynamical calculations and universal time (UT) used for celestial observations.


The file "JPLephemDE405.bin" is a dummy file and must be replaced with a file containing
the basic ephemerides. This file must be generated from the basic ephemerides files 
available from the Jet Propulsion Laboratory (JPL): 

ftp://ssd.jpl.nasa.gov/pub/eph/export/ascii/

e.g. ascp2000.405  
Read the README files in these download directories for further information on how to
convert the ASCII files into the binary ephemeride file "JPLephemDE405.bin".
