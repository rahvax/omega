#ifndef _CIPHER_H
#define _CIPHER_H
#define SIZEALP 26

/* Transformar texto em caixa baixa */
void toLowerCase(char *text);
/* Pegar posição do alfabeto de uma letra */
int position(const char letter);
/* Cifrar uma senha em Cifra de Cesar */
void caesar(char *password, const int rotation);
/* Cifrar uma senha em Cifra Atbash */
void atbash (char *password);
/* Cifra uma palavra em Cifra de Vigenere */
void vigenere(char *phrase, char *key);
#endif
