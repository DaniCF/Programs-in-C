#include <stdio.h>
#include <stdlib.h>

int main() {

int resultado;

printf("Escribe 10 numeros y te dare la media.\n");
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

printf("La media es %i.\n", resultado / 10);

return EXIT_SUCCESS;

}
