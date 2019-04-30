#include "himenobmtxpa.h"

int main(int argc, char *argv[]) {

    int msize[3] = { 3, 3, 6};

    float result = himenobmtxpa(msize);

    if(result - 1073800448.000000 > 0.0009){
        return 1;
    }
    return 10;
}
