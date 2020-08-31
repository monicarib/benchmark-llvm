#include "flops7.h"

// NORMAL
#define FACTOR 10000
#define SAIDA  111924
/*/
// SMALL
#define FACTOR 200
#define SAIDA  14154
*/

#pragma DATA_ALIGN(x, 8);  

int main()
{
    #pragma monitor start
    int resp = flops7(FACTOR);
    #pragma monitor stop

    // DEBUG
    //printf("Desejado [ %d ] e obtido [ %d ]\n", SAIDA, resp); 

    if (resp == SAIDA) {
       return 10;
    }
    else {
       return 0;
    }
}

