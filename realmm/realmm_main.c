#include <stdlib.h>
//#include <math.h>

#include "realmm.h"

#define rowsize 10
#define N       10

/*
    index = 1 .. rowsize;
    intmatrix = array [index,index] of integer;
    realmatrix = array [index,index] of real;
*/

long    seed;  /* converted to long for 16 bit WR*/


void Initrand () {
    seed = 74755L;   /* constant to long WR*/
}

int Rand () {
    seed = (seed * 1309L + 13849L) & 65535L;  /* constants to long WR*/
    return( (int)seed );     /* typecast back to int WR*/
}

float **rInitmatrix () {
    int temp, i, j;

    float **m = (float **) malloc(rowsize * sizeof(float *));

    for ( i = 0; i < rowsize; i++ ) {
        m[i] = (float *) malloc(rowsize * sizeof(float));

        for ( j = 0; j < rowsize; j++ ) {
            temp = Rand();
            m[i][j] = (float)(temp - (temp/120)*100 - 60)/300.0;
        }
    }

    return(m);
}

/* Multiplies two real matrices */
int main() {

    int expectedResults[N] = { 5361, 3200, 2485, 2364, 2367, 3750, 5869, 4509, 3255, 3307 };

    int i;

    Initrand();

    #pragma monitor start

    for (i = 0; i < N; i++) {
        float **rma = rInitmatrix();
        float **rmb = rInitmatrix();

        float **rmr = realmm(rma, rmb, rowsize, i);

        //printf("%d, ", (int)rmr[i][i]); // Debug

        if (expectedResults[i] != (int)rmr[i][i]) {
            return 1;
        }

    }

    #pragma monitor stop

    return 10;
}
