#ifndef TEXTURE_H
#define TEXTURE_H
#include <SDL2/SDL_ttf.h>
#include "game.h"


class Texture{

public:
Texture();
~Texture();
 static SDL_Texture* LoadTexture(const char* filename);
 static void Draw(SDL_Texture* tex,SDL_Rect src,SDL_Rect dest);
 //static SDL_Texture* LoadTexturebck(const char* filename);
SDL_Texture* loadFromRenderedText( const char* tex, SDL_Color textColor );
TTF_Font *gFont = NULL;
int mWidth ;
 int mHeight ;
 void rend(SDL_Texture* tex,SDL_Rect dest);
 void special( const char* tex, SDL_Color textColor,SDL_Rect dest );

private:








};
#endif
