#ifndef TEXTURE_H
#define TEXTURE_H

#include "game.h"

class Texture{

public:
Texture();
~Texture();
 static SDL_Texture* LoadTexture(const char* filename);
 static void Draw(SDL_Texture* tex,SDL_Rect src,SDL_Rect dest);
 //static SDL_Texture* LoadTexturebck(const char* filename);


private:








};
#endif
