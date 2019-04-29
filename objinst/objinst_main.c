#include "objinst.h"

int main(int argc, char *argv[]) {
#pragma monitor start
    int result = objinst(argc, argv);
#pragma monitor stop

    return result;
}
