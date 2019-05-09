#include "bubblesort.h"

/* Sorts an array using bubblesort */
void bubblesort(int srtelements, int *sortlist) {
  int i, j, top = srtelements-1;
  
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
}
