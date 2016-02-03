#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <time.h>

#define SW 800
#define SH 600
#define NW 32
#define SW 32

#define N 5


struct Nave {
    double x;
    double vx;
    double width;
    double height;
    ALLEGRO_BITMAP *nave;
};

void recalcular_posiciones(double *x, double *vx){
    if ( nave->x + nave->vx + nave->width > SW || nave->x + nave->vx < 0)
        *vx *= -1;
    *x += *vx;
};

void iniciar(struct Nave nave[N]){
    for (int i=0; i<N; i++){
    nave[i].x = random;
    nave[i].vx = random;
    nave[i].width = 32;
    nave[i].height = 32;
    nave[i].img = al_create_bitmap(nave[i].width, nave[i].height);
    al_set_target_bitmap(nave[i].img);
    al_clear_to_color(al_map_rgb(rand() % 256, rand() % 256, rand() % 256));
    }
}

int main(int argc, const char **argv){

    //Variables
    ALLEGRO_DISPLAY *ventana = NULL;
    ALLEGRO_EVENT_QUEUE *mensajes = NULL;
    ALLEGRO_TIMER *alarma = NULL;
    bool dibujar = true;
    struct Nave nave[N];
    srand48(time(NULL));
    al_init();
    

    //Crear:
    ventana = al_create_display(SW,SH);
    mensajes = al_create_event_queue();
    alarma = al_create_timer(1/60.);
    

    //Registrar como fuente de eventos:
 
    al_register_event_source(mensajes, al_get_display_event_source(ventana));
    al_register_event_source(mensajes, al_get_timer_event_source(alarma));

    iniciar(nave);
    nave.img = al_create_bitmap(nave.width, nave.height);

    al_set_target_bitmap(nave);
    al_clear_to_color(al_map_rgb(255,0,255));
    al_set_target_bitmap(al_get_backbuffer(ventana));

    al_start_timer(alarma);
    while(1){
        ALLEGRO_EVENT ev;
        al_wait_for_event(mensajes, &ev);

        if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            break;

        if (ev.type == ALLEGRO_EVENT_TIMER)
            dibujar = true;

        if (dibujar && al_is_event_queue_empty(mensajes)){
            dibujar = false;
            recalcular_posiciones(&nave);
            al_clear_to_color(al_map_rgb(0,0,0));
            al_draw_bitmap(nave, x, 120, 0);
            al_flip_display();

        }
    // Miro los eventos
    //     Si cierran la ventana
    //        Salgo del bucle
    //     Si se cumple el tiempo
    //        Repintar
    // Si repintar
    //    No repintar
    //    Mover el cuadrado
    //    Pintar
    }
    //DESTRUIR
    al_destroy_timer(alarma);
    al_destroy_display(ventana);
    al_destroy_event_queue(mensajes);

    return EXIT_SUCCESS;
}
