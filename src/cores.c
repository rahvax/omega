#include "include/core.h"
#include <stdio.h>
#include <string.h>
char* extend(char *key, const char *comparedPhrase) {
  size_t keySize = strlen(key);
  size_t comparedSize = strlen(comparedPhrase);

  if (keySize > comparedSize)
    key[comparedSize] = '\0';
  else if (keySize < comparedSize) {
    size_t originalSize = keySize;

    for (size_t x = keySize; x < comparedSize; x++)
      key[x] = key[x % originalSize];
    key[comparedSize] = '\0';
  }

  return key;
}
