#include<stdlib.h>
#include "lowercase.h"

#pragma DATA_ALIGN(x, 8);
int main(int argc, char **argv)
{
  size_t i,result = 10;
 #pragma monitor start
  for (i = 0; i < 10; i++){
    lowercase(i);
}
 #pragma monitor stop
    if(i != result){
      return 1;
    }
    return 10;
}
