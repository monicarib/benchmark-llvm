/* -*- mode: c -*-
 * $Id: strcat.c 14069 2004-06-08 17:21:42Z lattner $
 * http://www.bagley.org/~doug/shootout/
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "strcat2.h"

char * strcat2(int length){
    int i, buflen = 32;
    char *strbuf = calloc(sizeof(char), buflen);
    char *strend = strbuf;
    int stufflen = strlen(STUFF);

    if (!strbuf) { perror("calloc strbuf"); exit(1); }
    for (i=0; i<length; i++) {
        if (((strbuf+buflen)-strend) < (stufflen+1)) {
            buflen = 2*buflen;
            strbuf = realloc(strbuf, buflen);
            if (!strbuf) { perror("realloc strbuf"); exit(1); }
            strend = strbuf + strlen(strbuf);
        }
        /* much faster to strcat to strend than to strbuf */
        strcat(strend, STUFF);
        strend += stufflen;
    }

    return strbuf;
}
