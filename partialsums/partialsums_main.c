#include <stdlib.h>
#include "partialsums.h"

v2df make_vec(double a, double b)
{
    v2df v;
    double *tmp;
    tmp = (double *)&v; *(tmp) = a; *(tmp+1) = b;
    return v;
}

#pragma DATA_ALIGN(x, 8);  
int main(int argc, char* argv[]) {

    double  twoThrd = 0, sqrts = 0, Flint = 0, Cookson = 0;
    v2df    Harmonic, zeta, poly, alt, Gregory;
    v2df    zero, one, two, init, m_one, kv, av;

    double  k, k3, s, c;
    int n;  n = 250;

    zero  = make_vec( 0.0,  0.0);  one   = make_vec( 1.0,  1.0);
    two   = make_vec( 2.0,  2.0);  m_one = make_vec(-1.0, -1.0);
    init  = make_vec( 1.0,  2.0);  av    = make_vec( 1.0, -1.0);

    Harmonic = zeta = poly = alt = Gregory = zero;

#pragma monitor start
    int *res = partialsums(k, n, twoThrd, sqrts, Flint, Cookson, k3, s, c,
                           Harmonic, zeta, poly, alt, Gregory, zero, one, two,
                           init, m_one, kv, av);
#pragma monitor stop
    if(res[1]!=2 ||
       res[2]!=30 ||
       res[3]!=0 ||
       res[4]!=4 ||
       res[5]!=42 ||
       res[6]!=6 ||
       res[7]!=1 ||
       res[8]!=0 ||
       res[9]!=0) {
	    free(res);
        return 1;
    }
    free(res);
    return 10;
}