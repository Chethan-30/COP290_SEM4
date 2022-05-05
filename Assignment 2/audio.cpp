#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include "audio.h"
#include <iostream>
using namespace std;
Audio::Audio(){
//Initialize SDL_mixer
                if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
                {
                    printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
                   
                }
              }
Audio::~Audio(){
      Mix_FreeMusic(startmenumusic);
      Mix_FreeMusic(gamemusic);
      Mix_FreeMusic(gameovermusic);
      Mix_FreeMusic(death);
       Mix_FreeMusic(booster);

      this->startmenumusic= NULL;
      this->gamemusic=NULL;
      this->gameovermusic= NULL;
      this->death=NULL;
      this->booster=NULL;
     
      Mix_Quit();                
                }
void Audio::togglesound(){
    if(this->play){
     this->play=false;}
     else{this->play=true;}
     }
//loading the audio
void Audio::loadaudio(){     
        this->gamemusic=Mix_LoadMUS("allfiles/game.mp3");
	     if(this->gamemusic==NULL){ cout<<"Music not loaded: "<<Mix_GetError()<<endl;}
	this->startmenumusic=Mix_LoadMUS("allfiles/start.mp3");
	     if(this->startmenumusic==NULL){cout<<"Music not loaded: "<<Mix_GetError()<<endl;}
	this->gameovermusic=Mix_LoadMUS("allfiles/gameover.wav");
	     if(this->gameovermusic==NULL){cout<<"Music not loaded: "<<Mix_GetError()<<endl;}   
     this->death=Mix_LoadMUS("allfiles/death.wav");
	     if(this->gameovermusic==NULL){cout<<"Music not loaded: "<<Mix_GetError()<<endl;} 
     this->booster=Mix_LoadMUS("allfiles/booster.wav");
	     if(this->gameovermusic==NULL){cout<<"Music not loaded: "<<Mix_GetError()<<endl;}      

		} 
//start playing themusic		
void Audio::startMenuaudio(){
Mix_PlayMusic(startmenumusic,-1);
}
//resume the present  playing music
void Audio::resumeaudio(){
Mix_ResumeMusic();
}
//pause the present playing music
void Audio::pauseaudio(){
Mix_PauseMusic();
}
//changing the startmenu music to game music
void Audio::startmenuTogamemusic(){
Mix_HaltMusic();
Mix_PlayMusic(gamemusic, -1);	
}
//changing the game music to gameover music
void Audio::gameTogameovermusic(){
Mix_HaltMusic();
Mix_PlayMusic(gameovermusic, -1);	
}
// changing to death music
void Audio::changetodeath(){
     Mix_HaltMusic();
Mix_PlayMusic(death, -1);
}
// changing to booster music
void Audio::changetobooster(){
Mix_HaltMusic();
Mix_PlayMusic(booster, -1);

}
	
		
		
		 
		
		                 
