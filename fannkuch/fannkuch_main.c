//#include <stdio.h>

#include "fannkuch.h"

#define N 7 // 11

#pragma DATA_ALIGN(x, 8);
int main( int argc, char* argv[] )
{
    int i;
    long *r_c;
    long expectedResult[N] = {16, 4, 3, 5, 1, 6, 7}; // {51, 4, 3, 5, 1, 6, 7, 8, 9, 10, 11};

    #pragma monitor start
    r_c = fannkuch(N);
    #pragma monitor stop

    if (!r_c) {
       return 0;
    }

    for (i=0; i<N; i++){
        //printf("%ld, ", r_c[i]); // Debug

        if (r_c[i] != expectedResult[i]){
           return 1;
        }

    }
    return 10;
}
