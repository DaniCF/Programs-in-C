#include <stdio.h> //Librerias de Linux
#include <stdlib.h> //Librerias de Linux

//Hace la media de 10 numeros que pide al usuario.

int main() {

int resultado; //Variable

printf("Escribe 10 numeros y te dare la media.\n"); //El programa imprime el enunciado.

//Se piden los 10 numeros y se guardan en la Variable.

printf("Numero 1:");
scanf("%i", &resultado);
printf("Numero 2:");
scanf("%i", &resultado);
printf("Numero 3:");
scanf("%i", &resultado);
printf("Numero 4:");
scanf("%i", &resultado);
printf("Numero 5:");
scanf("%i", &resultado);
printf("Numero 6:");
scanf("%i", &resultado);
printf("Numero 7:");
scanf("%i", &resultado);
printf("Numero 8:");
scanf("%i", &resultado);
printf("Numero 9:");
scanf("%i", &resultado);
printf("Numero 10:");
scanf("%i", &resultado);

printf("La media es %i.\n", resultado / 10); //Se imprime el resultado.

return EXIT_SUCCESS;

}
