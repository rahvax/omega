#include "include/cipher.h"
#include <stdio.h>

int main(int argc, char **argv) {
  if (argc < 2) {
    fprintf(stderr, "[X]: faltam argumentos:\f%s <senha> <chave> [argumentos]\n", argv[0]);
    return -1;
  }
  vigenere(argv[1], argv[2]);
  return 0;
}