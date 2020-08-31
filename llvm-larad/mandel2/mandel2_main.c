#include <complex.h>
#include "mandel2.h"

int main() {
int max_i = 655;
  int i, j;
    for (j = 0; j < 10; ++j) {
        for (i = 0; i < 10; ++i){
            // printf(mandel2(j/40.0-0.5 + i/40.0*I) > max_i ? "*" : " ");
            mandel2(j/40.0-0.5 + i/40.0*I);
        }
    }
    if(j<10 || i<10){
        return 1;
    }
    return 10;
}

