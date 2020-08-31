//#include <time.h>
//#include <string.h>
//#include <stdio.h>
#include <stdlib.h>
//#include <stddef.h>
//#include <stdbool.h>
//#include <memory.h>
//#include <math.h>
#include "huffbench.h"

// embedded random number generator; ala Park and Miller
static       long seed = 1325;
static const long IA   = 16807;
static const long IM   = 2147483647;
static const long IQ   = 127773;
static const long IR   = 2836;
static const long MASK = 123459876;

/*
#if defined(ACOVEA)
#if defined(arch_pentium4)
static const int NUM_LOOPS =   5;
static const int TEST_SIZE = 100;
#else
static const int NUM_LOOPS =   2;
static const int TEST_SIZE =  50;
#endif
#else
#ifdef SMALL_PROBLEM_SIZE
static const int NUM_LOOPS =   2;
static const int TEST_SIZE =  50;
#else
static const int NUM_LOOPS =  5;
static const int TEST_SIZE = 10;
#endif
#endif
*/
static const int NUM_LOOPS =  5;
static const int TEST_SIZE = 50;

static size_t random4()
{
    long k;
    size_t result;
    
    seed ^= MASK;
    k = seed / IQ;
    seed = IA * (seed - k * IQ) - IR * k;
    
    if (seed < 0L)
        seed += IM;
    
    result = (size_t)(seed % 32L);
    seed ^= MASK;
    
    return result;
}

byte * generate_test_data(size_t n)
{
    char * codes = "ABCDEFGHIJKLMNOPQRSTUVWXYZ012345";
    
    byte * result = (byte *)malloc(n);
    byte * ptr = result;
    
    int i;
    for (i = 0; i < n; ++i)
    {
        *ptr = (byte)codes[random4()];
        ++ptr;
    }
    
    return result;
}

int main()
{
    int i;
    
    // initialization
    byte * test_data = generate_test_data(TEST_SIZE);
    
    /*
    FILE * before = fopen("before","wb");
    fwrite(test_data,1,TEST_SIZE,before);
    fclose(before);
    */
            
    // get starting time    
    //struct timespec start, stop;
    //clock_gettime(CLOCK_REALTIME,&start);

    // what we're timing
    for (i = 0; i < NUM_LOOPS; ++i) {
        if(huffbench(test_data,TEST_SIZE) == 1){
            return 1;
        }
    }
         
    // calculate run time
    //clock_gettime(CLOCK_REALTIME,&stop);        
    // double run_time = (stop.tv_sec - start.tv_sec) + (double)(stop.tv_nsec - start.tv_nsec) / 1000000000.0;

    /*
    FILE * after = fopen("after","wb");
    fwrite(test_data,1,TEST_SIZE,after);
    fclose(after);
    */
    
    // release resources
    free(test_data);

    // report runtime
    // if (ga_testing)
    //     fprintf(stdout,"%f",run_time);
    // else        
    //     fprintf(stdout,"\nhuffbench (Std. C) run time: %f\n\n",run_time);
    
    //fflush(stdout);
    
    // done
    return 10;
}
