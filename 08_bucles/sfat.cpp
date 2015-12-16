#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, const char **argv){
    int numero, pensado;
    char personaje[3];

    printf("Selecciona a tu personaje.\n");
    scanf(" %s", &personaje);
    printf(" %s VS M.Bison\n", personaje);

    srand(time(NULL));
    pensado = rand() % 3 + 1;
    do {
        printf("Numero: ");
        scanf(" %i", &numero);
    } while( numero != pensado );

    printf("Mu bien.\n");

    return EXIT_SUCCESS;
}

