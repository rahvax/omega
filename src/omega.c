#include "lib/omega.h"
#include <openssl/evp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>
#include <openssl/md5.h>
#include <openssl/crypto.h>
#include <getopt.h>
#include <unistd.h>
#include <openssl/hmac.h>
#define HASHLEN SHA256_DIGEST_LENGTH

/* Legacy Encripter */
int legacyHasher (const char *keyword) {
  unsigned char *hash = SHA256((const unsigned char *)keyword, strlen(keyword), NULL);
  if (!hash) return -1;
  printf("Key: %s\nHash: ", keyword);
  for (register int x=0; x<32; x++)
    printf("%02x", hash[x]);
  printf("\n");
  return 0;
}

void selectFlag(const int argc, char **argv) {
  char *key = argv[1], *tag = argv[2], *size = NULL, *type=NULL;
  int opt=0;

  while ((opt = getopt(argc, argv, "s:t:ho")) != -1) {
    switch (opt) {
      case 's':
        size = optarg;
        break;
      case 'h':
        printf("Flags:\n-s <SIZE>  tamanho da hash gerada\n-h  exibir essa mensagem\n-o  modo legado\n");
        break;
      case 'o':
        legacyHasher(argv[1]);
	return;
      case 't':
        if (strcmp(optarg, "hmac") && strcmp(optarg, "sha256")) {
          fprintf(stderr, "[X]: esse tipo não é conhecido! Só disponível: hmac, sha256\n");
          return;
        }
	type=optarg;
	break;
      default:
        fprintf(stderr, "Erro no formato!\f%s <key> <tag/-o> [--FLAGS]\n", argv[0]);
	break;
    }
  }
  
  if (size) {
    if (atoi(size) > 32)
      size = "32";
  }
  else
    size = "32";

  if (type && !strcmp(type, "hmac")) {
    if (hashHMAC(key, tag, atoi(size)) != 0) {
      fprintf(stderr, "[-]: impossível gerar a hash, encerrado!\n");
      return;
    }
  } else {
    if (hash(key, tag, atoi(size)) != 0) {
      fprintf(stderr, "[-]: impossível gerar a hash, encerrado!\n");
      return;
    }
  }
}

int hashHMAC(const char *password, const char *tag, const int size) {
  unsigned char keyHash[EVP_MAX_MD_SIZE];
  unsigned int keylen;

  if (!HMAC(EVP_sha3_512(), tag, strlen(tag), (const unsigned char *)password,
            strlen(password), keyHash, &keylen)) {
    return -1;
  }
  for (register int x = 0; x < keylen; x++) {
        printf("%02x", keyHash[x]);
  }
  printf("\n");
  return 0;
}

/* Hash a word */
int hash(const char *password, const char *tag, const int size) {
  unsigned char keyHash[SHA256_DIGEST_LENGTH],
  tagHash[SHA256_DIGEST_LENGTH];

  if (!SHA256((const unsigned char *)password, strlen(password), keyHash)) {
    fprintf(stderr, "[-]: não foi possível gerar a chave\n");
    return -1;
  }
  if (!SHA256((const unsigned char *)tag, strlen(tag), tagHash)) {
    fprintf(stderr, "[-]: não foi possível gerar a tag\n");
    return -1;
  }

  swap(keyHash, tagHash, tag);
  printf("Pass/tag: %s|%s\nHash: ", password, tag);
  for (register int x = 0; x < size; x++)
    printf("%02x", keyHash[x]);
  printf("\n");

  OPENSSL_cleanse(keyHash, HASHLEN);
  OPENSSL_cleanse(tagHash, HASHLEN);
  return 0;
}

/* Mix KEY and TAG*/
void swap(unsigned char *sha256Key, const unsigned char *sha256Tag, const char *tag) {
  size_t size = strlen(tag);
  if (size > 32) {
    size = 32;
    fprintf(stderr, "formatado para o máximo 32\n");
  }
  for (size_t x = 0; x < size; x++) {
    size_t hashPos = tag[x] % HASHLEN;
    size_t hashPos2 = (tag[x]*3+x) % HASHLEN;
    sha256Key[hashPos] ^= sha256Tag[x % HASHLEN];
    sha256Key[hashPos2] ^= sha256Tag[(x*5+7) % HASHLEN];
  }
}
