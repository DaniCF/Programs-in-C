#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <math.h>
 
const float FPS = 60;
const int SCREEN_W = 1280;
const int SCREEN_H = 720;
const int BOUNCER_SIZE_X = 50;
const int BOUNCER_SIZE_Y = 32;
const int BOUNCER2_SIZE_X = 50;
const int BOUNCER2_SIZE_Y = 32;
const int PARED_X = 100;
const int PARED_Y = 100;
enum MYKEYS {
   KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT, KEY_SPACE, KEY_W, KEY_S, KEY_A, KEY_D
};
 
int main(int argc, char **argv)
{
   ALLEGRO_DISPLAY *display = NULL;
   ALLEGRO_EVENT_QUEUE *event_queue = NULL;
   ALLEGRO_TIMER *timer = NULL;
   ALLEGRO_BITMAP *bouncer = NULL;
   ALLEGRO_BITMAP *bouncer2 = NULL;
   ALLEGRO_BITMAP *circuito = NULL;
   float angle = 0;
   float length = 0;
   float angle2 = 0;
   float length2 = 0;
   float vel_x, vel_y;
   float vel2_x, vel2_y;
   float bouncer_x = SCREEN_W / 2.0 - BOUNCER_SIZE_Y / 2.0;
   float bouncer_y = SCREEN_H / 2.0 - BOUNCER_SIZE_Y / 2.0;
   float bouncer2_x = SCREEN_W / 2.0 - BOUNCER2_SIZE_Y / 2.0;
   float bouncer2_y = SCREEN_H / 2.0 - BOUNCER2_SIZE_Y / 2.0;   
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

   al_get_allegro_primitives_version();
   al_init_primitives_addon();

 
   bouncer = al_create_bitmap(BOUNCER_SIZE_X,BOUNCER_SIZE_Y);
   bouncer2 = al_create_bitmap(BOUNCER2_SIZE_X,BOUNCER2_SIZE_Y);
   circuito = al_create_bitmap(PARED_X,PARED_Y);
 
   if(!bouncer) {
      fprintf(stderr, "failed to create bouncer bitmap!\n");
      al_destroy_display(display);
      al_destroy_timer(timer);
      return -1;
   }

   al_set_target_bitmap(bouncer);
 
   al_clear_to_color(al_map_rgb(0, 0, 0));
 
   al_set_target_bitmap(al_get_backbuffer(display));

   al_set_target_bitmap(bouncer2);
 
   al_clear_to_color(al_map_rgb(200, 0, 0));
 
   al_set_target_bitmap(al_get_backbuffer(display));
   
   al_set_target_bitmap(circuito);
 
   al_clear_to_color(al_map_rgb(0, 200, 0));
 
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
         if(key[KEY_UP] && length < 15) {
            length += 1;

         }
         else if(length > 0) {
            length -= 0.1;
         }
 
         if(key[KEY_DOWN] && length > 0) {
            length -= 0.3;
         }
 
         if(key[KEY_LEFT]) {
            angle = (angle - 0.08);
         }
 
         if(key[KEY_RIGHT]) {
            angle = (angle + 0.08);
         }

         if(key[KEY_W] && length2 < 15) {
            length2 += 1;

         }
         else if(length2 > 0) {
            length2 -= 0.1;
         }
 
         if(key[KEY_S] && length2 > 0) {
            length2 -= 0.3;
         }
 
         if(key[KEY_A]) {
            angle2 = (angle2 - 0.1);
         }
 
         if(key[KEY_D]) {
            angle2 = (angle2 + 0.1);
         }


            vel_x = length * cos(angle);
            vel_y = length * sin(angle);
            bouncer_x += vel_x;
            bouncer_y += vel_y;

            vel2_x = length2 * cos(angle2);
            vel2_y = length2 * sin(angle2);
            bouncer2_x += vel2_x;
            bouncer2_y += vel2_y;
 
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

            case ALLEGRO_KEY_W:
               key[KEY_W] = true;
               break;

            case ALLEGRO_KEY_S:
               key[KEY_S] = true;
               break;

            case ALLEGRO_KEY_A:
               key[KEY_A] = true;
               break;

            case ALLEGRO_KEY_D:
               key[KEY_D] = true;
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

            case ALLEGRO_KEY_W:
               key[KEY_W] = false;
               break;

            case ALLEGRO_KEY_S:
               key[KEY_S] = false;
               break;

            case ALLEGRO_KEY_A:
               key[KEY_A] = false;
               break;

            case ALLEGRO_KEY_D:
               key[KEY_D] = false;
               break; 
 
            case ALLEGRO_KEY_ESCAPE:
               doexit = true;
               break;

         }
      }
 
      if(redraw && al_is_event_queue_empty(event_queue)) {
         redraw = false;

         al_clear_to_color(al_map_rgb(240,240,240));

         al_draw_bitmap(circuito, 500, 500, 0);

         al_draw_rotated_bitmap(bouncer, BOUNCER_SIZE_X / 2, BOUNCER_SIZE_Y / 2, bouncer_x, bouncer_y, angle, angle);

         al_draw_rotated_bitmap(bouncer2, BOUNCER2_SIZE_X / 2, BOUNCER2_SIZE_Y / 2, bouncer2_x, bouncer2_y - 60, angle2, angle2);

        

 
         al_flip_display();
      }
   }
 
   al_destroy_bitmap(bouncer);
   al_destroy_bitmap(circuito);
   al_destroy_timer(timer);
   al_destroy_display(display);
   al_destroy_event_queue(event_queue);
 
   return 0;
}  