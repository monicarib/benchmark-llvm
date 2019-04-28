#include "realmm.h"


int test() {
	return 10;
}

int main()
{
	float expectedResults [] = { -775, 636, 961, -239, -337, -298, -962, 94, 62, 33 };
	int i;
#pragma monitor start
	for (i = 0; i < 10; i++) {
		int receivedResult = realmm(i);
	
#pragma monitor stop

		if(receivedResult != expectedResults[i]){
			return 1;
		}

	}

	return 10;

}
