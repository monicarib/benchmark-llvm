#include "dry.h"

#pragma DATA_ALIGN(x, 8);  

int main()
{
    #pragma monitor start
    dry();
    #pragma monitor stop

    return 10;
}

