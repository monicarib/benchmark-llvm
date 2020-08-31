#include "dt.h"

//static inline void dt(double * __restrict dvec1, double * __restrict dvec2, int ITERATIONS, int size){
void dt(double * __restrict dvec1, double * __restrict dvec2, int ITERATIONS, int size){
  long i, j;
  for(j = 0; j < ITERATIONS; j++)
    for(i = 0; i < size; i++)
      dvec1[i] /= dvec2[i];
}
