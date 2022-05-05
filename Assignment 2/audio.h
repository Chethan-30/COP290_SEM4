#ifndef AUDIO_H
#define AUDIO_H


#include <string.h>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
using namespace std;
class Audio{

public :
Audio();
~Audio();
bool play=true;
Mix_Music* startmenumusic=NULL;
Mix_Music* gamemusic=NULL;
Mix_Music* gameovermusic=NULL;
Mix_Music* death=NULL;
Mix_Music* booster=NULL;
void togglesound();
void loadaudio();
void resumeaudio();
void startMenuaudio();
void pauseaudio();
void startmenuTogamemusic();
void gameTogameovermusic();
void changetodeath();
void changetobooster();
	
};

#endif //AUDIO_H
