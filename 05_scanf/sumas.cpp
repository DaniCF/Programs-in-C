#include <stdio.h>
#include <stdlib.h>

int main(){

    int resultado = 0;
    int entrada;
    FILE *pf;

    pf = fopen("numeros", "r");
    while(!feof(pf)){
        fscanf(pf," %i", &entrada);
        resultado += entrada;
    }    
    fclose(pf);

    printf("%i\n", resultado);

    return EXIT_SUCCESS;
}

