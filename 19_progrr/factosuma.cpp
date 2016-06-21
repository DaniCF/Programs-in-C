#include <stdio.h>
#include <stdlib.h>

int factorial(int n)
{
    if (n == 0){
        return 1;
    }else
        return n + factorial(n - 1);
}

int main(){

    int numero;

    printf("Escribe un numero: \n");
    scanf(" %i", &numero);

    printf("Valor de retorno: %i\n", factorial(numero) - 1);

    
    return EXIT_SUCCESS;
}
