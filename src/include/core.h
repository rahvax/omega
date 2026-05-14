#ifndef _CORE_H
#define _CORE_H

#define SIZEALP 26
#define VERSION "2.0"
#define HELP_COMMAND "omega <tag> [argumentos]\n \
-p [--password]\tDefinir a senha por argumento, com exceção de caesar que\n\t\t\tusa a tag diretamente como password\n \
-a [--algorithm]\tDefinir o tipo de algoritmo do programa\n \
\n"

/* Tornando visível as variáveis globais */
extern const char lowerCaseAlphabet[];
extern const char upperCaseAlphabet[];

/* Definindo estruturas */
typedef struct {
    const char *password;
    const char *algorithm;
    int rotation;
} Options;

/* Exibir a mensagem de ajuda */
void showHelp (void);
/* Iniciar as variáveis de argumentos */
void initOptions(Options *options);
/* Ler e definir os argumentos */
void parsingOptions (int argc, char *argv[], Options *options);
/* Transformar texto em caixa baixa */
void toLowerCase(char *text);
/* Selecionar a função e executar */
void omegaRun (char *tag, Options *options);
#endif
