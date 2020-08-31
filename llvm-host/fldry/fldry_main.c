#include "fldry.h"

#pragma DATA_ALIGN(x, 8);  

int main(int argc, char *argv[])
{
    #pragma monitor start
    int resp = fldry(argc, argv);
    #pragma monitor stop

    // DEBUG
    //printf("%d\n", resp);

    if (resp == 0) {
       return 10;
    }
    else {
       return 0;
    }
}

