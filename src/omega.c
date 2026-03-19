#include "include/cipher.h"
#include <stdio.h>
#include <string.h>

void cesar(char *password, const int rotation) {
  if (!password) return;
  for (register int x = 0; password[x] != '\0'; x++) {
    char character = password[x];
    if (character >= 'A' && character <= 'Z') password[x] = ((character - 'A' + rotation) % 26) + 'A';
    else if (character >= 'a' && character <= 'z') password[x] = ((character - 'a' + rotation) % 26) + 'a';
  }
}

