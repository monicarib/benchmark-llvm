#include "lpbench.h"
#pragma DATA_ALIGN(x, 8);
int main(int argc, char ** argv)
{
	 #pragma monitor start
	 int result = lpbench(argc,argv);
 	 #pragma monitor stop

	if(result != 1){
		return 1;
	}

    return 10;
}
