#ifndef MAP_H
#define MAP_H

#include "game.h"
class Map{


public:

Map();
~Map();
void loadmap(int arr[33][60]);
void drawmap();









private:

SDL_Rect  src,dest;


SDL_Texture* build;                                               
SDL_Texture* grass;
//SDL_Texture* road;
SDL_Texture* gate;
SDL_Texture* ground;
SDL_Texture* swim;
SDL_Texture* hospital;
SDL_Texture* css;
SDL_Texture* cross;
SDL_Texture *hostel;
int map[33][60];


};

#endif
