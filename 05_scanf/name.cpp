#include <stdio.h>
#include <stdlib.h>

int main(){

    char mi_nombre[20];
    char comando[0x100];

    system("toilet -f pagga 'OMNICORP' ");


    printf("Nombre: ");
    scanf(" %s", mi_nombre);
    printf("Te llamas %s.\n", mi_nombre);
    sprintf(comando, "toilet -f pagga %s", mi_nombre);

    system(comando);

    return EXIT_SUCCESS;
}
