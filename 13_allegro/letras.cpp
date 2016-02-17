#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
 
int main(int argc, char **argv){
 
   if(!al_init()){
      fprintf(stderr, "Failed to initialize Allegro.\n");
      return -1;
   }
 
   al_init_font_addon(); // initialize the font addon
   al_init_ttf_addon();// initialize the ttf (True Type Font) addon
 
   ALLEGRO_DISPLAY *display = al_create_display(640,480);
 
   if (!display){
      fprintf(stderr, "Failed to create display.\n");
      return -1;
   }
 
   ALLEGRO_FONT *font = al_load_ttf_font("pirulen.ttf",72,0 );
 
   if (!font){
      fprintf(stderr, "Could not load 'pirulen.ttf'.\n");
      return -1;
   }
 
   al_clear_to_color(al_map_rgb(50,10,70));
   al_draw_text(font, al_map_rgb(255,255,255), 640/2, (480/4),ALLEGRO_ALIGN_CENTRE, "Your Text Here!");
 
   al_flip_display();
 
   al_rest(10.0);
 
   al_destroy_display(display);
 
   return 0;
}

   al_init_font_addon();
   al_init_ttf_addon();
   ALLEGRO_FONT *font = al_load_ttf_font("LCD.ttf", 72, 0);

   if (!font){
      fprintf(stderr, "Could not load 'lcd.ttf'.\n");
      return -1;
   }
 al_draw_text(font, al_map_rgb(0,0,0), 100, 100, 0, "Hola");