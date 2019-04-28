#include "recursive.h"
#pragma DATA_ALIGN(x, 8);
int main(int argc, char ** argv) {
 #pragma monitor start
  int result = recursive();
 #pragma monitor stop
  if(result != 10) {
    return (1);  
  }
  return 10;
}
