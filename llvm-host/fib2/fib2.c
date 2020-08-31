/* -*- mode: c -*-
 * $Id: fib2.c 36673 2007-05-03 16:55:46Z laurov $
 * http://www.bagley.org/~doug/shootout/
 */

int atoi(char *);
#include "fib2.h"

unsigned long
fib(unsigned long n) {
    if (n < 2)
	return(1);
    else
	return(fib(n-2) + fib(n-1));
}

int
fib2(int argc, char *argv[]) {
    int N = ((argc == 2) ? atoi(argv[1]) : LENGTH);
    //printf("%ld\n", fib(N));
    return(fib(N));
}
