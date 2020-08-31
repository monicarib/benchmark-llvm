#include <stdlib.h>
#include <ctype.h>

#include "lowercase.h"

#define LENGTH 100
#define MAX     50

#pragma DATA_ALIGN(x, 8);

void generateRandomLetters(int arraySize, UChar *randomLetters) {

     static UChar alphabet[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '!', '@', '#', '$', '%', '&', '?', ':', '{', '}', '[', ']', '(', ')', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0' };
     static const size_t DataLength = sizeof(alphabet) / sizeof(alphabet[0]);
     int i;

     for (i = 0; i < arraySize; i++) {
	 int temp = rand() % DataLength;
	 randomLetters[i] = alphabet[temp];
     }
}

int main(int argc, char **argv)
{
    int i,j;
    UChar inputData[LENGTH], expectedData[LENGTH];
    UChar * outputData;

    srand(time(NULL));

    #pragma monitor start
    for (j = 0; j < MAX; j++){

        generateRandomLetters(LENGTH, inputData); // Generate random sequences

        outputData = lowercase(inputData, LENGTH);
       
        // Evaluate the function's return
        for (i = 0; i < LENGTH; i++){
            expectedData[i] = tolower(inputData[i]);

            if (expectedData[i] != outputData[i]){
               return 1;
            }
        }
    }
    #pragma monitor stop
    
    return 10;
}
