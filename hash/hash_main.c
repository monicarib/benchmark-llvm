#include "hash.h"

int main(int argc, char *argv[]) {

    #define LENGTH 3000
    int i, c=0, n = LENGTH;
    char buf[32];

 #pragma monitor start
    int result = (int)hash(i, c, n, buf);
 #pragma monitor stop

    if( result != 999){
        return 1;
    }
    return 10;
}

