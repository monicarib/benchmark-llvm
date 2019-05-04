#include<stdlib.h>
#include <ctype.h>
#include "lowercase.h"

#pragma DATA_ALIGN(x, 8);
int main(int argc, char **argv)
{
    static UChar staticData[]  = {'H', 'E', 'L', 'L', 'O', ' ', 'W', 'O', 'R', 'L', 'D', '!', 'H', 'E', 'L', 'L'};
    static const size_t staticDataLength = sizeof(staticData) / sizeof(staticData[0]);
    
    int i;
    
    UChar * result;
    
    #pragma monitor start
    for (i = 0; i <= staticDataLength; i++){
        result = lowercase(i, staticData, staticDataLength);
    }
    #pragma monitor stop

    UChar *r_c = (UChar *) malloc(sizeof(UChar)*staticDataLength);
    
    for (i = 0; i < staticDataLength; i++){
       r_c[i] = tolower(staticData[i]);
              
       if (r_c[i] != result[i]){
          return 1;
       }
    }
    
    free(r_c);
    
    return 10;
}
