#include "intmm.h"

#pragma DATA_ALIGN(x, 8);
int main()
{
	int i;
	#pragma monitor start
	for (i = 0; i < 2; i++) intmm(i);
	#pragma monitor stop
	if( i != 2){
		return 1;
	}

	return 10;
}
