#include "dt.c"
#include <math.h>

int main(int argc, char *argv[]) {
  double	*dvec1, *dvec2;
  long i;

  posix_memalign((void**)&dvec1, 16, size * sizeof(double));
  posix_memalign((void**)&dvec2, 16, size * sizeof(double));

  //For sin(), cos() in <math.h> we need -lm option explicitly. 
  //gcc dt_main.c dt.c -o application -lm

  // With better alias analysis of posix_memalign, we'd avoid reloading
  // dvec1/dvec2 each time through the loop.
  for( i = 0; i < size; i++ ) {
          dvec1[i] = 1.0000001 * cos((double)(size - i));
          dvec2[i] = 1.0  + 0.0000000001 * sin((double)i);
  }

  dt( dvec1, dvec2 );
  if(dvec1[0] > 0.949733 && dvec1[0] < 0.949735){
    return 10;
  }
  return 1;
}