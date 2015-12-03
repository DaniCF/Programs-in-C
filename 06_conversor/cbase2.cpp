#include<stdio.h>
#include<stdlib.h>

#define BASE 8

int main(int argc, const char **argv){

    int entrada,
        destino = 0;

    printf("Introduce un numero entre 0 y 999: ");
    scanf(" %i", &entrada);
    printf("%i", entrada % BASE);
    entrada /= BASE;
    printf("%i", entrada % BASE);
    entrada /= BASE;
    printf("%i", entrada % BASE);
    entrada /= BASE;
    printf("%i", entrada % BASE);
    entrada /= BASE;

    do {
        destino *= 10;
        destino += entrada % 10;
        entrada /= 10;
    } while ( entrada != 0 );


     printf("\n", destino);


    return EXIT_SUCCESS;
}
