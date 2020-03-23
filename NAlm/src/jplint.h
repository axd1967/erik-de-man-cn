
#define ARRAY_SIZE 1018
#define EPHEMERIS   405

struct recOneData
{ char label[3][84];
  char constName[400][6];
  double timeData[3];
  long int numConst;
  double AU;
  double EMRAT;
  long int coeffPtr[12][3];
  long int DENUM;
  long int libratPtr[3];
};
typedef struct recOneData recOneType;

struct recTwoData
{ double constValue[400];
};
typedef struct recTwoData recTwoType;

struct headerOne
{ recOneType data;
  char pad[ARRAY_SIZE*sizeof(double) - sizeof(recOneType)];
};
typedef struct headerOne headOneType;

struct headerTwo
{ recTwoType data;
  char pad[ARRAY_SIZE*sizeof(double) - sizeof(recTwoType)];
};
typedef struct headerTwo headTwoType;

static headOneType  H1;
static headTwoType  H2;
static recOneType   R1;
static double       Coeff_Array[ARRAY_SIZE],JD0,JD1;

static double       EMRAT;
static double       AU;


#include <stdio.h>

static FILE  *EphemFile;

