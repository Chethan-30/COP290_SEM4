#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include "game.h"
using namespace std;
Game *g=nullptr;
 
int main( int argc ,char** argv){
const int FPS=60;
const int frame_delay=1000/FPS;
Uint32 framestart;
int frametime;



g=new Game();
  g->initialize("IIT DELHI MAZE GAME",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1920,1080,false);

   while(g->running_status()){
   framestart=SDL_GetTicks();
   g->handle_events();
   g->update();
   g->render();
   frametime =SDL_GetTicks()-framestart;
   if(frame_delay>frametime){
     SDL_Delay(frame_delay-frametime);
   
   }
   
   
   }
 g->clear();
 return 0;

}

