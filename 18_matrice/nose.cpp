#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define NLETRAS ('z'-'a'+1)

int main(int argc, const char **argv){
        
        FILE *pf = NULL;
        double firma[NLETRAS]; // El valor ascii de z menos el valor ascii de a = +1 para que englobe todas las letras menos la Ñ que nadie la quiere :D
        int letra;


        bzero(firma, NLETRAS * sizeof(double));
        if (argc < 2){
                fprintf(stderr, "El uso es %s <fichero>.\n", argv[0]);
                exit(1); // Mejor poner exit que return para que no vuelva al main. exit(EXIT_FAILURE);
                }

        if (!(pf = fopen(argv[1], "r++"))){ // No poner == NULL porque es rudimentario. la ! dice lo contrario :D (!pf)
                fprintf(stderr, "Fichero %s no ENCONTRADO :D.\n", argv[1]);
                exit(EXIT_FAILURE);
                }

        while( (letra = fgetc(pf)) != EOF)
        if (isalpha(letra)){
                letra = tolower(letra);
                firma[letra-'a']++;
                }




        fclose(pf);
        return EXIT_SUCCESS;
}
