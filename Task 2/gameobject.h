
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "game.h"
#include <vector>
class Gameobject{

public:
Gameobject( const char* texture,int x,int y);
~Gameobject();


void update();
void render();

void up();
void move1();
void move2();
void move3();
void move4();
void move5();
void move6();
void move7();
void move8();
void move9();
void move10();
SDL_Rect* gdrect();
SDL_Rect* gsrect();


private :

int xpos;
int ypos;


SDL_Texture* objtexture;
SDL_Rect  sRect,dRect;













};
#endif

