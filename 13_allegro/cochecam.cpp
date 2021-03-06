#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <math.h>
 
const float FPS = 60;
const int mundoLargo = 10000;
const int mundoAncho = 10000;
const int SCREEN_W = 1280;
const int SCREEN_H = 720;
const int BOUNCER_SIZE_X = 50;
const int BOUNCER_SIZE_Y = 32;
const int PARED_X = 500;
const int PARED_Y = 100;
const int PARED2_X = 100;
const int PARED2_Y = 300;
const int CKM_X = 100;
const int CKM_Y = 5;

enum MYKEYS {
   KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT, KEY_SPACE, KEY_SHIFT, KEY_CONTROL
};
 
int main(int argc, char **argv)
{
   ALLEGRO_DISPLAY *display = NULL;
   ALLEGRO_EVENT_QUEUE *event_queue = NULL;
   ALLEGRO_TIMER *timer = NULL;
   ALLEGRO_BITMAP *bouncer = NULL;
   ALLEGRO_BITMAP *pared = NULL;
   ALLEGRO_BITMAP *pared2 = NULL;
   ALLEGRO_BITMAP *cuentakm = NULL;
   ALLEGRO_FONT *font = NULL;
   int gear = 0;
   float RPM = 0;
   float KMH = 0;
   float angle = 0;
   float length = 0;
   float vel_x, vel_y;
   float bouncer_x = mundoLargo / 2;
   float bouncer_y = mundoAncho / 2;
   int camaraX = bouncer_x - SCREEN_W / 2;
   int camaraY = bouncer_y - SCREEN_H / 2;
   bool key[7] = { false, false, false, false, false, false, false };
   bool redraw = true;
   bool doexit = false;



 
   if(!al_init()) {
      fprintf(stderr, "failed to initialize allegro!\n");
      return -1;
   }


    if(!al_install_keyboard()) {
      fprintf(stderr, "failed to initialize the keyboard!\n");
      return -1;
   }
 
   timer = al_create_timer(1.0 / FPS);
   if(!timer) {
      fprintf(stderr, "failed to create timer!\n");
      return -1;
   }
 
   display = al_create_display(SCREEN_W, SCREEN_H);
   if(!display) {
      fprintf(stderr, "failed to create display!\n");
      al_destroy_timer(timer);
      return -1;
   }

   al_init_font_addon();
   al_init_ttf_addon();

   font = al_load_ttf_font("DTM-Sans.otf",72,0);
 
   bouncer = al_create_bitmap(BOUNCER_SIZE_X,BOUNCER_SIZE_Y);
   pared = al_create_bitmap(PARED_X,PARED_Y);
   pared2 = al_create_bitmap(PARED2_X, PARED2_Y);
   cuentakm = al_create_bitmap(CKM_X, CKM_Y);
 
   if(!bouncer) {
      fprintf(stderr, "failed to create bouncer bitmap!\n");
      al_destroy_display(display);
      al_destroy_timer(timer);
      return -1;
   }
 
   al_set_target_bitmap(bouncer);
 
   al_clear_to_color(al_map_rgb(0, 0, 0));
 
   al_set_target_bitmap(al_get_backbuffer(display));

   al_set_target_bitmap(pared);
 
   al_clear_to_color(al_map_rgb(150, 150, 150));
 
   al_set_target_bitmap(al_get_backbuffer(display));

   al_set_target_bitmap(pared2);
 
   al_clear_to_color(al_map_rgb(150, 150, 150));
 
   al_set_target_bitmap(al_get_backbuffer(display));

   al_set_target_bitmap(cuentakm);
 
   al_clear_to_color(al_map_rgb(255, 0, 0));
 
   al_set_target_bitmap(al_get_backbuffer(display));
 
   event_queue = al_create_event_queue();
   if(!event_queue) {
      fprintf(stderr, "failed to create event_queue!\n");
      al_destroy_bitmap(bouncer);
      al_destroy_bitmap(pared);
      al_destroy_bitmap(pared2);
      al_destroy_bitmap(cuentakm);
      al_destroy_display(display);
      al_destroy_timer(timer);
      return -1;
   }
 
   al_register_event_source(event_queue, al_get_display_event_source(display));
 
   al_register_event_source(event_queue, al_get_timer_event_source(timer));
 
   al_register_event_source(event_queue, al_get_keyboard_event_source());
 
   al_clear_to_color(al_map_rgb(0,0,0));
 
   al_flip_display();
 
   al_start_timer(timer);
 
   while(!doexit)
   {
      ALLEGRO_EVENT ev;
      al_wait_for_event(event_queue, &ev);
 
      if(ev.type == ALLEGRO_EVENT_TIMER) {
         
         if(key[KEY_UP] &&  RPM < 10 && gear == 0) {
            RPM += 0.4;
         }

         if(key[KEY_UP] &&  RPM < 10 && gear == 1) {
            RPM += 0.2;
         }

         if(key[KEY_UP] &&  RPM < 10 && gear == 2) {
            RPM += 0.1;
         }

         if(key[KEY_UP] &&  RPM < 10 && gear == 3) {
            RPM += 0.08;
         }

         if(key[KEY_UP] &&  RPM < 10 && gear == 4) {
            RPM += 0.05;
         }

         else if(RPM > 0) {
            RPM -= 0.04;
         }

         if(key[KEY_UP] && length < 5 && gear == 1) {
            length += 0.5;
         }

         if(key[KEY_UP] && length < 10 && gear == 2) {
            length += 0.25;
         }

         if(key[KEY_UP] && length < 20 && gear == 3) {
            length += 0.125;
         }

         if(key[KEY_UP] && length < 30 && gear == 4) {
            length += 0.0625;
         }

         else if(length > 0) {
            length -= 0.06;
         }
 
         if(key[KEY_DOWN] && length > 0) {
            length -= 0.5;
         }

         if(key[KEY_DOWN] && RPM > 0) {
            RPM -= 0.2;
         }
 
         if(key[KEY_LEFT] && length > 0) {
            angle = (angle - 0.1);
         }
 
         if(key[KEY_RIGHT] && length > 0) {
            angle = (angle + 0.1);
         }
 
         if(key[KEY_SPACE]) {
         }

         if(key[KEY_SHIFT] && gear < 4) {
            gear += 1;
            RPM -= RPM;
            key[KEY_SHIFT] = false;
            }

         if(key[KEY_CONTROL] && gear >= 1) {
            gear -= 1;
            RPM -= RPM / 2;
            key[KEY_CONTROL] = false;
         }

            vel_x = length * cos(angle);
            vel_y = length * sin(angle);
            bouncer_x += vel_x;
            bouncer_y += vel_y;


         if (camaraX < 0){
            camaraX = 0;
         }

         if (camaraY < 0) {
            camaraY = 0;
         }

         if (camaraX > mundoAncho - SCREEN_W) {
            camaraX = mundoAncho - SCREEN_W;
         }

         if (camaraY > mundoLargo - SCREEN_H) {
            camaraY = mundoLargo - SCREEN_H;
         }
 
         redraw = true;
      }


      else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
         break;
      }
      else if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
         switch(ev.keyboard.keycode) {
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
            case ALLEGRO_KEY_LSHIFT:
               key[KEY_SHIFT] = true;
               break;
            case ALLEGRO_KEY_LCTRL:
               key[KEY_CONTROL] = true;
               break;
         }
      }
      else if(ev.type == ALLEGRO_EVENT_KEY_UP) {
         switch(ev.keyboard.keycode) {
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

            case ALLEGRO_KEY_LSHIFT:
               key[KEY_SHIFT] = false;
               break;
            
            case ALLEGRO_KEY_LCTRL:
               key[KEY_CONTROL] = false;
               break;
 
            case ALLEGRO_KEY_ESCAPE:
               doexit = true;
               break;
         }
      }
 
      if(redraw && al_is_event_queue_empty(event_queue)) {
         redraw = false;
 
         al_clear_to_color(al_map_rgb(240,240,240));


         al_draw_bitmap(pared, 100 - camaraX, 600 - camaraY, 0);
         al_draw_bitmap(pared, 600 - camaraX, 600 - camaraY, 0);
         al_draw_bitmap(pared, 100 - camaraX, 50 - camaraY, 0);
         al_draw_bitmap(pared, 600 - camaraX, 50 - camaraY, 0);
         al_draw_bitmap(pared2, 100 - camaraX, 400 - camaraY, 0);
         al_draw_bitmap(pared2, 100 - camaraX, 100 - camaraY, 0);

         al_draw_textf(font, al_map_rgb(255,0,0), 660, 360, 0, "%i", gear);
         al_draw_textf(font, al_map_rgb(255,0,0), 660, 420, 0, "%.0f", length * 3);

         al_draw_rotated_bitmap(cuentakm, 90, CKM_Y / 2, 700, 360, RPM / 3, 0);
 
         al_draw_rotated_bitmap(bouncer, BOUNCER_SIZE_X / 3, BOUNCER_SIZE_Y / 2, bouncer_x, bouncer_y, angle, angle);

        
         al_flip_display();
      }
   }
 
   al_destroy_bitmap(bouncer);
   al_destroy_timer(timer);
   al_destroy_display(display);
   al_destroy_event_queue(event_queue);
 
   return 0;
}