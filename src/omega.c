#include "lib/omega.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>
#include <openssl/md5.h>
#include <openssl/crypto.h>
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

/* Hash a word */
int hash(const char *password, const char *tag, const int size) {
  unsigned char keyHash[SHA256_DIGEST_LENGTH];
  unsigned char tagHash[SHA256_DIGEST_LENGTH];

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
  if (size > 64) {
    size = 64;
    fprintf(stderr, "formatado para o máximo 64\n");
  }
  for (size_t x = 0; x < size; x++) {
    size_t hashPos = tag[x] % HASHLEN;
    size_t hashPos2 = (tag[x]*3+x) % HASHLEN;
    sha256Key[hashPos] ^= sha256Tag[x % HASHLEN];
    sha256Key[hashPos2] ^= sha256Tag[(x*5+7) % HASHLEN];
  }
}
