#include "flops5.h"

// NORMAL
#define FACTOR 10000
#define SAIDA  -2147483648
/*/
// SMALL
#define FACTOR 400
#define SAIDA  -2147483648
*/

#pragma DATA_ALIGN(x, 8);  

int main()
{
    #pragma monitor start
    int resp = flops5(FACTOR);
    #pragma monitor stop

    // DEBUG
    //printf("Desejado [ %ld ] e obtido [ %d ]\n", SAIDA, resp); 

    if (resp == SAIDA) {
       return 10;
    }
    else {
       return 0;
    }
}

