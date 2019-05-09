/* -*- mode: c -*-
 * $Id: strcat.c 14069 2004-06-08 17:21:42Z lattner $
 * http://www.bagley.org/~doug/shootout/
 */

#include "strcat2.h"

int main(int argc, char *argv[]) {
    int n = 1000;

#pragma monitor start
    char * result = strcat2(n);
#pragma monitor stop

    int c = (int)strlen(result);
    free(result);

    if (c != 6000){
        return 1;
    }

    return 10;
}
