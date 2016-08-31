#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <math.h>
#include <time.h>

const float FPS = 60;
const int mundoLargo = 2000;
const int mundoAncho = 2000;
const int SCREEN_W = 1280;
const int SCREEN_H = 720;
const int PARED2_X = 10;
const int PARED2_Y = 9280;

enum MYKEYS {
	KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT, KEY_SPACE,
};

struct Trafico {
	float traficox;
	float traficoy;
	float spawnp;
	int otrosi;
	int otrosy;
};

int main(int argc, char **argv)

{
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_BITMAP *pared2 = NULL;
	ALLEGRO_BITMAP *carretera = NULL;
	ALLEGRO_BITMAP *fondo = NULL;
	ALLEGRO_BITMAP *tierra = NULL;
	ALLEGRO_BITMAP *coche = NULL;
	ALLEGRO_BITMAP *coche2 = NULL;
	ALLEGRO_BITMAP *otros = NULL;
	ALLEGRO_BITMAP *porche1 = NULL;
	ALLEGRO_BITMAP *porche2 = NULL;
	ALLEGRO_BITMAP *porche3 = NULL;
	ALLEGRO_BITMAP *porche4 = NULL;
	ALLEGRO_BITMAP *porche5 = NULL;
	ALLEGRO_BITMAP *porche6 = NULL;
	ALLEGRO_BITMAP *freno = NULL;
	ALLEGRO_BITMAP *ciudad = NULL;
	ALLEGRO_BITMAP *ganas = NULL;
	ALLEGRO_BITMAP *pierdes = NULL;
	ALLEGRO_FONT *font = NULL;
	int i = 3;
	int objetivo = 10000;
	int tiempo = 3600;
	float velocidad = 0;
	float carreteray = 0;
	float carreteray2 = 720;
	float bouncer_x = 360;
	float bouncer_y = (SCREEN_H / 10) * 9;
	int camaraX;
	float carreterax1;
	float carreterax2;
	float angulo = 1.571;
	float velocidadt = -10;
	float veltraficox, veltraficoy;
	float centro = 695;
	float ladoizq = 620;
	float ladoder = 790;
	float frenosi = 3;
	float hasganao = 5000;
	float hasperdio = 5000;
	bool key[5] = { false, false, false, false, false};
	bool redraw = true;
	bool doexit = false;

	struct Trafico trafico1 = {1000, 300, 1000, 5, 1};
	struct Trafico trafico2 = {850, 200, 850, 5 , 2};
	struct Trafico trafico3 = {1170, 0, 1170, 5, 3};
	struct Trafico trafico4 = {1000, 400, 1000, 5, 4};
	struct Trafico trafico5 = {850, 100, 850, 5, 1};
	struct Trafico trafico6 = {1170, 500, 1170, 5, 2};


	if (!al_init()) {
		fprintf(stderr, "failed to initialize allegro!\n");
		return -1;
	}

	if (!al_init_image_addon()) {
		al_show_native_message_box(display, "Error", "Error", "No carga lo de imagen", NULL, ALLEGRO_MESSAGEBOX_ERROR);

	}

	if (!al_init_primitives_addon()) {
		al_show_native_message_box(display, "Error", "Error", "No carga lo de primitivos", NULL, ALLEGRO_MESSAGEBOX_ERROR);

	}

	if (!al_install_keyboard()) {
		fprintf(stderr, "failed to initialize the keyboard!\n");
		return -1;
	}

	timer = al_create_timer(1.0 / FPS);
	if (!timer) {
		fprintf(stderr, "failed to create timer!\n");
		return -1;
	}

	display = al_create_display(SCREEN_W, SCREEN_H);
	if (!display) {
		fprintf(stderr, "failed to create display!\n");
		al_destroy_timer(timer);
		return -1;
	}

	al_init_font_addon();
	al_init_ttf_addon();

	font = al_load_ttf_font("djc2.otf", 60, 0);

	pared2 = al_create_bitmap(PARED2_X, PARED2_Y);

	carretera = al_load_bitmap("road22.png");

	if (!carretera) {
		fprintf(stderr, "failed to create bouncer bitmap!\n");
		al_destroy_display(display);
		al_destroy_timer(timer);
		return -1;
	}

	fondo = al_load_bitmap("cielo2.png");
	tierra = al_load_bitmap("camino4.png");
	coche = al_load_bitmap("outrun2.png");
	otros = al_load_bitmap("outruntrprueba5.png");
	ciudad = al_load_bitmap("ciudad3.png");
	freno = al_load_bitmap("freno.png");

	ganas = al_load_bitmap("youwin.png");
	pierdes = al_load_bitmap("youlose.png");
	
	al_convert_mask_to_alpha(coche, al_map_rgb(186, 254, 202));
	al_convert_mask_to_alpha(otros, al_map_rgb(186, 254, 202));

	
	if (!fondo) {
		al_show_native_message_box(display, "Error", "Error", "Falla la carga de imagen", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		al_destroy_display(display);
		return 0;
	}

	if (!coche) {
		al_show_native_message_box(display, "Error", "Error", "Falla la carga de imagen", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		al_destroy_display(display);
		return 0;
	}

	al_set_target_bitmap(pared2);

	al_clear_to_color(al_map_rgb(150, 150, 150));

	al_set_target_bitmap(al_get_backbuffer(display));

	event_queue = al_create_event_queue();
	if (!event_queue) {
		fprintf(stderr, "failed to create event_queue!\n");
		al_destroy_bitmap(pared2);
		al_destroy_display(display);
		al_destroy_timer(timer);
		return -1;
	}

	al_register_event_source(event_queue, al_get_display_event_source(display));

	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	al_register_event_source(event_queue, al_get_keyboard_event_source());

	al_clear_to_color(al_map_rgb(0, 0, 0));

	al_flip_display();

	al_start_timer(timer);

	while (!doexit)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_TIMER) {

			tiempo -= 1;

			/*Spawn del trafico*/

			srand(time(NULL));
			int distancia = rand() % (950 - 750) + 750;
			int distancia2 = rand() % (950 - 750) + 750;
			int distancia3 = rand() % (950 - 750) + 750;
			int distancia4 = rand() % (1201 - 1050) + 1050;
			int distancia5 = rand() % (1201 - 1050) + 1050;
			int distancia6 = rand() % (1201 - 1050) + 1050;

			/*Teclas, movimiento y cambio de sprites en coche principal*/

			if (key[KEY_UP] && velocidad < 25) {
				velocidad += 0.5;
				velocidadt += 0.5;
			}
			else if (velocidad > 0) {
				velocidad -= 0.1;
				velocidadt -= 0.1;
			}

			if (key[KEY_DOWN]) {
				velocidad -= 0.3;
				velocidadt -= 0.3;
				frenosi = SCREEN_W / 2;
			}
			else{
				frenosi = 3000;
			}

			if (key[KEY_LEFT] && velocidad > 0) {
				bouncer_x -= 4;
				frenosi = frenosi + 3;
			}
			if (key[KEY_LEFT] && i > 1 && velocidad > 0) {
				i -= 1;
			}
			else if (!key[KEY_LEFT] && i < 4) {
				i += 1;
			}

			if (key[KEY_RIGHT] && velocidad > 0) {
				bouncer_x += 4;
				frenosi = frenosi - 3;
			}
			if (key[KEY_RIGHT] && i < 5 && velocidad > 0) {
				i += 1;
			}
			else if (!key[KEY_RIGHT] && i > 3) {
				i -= 1;
			}

			objetivo -= velocidad / 10;

			/*Carretera*/

			carreteray += velocidad;
			carreteray2 += velocidad;

			if (carreteray > 1080) {
				carreteray = carreteray2 - 720;
			}
			if (carreteray2 > 1080) {
				carreteray2 = carreteray -720;
			}
			
			/*Limites de sprite y velocidad segun posición*/

			if (velocidad < 0){
				velocidad = 0;
				i = 3;
			}

			if (bouncer_x < 140 && velocidad > 4) {
				velocidad -= 0.6;
				velocidadt -= 0.6;
			}

			if (bouncer_x > 590 && velocidad > 4) {
				velocidad -= 0.6;
				velocidadt -= 0.6;
			}

			/*Formulas para velocidad y posicion del trafico*/

			veltraficox = (velocidadt / 5) * cos(angulo);
			veltraficoy = (velocidadt / 5) * sin(angulo);
			trafico1.traficox += veltraficox;
			trafico1.traficoy += veltraficoy;
			trafico2.traficox += veltraficox;
			trafico2.traficoy += veltraficoy - 1;
			trafico3.traficox += veltraficox;
			trafico3.traficoy += veltraficoy - 1;
			trafico4.traficox += veltraficox;
			trafico4.traficoy += veltraficoy;
			trafico5.traficox += veltraficox;
			trafico5.traficoy += veltraficoy - 1;
			trafico6.traficox += veltraficox;
			trafico6.traficoy += veltraficoy - 1;

			/*Reaparicion del trafico.*/

			if (trafico1.traficoy > distancia) {
				trafico1.traficoy = 200;
				trafico1.traficox = trafico1.spawnp;
				trafico1.otrosi = 5;
				trafico1.otrosy = rand() % 4;
			}
			if (trafico2.traficoy > distancia2) {
				trafico2.otrosi = 5;
				trafico2.traficoy = 200;
				trafico2.traficox = trafico2.spawnp;
				trafico2.otrosy = rand() % 4;
			}

			if (trafico3.traficoy > distancia3) {
				trafico3.otrosi = 5;
				trafico3.traficoy = 200;
				trafico3.traficox = trafico3.spawnp;
				trafico3.otrosy = rand() % 4;
			}

			if (trafico4.traficoy > distancia4) {
				trafico4.otrosi = 5;
				trafico4.traficoy = 200;
				trafico4.traficox = trafico4.spawnp;
				trafico4.otrosy = rand() % 4;
			}
			if (trafico5.traficoy > distancia5) {
				trafico5.otrosi = 5;
				trafico5.traficoy = 200;
				trafico5.traficox = trafico5.spawnp;
				trafico5.otrosy = rand() % 4;
			}

			if (trafico6.traficoy > distancia6) {
				trafico6.otrosi = 5;
				trafico6.traficoy = 200;
				trafico6.traficox = trafico6.spawnp;
				trafico6.otrosy = rand() % 4;
			}


			/*Perspectiva - Falso 3D*/

			camaraX = bouncer_x;

			carreterax1 = 650 - (camaraX / 2);
			carreterax2 = 1130 - (camaraX / 2);

			if (carreterax1 < 820 - camaraX){
				carreterax1 = 820 - camaraX;
			}

			if (carreterax1 > 860 - camaraX) {
				carreterax1 = 860 - camaraX;
			}

			if (carreterax2 > 1320 - camaraX) {
				carreterax2 = 1320 - camaraX;
			}

			if (carreterax2 < 1280 - camaraX) {
				carreterax2 = 1280 - camaraX;
			}

			/*Creacion de sprites*/

			coche2 = al_create_sub_bitmap(coche, i * 130, 0, 130, 74);
			porche1 = al_create_sub_bitmap(otros, trafico1.otrosi * 130, trafico1.otrosy * 62, 130, 62);
			porche2 = al_create_sub_bitmap(otros, trafico2.otrosi * 130, trafico2.otrosy * 62, 130, 62);
			porche3 = al_create_sub_bitmap(otros, trafico3.otrosi * 130, trafico3.otrosy * 62, 130, 62);
			porche4 = al_create_sub_bitmap(otros, trafico4.otrosi * 130, trafico4.otrosy * 62, 130, 62);
			porche5 = al_create_sub_bitmap(otros, trafico5.otrosi * 130, trafico5.otrosy * 62, 130, 62);
			porche6 = al_create_sub_bitmap(otros, trafico6.otrosi * 130, trafico6.otrosy * 62, 130, 62);

			/*Cambio de sprites en Trafico*/

			/*porche1*/
			if (trafico1.traficoy > 370) {
				if (trafico1.traficox - camaraX < centro) {
					trafico1.otrosi = 5;
				}

				if (trafico1.traficox - camaraX > centro) {
					trafico1.otrosi = 6;
				}
			}

			if (trafico1.traficoy > 420){
				if (trafico1.traficox - camaraX < centro) {
					trafico1.otrosi = 4;
				}

				if (trafico1.traficox - camaraX > centro) {
					trafico1.otrosi = 7;
				}
			}

			if (trafico1.traficoy > 470) {
				if (trafico1.traficox - camaraX < centro) {
					trafico1.otrosi = 3;
				}

				if (trafico1.traficox - camaraX > centro) {
					trafico1.otrosi = 8;
				}
			}

			if (trafico1.traficoy > 520) {
				if (trafico1.traficox - camaraX < centro) {
					trafico1.otrosi = 2;
				}

				if (trafico1.traficox - camaraX > centro) {
					trafico1.otrosi = 9;
				}
			}

			if (trafico1.traficoy > 570) {
				if (trafico1.traficox - camaraX < centro) {
					trafico1.otrosi = 1;
				}

				if (trafico1.traficox - camaraX > centro) {
					trafico1.otrosi = 10;
				}

			}
			if (trafico1.traficoy > 620) {
				if (trafico1.traficox - camaraX < centro) {
					trafico1.otrosi = 0;
				}

				if (trafico1.traficox - camaraX > centro) {
					trafico1.otrosi = 11;
				}

			}

			/*porche2*/
			if (trafico2.traficoy > 370) {
				if (trafico2.traficox - camaraX < centro) {
					trafico2.otrosi = 5;
				}

				if (trafico2.traficox - camaraX > centro) {
					trafico2.otrosi = 6;
				}
			}

			if (trafico2.traficoy > 420) {
				if (trafico2.traficox - camaraX < centro) {
					trafico2.otrosi = 4;
				}

				if (trafico2.traficox - camaraX > centro) {
					trafico2.otrosi = 7;
				}
			}

			if (trafico2.traficoy > 470) {
				if (trafico2.traficox - camaraX < centro) {
					trafico2.otrosi = 3;
				}

				if (trafico2.traficox - camaraX > centro) {
					trafico2.otrosi = 8;
				}
			}

			if (trafico2.traficoy > 520) {
				if (trafico2.traficox - camaraX < centro) {
					trafico2.otrosi = 2;
				}

				if (trafico2.traficox - camaraX > centro) {
					trafico2.otrosi = 9;
				}
			}

			if (trafico2.traficoy > 570) {
				if (trafico2.traficox - camaraX < centro) {
					trafico2.otrosi = 1;
				}

				if (trafico2.traficox - camaraX > centro) {
					trafico2.otrosi = 10;
				}

			}
			if (trafico2.traficoy > 620) {
				if (trafico2.traficox - camaraX < centro) {
					trafico2.otrosi = 0;
				}

				if (trafico2.traficox - camaraX > centro) {
					trafico2.otrosi = 11;
				}

			}

			/*porche3*/
			if (trafico3.traficoy > 370) {
				if (trafico3.traficox - camaraX < centro) {
					trafico3.otrosi = 5;
				}

				if (trafico3.traficox - camaraX > centro) {
					trafico3.otrosi = 6;
				}
			}

			if (trafico3.traficoy > 420) {
				if (trafico3.traficox - camaraX < centro) {
					trafico3.otrosi = 4;
				}

				if (trafico3.traficox - camaraX > centro) {
					trafico3.otrosi = 7;
				}
			}

			if (trafico3.traficoy > 470) {
				if (trafico3.traficox - camaraX < centro) {
					trafico3.otrosi = 3;
				}

				if (trafico3.traficox - camaraX > centro) {
					trafico3.otrosi = 8;
				}
			}

			if (trafico3.traficoy > 520) {
				if (trafico3.traficox - camaraX < centro) {
					trafico3.otrosi = 2;
				}

				if (trafico3.traficox - camaraX > centro) {
					trafico3.otrosi = 9;
				}
			}

			if (trafico3.traficoy > 570) {
				if (trafico3.traficox - camaraX < centro) {
					trafico3.otrosi = 1;
				}

				if (trafico3.traficox - camaraX > centro) {
					trafico3.otrosi = 10;
				}

			}
			if (trafico3.traficoy > 620) {
				if (trafico3.traficox - camaraX < centro) {
					trafico3.otrosi = 0;
				}

				if (trafico3.traficox - camaraX > centro) {
					trafico3.otrosi = 11;
				}

			}

			/*porche4*/
			if (trafico4.traficoy > 370) {
				if (trafico4.traficox - camaraX < centro) {
					trafico4.otrosi = 5;
				}

				if (trafico4.traficox - camaraX > centro) {
					trafico4.otrosi = 6;
				}
			}

			if (trafico4.traficoy > 420) {
				if (trafico4.traficox - camaraX < centro) {
					trafico4.otrosi = 4;
				}

				if (trafico4.traficox - camaraX > centro) {
					trafico4.otrosi = 7;
				}
			}

			if (trafico4.traficoy > 470) {
				if (trafico4.traficox - camaraX < centro) {
					trafico4.otrosi = 3;
				}

				if (trafico4.traficox - camaraX > centro) {
					trafico4.otrosi = 8;
				}
			}

			if (trafico4.traficoy > 520) {
				if (trafico4.traficox - camaraX < centro) {
					trafico4.otrosi = 2;
				}

				if (trafico4.traficox - camaraX > centro) {
					trafico4.otrosi = 9;
				}
			}

			if (trafico4.traficoy > 570) {
				if (trafico4.traficox - camaraX < centro) {
					trafico4.otrosi = 1;
				}

				if (trafico4.traficox - camaraX > centro) {
					trafico4.otrosi = 10;
				}

			}
			if (trafico4.traficoy > 620) {
				if (trafico4.traficox - camaraX < centro) {
					trafico4.otrosi = 0;
				}

				if (trafico4.traficox - camaraX > centro) {
					trafico4.otrosi = 11;
				}

			}

			/*porche5*/
			if (trafico5.traficoy > 370) {
				if (trafico5.traficox - camaraX < centro) {
					trafico5.otrosi = 5;
				}

				if (trafico5.traficox - camaraX > centro) {
					trafico5.otrosi = 6;
				}
			}

			if (trafico5.traficoy > 420) {
				if (trafico5.traficox - camaraX < centro) {
					trafico5.otrosi = 4;
				}

				if (trafico5.traficox - camaraX > centro) {
					trafico5.otrosi = 7;
				}
			}

			if (trafico5.traficoy > 470) {
				if (trafico5.traficox - camaraX < centro) {
					trafico5.otrosi = 3;
				}

				if (trafico5.traficox - camaraX > centro) {
					trafico5.otrosi = 8;
				}
			}

			if (trafico5.traficoy > 520) {
				if (trafico5.traficox - camaraX < centro) {
					trafico5.otrosi = 2;
				}

				if (trafico5.traficox - camaraX > centro) {
					trafico5.otrosi = 9;
				}
			}

			if (trafico5.traficoy > 570) {
				if (trafico5.traficox - camaraX < centro) {
					trafico5.otrosi = 1;
				}

				if (trafico5.traficox - camaraX > centro) {
					trafico5.otrosi = 10;
				}

			}
			if (trafico5.traficoy > 620) {
				if (trafico5.traficox - camaraX < centro) {
					trafico5.otrosi = 0;
				}

				if (trafico5.traficox - camaraX > centro) {
					trafico5.otrosi = 11;
				}

			}

			/*porche6*/
			if (trafico6.traficoy > 370) {
				if (trafico6.traficox - camaraX < centro) {
					trafico6.otrosi = 5;
				}

				if (trafico6.traficox - camaraX > centro) {
					trafico6.otrosi = 6;
				}
			}

			if (trafico6.traficoy > 420) {
				if (trafico6.traficox - camaraX < centro) {
					trafico6.otrosi = 4;
				}

				if (trafico6.traficox - camaraX > centro) {
					trafico6.otrosi = 7;
				}
			}

			if (trafico6.traficoy > 470) {
				if (trafico6.traficox - camaraX < centro) {
					trafico6.otrosi = 3;
				}

				if (trafico6.traficox - camaraX > centro) {
					trafico6.otrosi = 8;
				}
			}

			if (trafico6.traficoy > 520) {
				if (trafico6.traficox - camaraX < centro) {
					trafico6.otrosi = 2;
				}

				if (trafico6.traficox - camaraX > centro) {
					trafico6.otrosi = 9;
				}
			}

			if (trafico6.traficoy > 570) {
				if (trafico6.traficox - camaraX < centro) {
					trafico6.otrosi = 1;
				}

				if (trafico6.traficox - camaraX > centro) {
					trafico6.otrosi = 10;
				}

			}
			if (trafico6.traficoy > 620) {
				if (trafico6.traficox - camaraX < centro) {
					trafico6.otrosi = 0;
				}

				if (trafico6.traficox - camaraX > centro) {
					trafico6.otrosi = 11;
				}

			}

			/*Colisiones*/

			if (ladoizq < trafico1.traficox + 65 - camaraX && trafico1.traficox + 65 - camaraX < ladoder && bouncer_y < trafico1.traficoy && trafico1.traficoy < 700) {
				velocidad = 0;
				velocidadt = -10;
			}

			if (ladoizq < trafico2.traficox + 65 - camaraX && trafico2.traficox + 65 - camaraX < ladoder && bouncer_y < trafico2.traficoy && trafico2.traficoy < 700) {
				velocidad = 0;
				velocidadt = -10;
			}
			if (ladoizq < trafico3.traficox + 65 - camaraX && trafico3.traficox + 65 - camaraX < ladoder && bouncer_y < trafico3.traficoy && trafico3.traficoy < 700) {
				velocidad = 0;
				velocidadt = -10;
			}
			if (ladoizq < trafico4.traficox + 65 - camaraX && trafico4.traficox + 65 - camaraX < ladoder && bouncer_y < trafico4.traficoy && trafico4.traficoy < 700) {
				velocidad = 0;
				velocidadt = -10;
			}
			if (ladoizq < trafico5.traficox + 65 - camaraX && trafico5.traficox + 65 - camaraX < ladoder && bouncer_y < trafico5.traficoy && trafico5.traficoy < 700) {
				velocidad = 0;
				velocidadt = -10;
			}
			if (ladoizq < trafico6.traficox + 65 - camaraX && trafico6.traficox + 65 - camaraX < ladoder && bouncer_y < trafico6.traficoy && trafico6.traficoy < 700) {
				velocidad = 0;
				velocidadt = -10;
			}

			/*Funcionamiento de la Camara*/

			if (camaraX > mundoAncho - SCREEN_W) {
				camaraX = mundoAncho - SCREEN_W;
			}

			if (camaraX < 0) {
				camaraX = 0;
			}

			if (bouncer_x > mundoAncho - SCREEN_W) {
				bouncer_x = mundoAncho - SCREEN_W;
			}

			if (bouncer_x < 0) {
				bouncer_x = 0;
			}

			/*Fin de partida*/

			if (tiempo < 0 & objetivo > 0){
				al_stop_timer(timer);
				hasperdio = 292.5;
			}

			if (objetivo < 0 & tiempo > 0) {
				al_stop_timer(timer);
				hasganao = 292.5;
			}

			redraw = true;
		}


		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_UP:
				key[KEY_UP] = true;
				break;

			case ALLEGRO_KEY_DOWN:
				key[KEY_DOWN] = true;
				break;

			case ALLEGRO_KEY_LEFT:
				key[KEY_LEFT] = true;
				break;

			case ALLEGRO_KEY_RIGHT:
				key[KEY_RIGHT] = true;
				break;
			case ALLEGRO_KEY_SPACE:
				key[KEY_SPACE] = true;
				break;
			}
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_UP:
				key[KEY_UP] = false;
				break;

			case ALLEGRO_KEY_DOWN:
				key[KEY_DOWN] = false;
				break;

			case ALLEGRO_KEY_LEFT:
				key[KEY_LEFT] = false;
				break;

			case ALLEGRO_KEY_RIGHT:
				key[KEY_RIGHT] = false;
				break;

			case ALLEGRO_KEY_SPACE:
				key[KEY_SPACE] = false;
				break;

			case ALLEGRO_KEY_ESCAPE:
				doexit = true;
				break;
			}
		}

		if (redraw && al_is_event_queue_empty(event_queue)) {
			redraw = false;

			al_clear_to_color(al_map_rgb(10, 10, 10));

			al_draw_bitmap(carretera, 640 - camaraX, carreteray, 0);
			al_draw_bitmap(carretera, 640 - camaraX, carreteray2, 0);

			al_draw_bitmap(tierra, 640 - camaraX, 0, 0);

			al_draw_filled_triangle(820 - camaraX, 720, 775 - camaraX, 400, carreterax1, 400, al_map_rgb(0, 0, 0));
			al_draw_filled_triangle(1320 - camaraX, 720, 1365 - camaraX, 400, carreterax2, 400, al_map_rgb(0, 0, 0));

			al_draw_line(820 - camaraX, 720, carreterax1, 400, al_map_rgb(0, 255, 255), 6);
			al_draw_line(1320 - camaraX, 720, carreterax2, 400, al_map_rgb(0, 255, 255), 6);

			al_draw_line(640 - camaraX, 425, carreterax1 - 4, 425, al_map_rgb(0, 255, 255), 10);
			al_draw_line(1485 - camaraX, 425, carreterax2 + 4, 425, al_map_rgb(0, 255, 255), 10);

			al_draw_bitmap(porche1, trafico1.traficox - camaraX, trafico1.traficoy, 0);
			al_draw_bitmap(porche2, trafico2.traficox - camaraX, trafico2.traficoy, 0);
			al_draw_bitmap(porche3, trafico3.traficox - camaraX, trafico3.traficoy, 0);
			al_draw_bitmap(porche4, trafico4.traficox - camaraX, trafico4.traficoy, 0);
			al_draw_bitmap(porche5, trafico5.traficox - camaraX, trafico5.traficoy, 0);
			al_draw_bitmap(porche6, trafico6.traficox - camaraX, trafico6.traficoy, 0);

			al_draw_bitmap(fondo, 640 - camaraX, 5, 0);

			al_draw_bitmap(ciudad, 640 - camaraX, 65, 0);

			al_draw_bitmap(pared2, 1485 - camaraX, 0, 0);
			al_draw_bitmap(pared2, 630 - camaraX, 0, 0);

			al_draw_bitmap(coche2, SCREEN_W / 2, bouncer_y - 10, 0);
			al_draw_bitmap(freno, frenosi, bouncer_y - 10, 0);

			al_draw_textf(font, al_map_rgb(255, 0, 0), SCREEN_W / 2 + 200, 50, 0, "%i", objetivo / 2);
			al_draw_textf(font, al_map_rgb(0, 255, 255), SCREEN_W / 2, 50, 0, "%i", tiempo / 60);

			al_draw_bitmap(ganas, hasganao, 200, 0);
			al_draw_bitmap(pierdes, hasperdio, 200, 0);

			al_flip_display();
		}
	}

	al_destroy_bitmap(fondo);
	al_destroy_bitmap(coche);
	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);

	return 0;
}