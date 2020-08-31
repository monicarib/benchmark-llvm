#include "nbody.h"
#pragma DATA_ALIGN(x, 8);  
int main(int argc, char ** argv)
{
 #pragma monitor start
 float result = nbody(); 
 #pragma monitor stop
 if(-0.169083133 - result > 0.0000000009){
    return 1;
 }
 return 10;
}
