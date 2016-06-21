#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char **argv) {
    
    int a11,
        a12,
        a13,
        a21,
        a22,
        a23,
        a31,
        a32,
        a33,
        a41,
        a42,
        a43;
    
    int b11,
        b12,
        b13,
        b14,
        b15,
        b21,
        b22,
        b23,
        b24,
        b25,
        b31,
        b32,
        b33,
        b34,
        b35;

    printf("Introduzca la matriz A\n");
    printf("a11: ");
    scanf(" %i", &a11);
    printf("a12: ");
    scanf(" %i", &a12);
    printf("a13: ");
    scanf(" %i", &a13);
    printf("a21: ");
    scanf(" %i", &a21);
    printf("a22: ");
    scanf(" %i", &a22);
    printf("a23: ");
    scanf(" %i", &a23);
    printf("a31: ");
    scanf(" %i", &a31);
    printf("a32: ");
    scanf(" %i", &a32);
    printf("a33: ");
    scanf(" %i", &a33);

    printf("Introduzca la matriz B\n");
    printf("b11: ");
    scanf(" %i", &b11);
    printf("b12: ");
    scanf(" %i", &b12);
    printf("b13: ");
    scanf(" %i", &b13);
    printf("b14: ");
    scanf(" %i", &b14);
    printf("b15: ");
    scanf(" %i", &b15);
    printf("b21: ");
    scanf(" %i", &b22);
    printf("b22: ");
    scanf(" %i", &b22);
    printf("b23: ");
    scanf(" %i", &b23);
    printf("b24: ");
    scanf(" %i", &b22);
    printf("b25: ");
    scanf(" %i", &b23);
    printf("b31: ");
    scanf(" %i", &b31);
    printf("b32: ");
    scanf(" %i", &b32);
    printf("b33: ");
    scanf(" %i", &b33);
    printf("b34: ");
    scanf(" %i", &b32);
    printf("b35: ");
    scanf(" %i", &b33);

    printf("La matriz resultante es:\n");
    printf("%i   %i   %i   %i   %i\n", a11, a12, a13, b11, b12);
    
    
    
    
    
    
    return EXIT_SUCCESS;
}
