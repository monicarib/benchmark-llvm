#include "nsievebits.h"
int main(int argc, char *argv[]) {

#pragma monitor start
    int result = nsievebits(argc,argv);
#pragma monitor stop

    return result;
}