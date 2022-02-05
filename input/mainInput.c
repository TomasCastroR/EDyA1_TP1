#include <stdio.h>
#include <stdlib.h>
#include "input/input.h"

int main (int argc, char** argv) {
    if (argc == 5) {
        int cantidad = atoi(argv[3]);
        crear_archivo_personas(cantidad, argv[1], argv[2], argv[4]);
    }
    else {
        printf("No se ingresaron la cantidad correcta de argumentos\n");
    }
}