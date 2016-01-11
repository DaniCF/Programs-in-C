#include <stdio.h> //Librerias de Linux
#include <stdlib.h> //Librerias de Linux
#include <time.h> //Librerias de Tiempo

//Genera un numero del 1 al 10 que hay que tratar de adivinar.

int main(int argc, const char **argv){
    int numero, pensado; //Variables

    printf("Adivina el numero entre 1 y 10.\n"); //El programa imprime el primer enunciado.

    srand(time(NULL));
    pensado = rand() % 10 + 1; //Estas dos lineas generan el numero aleatorio.
    do {
        printf("Numero: ");
        scanf(" %i", &numero);
    } while( numero != pensado ); //Ciclo que se repite hasta acertar el numero

    printf("Mu bien.\n");  //Mensaje una vez acertado el numero.

    return EXIT_SUCCESS;
}

