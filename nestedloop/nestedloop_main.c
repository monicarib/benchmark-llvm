/* -*- mode: c -*-
 * $Id: nestedloop.c 36673 2007-05-03 16:55:46Z laurov $
 * http://www.bagley.org/~doug/shootout/
 */
//#include <stdio.h>

#include "nestedloop.h"

#define LENGTH 8 // 9

#pragma DATA_ALIGN(x, 8); 

int main() {

    int x;

    #pragma monitor start
    x = nestedloop(LENGTH);
    #pragma monitor stop

    if (x != 262144) { // 531441
        //printf("%d\n", x); // Debug
        return (1);
    }

    return 10;
}
