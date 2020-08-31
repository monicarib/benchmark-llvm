#include <stdio.h>
#include <stdlib.h>

double fpconvert(float *x, float *y, long length) {
  long i;
  double accumulator = 0.0;
  for (i=0; i<length; ++i) {
    accumulator += (double)(x[i] * y[i]);
  }
  return accumulator;
}