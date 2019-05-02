#include <stdio.h>

/*
      Simple adding subroutine thrown in to allow subroutine
      calls/returns to be factored in as part of the benchmark.
*/

float pi(float sum,float addend) {
      return sum + addend;
}

