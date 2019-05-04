//#include <stdio.h>
#include <string.h>
#include "lowercase.h"

void *malloc(size_t);

static inline UChar toASCIILower(UChar c) { return c | ((c >= 'A' && c <= 'Z') << 5); }

static size_t lower_StringImp(const UChar* data, size_t m_length, UChar* output) __attribute__((__noinline__));
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

UChar * lowercase(size_t numberOfCharacters, UChar *staticData, size_t staticDataLength)
{
  const size_t testDataLength = ((numberOfCharacters + staticDataLength - 1) / staticDataLength) * staticDataLength;
  UChar* testData = malloc(sizeof(UChar) * testDataLength);
  size_t i;
  for (i = 0; i < testDataLength; i += staticDataLength)
    memcpy(testData + i, staticData, staticDataLength * sizeof(staticData[0]));

  UChar* result = malloc(sizeof(UChar) * testDataLength);
  // printf("iterations (%ld characters)\n", numberOfCharacters);

  memset(result, 0, sizeof(UChar) * testDataLength);
  //for (i = 0; i < 100; i++)
    lower_StringImpl(testData, numberOfCharacters, result);
    
  return result;
}


