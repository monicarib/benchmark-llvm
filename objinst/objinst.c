/* -*- mode: c -*-
 * $Id: objinst.c 36673 2007-05-03 16:55:46Z laurov $
 * http://www.bagley.org/~doug/shootout/
 */

// #include <stdio.h>
#include <stdlib.h>
#include "objinst.h"

int objinst(int length, NthToggle *ntog){
    int aux1,aux2;
    int i = 0;
    int n = length;

    for (i=0; i<n; i++) {
        ntog = new_NthToggle(true, 3);
        aux1=ntog->count_max;
        aux2=ntog->counter;
        DESTROY(ntog);
    }

    int result[2];
    result[0] = aux1;
    result[1] = aux2;
    return result;
}
