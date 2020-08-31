#include <math.h>

#define permrange     10

    /* Perm */
int    permarray[permrange+1];
unsigned int    pctr;

void Swap ( int *a, int *b ) {
	int t;
	t = *a;  *a = *b;  *b = t;
}

void Initialize () {
	int i;
	for ( i = 1; i <= 7; i++ ) {
	    permarray[i]=i-1;
	}
}

void Permute (int n) {   /* permute */
	int k;
	pctr = pctr + 1;
	if ( n!=1 )  {
	    Permute(n-1);
	    for ( k = n-1; k >= 1; k-- ) {
			Swap(&permarray[n],&permarray[k]);
			Permute(n-1);
			Swap(&permarray[n],&permarray[k]);
		}
    }
}     /* permute */

int perm ()    {   /* Perm */
    int i;
    pctr = 0;
    for ( i = 1; i <= 5; i++ ) {
		Initialize();
		Permute(7);
	}

    return pctr;
}     /* Perm */