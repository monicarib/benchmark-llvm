#include "nsievebits.h"
int main(int argc, char *argv[]) {

#pragma monitor start
    int result = nsievebits();
#pragma monitor stop

    if(result == 1) {
        return 1;
    } else {
        return 10;   
    }
}