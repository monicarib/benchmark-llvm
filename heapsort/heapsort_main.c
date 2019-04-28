#include "heapsort.h"

double gen_random(double max);
#include <stdio.h>
#include <stdlib.h>
#define LENGTH 800
#pragma DATA_ALIGN(x, 8);
int main(int argc, char *argv[]) {

    int N = 10;//((argc == 2) ? atoi(argv[1]) : LENGTH);
    double *ary;
    int i;

    /* create an array of N random doubles */
    ary = (double *)malloc((N+1) * sizeof(double));
    for (i=1; i<=N; i++) {
	ary[i] = gen_random(1);
    }
 #pragma monitor start
    heapsort(N, ary);
 #pragma monitor stop

double um = 0.008338;
double dois = 0.148405;
double tres = 0.316429;
double quatro = 0.374650;
double cinco = 0.536237;
double seis = 0.538545;
double sete= 0.578825;
double oito= 0.636467;
double nove = 0.729024;
double dez = 0.793481;

  
	if(ary[0] - um > 0.00001){
return 1;
    }
	if(ary[1] - dois > 0.00001){
return 1;
    }
	if(ary[2] - tres > 0.00001){
return 1;
    }
	if(ary[3] - quatro > 0.00001){
return 1;
    }
	if(ary[4] - cinco > 0.00001){
return 1;
    }
	if(ary[5] - seis > 0.00001){
return 1;
    }
	if(ary[6] - sete > 0.00001){
return 1;
    }
	if(ary[7] - oito > 0.00001){
return 1;
    }
	if(ary[8] - nove > 0.00001){
return 1;
    }
	if(ary[9] - dez > 0.00001){
return 1;
    }
    free(ary);
    return 10;
}