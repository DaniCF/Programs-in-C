#include<stdio.h>
#include<stdlib.h>

int main(int argc, const char **argv){

    int entrada;

    printf("Introduce un numero entre 0 y 999: ");
    scanf(" %i", &entrada);
    printf("%i", entrada % 2);
    entrada /= 2;
    printf("%i", entrada % 2);
    entrada /= 2;
    printf("%i", entrada % 2);
    entrada /= 2;
    printf("%i", entrada % 2);
    entrada /= 2;
    printf("%i", entrada % 2);
    entrada /= 2;
    printf("%i", entrada % 2);
    entrada /= 2;
    printf("%i", entrada % 2);
    entrada /= 2;
    printf("%i", entrada % 2);
    entrada /= 2;
    printf("%i", entrada % 2);
    entrada /= 2;
    printf("%i", entrada % 2);
    entrada /= 2;
    

    printf("\n");



    return EXIT_SUCCESS;
}
