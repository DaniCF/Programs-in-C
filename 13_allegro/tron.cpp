#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <math.h>
 
const float FPS = 60;
const int SCREEN_W = 1280;
const int SCREEN_H = 720;
const int BOUNCER_SIZE_X = 30;
const int BOUNCER_SIZE_Y = 15;
const int paredXY = 5;
enum MYKEYS {
   KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT, KEY_SPACE
};
 
int main(int argc, char **argv)
{
   ALLEGRO_DISPLAY *display = NULL;
   ALLEGRO_EVENT_QUEUE *event_queue = NULL;
   ALLEGRO_TIMER *timer = NULL;
   ALLEGRO_BITMAP *bouncer = NULL;
   ALLEGRO_BITMAP *pared = NULL;
   float angle = 0;
   float length = 0;
   float vel_x, vel_y;
   float bouncer_x = SCREEN_W / 2.0 - BOUNCER_SIZE_Y / 2.0;
   float bouncer_y = SCREEN_H / 2.0 - BOUNCER_SIZE_Y / 2.0;
   bool key[5] = { false, false, false, false, false };
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

   al_init_primitives_addon();
 
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

   bouncer = al_create_bitmap(BOUNCER_SIZE_X,BOUNCER_SIZE_Y);
   pared = al_create_bitmap(paredXY,paredXY);
 
   if(!bouncer) {
      fprintf(stderr, "failed to create bouncer bitmap!\n");
      al_destroy_display(display);
      al_destroy_timer(timer);
      return -1;
   }
 
   al_set_target_bitmap(bouncer);
 
   al_clear_to_color(al_map_rgb(0,255,255));

   al_set_target_bitmap(pared);
 
   al_clear_to_color(al_map_rgb(255,0,0));
 
   al_set_target_bitmap(al_get_backbuffer(display));
 
   event_queue = al_create_event_queue();
   if(!event_queue) {
      fprintf(stderr, "failed to create event_queue!\n");
      al_destroy_bitmap(bouncer);
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
         if(key[KEY_UP] && length < 10){
            length = 5;
         }
 
         if(key[KEY_LEFT] && length > 0) {
            angle = (angle - 1.5708);
            key[KEY_LEFT] = false;
         }
 
         if(key[KEY_RIGHT] && length > 0) {
            angle = (angle + 1.5708);
            key[KEY_RIGHT] = false;
         }


            vel_x = length * cos(angle);
            vel_y = length * sin(angle);
            bouncer_x += vel_x;
            bouncer_y += vel_y;
 
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
 
            case ALLEGRO_KEY_ESCAPE:
               doexit = true;
               break;
         }
      }
 
      if(redraw && al_is_event_queue_empty(event_queue)) {
         redraw = false;
 
         al_clear_to_color(al_map_rgb(0,0,0));

         al_draw_rotated_bitmap(bouncer, BOUNCER_SIZE_X / 2, BOUNCER_SIZE_Y / 2, bouncer_x, bouncer_y, angle, angle);

         al_hold_bitmap_drawing(1);
            al_draw_rotated_bitmap(pared, paredXY / 2, paredXY / 2, bouncer_x, bouncer_y, 0, 0);

         al_flip_display();
      }
   }
 
   al_destroy_bitmap(bouncer);
   al_destroy_timer(timer);
   al_destroy_display(display);
   al_destroy_event_queue(event_queue);
 
   return 0;
}  