#include <stdio.h>
#include <stdlib.h>
#include "fannkuch.h"

#define N 4
#pragma DATA_ALIGN(x, 8);
int main( int argc, char* argv[] )
{
    int i;
    // int n = 11;
    int n = 7;
    long *r_c;
    long expectedResult[N] = {16, 4, 3, 5};

 #pragma monitor start
    r_c = fannkuch(n);
 #pragma monitor stop
    for(i=0; i<N; i++){
      if(r_c[i] != expectedResult[i]){
        return 1;
      }
  }
  return 10;
}