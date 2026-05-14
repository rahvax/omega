#ifndef _HASH_H
#define _HASH_H

#define SHA256_DIGEST_SIZE 32
#define SHA256_TEXT_SIZE 65

/* Gerar hash SHA256 usando password e tag */
void sha256(const char *password, const char *tag);

#endif
