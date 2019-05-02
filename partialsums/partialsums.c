//  The Computer Language Shootout
//  http://shootout.alioth.debian.org/
//  contributed by Greg Buchholz
//
//  compile with:  -O3 -msse2 -lm

#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include "partialsums.h"

double sum_vec(v2df x)
{
    double *tmp = (double *)&x;
    return *(tmp) + *(tmp+1);
}

int* partialsums(int k, int n, double twoThrd, double sqrts, double Flint, double Cookson, double k3, double s, double c,
                 v2df Harmonic, v2df zeta, v2df poly, v2df alt, v2df Gregory,
                 v2df zero, v2df one, v2df two, v2df init, v2df m_one, v2df kv, v2df av){
    for (k=1; k<=n; k++)
    {
        twoThrd += pow(2.0/3.0, k-1);
        sqrts   += 1.0/sqrt(k);
              k3 = k*k*k;
              s  = sin(k); c = cos(k);
        Flint   += 1.0/(k3 * s*s);
        Cookson += 1.0/(k3 * c*c);
    }

    for (kv=init; *(double *)(&kv)<=n; kv+=two)
    {
        poly    += one /(kv*(kv+one));
        Harmonic+= one / kv;
        zeta    += one /(kv*kv);
        alt     +=  av / kv;
        Gregory +=  av /(two*kv - one);
    }

    int *res = (int*)malloc(sizeof(int)*9);

    res[1] = twoThrd;
    res[2] = sqrts;
    res[3] = sum_vec(poly);
    res[4] = Flint;
    res[5] = Cookson;
    res[6] = sum_vec(Harmonic);
    res[7] = sum_vec(zeta);
    res[8] = sum_vec(alt);
    res[9] = sum_vec(Gregory);

    return res;
}
