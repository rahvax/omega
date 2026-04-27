#include "include/cipher.h"
#include <string.h>
#include <stdio.h>

char alphabet[] = "abcdefghijklmnopqrstuvwxyz";

int position(const char letter) {
  for (register int x = 0; x < 26; x++)
    if (alphabet[x] == letter) return x;

  return -1;
}

char* extend(char *phrase, const char *comparedPhrase) {
  size_t phraseSize = strlen(phrase);
  size_t comparedSize = strlen(comparedPhrase);

  if (phraseSize > comparedSize) {
    for (register int x = phraseSize; x > comparedSize; x--) {
      phrase[x] = '\0';
    }

    phrase[comparedSize] = '\0';
  }
  else if (phraseSize < comparedSize) {
    for (register int x = phraseSize; x < comparedSize; x++) {
      phrase[x] = phrase[x % phraseSize];
    }

    phrase[comparedSize] = '\0';
  }

  return phrase;
}

void vigenere(char *phrase, char *key) {
  char *keyPointer = extend(key, phrase);
  int maxSize = strlen(phrase);

  for (register int x = 0; x < maxSize; x++) {
    printf("%c",
      alphabet[(position(phrase[x]) + position(keyPointer[x])) % 26]
    );
  }

  printf("\n");
}

int main(int argc, char **argv) {
  char text[] = "gabriel";
  char key[100] = "arrozar";
  vigenere(text, key);

  return 0;
}