#ifndef _CIPHER_H
#define _CIPHER_H
#define SIZEALP 26

/* Cifrar uma senha em Cifra de Cesar */
void cesar (char *password, const int rotation);
/* Cifrar uma senha em Cifra Atbash */
void atbash (char *password);
#endif
