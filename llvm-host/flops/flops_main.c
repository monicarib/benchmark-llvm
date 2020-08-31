#include "flops.h"

#pragma DATA_ALIGN(x, 8);  

int main(int argc, char *argv[]) {

    #pragma monitor start
    int resp = (int) flops();
    #pragma monitor stop

    // DEBUG
    //printf("%d\n", resp);

    if (resp == SAIDA) {
       return 10;
    }
    else {
       return 0;
    }
}

