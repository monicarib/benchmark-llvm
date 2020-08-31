#include "towers.h"

#pragma DATA_ALIGN(x, 8);
int main()
{
	int i,flag = 0;
#pragma monitor start
	for (i = 0; i < 100; i++) {
            if(towers() != 7){
                flag = 1;
            }
	}
#pragma monitor stop
	if(flag == 1)
		return (1);
	return 10;
}
