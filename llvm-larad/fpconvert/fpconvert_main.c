#include "fpconvert.h"

#ifdef SMALL_PROBLEM_SIZE
#define COUNT 100000
#else
#define COUNT 500000
#endif
#pragma DATA_ALIGN(x, 8);
int main(int argc, char *argv[]) {
  int i, j;
  float x[2048];
  float y[2048];
  double total = 0.0;
  float a = 0.0f;
  float b = 1.0f;
//  for (i=0; i<COUNT; ++i) {
 #pragma monitor start
  for (i=0; i<100; ++i) {
    if (i % 10) {
      a = 0.0f;
      b = 1.0f;
    } else {
      a += 0.1f;
      b += 0.2f;
    }

    for (j=0; j<512; ++j) {
      x[j] = a + (float)j;
      y[j] = b + (float)j;
    }

    total += fpconvert(x, y, 512);
  }
 #pragma monitor stop
    double result = 4474300281.046806335;
    if(total - result > 0.000009){
        return 1;
      
    }
    return 10;
}
