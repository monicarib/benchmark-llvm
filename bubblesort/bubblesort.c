#include "bubblesort.h"

int bubblesort(int biggest, int littlest, int srtelements, int *sortlist) {
  int i, j, top = srtelements;
  
  while (top > 0) {
    i=0;
    
    while ( i<top ) {
      if ( sortlist[i] > sortlist[i+1] ) {
        j = sortlist[i];
        sortlist[i] = sortlist[i+1];
        sortlist[i+1] = j;
      }
      i=i+1;
    }
    
    top=top-1;
  }
  
  if ( (sortlist[0] != littlest) || (sortlist[srtelements] != biggest) )
    return 0;
    
  return 1;
}
