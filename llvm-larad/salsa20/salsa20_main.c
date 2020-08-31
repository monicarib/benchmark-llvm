#include <stdint.h>
#include "salsa20.h"

#pragma DATA_ALIGN(x, 8);
int main(void) {
  uint32_t val, i;
uint32_t STATE[16];

// #ifdef SMALL_PROBLEM_SIZE
  uint32_t count = 537;
  uint32_t offset = 0xf655703d - 0xb67e7950;
// #else
//   uint32_t count = 537919488;
//   uint32_t offset = 0;
// #endif

  for(i=0; i<16; i++)
    STATE[i] = (0xedababe5+(i+13))^(0xdeadbeef-i);
 #pragma monitor start
  for(i=0; i<count; i++)
    salsa20();

  val = salsa20();
 #pragma monitor stop
  val += offset;

  // printf("got:       %x\n", val);
  // printf("should be: %x\n", 0xf655703d);
  if(val != 0x4820a4b5){
    return 1;
  }
  return 10;
}
