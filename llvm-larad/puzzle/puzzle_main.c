#include "stdlib.h"
#include "stdio.h"
#include "puzzle.h"

#define ARRAY_SIZE 500
#define NLOOPS1 5
#define NLOOPS2 20

static unsigned long long int next = 1;

void srand( unsigned int seed ) {
    next = seed;
}

int *createRandomArray(int size) {
    int i, len;
    int *result;

    len = size + 1;
    result = (int*)malloc(len * sizeof(int));
    for (i = 0; i < len; i++)
        result[i] = i;
    result[0] = randInt(1, size);
    shuffle(result, len);
    return result;
}

int main() {
    int i, j, duplicate;
    int *rndArr;
    int result[] = {257,301,76,43,101};

    srand(1);
	#pragma monitor start
	for (i = 0; i < NLOOPS1; i++) {
       

		rndArr = createRandomArray(ARRAY_SIZE);
		for (j = 0; j < NLOOPS2; j++){
			duplicate = puzzle(rndArr, ARRAY_SIZE+1);
		}
		// free(rndArr);
		// printf("Found duplicate: %d\n", duplicate);
		if(duplicate != result[i]){
			// printf("%d\n",i);
			return 1;            
		}
	}
        #pragma monitor stop
		// printf("10");
    return 10;
}
