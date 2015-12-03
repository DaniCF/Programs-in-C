#include <stdio.h>
#include <stdlib.h>

int main(){
    int rojo = 0,
        azul = 0;

    char respuesta;

    printf("Ves rojo (s/n): ");
    scanf(" %c", &rojo);
    rojo = respuesta == 's';
    printf("Ves azul (s/n): ");
    scanf(" %c", &azul);
    azul = respuesta == 's';

    if (rojo)
        if (azul)
            printf("Morado,\n");
        else
            printf("Rojo.\n");
    else
        if (azul)
            printf("Azul.\n");
        else
            printf("Negro.\n");

    return EXIT_SUCCESS;
}
