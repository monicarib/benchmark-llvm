#include <stdio.h>
#include "ackermann.h"

#pragma DATA_ALIGN(x, 8);  
int main() {
  int expectedResult = 61;
  int n = 8;

 #pragma monitor start
  int receivedResult = ackermann(3, 3);

 #pragma monitor stop
  if(receivedResult == expectedResult) {
    return 10;
  } else {
    return 1;
  }
}