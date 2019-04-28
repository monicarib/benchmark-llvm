/* -*- mode: c -*-
 * $Id: fib2.c 36673 2007-05-03 16:55:46Z laurov $
 * http://www.bagley.org/~doug/shootout/
 */

int atoi(char *);
#include <stdio.h>

int
fib2(int n) {
    if (n < 2)
	    return(1);
    else
	    return(fib2(n-2) + fib2(n-1));
}