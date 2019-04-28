#include "dry.h"

#pragma DATA_ALIGN(x, 8);
int main()
{
 #pragma monitor start
	int result = dry();
 #pragma monitor stop
	if(result){
		return 10;
	}
	return (1);
}

