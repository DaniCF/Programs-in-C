#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct TCurriculo {
    char nombre[20];
    int programacion;
    int bases;
    int fol;
};

void muestra(struct TCurriculo notas){
    printf("Las notas de %s\n", notas.nombre);
    printf("\n");
    printf("Programacion: %i\n", notas.programacion);
    printf("Bases: %i\n", notas.bases);
    printf("FOL: %i\n" , notas.fol);
    printf("\n");
}

int main(int argc, const char **argv){

    struct TCurriculo angel = { "Angel", 4, 7, 9 };
    struct TCurriculo victor = angel;
    strcpy(victor.nombre, "Victor");

    muestra(angel);
    muestra(victor);


    return EXIT_SUCCESS;
}
