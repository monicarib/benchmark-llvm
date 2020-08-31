#include "queens.h"

int main()
{
	int i;
#pragma monitor start
	for (i = 0; i < 100; i++) queens();
#pragma monitor stop

	if(i==100)
        return 10;

    return 1;
}