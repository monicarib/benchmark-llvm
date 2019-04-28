#include "perm.h"
#pragma DATA_ALIGN(x, 8);
int main()
{
	int i;
	int result;
	#pragma monitor start
	for (i = 0; i < 10; i++) {

            result = perm();
            if(result == 1){
                return 1;
            }
    }
	#pragma monitor stop
	return 10;
}
