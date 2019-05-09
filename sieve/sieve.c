/* -*- mode: c -*-
 * $Id: sieve.c 36673 2007-05-03 16:55:46Z laurov $
 * http://www.bagley.org/~doug/shootout/
 */

#include <stdio.h>
#include <stdlib.h>

int sieve(int length) {
    static char flags[200 + 1];
    long i, k;
    int count = 0;

    while (length--) {
		count = 0; 
		for (i=2; i <= 200; i++) {
			flags[i] = 1;
		}
		for (i=2; i <= 200; i++) {
			if (flags[i]) {
					/* remove all multiples of prime: i */
			for (k=i+i; k <= 200; k+=i) {
				flags[k] = 0;
			}
			count++;
			}
		}
    }
	
    return count;
}

