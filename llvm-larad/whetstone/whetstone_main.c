#include "whetstone.h"

int main(int argc, char *argv[])
{
	long I;
	long N1, N2, N3, N4, N6, N7, N8, N9, N10, N11;
	double X1,X2,X3,X4,X,Y,Z;
	long LOOP;
	int II, JJ;
	long resultado;

	long loopstart;
	long startsec, finisec;
	float KIPS;
	int continuous;

	loopstart = 52; // 250
	continuous = 0;

	II = 1;

#pragma monitor start
    int result = whetstone(startsec, LOOP, loopstart, II, JJ, N1, N2, N3, N4, N6, N7, N8, N9, N10, N11, X1, X2, X3, X4, I, resultado, continuous, X, Y, Z, finisec);
#pragma monitor stop

    if (result - (long)9300000 > 0) {
        return 1;
    }
        
	return 10;
}