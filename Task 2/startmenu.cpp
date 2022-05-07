
#include "startmenu.h"

using namespace std;


StartMenu::StartMenu(){}
StartMenu::~StartMenu(){}
void StartMenu::loadstartmenu(){
 this->texture1=Texture::LoadTexture("pictures/s1.png");
 this->texture2=Texture::LoadTexture("pictures/s2.png");
 this->texture3=Texture::LoadTexture("pictures/s3.png");
 this->texture4=Texture::LoadTexture("pictures/s4.png");
 this->texture5=Texture::LoadTexture("pictures/s5.png");
 this->texture_for_instruction=Texture::LoadTexture("pictures/inst.png");
 }

 bool StartMenu::mousePress(SDL_MouseButtonEvent& b){
  if(b.button == SDL_BUTTON_LEFT){
   return true;
  }
else
return false;
}

void StartMenu::render(){

 //Clear screen
                SDL_RenderClear( Game::renderer );

                //Render texture to screen
                SDL_RenderCopy(Game::renderer, this->texture1, NULL, NULL );

                //Update screen
                SDL_RenderPresent( Game::renderer );
                
                bool quit = false;
SDL_Event e;
int xMouse, yMouse;

while(quit == false)
{




    while(SDL_PollEvent(&e) != 0)
    {  if(e.type==SDL_QUIT)
      {SDL_Quit();
       exit(0);}
       
       if(xMouse<=1060 && xMouse >=734 && yMouse<=1030 && yMouse>=950&&e.type==SDL_MOUSEBUTTONDOWN)
       {
       
       if(mousePress(e.button)==true)
       {
           SDL_Quit();
           exit(1);
       }

       }


    if(xMouse<=1067 && xMouse >=740 && yMouse<=542 && yMouse>=456&&e.type==SDL_MOUSEBUTTONDOWN)
       {
       
       if(mousePress(e.button)==true)
       {
          quit=true;
       }

       }

     
    if(xMouse<=1190 && xMouse >=598 && yMouse<=724 && yMouse>=630&&e.type==SDL_MOUSEBUTTONDOWN)
       {  
      
       if(mousePress(e.button)==true)
       {
         
                SDL_RenderClear( Game::renderer );

                //Render texture to screen
                SDL_RenderCopy(Game::renderer, this->texture_for_instruction, NULL, NULL );

                //Update screen
                SDL_RenderPresent( Game::renderer );          
          
          //quit=true;
       }

 }



   
       
       
        if(e.type == SDL_MOUSEMOTION)
        {
            
            SDL_GetGlobalMouseState(&xMouse,&yMouse);
            
            if(xMouse<=1067 && xMouse >=740 && yMouse<=542 && yMouse>=456){
             SDL_RenderClear( Game::renderer );

                //Render texture to screen
                SDL_RenderCopy(Game::renderer, this->texture2, NULL, NULL );

                //Update screen
                SDL_RenderPresent( Game::renderer );}
                
                
       
            
            else if(xMouse<=1190 && xMouse >=598 && yMouse<=724 && yMouse>=630){
             SDL_RenderClear( Game::renderer );

                //Render texture to screen
                SDL_RenderCopy(Game::renderer, this->texture3, NULL, NULL );

                //Update screen
                SDL_RenderPresent( Game::renderer );}
                
             else if(xMouse<=1064 && xMouse >=732 && yMouse<=880 && yMouse>=788){
             SDL_RenderClear( Game::renderer );

                //Render texture to screen
                SDL_RenderCopy(Game::renderer, this->texture4, NULL, NULL );

                //Update screen
                SDL_RenderPresent( Game::renderer );}    
                
                
                
                
                 else if(xMouse<=1060 && xMouse >=734 && yMouse<=1030 && yMouse>=950){
             SDL_RenderClear( Game::renderer );

                //Render texture to screen
                SDL_RenderCopy(Game::renderer, this->texture5, NULL, NULL );

                //Update screen
                SDL_RenderPresent( Game::renderer );}
                
                
                
           
                else{
                 SDL_RenderClear( Game::renderer );

                //Render texture to screen
                SDL_RenderCopy(Game::renderer, this->texture1, NULL, NULL );

                //Update screen
                SDL_RenderPresent( Game::renderer );
                
               }
            
            
            
          }  
            
        }
    }
}




                
                
                
                
                
                
                
  //Clear screen
  /*              SDL_RenderClear( Game::renderer );

                //Render texture to screen
                SDL_RenderCopy(Game::renderer, this->texture2, NULL, NULL );

                //Update screen
                SDL_RenderPresent( Game::renderer );
                SDL_Delay(5000);   
                           
                 //Clear screen
                SDL_RenderClear( Game::renderer );

                //Render texture to screen
                SDL_RenderCopy(Game::renderer, this->texture3, NULL, NULL );

                //Update screen
                SDL_RenderPresent( Game::renderer );
                SDL_Delay(5000);   
                           
                //Clear screen
                SDL_RenderClear( Game::renderer );

                //Render texture to screen
                SDL_RenderCopy(Game::renderer, this->texture4, NULL, NULL );

                //Update screen
                SDL_RenderPresent( Game::renderer );
                SDL_Delay(5000);
                 //Clear screen
                SDL_RenderClear( Game::renderer );

                //Render texture to screen
                SDL_RenderCopy(Game::renderer, this->texture5, NULL, NULL );

                //Update screen
                SDL_RenderPresent( Game::renderer );
                SDL_Delay(5000);   
                              
                    */        
                
                
                  
