#include "include/cipher.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  if (argc < 2) {
    fprintf(stderr, "[X] falta de argumento\t%s <palavra> <chave>\n", argv[0]);
    return 1;
  }

  printf("[Original]: %s\n", argv[1]);
  cesar(argv[1], atoi(argv[2]));
  printf("[Cifrado]: %s\n", argv[1]);

  return 0;
}
