/*
 Omega - Password-generator
 Encript a password with keys and words

 Version: 2.0v 
 Compile: make
 By: @Rahvax
*/
#include <stdio.h>

int main(int argc, char *argv[]) {
  if (argc < 3) {
    fprintf(stderr, "Modo de uso incorreto\f%s <key> <tag/-o> [--FLAGS]\n", argv[0]);
    return -1;
  }
  return 0;
}

/*
  Vou refazer toda a base do software, então
  essa branch pode conter problemas.
*/
