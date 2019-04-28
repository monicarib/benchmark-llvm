#include "fib2.h"

#pragma DATA_ALIGN(x, 8);
int main(int argc, char *argv[]) {
#ifdef SMALL_PROBLEM_SIZE
#define LENGTH 40
#else
#define LENGTH 43
#endif
    int N;// = ((argc >= 2) ? atoi(argv[1]) : LENGTH);
 #pragma monitor start
    int result = fib2(11);
 #pragma monitor stop
    if(result -144 > 0){
        return 1;
    }
    
    return 10;
}
