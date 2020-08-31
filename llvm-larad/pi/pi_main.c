#include "pi.h"

#pragma DATA_ALIGN(x, 8); 

int main() {

    long int itot = 40000; // 4000000 (small size) or 40000000 (big size)
    float p;

    #pragma monitor start
    p = pi(itot);
    #pragma monitor stop

    //printf("Pi = %.6f\n",p);

    if (p-3.128800 > 0.0000009) { // 3.130682 (small size) or 3.131497 (big size)
       return 1;
    }

    return 10;
}
