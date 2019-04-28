#include "oscar.h"
#pragma DATA_ALIGN(x, 8); 
int main ()
{
  int error;
  #pragma monitor start
  error = oscar ();
  #pragma monitor stop
  if(error != 0){
    return (1);
  }

  return 10;
}
