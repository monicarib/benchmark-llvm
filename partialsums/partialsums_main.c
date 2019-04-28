#include "partialsums.h"
#pragma DATA_ALIGN(x, 8);  
int main(int argc, char* argv[])
{
#pragma monitor start
    int *res = partialsums();
#pragma monitor stop
    if(res[1]!=20 ||
    res[2]!=20 ||
    res[3]!=20 ||
    res[4]!=24 ||
    res[5]!=27 ||
    res[6]!=21 ||
    res[7]!=25 ||
    res[8]!=33 ||
    res[9]!=20){
	free(res);
        return 1;
    }
    free(res);
    return 10;
}
