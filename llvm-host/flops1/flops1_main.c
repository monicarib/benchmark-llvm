#include "flops1.h"

// NORMAL
#define FACTOR 10000
#define SAIDA  394
/*/
// SMALL
#define FACTOR 200
#define SAIDA  -987
*/

#pragma DATA_ALIGN(x, 8);  

int main()
{
    #pragma monitor start
    int resp = flops1(FACTOR);
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


