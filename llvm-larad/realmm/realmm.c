#include <stdlib.h>

#include "realmm.h"

void rInnerproduct(float *result, float **a, float **b, int row, int column, int rowsize) {
	/* computes the inner product of A[row,*] and B[*,column] */
	int i;
	*result = 0.0f;
	for (i = 0; i < rowsize; i++) *result = *result+a[row][i]*b[i][column];
}

float **realmm (float **rma, float **rmb, int rowsize, int run) {
    int i, j;

    float **rmr = (float **) malloc(rowsize * sizeof(float *)); 

    for ( i = 0; i < rowsize; i++ ) {
        rmr[i] = (float *) malloc(rowsize * sizeof(float));

	for ( j = 0; j < rowsize; j++ ) { 
            rInnerproduct(&rmr[i][j],rma,rmb,i,j, rowsize);
        }
    }

    return rmr;
}
