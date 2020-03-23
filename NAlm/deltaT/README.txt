
This directory contains downloaded files and scripts needed to evaluate:

  Delta T = 32.184 s + (TAI - UTC) - (UT1 - UTC)

  where (TAI - UTC) is the cumulative number of leap seconds available in the file "tai-utc.dat"
  and   (UT1 - UTC) is a standard Earth orientation product available e.g. in the file "finals.data"


The files "finals.data" and "tai-utc.dat" are downloaded from "ftp://maia.usno.navy.mil/ser7/" and are
used to generate prediction values for "deltaT" for the next 12 months.

After the files have been updated, the values for deltaT since the year 2000 and untill 12 months in
advance can be generated with the script "deltaT_script"

The values for deltaT are shown in a fromat that can be pasted directly in the source code of "../src/deltaT.c".
This is the pace to update the deltaT values for the nautical almanac.

-------------------------------------------------------------------------------------------------------------------------

UPDATE (Nov2006):
The file "tai-utc.dat" containing the accumulated leap seconds is no longer updated.
The values can be computed using the information provided in the weekly IERS Bulletin A General Information section.
"ftp://hpiers.obspm.fr/iers/bul/bulc/bulletinc.dat"

ALSO 
"ftp://hpiers.obspm.fr/iers/bul/bulc/UTC-TAI.history" may be used instead of "tai-utc.dat" 
which used to be downloaded from "ftp://maia.usno.navy.mil/ser7/".


-------------------------------------------------------------------------------------------------------------------------

UPDATE (Dec 2010):

The files "finals.data" and "tai-utc.dat" can further be downloaded from "ftp://maia.usno.navy.mil/ser7/"
Copy them into this directory and run the script "deltaT_script".
-------------------------------------------------------------------------------------------------------------------------
