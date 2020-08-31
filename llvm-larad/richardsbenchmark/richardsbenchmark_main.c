#include "richardsbenchmark.h"
 
#pragma DATA_ALIGN(x, 8); 
int main()
{
 #pragma monitor start
    int result = richardsbenchmark();
 #pragma monitor stop
    if(result == 0)
        return 10;
    return 1;
}

