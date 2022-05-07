#ifndef STARTMENU_H
#define STARTMENU_H



#include <iostream>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

#include <vector>
#include <string.h>
#include "audio.h"
#include "texturemng.h"
using namespace std;

class StartMenu{
public :
  StartMenu();
  ~StartMenu();
  void loadstartmenu();
  SDL_Texture* texture1;
  SDL_Texture* texture2;
  SDL_Texture* texture3;
  SDL_Texture* texture4;
  SDL_Texture* texture5;
  SDL_Texture* texture_for_instruction;
  void render();
 bool mousePress(SDL_MouseButtonEvent &b);





};



































#endif //STARTMENU_H

