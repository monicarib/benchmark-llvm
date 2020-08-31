#include "flops3.h"

// NORMAL
#define FACTOR 20000
#define SAIDA  -41
/*/
// SMALL
#define FACTOR 400
#define SAIDA  -9
*/

#pragma DATA_ALIGN(x, 8);  

int main()
{
    #pragma monitor start
    int resp = flops3(FACTOR);
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

