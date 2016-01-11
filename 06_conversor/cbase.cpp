#include<stdio.h> //Librerias de Linux.
#include<stdlib.h> //Librerias de Linux.

//Conversor de decimal a octal.

#define BASE 8 //Definir la Base. Se puede cambiar para convertirlo en otro conversor

int main(int argc, const char **argv){

    int entrada; //Variable

    printf("Introduce un numero entre 0 y 999: "); //Se imprime el enunciado.
    
    //Se indica el numero, se divide cada cifra entre la base y se imprime.
    
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
