#include "perm.h"
#pragma DATA_ALIGN(x, 8);
int main()
{
	int i;
	int result;
	#pragma monitor start
	for (i = 0; i < 3; i++) {
		result = perm();

		if ( result != 43300 ){
			return 1;
		}
    }
	#pragma monitor stop
	return 10;
}
