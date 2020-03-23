#
# MAKEFILE FOR COMPILING "NauticalAlmanc"
#
GCC = /usr/bin/gcc
GCC_OPTIONS = -O2 -Wall
#

NauticalAlmanac: include/novascon.o include/novas.o include/solsys.o include/readeph0.o include/jplint.o \
	include/deltaT.o include/convert.o include/trigo.o include/formatPS.o include/formatMoonPages.o \
	include/formatSunPages.o include/formatEquationOfTime.o include/generateJS.o \
        src/NauticalAlmanac.c  src/dimensions.h src/primitives.h
	$(GCC) -o NauticalAlmanac $(GCC_OPTIONS) include/novascon.o include/novas.o include/solsys.o \
        include/readeph0.o include/jplint.o include/deltaT.o include/convert.o include/trigo.o include/formatPS.o \
        include/formatMoonPages.o include/formatSunPages.o  include/formatEquationOfTime.o include/generateJS.o \
        src/NauticalAlmanac.c -lm

include/novascon.o: novas/novascon.c novas/novascon.h
	$(GCC) -o include/novascon.o $(GCC_OPTIONS) -c novas/novascon.c

include/novas.o: novas/novas.c novas/novas.h novas/solarsystem.h novas/readeph0.c
	$(GCC) -o include/novas.o $(GCC_OPTIONS) -c novas/novas.c

include/solsys.o: novas/solsys2.c novas/solarsystem.h novas/novas.h
	$(GCC) -o include/solsys.o $(GCC_OPTIONS) -c novas/solsys2.c

include/readeph0.o: novas/readeph0.c
	$(GCC) -o include/readeph0.o $(GCC_OPTIONS) -c novas/readeph0.c

include/jplint.o: src/jplint.c src/jplint.h
	$(GCC) -o include/jplint.o $(GCC_OPTIONS) -c src/jplint.c

include/deltaT.o: src/deltaT.c
	$(GCC) -o include/deltaT.o $(GCC_OPTIONS) -c src/deltaT.c

include/convert.o: src/convert.c
	$(GCC) -o include/convert.o $(GCC_OPTIONS) -c src/convert.c

include/trigo.o: src/trigo.c
	$(GCC) -o include/trigo.o $(GCC_OPTIONS) -c src/trigo.c

include/formatPS.o: src/formatPS.c
	$(GCC) -o include/formatPS.o $(GCC_OPTIONS) -c src/formatPS.c

include/formatMoonPages.o: src/formatMoonPages.c src/dimensions.h src/primitives.h
	$(GCC) -o include/formatMoonPages.o $(GCC_OPTIONS) -c src/formatMoonPages.c

include/formatSunPages.o: src/formatSunPages.c src/dimensions.h src/primitives.h
	$(GCC) -o include/formatSunPages.o $(GCC_OPTIONS) -c src/formatSunPages.c

include/formatEquationOfTime.o: src/formatEquationOfTime.c src/dimensions.h src/primitives.h
	$(GCC) -o include/formatEquationOfTime.o $(GCC_OPTIONS) -c src/formatEquationOfTime.c

include/generateJS.o: src/generateJS.c
	$(GCC) -o include/generateJS.o $(GCC_OPTIONS) -c src/generateJS.c

clean: 
	rm include/*.o
	rm NauticalAlmanac
