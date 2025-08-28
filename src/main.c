/*
 Omega - Password-generator
 Encript a password with keys and words

 Version: 1.5v without multipleHASH
 Compile: make
 By: @Rahvax
*/
#include "lib/omega.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  if (argc < 3) {
    fprintf(stderr, "Modo de usar incorreto\f%s <key> <tag/-o> [--FLAGS]\n", argv[0]);
    return -1;
  }
  selectFlag(argc, argv);
  return 0;
}
