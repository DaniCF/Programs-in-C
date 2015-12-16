#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define NORTESUR 1
#define ESTEOESTE 2

int main(int argc, const char **argv) {
    char direccion;
    int lugar = 0;        

    printf("Te encuentras en un cruce.\n");
    printf("¿Adonde quieres ir? Escribir: N, S, E, O.\n");
    scanf(" %c", &direccion);
    if (tolower(direccion) == 'N')
        lugar += NORTESUR;
    if (tolower(direccion) == 'S')
        lugar -= NORTESUR;
    if (tolower(direccion) == 'E')
        lugar += ESTEOESTE;
    if (tolower(direccion) == 'O')
        lugar -= ESTEOESTE;

    switch(lugar){
        case 0:
            printf("Lugar 1.\n");
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
        case 1:
            printf("Lugar 4.\n");
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
        case 2:
            printf("Lugar 2.\n");
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
        case 3:
            printf("Lugar 3.\n");
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
        case -1:
            printf("Lugar 5.\n");
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
