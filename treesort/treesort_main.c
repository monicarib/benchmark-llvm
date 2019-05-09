#include <stdlib.h>

#include "treesort.h"

#define	 false	0

#define srtelements 100
#define N 10
/*
    listsize = 0..srtelements;
    sortarray = array [listsize] of integer;
*/

#pragma DATA_ALIGN(x, 8);  

long seed; /* converted to long for 16 bit WR*/

void Initrand() {
  seed = 74755L; /* constant to long WR*/
}

int Rand() {
    seed = (seed * 1309L + 13849L) & 65535L; /* constants to long WR*/
    return( (int)seed ); /* typecast back to int WR*/
}

void bInitarr(int *sortlist, int *biggest, int *littlest) {
     int i;
     long temp;  /* converted temp to long for 16 bit WR*/

     Initrand();

     *biggest = 0; *littlest = 0;
     for ( i = 0; i < srtelements; i++ ) {
         temp = Rand();
         /* converted constants to long in next stmt, typecast back to int WR*/
         sortlist[i] = (int)(temp - (temp/100000L)*100000L - 50000L);
         if ( sortlist[i] > *biggest ) *biggest = sortlist[i];
         else if ( sortlist[i] < *littlest ) *littlest = sortlist[i];
     }
}


int main() {

    Node *tree;
    int r_c[srtelements];
    int i, answer, biggest, littlest;

    #pragma monitor start

    for (i = 0; i < N; i++) {
        bInitarr(r_c, &biggest, &littlest); // Initialization of the input vector
      
        answer = treesort(srtelements, r_c, &tree);

        if (answer == false) {
           printf("answer = %d\n", answer); // Debug
           return 1;
        }
    }

  #pragma monitor stop

  return 10;
}
