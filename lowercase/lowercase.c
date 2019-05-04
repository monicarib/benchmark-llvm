#include <string.h>

#include "lowercase.h"

void *malloc(size_t);

static inline UChar toASCIILower(UChar c) { 
    return c | ((c >= 'A' && c <= 'Z') << 5); 
}

static size_t lower_StringImpl(const UChar* __restrict data, size_t length, UChar* __restrict output)
{
    // Do a faster loop for the case where all the characters are ASCII.
    UChar ored = 0;
    size_t i;
    for (i = 0; i < length; i++) {
        UChar c = data[i];
        ored |= c;
        output[i] = toASCIILower(c);
    }
    if (!(ored & ~0x7F))
       return 1;

    return 0;
}

UChar * lowercase(UChar *staticData, size_t numberOfCharacters)
{
    const size_t testDataLength = ((numberOfCharacters + numberOfCharacters - 1) / numberOfCharacters) * numberOfCharacters; // useless code (could be only numberOfCharacters)

    UChar* testData = malloc(sizeof(UChar) * testDataLength);
    UChar* result = malloc(sizeof(UChar) * testDataLength);

    size_t i;

    for (i = 0; i < testDataLength; i += numberOfCharacters)
        memcpy(testData + i, staticData, numberOfCharacters * sizeof(staticData[0]));


    memset(result, 0, sizeof(UChar) * testDataLength);

    lower_StringImpl(testData, numberOfCharacters, result);
    
    return result;
}


