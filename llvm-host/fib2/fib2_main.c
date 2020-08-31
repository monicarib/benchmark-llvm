/* -*- mode: c -*-
 * $Id: fib2.c 36673 2007-05-03 16:55:46Z laurov $
 * http://www.bagley.org/~doug/shootout/
 */

#include "fib2.h"

#pragma DATA_ALIGN(x, 8);  

int main(int argc, char *argv[]) {

    #pragma monitor start
    int resp = fib2(argc, argv);
    #pragma monitor stop

    // DEBUG
    //printf("%d\n", resp);

    if (resp == SAIDA) {
       return 10;
    }
    else {
       return 0;
    }
}

