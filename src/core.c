#include "include/core.h"
#include <stdio.h>
#include <string.h>

/* Declarando as variáveis globais */
const char lowerCaseAlphabet[] = "abcdefghijklmnopqrstuvwxyz";
const char upperCaseAlphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void showHelp (void) { printf("%s", HELP_COMMAND); }

void toLowerCase(char *text) {
    for (register int x = 0; text[x] != '\0'; x++) {
        for (register int y = 0; y < SIZEALP; y++) {
        if (text[x] == upperCaseAlphabet[y]) {
            text[x] = lowerCaseAlphabet[y];
            break;
            }
        }
    }
}

void initOptions(Options *options) {
    options->password = NULL;
    options->algorithm = NULL;
    options->rotation = 2;
}

void parsingOptions (int argc, char *argv[], Options *options) {
    for (int x=2; x<argc;x++) {
        if (!(strcmp(argv[x], "-p")) || !(strcmp(argv[x], "--password"))) {
            options->password = argv[x+1];
            x++;
        }
        else if (!(strcmp(argv[x], "--algorithm")) || !(strcmp(argv[x], "-a"))) {
            options->algorithm = argv[x+1];
            x++;
        }
    }
}

void omegaRun (char *tag, Options *options) {
    if (!(strcmp(options->algorithm, "vigenere")))
        vigenere((char *)options->password, tag);
    else if (!(strcmp(options->algorithm, "caesar")) || !(strcmp(options->algorithm, "cesar")))
        caesar(tag, options->rotation);
    else if (!(strcmp(options->algorithm, "atbash"))) 
        atbash(tag);
}