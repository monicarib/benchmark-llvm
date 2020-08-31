#include "puzzlestanford.h"

int main()
{
	#pragma monitor start
	int result = puzzlestanford();
	#pragma monitor stop
	
	if(result == 13) {
		return 10;
	} else {
		return 1;
	}
}
