#include <stdio.h>
#include <stdlib.h>

#include "bubblesort.h"

#define srtelements 50 //100
/*
    listsize = 0..srtelements;
    sortarray = array [listsize] of integer;
*/

#pragma DATA_ALIGN(x, 8); 

long seed; /* converted to long for 16 bit WR*/
int sortlist[srtelements], biggest, littlest;

void Initrand () {
  seed = 74755L; /* constant to long WR*/
}

int Rand () {
  seed = (seed * 1309L + 13849L) & 65535L; /* constants to long WR*/
  return( (int)seed ); /* typecast back to int WR*/
}

/* Sorts an array using bubblesort */
void bInitarr() {
  int i;
  long temp; /* converted temp to long for 16 bit WR*/
  Initrand();
  biggest = 0; littlest = 0;
  for ( i = 0; i < srtelements; i++ ) {
    temp = Rand();
    /* converted constants to long in next stmt, typecast back to int WR*/
    sortlist[i] = (int)(temp - (temp/100000L)*100000L - 50000L);
    if ( sortlist[i] > biggest ) biggest = sortlist[i];
    else if ( sortlist[i] < littlest ) littlest = sortlist[i];
  }
}

int main()
{
  int i, resp;
  int r_c[srtelements];
  int expectedResult[srtelements] = {-48454, 47284, -47152, -46323, -44411, -44053, -43671, -43129, -38193, -36605, -36527, -35161, -29178, -27104, -26920, -26077, -24685, -24666, -23782, -20444, -19851, -17764, -16206, -15986, -15239, -13587, -11011, -10769, -10556, -10026, -9633, -9026, -8555, -7913, -7086, -3090, -1207, -415, -208, 2540, 4697, 4955, 5354, 5492, 5504, 6952, 7883, 13442, 14193, 15224};
//  int expectedResult[srtelements] = {-48454, -47284, -47152, -46323, -44759, -44411, -44053, -43671, -43129, -42427, -42191, -40392, -39905, -39872, -38809, -38193, -37786, -36605, -36527, -35269, -35161, -34845, -30913, -30494, -29422, -29178, -28607, -27242, -27104, -26920, -26077, -24685, -24666, -23782, -22828, -22476, -21165, -20856, -20484, -20444, -19992, -19851, -19030, -17764, -16871, -16586, -16206, -15986, -15239, -13587, -12990, -11743, -11011, -10769, -10556, -10026, -9737, -9633, -9026, -8555, -7913, -7086, -4790, -3206, -3090, -2900, -1660, -1331, -1207, -415, -411, -208, 727, 1248, 1822, 2331, 2540, 3699, 4153, 4697, 4955, 5354, 5468, 5492, 5504, 5710, 6571, 6952, 7883, 8574, 9359, 9872, 10414, 11485, 12207, 13442, 13501, 13909, 14193, 15224};

#pragma monitor start

  for (i = 0; i < srtelements; i++) {
      bInitarr(); // Initialization of the input vector
      
      resp = bubblesort(biggest, littlest, srtelements, sortlist);
    
      if (resp == 0) {
         //printf("Bubblesort Error\n"); //Debug
         return 0;
      }
         
      r_c[i] = sortlist[i];
  }

#pragma monitor stop

  //for (i = 0; i < srtelements; i++) printf (" %d,", r_c[i]); // Debug


  for (i = 0; i < srtelements; i++){
      if (r_c[i] - expectedResult[i] > 0) {
         return 1;
	  }
  }
  
  return 10;
}
