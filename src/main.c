/*
 Omega - Password-generator
 Encript a password with keys and words
 By: @Rahvax
*/
#include "lib/omega.h"
#include <stdio.h>
#include <getopt.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  char *key = argv[1], *tag = argv[2], *size = NULL;
  int opt=0, sizeHash=0;

  if (argc < 3) {
    fprintf(stderr, "Modo de usar incorreto\f%s <key> <tag/-o> [--FLAGS]\n", argv[0]);
    return 1;
  }

  while ((opt = getopt(argc, argv, "s:ho")) != -1) {
    switch (opt) {
      case 's':
        size = optarg;
        break;
      case 'h':
        printf("Flags:\n-s <SIZE>  tamanho da hash gerada\n-h  exibir essa mensagem\n-o  modo legado\n");
        break;
      case 'o':
        legacyHasher(argv[1]);
	return 0;
      default:
        fprintf(stderr, "Erro no formato!\f%s <key> <tag/-o> [--FLAGS]\n", argv[0]);
	break;
    }
  }
  
  if (size) {
    sizeHash = atoi(size);
    if (sizeHash > 32)
      sizeHash = 32;
  }
  else
    sizeHash = 32;
  if (hash(key, tag, sizeHash) != 0) {
    fprintf(stderr, "[-]: impossível gerar a hash, encerrado!\n");
    return 1;
  }

  return 0;
}
