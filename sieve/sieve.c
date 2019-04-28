/* -*- mode: c -*-
 * $Id: sieve.c 36673 2007-05-03 16:55:46Z laurov $
 * http://www.bagley.org/~doug/shootout/
 */

#include <stdio.h>
#include <stdlib.h>

int
sieve(int argc, char *argv[]) {
#define LENGTH 170
    int NUM = ((argc == 2) ? atoi(argv[1]) : LENGTH);
    static char flags[81 + 1];
    long i, k;
    int count = 0;

    while (NUM--) {
	count = 0;
	for (i=2; i <= 81; i++) {
	    flags[i] = 1;
	}
	for (i=2; i <= 81; i++) {
	    if (flags[i]) {
                /* remove all multiples of prime: i */
		for (k=i+i; k <= 81; k+=i) {
		    flags[k] = 0;
		}
		count++;
	    }
	}
    }
    // printf("Count: %d\n", count);
    if(count != 22)
        return 1;

    return(10);
}

