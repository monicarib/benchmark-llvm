#include <string.h>
#include "ary3.h"

int receivedResult[2];
int expectedResult[2] = {1000, 150000}; //expectedResult[2] = {1000, 150000000};

#pragma DATA_ALIGN(x, 8);
int main(int argc, char **argv) {
  int n = 150; //n = 150000;

#pragma monitor start
  ary3(n, receivedResult);
#pragma monitor stop

//printf("%d\t%d\n", receivedResult[0], receivedResult[1]);

  if(receivedResult[0] == expectedResult[0] && receivedResult[1] == expectedResult[1]){
    return 10;
  }
  return 1;
}
