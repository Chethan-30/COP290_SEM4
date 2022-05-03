#ifndef GAME_H
#define GAME_H
#include <iostream>
using namespace std;
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>

class Game{

private :
SDL_Window* window;

bool torun;
int count=0;
int frameCount,timerFPS,lastFrame;

public :
Game();
~Game();
void initialize(const char* title,int xpos,int ypos,int width,int height,bool fullscreen);
void handle_events();

void update();
void render();
void clear();
bool running_status(){return torun;}
static SDL_Renderer* renderer;
static SDL_Event event;

  

   

};



#endif // GAME_H
