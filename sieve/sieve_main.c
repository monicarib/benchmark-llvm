/* -*- mode: c -*-
 * $Id: sieve.c 36673 2007-05-03 16:55:46Z laurov $
 * http://www.bagley.org/~doug/shootout/
 */

#include <stdio.h>
#include <stdlib.h>
#include "sieve.h"

int main(int argc, char *argv[]) {

    int length = 1700;
 #pragma monitor start
    int result = sieve(length);
 #pragma monitor stop
 
    if(result == 46) {
       return 10;
    } else {
        return 1;
    }
}
