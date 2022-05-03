#include "texturemng.h"


SDL_Texture* Texture::LoadTexture(const char* tex){
 SDL_Texture* t;
   SDL_Surface* loadedSurface = IMG_Load(tex);
    if( loadedSurface == NULL )
    {
        printf( "Unable to load image ! SDL_image Error: %s\n", IMG_GetError() );
    }
    else
    {
        //Create texture from surface pixels
     t = SDL_CreateTextureFromSurface( Game::renderer, loadedSurface );
        if( t == NULL )
        {
            printf( "Unable to create texture from ! SDL Error: %s\n", SDL_GetError() );
        }

        //Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
    }


return t;

}

/*SDL_Texture* Texture::LoadTexturebck(const char* tex){
 SDL_Texture* t;
   SDL_Surface* loadedSurface = IMG_Load(tex);
    if( loadedSurface == NULL )
    {
        printf( "Unable to load image ! SDL_image Error: %s\n", IMG_GetError() );
    }
    else
    {
        SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0xFF, 0, 0 ) );

        //Create texture from surface pixels
     t = SDL_CreateTextureFromSurface( Game::renderer, loadedSurface );
        if( t == NULL )
        {
            printf( "Unable to create texture from ! SDL Error: %s\n", SDL_GetError() );
        }

        //Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
    }


return t;

}*/

void Texture::Draw(SDL_Texture* tex,SDL_Rect src,SDL_Rect dest){
    // SDL_RenderClear( Game::renderer );

SDL_RenderCopy(Game::renderer,tex,&src,&dest);


}
