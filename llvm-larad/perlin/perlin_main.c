#include "perlin.h"
#pragma DATA_ALIGN(x, 8);
int main() {
  //init();

  double x, y, z, sum = 0.0;
  #pragma monitor start
  for (x = -11.57; x < 261.57; x += 2.235)
    for (y = -346.1235; y < 1.124; y += 4.4325)
      for (z = -16.235; y < 23.2345; y += 5.45)
        sum += perlin(x, y, z);
  #pragma monitor stop
  double result = sum;
  double zero = 0.00000000000000;
  if(result + 8.908250 >  zero){
    return 1;
  }
  return 10;
}
