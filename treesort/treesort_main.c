#include "treesort.h"
#pragma DATA_ALIGN(x, 8);  
int main()
{
	int i ,respostas[] = {-15239,
-15986,
-10769
};
	#pragma monitor start
	for (i = 0; i < 3; i++){
		int answer = treesort(i);
      if( answer != respostas[i]){
        return 1;
      }
	#pragma monitor stop
	}

	return 10;
}
