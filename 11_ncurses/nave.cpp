#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

//Como se define e inicializa una estructura.

struct TNave {
    int vida;
    char cuerpo;
};

//Declarando variables globales.

struct TAlgo {
    int vida;
    char cuerpo;
} nave1, nave2;

//Alias de una estructura anonima.

typedef struct {
    int vida;
    char cuerpo;
} Nave;

//Alias

typedef struct TNave Nave;

int main(int argc, const char **argv){

    struct TNave bueno = { 3, 'O' };
    struct TNave malo;

    Nave otra;

    malo.vida = 5;
    malo.cuerpo = 'A';

    memset(&bueno, 0, sizeof(TNave));
    bzero(&bueno, sizeof(bueno));

    return EXIT_SUCCESS;
}
