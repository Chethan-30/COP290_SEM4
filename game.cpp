#include "game.h"

#include "texturemng.h"
#include "gameobject.h"
#include "audio.h"
#include "startmenu.h"
#include "map.h"
Gameobject* player;
Gameobject* opponent;
Gameobject*coin1;
Gameobject*coin2;
Gameobject*coin3;
Gameobject*coin4;
Gameobject*coin5;
Gameobject*coin6;
Gameobject*coin7;
Gameobject*coin8;
Gameobject*coin9;
Gameobject*coin10;
Gameobject* road1;
Gameobject* road2;
Gameobject* road3;
Gameobject* road4;
Gameobject* road5;
Gameobject* road6;
Gameobject* road7;
Gameobject* road8;
Gameobject* road9;
Gameobject* road10;
SDL_Renderer* Game::renderer=nullptr;
SDL_Event Game::event;
Audio* a;
StartMenu* m;
Map* map;
int toggle=1;
int q=1;
Game::Game(){


}





  
Game::~Game(){


  



} 
void Game::initialize(const char* title,int xpos,int ypos,int width,int height,bool fullscreen){
               int flags=0;
               if(fullscreen){flags=SDL_WINDOW_FULLSCREEN;}
               torun=true;
              if( SDL_Init( SDL_INIT_EVERYTHING) < 0 )
                  {
                     printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
                     torun=false;
                  }    
              else  {
                     window = SDL_CreateWindow( title, xpos,ypos, width, height, flags );
                     if( window == NULL )
                           {
                             printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
                             torun=false;
                           }
                     else  {
                              renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
                              
                              if( renderer == NULL )
                                  {
                                        printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
                                        torun=false;
                                  } 
                             else{      //Initialize renderer color
                              SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
                               //Initialize PNG loading
                                  
                               int imgFlags = IMG_INIT_PNG;
                               if( !( IMG_Init( imgFlags ) & imgFlags ) )
                                    {
                                  printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
                                   torun=false;
                  
                                        }
                            }
                          }      
                    }          

a= new Audio();
a->loadaudio();
a->startMenuaudio(); 
m=new StartMenu();
m->loadstartmenu();
m->render();
   

road1 =new Gameobject("pictures/map_items/road.png",1376,0);
coin1 =new Gameobject("pictures/gold.png",1376,0);
road2 =new Gameobject("pictures/map_items/road.png",160,640);
coin2 =new Gameobject("pictures/gold.png",160,640);
road3 =new Gameobject("pictures/map_items/road.png",160,992);
coin3 =new Gameobject("pictures/gold.png",160,992);
road4 =new Gameobject("pictures/map_items/road.png",32,384);
coin4 =new Gameobject("pictures/gold.png",32,384);
road5 =new Gameobject("pictures/map_items/road.png",384,384);
coin5 =new Gameobject("pictures/gold.png",384,384);
road6 =new Gameobject("pictures/map_items/road.png",1056,736);
coin6 =new Gameobject("pictures/gold.png",1056,736);
road7 =new Gameobject("pictures/map_items/road.png",1536,608);
coin7 =new Gameobject("pictures/gold.png",1536,608);
road8 =new Gameobject("pictures/map_items/road.png",1504,352);
coin8 =new Gameobject("pictures/gold.png",1504,352);
road9 =new Gameobject("pictures/map_items/road.png",320,768);
coin9 =new Gameobject("pictures/gold.png",320,768);
road10 =new Gameobject("pictures/map_items/road.png",1152,128);
coin10 =new Gameobject("pictures/gold.png",1152,128);

player= new Gameobject("pictures/man.png",128,32);
opponent= new Gameobject("pictures/man2.png",50,50);
a->startmenuTogamemusic();
map=new Map();
}

void Game::handle_events(){

     // SDL_Event event;      
      SDL_PollEvent(&event);
      switch(event.type){
        case SDL_QUIT:
            torun =false;
            break;
            
            
       default :
         break;
         }     
      

}

void Game::render() {
  //Clear screen 
      SDL_RenderClear( renderer );
    //Render texture to screen
    map->drawmap();
      player->render();
      if (toggle==1){coin1->render();}
      else {road1->render();}
      if (toggle==1){coin2->render();}
      else {road2->render();}
      if (toggle==1){coin3->render();}
      else {road3->render();}
      if (toggle==1){coin4->render();}
      else {road4->render();}
      if (toggle==1){coin5->render();}
      else {road5->render();}
      if (toggle==1){coin6->render();}
      else {road6->render();}
      if (toggle==1){coin7->render();}
      else {road7->render();}
      if (toggle==1){coin8->render();}
      else {road8->render();}
      if (toggle==1){coin9->render();}
      else {road9->render();}
      if (toggle==1){coin10->render();}
      else {road10->render();}
     if(q%15==0) {
      if(toggle==0){toggle=1;}
      else {toggle=0;}}
      
      q++;
      
      //road->render();
      
      // opponent->render();
  //Update screen
      SDL_RenderPresent( renderer );


}

void Game::update(){
count++;
player->update();
opponent->update();
coin1->up();
coin2->up();
coin3->up();
coin4->up();
coin5->up();
coin6->up();
coin7->up();
coin8->up();
coin9->up();
coin10->up();
road1->up();
road2->up();
road3->up();
road4->up();
road5->up();
road6->up();
road7->up();
road8->up();
road9->up();
road10->up();



}

void Game::clear(){

     a->~Audio();
    //Destroy window    
    SDL_DestroyRenderer( renderer );
    SDL_DestroyWindow( window );
    window = NULL;
    renderer = NULL;
    
    //Quit SDL subsystems
    SDL_Quit();

}

  
