#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include "game.h"
#include <vector>
#include <string>
#include "texturemng.h"
using namespace std;
Game *g=nullptr;
int time_count=0; 

int main( int argc ,char** argv){
const int FPS=60;
int timer=60*15;

const int frame_delay=1000/FPS;
Uint32 framestart;
int frametime;
string temp5(argv[1]);

g=new Game();
g->temp899=temp5;
g->realtime=timer;
  g->initialize("IIT DELHI MAZE GAME",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1920,1080,false);

if(temp5.compare("client")==0)
{
  string temp6(argv[2]);
  g->ip_adress=temp6;
}
   while(g->running_status()){
   framestart=SDL_GetTicks();
   g->handle_events();
   g->update();
   g->render();
   frametime =SDL_GetTicks()-framestart;
   if(frame_delay>frametime){
     SDL_Delay(frame_delay-frametime);
   
   }
   
   


   time_count++;
   if(time_count%63==0)
   {
     timer--;
   }
g->realtime=timer;
   if(time_count>=3750*15){
     
     if(g->playscore>g->playscore2)
     {
       printf("YOU WIN\n");
       SDL_Texture* text_for_win;
       text_for_win=Texture::LoadTexture("pictures/WINNER.png");
          SDL_RenderClear( Game::renderer );

                //Render texture to screen
                SDL_RenderCopy(Game::renderer, text_for_win, NULL, NULL );

                //Update screen
                SDL_RenderPresent( Game::renderer );
                SDL_Delay(5000);
       

     }
     
      if(g->playscore<g->playscore2)
     {
       printf("YOU LOOSE\n");

       SDL_Texture* text_for_lose;
      
      text_for_lose=Texture::LoadTexture("pictures/LOOSER.png");
         SDL_RenderClear( Game::renderer );

                //Render texture to screen
                SDL_RenderCopy(Game::renderer, text_for_lose, NULL, NULL );

                //Update screen
                SDL_RenderPresent( Game::renderer );
                SDL_Delay(5000);
       
     }
     
     
     break;
   
   
   
   }
   }
 g->clear();
 return 0;

}

