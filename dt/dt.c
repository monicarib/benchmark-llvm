#include <stdio.h>
#include <stdlib.h>
#include <math.h>

enum {
  ITERATIONS = 131072,
  size = 2048
};

static inline void
dt(double * __restrict dvec1, double * __restrict dvec2){
  long i, j;
  for(j = 0; j < ITERATIONS; j++)
    for(i = 0; i < size; i++)
      dvec1[i] /= dvec2[i];
}