#include "methcall.h"

int main(int argc, char *argv[]) {
    if(!methcall(argc,argv)){
        return 1;
    }
    return 10;
}