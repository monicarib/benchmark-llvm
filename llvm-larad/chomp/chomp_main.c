#include "chomp.h"
#include<stdlib.h>

#define N 55
#pragma DATA_ALIGN(x, 8);
int main(void)
{
  int i;
  int *receivedResult;
  int expectedResult[55] = {0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                          0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
#pragma monitor start
  receivedResult = chomp();
#pragma monitor stop

  for(i=0; i<N; i++){
    if(receivedResult[i] != expectedResult[i]){
      free(receivedResult);
      return 1;
    }
  }

  free(receivedResult);
  return 10;
}