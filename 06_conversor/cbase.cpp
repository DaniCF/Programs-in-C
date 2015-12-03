#include<stdio.h>
#include<stdlib.h>

#define BASE 8

int main(int argc, const char **argv){

    int entrada;

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
    
    printf("\n");




    return EXIT_SUCCESS;
}
