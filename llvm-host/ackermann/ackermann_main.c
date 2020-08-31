/* -*- mode: c -*-
 * $Id: ackermann.c 35417 2007-03-28 04:46:30Z jeffc $
 * http://www.bagley.org/~doug/shootout/
 */

#include "ackermann.h"

#pragma DATA_ALIGN(x, 8);  

int main(int argc, char *argv[]) {

    #pragma monitor start
    int resp = ackermann(argc, argv);
    #pragma monitor stop

    // DEBUG
    //printf("%d\n", resp);

    if (resp == 2045) {
       return 10;
    }
    else {
       return 0;
    }
}

