#include "include/cipher.h"
#include "include/core.h"
#include <stdio.h>

void cesar(char *password, const int rotation) {
  if (!password) return;
  for (register int x = 0; password[x] != '\0'; x++) {
    char character = password[x];
    if (character >= 'A' && character <= 'Z') password[x] = ((character - 'A' + rotation) % 26) + 'A';
    else if (character >= 'a' && character <= 'z') password[x] = ((character - 'a' + rotation) % 26) + 'a';
  }
}

void atbash(char *password) {
  char alfabeto[] = "abcdefghijklmnopqrstuvwxyz";
  char chave[]    = "zyxwvutsrqponmlkjihgfedcba";

  toLower(password);
  for (register int x = 0; password[x] != '\0'; x++) {
    for (register int y = 0; y < SIZEALP; y++) {
      if (alfabeto[y] == password[x]) {
        password[x] = chave[y];
	break;
      }
    }
  }

  printf("[Cipher]: %s\n", password);
}

void toLower(char *text) {
  char lowerCase[] = "abcdefghijklmnopqrstuvwxyz";
  char upperCase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  for (register int x = 0; text[x] != '\0'; x++) {
    for (register int y = 0; y < SIZEALP; y++) {
      if (text[x] == upperCase[y]) text[x]=lowerCase[y];
    }
  }
}
