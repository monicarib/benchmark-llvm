#include "matrix.h"
#include <stdlib.h>

void freematrix(int rows, int **m) {
    while (--rows > -1) { free(m[rows]); }
    free(m);
}

int **mkmatrix(int rows, int cols) {
    int i, j, count = 1;
    int **m = (int **) malloc(rows * sizeof(int *));
    for (i=0; i<rows; i++) {
	    m[i] = (int *) malloc(cols * sizeof(int));
	    for (j=0; j<cols; j++) {
	        m[i][j] = count++;
	    }
    }
    return(m);
}

int main(int argc, char *argv[]) {
    int length = 30;
    int **m1 = mkmatrix(SIZE, SIZE);
    int **m2 = mkmatrix(SIZE, SIZE);
    int **mm = mkmatrix(SIZE, SIZE);
#pragma monitor start
	mm = matrix(length, m1, m2, mm);
#pragma monitor stop

    if(mm[0][0] != 3355 || mm[2][3] != 13320 || mm[3][2] != 17865 || mm[4][4]!= 23575){
        freematrix(SIZE, m1);
        freematrix(SIZE, m2);
        freematrix(SIZE, mm);
        return 1;
    }

    freematrix(SIZE, m1);
    freematrix(SIZE, m2);
    freematrix(SIZE, mm);
    return 10;
}