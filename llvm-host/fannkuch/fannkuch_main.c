/*
 * The Computer Lannguage Shootout
 * http://shootout.alioth.debian.org/
 * Contributed by Heiner Marxen
 *
 * "fannkuch"	for C gcc
 *
 * $Id: fannkuch-gcc.code,v 1.51 2008-03-06 02:23:27 igouy-guest Exp $
 */

#include "fannkuch.h"

#pragma DATA_ALIGN(x, 8);  

int main(int argc, char* argv[])
{

    int i;
    long resp[30],
         saida[30] = { 1234567891011, 2134567891011, 2314567891011, 3214567891011, 3124567891011,
                       1324567891011, 2341567891011, 3241567891011, 3421567891011, 4321567891011,
                       4231567891011, 2431567891011, 3412567891011, 4312567891011, 4132567891011,
                       1432567891011, 1342567891011, 3142567891011, 4123567891011, 1423567891011,
                       1243567891011, 2143567891011, 2413567891011, 4213567891011, 2345167891011,
                       3245167891011, 3425167891011, 4325167891011, 4235167891011, 2435167891011
         };

    #pragma monitor start
    long retorno = fannkuch(resp);
    #pragma monitor stop

    for (i=0; i<30; i++) {
        // DEBUG
        //printf("Posicao %d: desejado [ %ld ] vs. obtido [ %ld ]\n", i, saida[i], resp[i]);

        if (resp[i] != saida[i]) {
           return 0;
        }
    }

    // DEBUG
    //printf("%ld\n", retorno);

    if (retorno == 51) {
       return 10;
    }
    else {
       return 0;
    }
}
