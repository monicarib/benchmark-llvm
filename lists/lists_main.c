#include "lists.h"

#pragma DATA_ALIGN(x, 8);
int main(int argc, char *argv[]) {
#define LENGTH 30
  int n = ((argc == 2) ? atoi(argv[1]) : LENGTH);
  int result = 0;
 #pragma monitor start
  while(n--){ result = lists();
 #pragma monitor stop
    if(result != 100){
      return 1;
    }
  }
  return 10;
}
