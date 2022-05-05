#include "texturemng.h"

Texture::Texture(){}


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

 SDL_Texture* Texture::loadFromRenderedText( const char* tex, SDL_Color textColor )
{
	
    SDL_Texture* t;
	//Render text surface
	SDL_Surface* textSurface = TTF_RenderText_Solid( gFont, tex, textColor );
	if( textSurface == NULL )
	{
		printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
	}
	else
	{
		//Create texture from surface pixels
        t = SDL_CreateTextureFromSurface( Game::renderer, textSurface );
		if( t== NULL )
		{
			printf( "Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError() );
		}
		else
		{
			//Get image dimensions
			mWidth = textSurface->w;
			mHeight = textSurface->h;
		}

		//Get rid of old surface
		SDL_FreeSurface( textSurface );
	}
	
	//Return success
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
void Texture::rend(SDL_Texture* tex,SDL_Rect dest){
    SDL_RenderCopy(Game::renderer,tex,NULL,&dest);
}
