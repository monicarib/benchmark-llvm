#include "stdlib.h"
#include "stdio.h"

// RNG implemented localy to avoid library incongruences
#ifdef RAND_MAX
#undef RAND_MAX
#endif
#define RAND_MAX 32767
static unsigned long long int next = 1;
 
int rand( void ) {
    next = next * 1103515245 + 12345;
    return (unsigned int)(next / 65536) % RAND_MAX+1;
}
 
// End of RNG implementation

int randInt(int min, int max) {
    int k, n;
    n = (max - min) + 1;
    k = (int)(n * (rand() / (RAND_MAX + 1.0)));
    return (k == n) ? k + min - 1 : k + min;
}

void shuffle(int* items, int len) {
    size_t j, k, i;
    int aux;

    for(i = len-1; i > 0; --i) {
        k = (int)((i + 1) * (rand() / (RAND_MAX + 1.0)));
        j = (k == (i + 1)) ? k - 1 : k;

        aux = items[i];
        items[i] = items[j];
        items[j] = aux;
    }
}

int puzzle(int *data, int len) {
    int i;
    int result = 0;

    for (i = 0; i < len; i++)
        result = result ^ (i + 1) ^ data[i];
    result ^= len;
    return result;
}


