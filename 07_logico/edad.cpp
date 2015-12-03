#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char **argv){

    int input1, input2;

    printf("Numero 1: ");
    scanf(" %i", &input1);
    printf("Numero 2: ");
    scanf(" %i", &input2);

    if (input1 > input2)
        printf("%i\n%i\n", input1, input2);
    else
        printf("%i\n%i\n", input2, input1);

    return EXIT_SUCCESS;
}    
