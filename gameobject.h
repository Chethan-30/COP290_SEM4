
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

private:

int xpos;
int ypos;


SDL_Texture* objtexture;
SDL_Rect  sRect,dRect;













};
#endif

