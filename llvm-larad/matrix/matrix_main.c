//#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"

#define SIZE 10 //20
#define N 50

#pragma DATA_ALIGN(x, 8);

int **zeromatrix(int rows, int cols) {
    int i, j;
    int **m = (int **) malloc(rows * sizeof(int *));
    for (i=0; i<rows; i++) {
	    m[i] = (int *) malloc(cols * sizeof(int));
	    for (j=0; j<cols; j++) {
	        m[i][j] = 0;
	    }
    }
    return(m);
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

void freematrix(int rows, int **m) {
    while (--rows > -1) { free(m[rows]); }
    free(m);
}

int main() {

    int **m1 = mkmatrix(SIZE, SIZE);
    int **m2 = mkmatrix(SIZE, SIZE);
    int **mm = zeromatrix(SIZE, SIZE);
    int expected[SIZE] = {3355, 8110, 13065, 18220, 23575, 29130, 34885, 40840, 46995, 53350}; // size 10
    //int expected[SIZE] = {53410, 130420, 208230, 286840, 366250, 446460, 527470, 609280, 691890, 775300, 859510, 944520, 1030330, 1116940, 1204350, 1292560, 1381570, 1471380, 1561990, 1653400}; // size 20

#pragma monitor start
    matrix(SIZE, SIZE, m1, m2, mm, N);
#pragma monitor stop

    freematrix(SIZE, m1);
    freematrix(SIZE, m2);

    int i;

    for (i = 0; i < SIZE; i++) {
        //printf("%d, ", mm[i][i]); //Debug

        if (mm[i][i] != expected[i]){
            freematrix(SIZE, mm);
            return 1;
        }

}

    freematrix(SIZE, mm);
    return 10;
}
