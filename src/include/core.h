#ifndef _CORE_H
#define _CORE_H
/* Transformar texto em caixa baixa */
void toLowerCase(char *text);
/* Estender uma chave até o tamanho da frase */
char* extend(char *key, const char *comparedPhrase);
/* Pegar posição do alfabeto de uma letra */
int position(const char letter);
#endif
