#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define NORTESUR 1
#define ESTEOESTE 2

int main(int argc, const char **argv) {
    int direccion;
    int lugar = 0;        

    printf("Te encuentras en un cruce.\n");
    printf("¿Adonde quieres ir? Escribir: N1, S2, E3, O4.\n");
    scanf(" %i", &direccion);
    if (tolower(direccion) == '1')
        lugar += NORTESUR;
    if (tolower(direccion) == '2')
        lugar -= NORTESUR;
    if (tolower(direccion) == '3')
        lugar += ESTEOESTE;
    if (tolower(direccion) == '4')
        lugar -= ESTEOESTE;

    switch(lugar){
        case 0:
            printf("Lugar 1.\n");
            scanf(" %i", &direccion);
            break;
        case 1:
            printf("Lugar 4.\n");
            scanf(" %i", &direccion);
            break;
        case 2:
            printf("Lugar 2.\n");
            scanf(" %i", &direccion);
            break;
        case 3:
            printf("Lugar 3.\n");
            scanf(" %i", &direccion);
            break;
        case -1:
            printf("Lugar 5.\n");
            scanf(" %i", &direccion);
            break;
        case -2:
            printf("Lugar 7.\n");
            scanf(" %c", &direccion);
            if (tolower(direccion) == 'N')
                lugar += NORTESUR;
            if (tolower(direccion) == 'S')
                lugar -= NORTESUR;
            if (tolower(direccion) == 'E')
                lugar += ESTEOESTE;
            if (tolower(direccion) == 'O')
                lugar -= ESTEOESTE;
            break;
        case -3:
            printf("Lugar 6.\n");
            scanf(" %c", &direccion);
            if (tolower(direccion) == 'N')
                lugar += NORTESUR;
            if (tolower(direccion) == 'S')
                lugar -= NORTESUR;
            if (tolower(direccion) == 'E')
                lugar += ESTEOESTE;
            if (tolower(direccion) == 'O')
                lugar -= ESTEOESTE;
            break;
    }



    return EXIT_SUCCESS;
}
