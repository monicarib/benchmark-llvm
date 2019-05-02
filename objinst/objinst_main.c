#include "objinst.h"

#define LENGTH 700

int main() {
    int resp[2];
    
    objinst(LENGTH, resp);
    
    //printf("%d, %d", resp[0], resp[1]); //Debug 
    
    if(resp[0] != 3 && resp[1] != 0) {
        return 1;
    }
    return 10;
}
