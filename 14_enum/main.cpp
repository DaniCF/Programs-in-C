#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char **argv){
    double op[2];

    printf("Este programa suma.\n\n");
    for(int i=0; i<2; i++){
        printf("Operando %i: ", i + 1);
        scanf(" %lf", &op[i]);
    }

    printf("Resultado = %.2lf\n", op[0] + op[1]);

    return EXIT_SUCCESS;
}
