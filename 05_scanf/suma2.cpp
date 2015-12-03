#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *agrv){
   
   
    FILE *pf;

    pf = fopen("numeros.txt");

    fclose(pf);


    return EXIT_SUCCESS;
}
