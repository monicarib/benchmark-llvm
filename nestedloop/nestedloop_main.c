/* -*- mode: c -*-
 * $Id: nestedloop.c 36673 2007-05-03 16:55:46Z laurov $
 * http://www.bagley.org/~doug/shootout/
 */

#include <stdio.h>
#include <stdlib.h>
#include "nestedloop.h"

#pragma DATA_ALIGN(x, 8); 
int main(int argc, char *argv[]) {
#define LENGTH 10
#pragma monitor start
    int x = nestedloop(argc, argv);
#pragma monitor stop
    if(x != 1000000)
        return (1);
    return 10;
}
