#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char **argv) {

    int accion;
    int arma = 0;

    const char *ACCION[5] = {
        "Callejon sin salida.Te encuentras un palo",
        "Llegas a un edificio. La puerta esta cerrada",
        "Callejon sin salida",
        "Un señor con malas pintas te mira regular",
        "Te encuentras en un cruce",
    };        

    printf("Te encuentras en un cruce.\n");
    printf("¿Adonde quieres ir? N=1 S=2 E=3 W=4\n");
    printf("Usa 5 para volver.\n");
    scanf("%i", &accion);
    printf("%s.\n", ACCION[accion-1]);

    if (accion > 0) {
       accion = 0; 
       scanf("%i", &accion);
       printf("%s.\n", ACCION[accion-1]);
    }
         
    if (accion = 1) {
       (arma = 1); 
    }
      
    if (accion = 4)
    {
       printf("El señor se dirije hacia ti. Tendras que pelear.\n");
       printf("No puedes defenderte. Recibes una paliza. Fin del juego.\n");    
    } else (arma = 1);
    {
       printf("El señor se dirije hacia ti. Tendras que pelear.\n");
       printf("Gracias al palo consigues quitartelo de encima. Puedes continuar.\n");
    }   



    return EXIT_SUCCESS;
}
