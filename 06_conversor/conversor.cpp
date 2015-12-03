#include<stdio.h>
#include<stdlib.h>

int main(int argc, const char **argv){

    int entrada;

    printf("Introduce un numero entre 0 y 999: ");
    scanf(" %i", &entrada);
    printf("%i", entrada % 10);
    entrada /= 10;
    printf("%i", entrada % 10);
    entrada /= 10;
    printf("%i", entrada % 10);
    entrada /= 10;
    printf("\n");



    return EXIT_SUCCESS;
}
