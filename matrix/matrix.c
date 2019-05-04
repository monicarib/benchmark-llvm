/* -*- mode: c -*-
 * $Id: matrix.c 36673 2007-05-03 16:55:46Z laurov $
 * http://www.bagley.org/~doug/shootout/
 */

int **mmult(int rows, int cols, int **m1, int **m2, int **m3) {
    int i, j, k, val;
    for (i=0; i<rows; i++) {
	for (j=0; j<cols; j++) {
	    val = 0;
	    for (k=0; k<cols; k++) {
		val += m1[i][k] * m2[k][j];
	    }
	    m3[i][j] = val;
	}
    }
    return(m3);
}

void matrix(int rows, int cols, int **m1, int **m2, int **mm, int n){

    int i;

    for (i = 0; i < n; i++) {
	mm = mmult(rows, cols, m1, m2, mm);
    }
}
