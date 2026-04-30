#include "include/core.h"
#include "include/cipher.h"
#include <stdio.h>
#include <string.h>

#ifdef DEBUG
    #define DEBUG_PRINT(...) printf(__VA_ARGS__)
#else
    #define DEBUG_PRINT(...)
#endif

int main (int argc, char *argv[]) {
    Options options;
    initOptions(&options);

    if (argc < 2) {
        showHelp();
        return 0;
    }
    printf("[Omega]: %s\n", VERSION);
    
    parsingOptions(argc, argv, &options);
    DEBUG_PRINT("Opções escolhidas: \n\
        --password=%s\n\
        --algorithm=%s\n",
    options.password ? options.password : "Não informado",
    options.algorithm ? options.algorithm : "Não informado");

    return 0;
}