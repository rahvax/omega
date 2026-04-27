#include "include/cipher.h"
#include "include/core.h"
#include <stdio.h>
#include <string.h>

#define ALPHABET_SIZE 26

const char lowerCaseAlphabet[] = "abcdefghijklmnopqrstuvwxyz";
const char upperCaseAlphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void caesar(char *password, const int rotation) {
  for (register int x = 0; password[x] != '\0'; x++) {
    char character = password[x];
    
    if (character >= 'A' && character <= 'Z')
      password[x] = upperCaseAlphabet[(character - 'A' + rotation) % ALPHABET_SIZE];
    else if (character >= 'a' && character <= 'z')
      password[x] = lowerCaseAlphabet[(character - 'a' + rotation) % ALPHABET_SIZE];
  }
}

void atbash(char *password) {
  toLowerCase(password);

  for (register int x = 0; password[x] != '\0'; x++) {
    int index = position(password[x]);

    if (index != -1)
      password[x] = lowerCaseAlphabet[ALPHABET_SIZE - 1 - index];
  }

  printf("[Cipher]: %s\n", password);
}

void toLowerCase(char *text) {
  for (register int x = 0; text[x] != '\0'; x++) {
    for (register int y = 0; y < ALPHABET_SIZE; y++) {
      if (text[x] == upperCaseAlphabet[y]) {
        text[x] = lowerCaseAlphabet[y];
        break;
      }
    }
  }
}

int position(const char letter) {
  for (register int x = 0; x < ALPHABET_SIZE; x++) {
    if (lowerCaseAlphabet[x] == letter)
      return x;
  }
  return -1;
}

char* extend(char *key, const char *comparedPhrase) {
  size_t keySize = strlen(key);
  size_t comparedSize = strlen(comparedPhrase);

  if (key > comparedSize)
    key[comparedSize] = '\0';
  else if (keySize < comparedSize) {
    size_t originalSize = keySize;

    for (size_t x = keySize; x < comparedSize; x++)
      key[x] = key[x % originalSize];
    key[comparedSize] = '\0';
  }

  return key;
}

void vigenere(char *phrase, char *key) {
  char *keyPointer = extend(key, phrase);
  size_t maxSize = strlen(phrase);
  
  toLowerCase(phrase);
  toLowerCase(key);

  for (size_t x = 0; x < maxSize; x++) {
    int phrasePosition = position(phrase[x]);
    int keyPosition = position(keyPointer[x]);

    if (phrasePosition == -1 || keyPosition == -1) {
      printf("%c", phrase[x]);
      continue;
    }

    printf("%c", lowerCaseAlphabet[(phrasePosition + keyPosition) % ALPHABET_SIZE]);
  }

  printf("\n");
}