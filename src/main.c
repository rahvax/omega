#include "include/core.h"
#include "include/cipher.h"
#include <stdio.h>
#include <string.h>

int main (int argc, char *argv[]) {
    Options options;
    initOptions(&options);

    if (argc < 2) {
        showHelp();
        return 0;
    }
    printf("[Omega]: %s\n", VERSION);
    
    parsingOptions(argc, argv, &options);
    printf("Opções escolhidas: \n\
        --password=%s\n\
        --algorithm=%s\n",
    options.password ? options.password : "Não informado",
    options.algorithm ? options.algorithm : "Não informado");

    return 0;
}