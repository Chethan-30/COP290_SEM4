#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string>
#include<sstream>  
#include <stdio.h>
#include <vector>
using namespace std;
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
 string temp899;
 string ip_adress;
 int realtime=60;
void update();
void render();
void clear();
bool running_status(){return torun;}
static SDL_Renderer* renderer;
static SDL_Event event;
int playscore=0;
int playscore2=0;

  

   

};



#endif // GAME_H
