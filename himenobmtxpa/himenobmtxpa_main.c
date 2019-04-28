#include "himenobmtxpa.h"

int main(int argc, char *argv[]) {

    float result = himenobmtxpa(argc,argv);

    if(result - 1073800448.000000 > 0.0009){
        return 1;
    }
    return 10;
}
