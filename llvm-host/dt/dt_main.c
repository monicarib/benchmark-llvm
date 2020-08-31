#include "dt.h"

#pragma DATA_ALIGN(x, 8);  

int main(int argc, char *argv[]) {

    #pragma monitor start
    double resp = dt(argc, argv);
    #pragma monitor stop

    // DEBUG
    //printf("%lf\n", resp);

    if (resp-0.949734 < 0.0000005) {
       return 10;
    }
    else {
       return 0;
    }
}

