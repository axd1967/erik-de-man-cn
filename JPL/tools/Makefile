GCC = /usr/bin/gcc

all: convert.o append.o ephem_util.o
	$(GCC) -o ./bin/append append.o ephem_util.o -lm
	$(GCC) -o ./bin/convert convert.o ephem_util.o -lm
	rm *.o


ephem_util.o: src/ephem_types.h
	$(GCC) -c src/ephem_util.c

convert.o: src/ephem_util.h src/ephem_types.h
	$(GCC) -c src/convert.c

append.o: src/ephem_util.h src/ephem_types.h
	$(GCC) -c src/append.c
