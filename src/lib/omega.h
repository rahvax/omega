/*
  Header
  By: @Rahvax
 */
#include <stdlib.h>
#ifndef _OMEGA_H
#define _OMEGA_H
/* Hash a keyword with single-tag */
int hash (const char *password, const char *tag, const int size);
/* Hash a keyword without single-tag */
int legacyHasher (const char *password);
/* Swap a hash */
void swap (unsigned char *sha256Key, const unsigned char *sha256Tag, const char *tag);
/* Select Flags and Start */
void selectFlag(const int argc, char **argv);
/* Hash a keywork with single-tag and HMAC */
int hashHMAC (const char *password, const char *tag, const int size);
/* Argon2 Hash */
int hashArgo (const char *password, const char *tag, const int size);
#endif
