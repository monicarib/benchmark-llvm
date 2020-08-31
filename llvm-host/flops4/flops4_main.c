#include "flops4.h"

// NORMAL
#define FACTOR 10000
#define SAIDA  285
/*/
// SMALL
#define FACTOR 400
#define SAIDA  143
*/

#pragma DATA_ALIGN(x, 8);  

int main()
{
    #pragma monitor start
    int resp = flops4(FACTOR);
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

