#include "random.h"

int main(int argc, char *argv[]) {
#define LENGTH 4000
  int N = ((argc == 2) ? atoi(argv[1]) : LENGTH) - 1;

  while (N--) {
    random(100.0);
  }
  float f;
  f = random(100.0);
  // printf("%.9f\n", f);
  if(f - 44.085792542 > 0.000001){
    return 1;
  }

  return 10;
}
