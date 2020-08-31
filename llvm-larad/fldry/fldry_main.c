#include "fldry.h"

#ifndef extended
#define extended double
#endif

#pragma DATA_ALIGN(x, 8);
int main( argc, argv)
int argc;
char **argv;
{
 #pragma monitor start
	int result = fldry();
 #pragma monitor stop
if (result == 10) {
  return 10;
  } else {
    return 1;
    }
}
