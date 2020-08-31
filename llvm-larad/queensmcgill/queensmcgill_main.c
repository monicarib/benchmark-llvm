#include "queensmcgill.h"

int main(int argc, char **argv)
{
#pragma monitor start
  int result = queensmcgill( argc, argv);
#pragma monitor stop

  if(result != 0){
    return 1;
  }
    
  return 10;
}