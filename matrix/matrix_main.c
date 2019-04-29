#include "matrix.h"
int main(int argc, char *argv[]) {
#pragma monitor start
	int result = matrix(argc,argv);
#pragma monitor stop
    return result;
}