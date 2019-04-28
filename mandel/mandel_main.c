#include "mandel.h"
#pragma DATA_ALIGN(x, 8);
int main() {
 #pragma monitor start
	int result = mandel();
 #pragma monitor stop
  if(result != 50){
    return 1;
	}
  return 10;
}