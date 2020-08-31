/* -*- mode: c -*-
 * $Id: ary3.c 36673 2007-05-03 16:55:46Z laurov $
 * http://www.bagley.org/~doug/shootout/
 *
 * this program is modified from:
 *   http://cm.bell-labs.com/cm/cs/who/bwk/interps/pap.html
 * Timing Trials, or, the Trials of Timing: Experiments with Scripting
 * and User-Interface Languages by Brian W. Kernighan and
 * Christopher J. Van Wyk.
 *
 * I added free() to deallocate memory.
 */

#include "ary3.h"

#pragma DATA_ALIGN(x, 8);  

int main(int argc, char *argv[]) {

    #pragma monitor start
    int resp = ary3(argc, argv);
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
