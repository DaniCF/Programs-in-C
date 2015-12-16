#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, const char **argv){
    int numero, pensado;

    printf("Adivina el numero entre 1 y 10.\n");

    srand(time(NULL));
    pensado = rand() % 10 + 1;
    do {
        printf("Numero: ");
        scanf(" %i", &numero);
    } while( numero != pensado );

    printf("Mu bien.\n");

    return EXIT_SUCCESS;
}

