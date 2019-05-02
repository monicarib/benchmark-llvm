/* -*- mode: c -*-
 * $Id: nestedloop.c 36673 2007-05-03 16:55:46Z laurov $
 * http://www.bagley.org/~doug/shootout/
 */

#include "nestedloop.h"

int main(int argc, char *argv[]) {
    // int length = 10;
    int length = 7;
#pragma monitor start
    int x = nestedloop(length);
#pragma monitor stop
    if(x != 1000000) {
        return 1;
    }

    return 10;
}
