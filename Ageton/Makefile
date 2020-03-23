#
# MAKEFILE FOR COMPILING "Ageton"
#
GCC_OPTIONS = -O2 -W
#
all: AgetonAnalysis AgetonCalculationScheme AgetonTables

AgetonAnalysis: src/AgetonAnalysis.c
	gcc -o AgetonAnalysis $(GCC_OPTIONS) src/AgetonAnalysis.c -lm

AgetonCalculationScheme: src/AgetonCalculationScheme.c
	gcc -o AgetonCalculationScheme  $(GCC_OPTIONS) src/AgetonCalculationScheme.c -lm

AgetonTables: src/AgetonTables.c
	gcc -o AgetonTables $(GCC_OPTIONS) src/AgetonTables.c -lm

clean: 
	rm -f AgetonAnalysis AgetonCalculationScheme AgetonTables
