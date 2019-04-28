#include "flops.h"

#pragma DATA_ALIGN(x, 8);
int main()
{
	#pragma monitor start
		int result = flops();
	#pragma monitor stop
	if (result == 10) {
		return 10;
	} else {
		return 1;
	}
}
