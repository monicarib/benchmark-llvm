#include <stdio.h>
#include "ackermann.h"

#pragma DATA_ALIGN(x, 8);  
int main() {
  int expectedResult = 61; //expectedResult = 2045;
  int n = 3; //n = 8;

 #pragma monitor start
  int receivedResult = ackermann(3, n);

 #pragma monitor stop
  if(receivedResult == expectedResult) {
    return 10;
  } else {
    return 1;
  }
}
