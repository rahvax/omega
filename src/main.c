#include "include/cipher.h"
#include <string.h>
#include <stdio.h>

int main(int argc, char **argv) {
  char text[] = "gabriel";
  char key[100] = "arrozar";
  vigenere(text, key);

  return 0;
}