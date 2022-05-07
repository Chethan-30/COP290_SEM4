#include "game.h"
#include "SDL2/SDL_ttf.h"
#include "texturemng.h"
#include "gameobject.h"
#include "audio.h"
#include "startmenu.h"
#include "map.h"
#include <string>
#include<sstream>  
#include "server.h"
#include "client.h"
#include <stdio.h>
#include <vector>
using namespace std;
// gameobject objects
Gameobject* player;
Gameobject* opponent;
Gameobject*coin1;
Gameobject*coin2;
Gameobject*coin3;
Gameobject*coin4;
Gameobject*coin5;
Gameobject*coin6;
Gameobject*coin7;
Gameobject*coin8;
Gameobject*coin9;
Gameobject*coin10;
Gameobject*guard1;
Gameobject*guard2;
Gameobject*guard3;
Gameobject*guard4;
Gameobject*guard5;
Gameobject*guard6;
Gameobject*guard7;
Gameobject*guard8;
Gameobject*guard9;
Gameobject*guard10;
Gameobject* road1;
Gameobject* road2;
Gameobject* road3;
Gameobject* road4;
Gameobject* road5;
Gameobject* road6;
Gameobject* road7;
Gameobject* road8;
Gameobject* road9;
Gameobject* road10;
Gameobject* food1;
Gameobject* food2;
Gameobject* food3;
Gameobject* food4;
Gameobject* food5;
Gameobject*snake1;
Gameobject* snake2;
Gameobject* snake3;
Gameobject* snake4;
Gameobject*snake5;
Gameobject*snake6;
Gameobject*snake7;
Gameobject*snake8;
Gameobject*snake9;
Gameobject*snake10;

Gameobject*diamond1;
Gameobject*diamond2;
Gameobject*diamond3;
Gameobject*diamond4;
Gameobject*diamond5;
Gameobject*diamond6;
Gameobject*diamond7;
Gameobject*diamond8;
Gameobject*diamond9;
Gameobject*diamond10;

//
Gameobject*assignment1;
 bool assignment1_to_exist;
Gameobject*assignment2;
 bool assignment2_to_exist;
Gameobject*assignment3;
 bool assignment3_to_exist;
Gameobject*assignment4;
 bool assignment4_to_exist;
Gameobject*assignment5;
 bool assignment5_to_exist;    
 bool submitting;


Gameobject*teacher;
 bool  teacher_to_exist; 



int submitting_count=0;



//

 SDL_Texture* texture_for_win;
  SDL_Texture* texture_for_lose;

//
Gameobject*key1;
bool key1_to_exist;
Gameobject*key2;
 bool key2_to_exist;
Gameobject*pass;
 bool pass_to_exist;
Gameobject*rdv;
 bool rdv_to_exist; 
 bool taking_pass;
 bool taken_pass;
  



 //
 bool Task1;
 bool Task2;
 bool Task3;

     
//


//
SDL_Color textColor = { 255, 255, 0 };

//bool declaration

bool coin1_to_exist;
bool coin2_to_exist;
bool coin3_to_exist;
bool coin4_to_exist;
bool coin5_to_exist;
bool coin6_to_exist;
bool coin7_to_exist;
bool coin8_to_exist;
bool coin9_to_exist;
bool coin10_to_exist;


//diamond declarations

bool diamond1_to_exist;
bool diamond2_to_exist;
bool diamond3_to_exist;
bool diamond4_to_exist;
bool diamond5_to_exist;
bool diamond6_to_exist;
bool diamond7_to_exist;
bool diamond8_to_exist;
bool diamond9_to_exist;
bool diamond10_to_exist;

//food


bool food1_to_exist;
bool food2_to_exist;
bool food3_to_exist;
bool food4_to_exist;
bool food5_to_exist;

// song change
bool song_change=false;
int song_count=0;

bool death_change=false;
int death_count=0;


// initials for the text rendering for health power
Texture* hp;
Texture* hp5;
int game_situation=0;
int hp3=5000000;
SDL_Texture* text5;
SDL_Rect  destiny2;


int hp2=5000000;
SDL_Texture* text;
SDL_Rect destiny;

//initials for the text rendering for score
Texture* score;


//int playscore=0;

SDL_Texture* texscore;
SDL_Rect scoredest;


//

//********************************************timer**************************

SDL_Texture* realtime1;
SDL_Rect realrect;

Texture* realtime2;

//*********************************************************************************


Texture* score2;

//int playscore2=0;

SDL_Texture* texscore2;
SDL_Rect scoredest2;
  int handler=0;

// 
SDL_Renderer* Game::renderer=nullptr;
SDL_Event Game::event;

//audio
Audio* aud;

//menu
StartMenu* m;
// map
Map* map;
int toggle=1;
int q=1;
bool id[10];
int gold_diamond=0;


//food
int lunch1=0;
int lunch2=0;
int lunch3=0;
int lunch4=0;
int lunch5=0;

//
  const char *temp15;
   const char *temp32;

  


//constructor
Game::Game(){}



//destructor
Game::~Game(){}


  


//initialization components it will not be in the loop  it will run only once

void Game::initialize(const char* title,int xpos,int ypos,int width,int height,bool fullscreen){
             

               int flags=0;
               if(fullscreen){flags=SDL_WINDOW_FULLSCREEN;}
               torun=true;
              if( SDL_Init( SDL_INIT_EVERYTHING) < 0 )
                  {
                     printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
                     torun=false;
                  }    
              else  {
                     window = SDL_CreateWindow( title, xpos,ypos, width, height, flags );
                     if( window == NULL )
                           {
                             printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
                             torun=false;
                           }
                     else  {
                              renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
                              
                              if( renderer == NULL )
                                  {
                                        printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
                                        torun=false;
                                  } 
                             else{      //Initialize renderer color
                              SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
                               //Initialize PNG loading
                                  
                               int imgFlags = IMG_INIT_PNG;
                               if( !( IMG_Init( imgFlags ) & imgFlags ) )
                                    {
                                  printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
                                   torun=false;
                  
                                        }

                                 if ( TTF_Init() < 0 ) {
	                                 printf("Error initializing SDL_ttf: %s\n",TTF_GetError());
                                      }       
                            }
                          }      
                    }          



aud= new Audio();
aud->loadaudio();
aud->startMenuaudio(); 
m=new StartMenu();
m->loadstartmenu();
m->render();
road1 =new Gameobject("pictures/map_items/road.png",1376,0);
coin1 =new Gameobject("pictures/gold.png",1376,0);
guard1 =new Gameobject("pictures/guard.png",1344,0);
road2 =new Gameobject("pictures/map_items/road.png",160,640);
coin2 =new Gameobject("pictures/gold.png",160,640);
guard2 =new Gameobject("pictures/guard.png",160,608);
road3 =new Gameobject("pictures/map_items/road.png",160,992);
coin3 =new Gameobject("pictures/gold.png",160,992);
guard3 =new Gameobject("pictures/guard.png",160,960);
road4 =new Gameobject("pictures/map_items/road.png",32,384);
coin4 =new Gameobject("pictures/gold.png",32,384);
guard4 =new Gameobject("pictures/guard.png",64,352);
road5 =new Gameobject("pictures/map_items/road.png",384,384);
coin5 =new Gameobject("pictures/gold.png",384,384);
guard5 =new Gameobject("pictures/guard.png",352,384);
road6 =new Gameobject("pictures/map_items/road.png",1056,736);
coin6 =new Gameobject("pictures/gold.png",1056,736);
guard6 =new Gameobject("pictures/guard.png",1056,704);
road7 =new Gameobject("pictures/map_items/road.png",1536,608);
coin7 =new Gameobject("pictures/gold.png",1536,608);
guard7 =new Gameobject("pictures/guard.png",1504,608);
road8 =new Gameobject("pictures/map_items/road.png",1504,352);
coin8 =new Gameobject("pictures/gold.png",1504,352);
guard8 =new Gameobject("pictures/guard.png",1504,384);
road9 =new Gameobject("pictures/map_items/road.png",320,768);
coin9 =new Gameobject("pictures/gold.png",320,768);
guard9 =new Gameobject("pictures/guard.png",288,768);
road10 =new Gameobject("pictures/map_items/road.png",1152,128);
coin10 =new Gameobject("pictures/gold.png",1152,128);
guard10 =new Gameobject("pictures/guard.png",1152,160);

//diamonds

diamond1 =new Gameobject("pictures/reddiamond.png",1376,0);
diamond2 =new Gameobject("pictures/greendiamond.png",160,640);
diamond3 =new Gameobject("pictures/bluediamond.png",160,992);
diamond4 =new Gameobject("pictures/pinkdiamond.png",32,384);
diamond5 =new Gameobject("pictures/bluediamond.png",384,384);
diamond6 =new Gameobject("pictures/greendiamond.png",1056,736);
diamond7 =new Gameobject("pictures/reddiamond.png",1536,608);
diamond8 =new Gameobject("pictures/pinkdiamond.png",1504,352);
diamond9 =new Gameobject("pictures/reddiamond.png",320,768);
diamond10 =new Gameobject("pictures/bluediamond.png",1152,128);
//end game
texture_for_win=Texture::LoadTexture("pictures/WINNER.png");
texture_for_lose=Texture::LoadTexture("pictures/LOOSER.png");



// food objects
food1 =new Gameobject("pictures/food.png",160,192);
food2 =new Gameobject("pictures/food.png",480,320);
food3 =new Gameobject("pictures/food.png",1088,352);
food4 =new Gameobject("pictures/food.png",1248,672);
food5 =new Gameobject("pictures/food.png",1824,320);

//snake
snake1 =new Gameobject("pictures/snake.png",1600,704);
snake2 =new Gameobject("pictures/snake.png",480,416);
snake3 =new Gameobject("pictures/snake.png",736,384);
snake4 =new Gameobject("pictures/snake.png",1024,416);
snake5 =new Gameobject("pictures/snake.png",1216,128);
snake6 =new Gameobject("pictures/snake.png",1120,736);
snake7 =new Gameobject("pictures/snake.png",1536,224);
snake8 =new Gameobject("pictures/snake.png",1472,416);
snake9 =new Gameobject("pictures/snake.png",1344,288);
snake10 =new Gameobject("pictures/snake.png",1472,128);

//

assignment1=new Gameobject("pictures/paper.png",64,512);
assignment2=new Gameobject("pictures/paper.png",480,128);
assignment3=new Gameobject("pictures/paper.png",1792,448);
assignment4=new Gameobject("pictures/paper.png",1888,64);
assignment5=new Gameobject("pictures/paper.png",928,320);


teacher=new Gameobject("pictures/teacher.png",1312,480);


//
key1=new Gameobject("pictures/key.png",864,320);
key2=new Gameobject("pictures/key.png",992,320);
pass=new Gameobject("pictures/pass.png",512,832);
rdv =new Gameobject("pictures/rdvevent.png",1312,64);





//

if(temp899.compare("server")==0)
{player= new Gameobject("pictures/man.png",128,32);
opponent= new Gameobject("pictures/man2.png",1888,960);}

else
{player= new Gameobject("pictures/man.png",1888,960);
  opponent= new Gameobject("pictures/man2.png",128,32);
  }



aud->startmenuTogamemusic();
map=new Map();

// bool declaration
 coin1_to_exist = true;
 coin2_to_exist = true;
 coin3_to_exist = true;
 coin4_to_exist = true;
 coin5_to_exist = true;
 coin6_to_exist = true;
 coin7_to_exist = true;
 coin8_to_exist = true;
 coin9_to_exist = true;
 coin10_to_exist= true;

 //diamonds
 diamond1_to_exist=false;
 diamond2_to_exist=false;
 diamond3_to_exist=false;
 diamond4_to_exist=false;
 diamond5_to_exist=false;
 diamond6_to_exist=false;
 diamond7_to_exist=false;
 diamond8_to_exist=false;
 diamond9_to_exist=false;
 diamond10_to_exist=false;



 food1_to_exist=false;
 food2_to_exist=false;
 food3_to_exist=false;
 food4_to_exist=false;
 food5_to_exist=false;

// 
assignment1_to_exist=true;
assignment2_to_exist=true;
assignment3_to_exist=true;
assignment4_to_exist=true;
assignment5_to_exist=true;
submitting =false;
teacher_to_exist=true;


//

key1_to_exist=true;
key2_to_exist=true;
pass_to_exist=true;
rdv_to_exist=true;
 taking_pass=false;
 taken_pass=false;

//
Task1=true;
Task2=false;
Task3=false;





// if(temp899.compare("server"));
// {
//   hp3=sendHPdataserver(hp2);
// }



//initialization
hp=new Texture();
hp5 =new Texture();
score=new Texture();
score2=new Texture();
realtime2=new Texture();
//loading the font
hp->gFont = TTF_OpenFont( "lazy.ttf", 24 );
hp5->gFont = TTF_OpenFont( "lazy.ttf", 28 );
score->gFont =TTF_OpenFont( "lazy.ttf", 28 );
score2->gFont =TTF_OpenFont( "lazy.ttf", 28 );

realtime2->gFont=TTF_OpenFont( "lazy.ttf", 28 );

//declaring integer variables


playscore =0;

playscore2 =0;
// stream declaration
 //hp
 stringstream ss;  
   
  string temp="PLAYER1 HP:";
   
  ss<<hp2;
  
   string s;  
  
  ss>>s;  
 
  temp=temp+s;
  
  const char *temp2=temp.c_str();
text=hp->loadFromRenderedText(temp2,textColor);
  //score
  stringstream ss1;  
  string temp5="PLAYER1 SCORE:";
  ss1<<playscore;
   string s1;  
  ss1>>s1;  
  temp5=temp5+s1;
  const char *temp3=temp5.c_str();
texscore=score->loadFromRenderedText(temp3,textColor);

//second player
stringstream stream_other;   
  string temp_other="PLAYER2 HP:";
 stream_other<<hp3;
   string s111;  
   stream_other>>s111;  
   temp_other=temp_other+s111;
 temp15=temp_other.c_str();
text5=hp5->loadFromRenderedText(temp15,textColor);

//SECOND PLAYER score
stringstream ss12;  
  string temp52="OPPONENT SCORE:";
  ss12<<playscore2;
   string s12;  
  ss12>>s12;  
  temp52=temp52+s12;
temp32=temp52.c_str();
texscore2=score2->loadFromRenderedText(temp32,textColor);


//*********************************************time******************************************

stringstream realstream222;  
  string temp_real="TIME :";
  realstream222<<realtime;
   string s1234;  
  realstream222>>s1234;  
  temp_real=temp_real+s1234;
  const char *temp3245=temp_real.c_str();
realtime1=realtime2->loadFromRenderedText(temp3245,textColor);

 
 
 
 
 //*****************************************************************************************
 
 
 //hp2=hp2-5;
//   stringstream ss;  
//   ss<<hp2;
//    string s;  
//   ss>>s;  
//   temp=temp+s;
//   const char *temp2=temp.c_str();
// text=hp->loadFromRenderedText(temp2,textColor);
destiny.x= 1400;
destiny.y= 900;
destiny.w=hp->mWidth;
destiny.h=hp->mHeight;


destiny2.x=1100  ;
destiny2.y=900  ;
destiny2.w=hp5->mWidth  ;
destiny2.h=hp5->mHeight  ;


scoredest.x=1400;
scoredest.y=950;
scoredest.w=score->mWidth;
scoredest.h=score->mHeight;


scoredest2.x=1100;
scoredest2.y=950;
scoredest2.w=score2->mWidth;
scoredest2.h=score2->mHeight;



//************************************time*************************************************************8





realrect.x=900;
realrect.y=920;
realrect.w=realtime2->mWidth;
realrect.h=realtime2->mHeight;


//**************************************************************************************************

// if(!SDL_HasIntersection(guard1->gdrect(),player->gdrect()) && !SDL_HasIntersection(guard2->gdrect(),player->gdrect()) && !SDL_HasIntersection(guard3->gdrect(),player->gdrect()) && !SDL_HasIntersection(guard4->gdrect(),player->gdrect())  && !SDL_HasIntersection(guard5->gdrect(),player->gdrect()) && !SDL_HasIntersection(guard6->gdrect(),player->gdrect()) && !SDL_HasIntersection(guard7->gdrect(),player->gdrect()) && !SDL_HasIntersection(guard8->gdrect(),player->gdrect()) && !SDL_HasIntersection(guard9->gdrect(),player->gdrect())  && !SDL_HasIntersection(guard10->gdrect(),player->gdrect()) )
// {hp2=hp2-5;   }

}

//events handler

void Game::handle_events(){
 
     // SDL_Event event;      
      SDL_PollEvent(&event);
      switch(event.type){
        case SDL_QUIT:
            torun =false;
            break;
            
            
       default :
         break;
         }     
      
 //if (hp2/500000<=0){torun=false;}
 //if (hp3/500<=0){torun=false;}
}

//render function run always in the loop

void Game::render() {
  //Clear screen 
      SDL_RenderClear( renderer );
    //Render texture to screen
    map->drawmap();
      player->render();
       opponent->render();
      if(gold_diamond==0){
      if( coin1_to_exist){
      if (toggle==1 ){coin1->render();}
      else {road1->render();}}
      if( coin2_to_exist){
      if (toggle==1){coin2->render();}
      else {road2->render();}}
      if( coin3_to_exist){
      if (toggle==1 ){coin3->render();}
      else {road3->render();}}
      if( coin4_to_exist){
      if (toggle==1  ){coin4->render();}
      else {road4->render();}}
      if( coin5_to_exist){
      if (toggle==1  ){coin5->render();}
      else {road5->render();}}
      if( coin6_to_exist){
      if (toggle==1 ){coin6->render();}
      else {road6->render();}}
      if(coin7_to_exist){
      if (toggle==1 ){coin7->render();}
      else {road7->render();}}
      if(coin8_to_exist){
      if (toggle==1  ){coin8->render();}
      else {road8->render();}}
      if(coin9_to_exist){
      if (toggle==1 ){coin9->render();}
      else {road9->render();}}
      if( coin10_to_exist){
      if (toggle==1  ){coin10->render();}
      else {road10->render();}}
      if(coin1_to_exist==false && coin2_to_exist==false && coin3_to_exist==false && coin4_to_exist==false && coin5_to_exist==false && coin6_to_exist==false && coin7_to_exist==false && coin8_to_exist==false  && coin9_to_exist==false && coin10_to_exist==false){
        gold_diamond=1;
         diamond1_to_exist=true;
         diamond2_to_exist=true;
         diamond3_to_exist=true;
         diamond4_to_exist=true;
         diamond5_to_exist=true;
         diamond6_to_exist=true;
         diamond7_to_exist=true;
        diamond8_to_exist=true;
        diamond9_to_exist=true;
        diamond10_to_exist=true;

      }
      }
      else{
      if( diamond1_to_exist){
      if (toggle==1 ){diamond1->render();}
      else {road1->render();}}
      if( diamond2_to_exist){
      if (toggle==1){diamond2->render();}
      else {road2->render();}}
      if( diamond3_to_exist){
      if (toggle==1 ){diamond3->render();}
      else {road3->render();}}
      if( diamond4_to_exist){
      if (toggle==1  ){diamond4->render();}
      else {road4->render();}}
      if( diamond5_to_exist){
      if (toggle==1  ){diamond5->render();}
      else {road5->render();}}
      if( diamond6_to_exist){
      if (toggle==1 ){diamond6->render();}
      else {road6->render();}}
      if(diamond7_to_exist){
      if (toggle==1 ){diamond7->render();}
      else {road7->render();}}
      if(diamond8_to_exist){
      if (toggle==1  ){diamond8->render();}
      else {road8->render();}}
      if(diamond9_to_exist){
      if (toggle==1 ){diamond9->render();}
      else {road9->render();}}
      if( diamond10_to_exist){
      if (toggle==1  ){diamond10->render();}
      else {road10->render();}}  
      if(diamond1_to_exist==false && diamond2_to_exist==false && diamond3_to_exist==false && diamond4_to_exist==false && diamond5_to_exist==false && diamond6_to_exist==false && diamond7_to_exist==false  && diamond8_to_exist==false  && diamond9_to_exist==false && diamond10_to_exist==false){
       gold_diamond=0; 
        coin1_to_exist = true;
        coin2_to_exist = true;
        coin3_to_exist = true;
        coin4_to_exist = true;
        coin5_to_exist = true;
        coin6_to_exist = true;
        coin7_to_exist = true;
        coin8_to_exist = true;
       coin9_to_exist = true;
        coin10_to_exist= true;

      }
      }

     if(q%15==0) {
      if(toggle==0){toggle=1;}
      else {toggle=0;}}



// assignments
  if(Task1){
   if (toggle==1 && assignment1_to_exist ){assignment1->render();}
   if (toggle==1 && assignment2_to_exist ){assignment2->render();}
   if (toggle==1 && assignment3_to_exist ){assignment3->render();}
   if (toggle==1 && assignment4_to_exist ){assignment4->render();}
   if (toggle==1 && assignment5_to_exist ){assignment5->render();}
    if (toggle==1 && teacher_to_exist){teacher->render();}

    if(!teacher_to_exist){
      Task1=false; 
     assignment1_to_exist=true;
    assignment2_to_exist=true;
    assignment3_to_exist=true;
    assignment4_to_exist=true;
    assignment5_to_exist=true;
   submitting =false;
    teacher_to_exist=true;
      
      Task2=true;  }

  }

   if(Task2){
   if (toggle==1 && key1_to_exist ){key1->render(); }
   if (toggle==1 && key2_to_exist ){key2->render();}
   if (toggle==1 && pass_to_exist ){pass->render();}
   if (toggle==1 && rdv_to_exist){rdv->render();}
   
    

    if(!rdv_to_exist){Task2=false;
     key1_to_exist=true;
     key2_to_exist=true;
     pass_to_exist=true;
     rdv_to_exist=true;
     taking_pass=false;
     taken_pass=false;
    
    
     Task1=true;}

  }

// food

     
      if (toggle==1 && food1_to_exist ){food1->render();}
      if (toggle==1 && food2_to_exist ){food2->render();}
      if (toggle==1 && food3_to_exist ){food3->render();}
      if (toggle==1 && food4_to_exist ){food4->render();}
      if (toggle==1 && food5_to_exist ){food5->render();}
      

      guard1->render();
      guard2->render();
      guard3->render();
      guard4->render();
      guard5->render();
      guard6->render();
      guard7->render();
      guard8->render();
      guard9->render();
      guard10->render();


      snake1->render();
      snake2->render();
      snake3->render();
      snake4->render();
      snake5->render();
      snake6->render();
      snake7->render();
      snake8->render();
      snake9->render();
      snake10->render();      
     
      if(lunch1/2000>0){food1_to_exist=true;}
      else{food1_to_exist=false;}

      if(lunch2/2000>0){food2_to_exist=true;}
      else{food2_to_exist=false;}

      if(lunch3/2000>0){food3_to_exist=true;}
      else{food3_to_exist=false;}

      if(lunch4/2000>0){food4_to_exist=true;}
      else{food4_to_exist=false;}

      if(lunch5/2000>0){food5_to_exist=true;}
      else{food5_to_exist=false;}
      q++;
      lunch1++;
      lunch2++;
      lunch3++;
      lunch4++;
      lunch5++;
      if(lunch1==4000){lunch1=0;}
      if(lunch2==4000){lunch2=0;}
      if(lunch3==4000){lunch3=0;}
      if(lunch4==4000){lunch4=0;}
      if(lunch5==4000){lunch5=0;}





      
     hp->rend(text,destiny);
     hp5->rend(text5,destiny2);
     score->rend(texscore,scoredest);
     score2->rend(texscore2,scoredest2);
    realtime2->rend(realtime1,realrect);
      //road->render();
      //score2->special(temp32,textColor,scoredest2);
      //hp5->special(temp15,textColor,destiny2);

      
      
  //Update screen
      SDL_RenderPresent( renderer );

  //    if(!SDL_HasIntersection(guard1->gdrect(),player->gdrect()) && !SDL_HasIntersection(guard2->gdrect(),player->gdrect()) && !SDL_HasIntersection(guard3->gdrect(),player->gdrect()) && !SDL_HasIntersection(guard4->gdrect(),player->gdrect())  && !SDL_HasIntersection(guard5->gdrect(),player->gdrect()) && !SDL_HasIntersection(guard6->gdrect(),player->gdrect()) && !SDL_HasIntersection(guard7->gdrect(),player->gdrect()) && !SDL_HasIntersection(guard8->gdrect(),player->gdrect()) && !SDL_HasIntersection(guard9->gdrect(),player->gdrect())  && !SDL_HasIntersection(guard10->gdrect(),player->gdrect()) )
//{hp2=hp2-5;   }


}

// update function which always run in loop and it will update the destiny locations of the objects which are used in the game

void Game::update(){
count++;
//if(!SDL_HasIntersection(guard1->gdrect(),player->gdrect()) && !SDL_HasIntersection(guard2->gdrect(),player->gdrect()) && !SDL_HasIntersection(guard3->gdrect(),player->gdrect()) && !SDL_HasIntersection(guard4->gdrect(),player->gdrect())  && !SDL_HasIntersection(guard5->gdrect(),player->gdrect()) && !SDL_HasIntersection(guard6->gdrect(),player->gdrect()) && !SDL_HasIntersection(guard7->gdrect(),player->gdrect()) && !SDL_HasIntersection(guard8->gdrect(),player->gdrect()) && !SDL_HasIntersection(guard9->gdrect(),player->gdrect())  && !SDL_HasIntersection(guard10->gdrect(),player->gdrect()) )
  player->update();

opponent->update();
coin1->up();
coin2->up();
coin3->up();
coin4->up();
coin5->up();
coin6->up();
coin7->up();
coin8->up();
coin9->up();
coin10->up();
road1->up();
road2->up();
road3->up();
road4->up();
road5->up();
road6->up();
road7->up();
road8->up();
road9->up();
road10->up();
//guards
guard1->move1();
guard2->move2();
guard3->up();
guard4->up();
guard5->move5();
guard6->move6();
//guard2->move2();
guard7->up();
guard8->up();
guard9->up();
guard10->up();

//diamonds
diamond1 ->up();
diamond2 ->up();
diamond3 ->up();
diamond4 ->up();
diamond5 ->up();
diamond6 ->up();
diamond7 ->up();
diamond8 ->up();
diamond9 ->up();
diamond10 ->up();



//sanke
      snake1->move10();
      snake2->move10();
      snake3->move10();
      snake4->move10();
      snake5->move10();
      snake6->move10();
      snake7->move10();
      snake8->move10();
      snake9->move10();
      snake10->move10();  

// food
food1->up();
food2->up();
food3->up();
food4->up();
food5->up();


// assignments
assignment1->up();
assignment2->up();
assignment3->up();
assignment4->up();
assignment5->up();
teacher->up();

//
key1->up();
key2->up();
pass->up();
rdv->up();



//conditions
 if(!(!SDL_HasIntersection(guard1->gdrect(),player->gdrect()) && !SDL_HasIntersection(guard2->gdrect(),player->gdrect()) && !SDL_HasIntersection(guard3->gdrect(),player->gdrect()) && !SDL_HasIntersection(guard4->gdrect(),player->gdrect())  && !SDL_HasIntersection(guard5->gdrect(),player->gdrect()) && !SDL_HasIntersection(guard6->gdrect(),player->gdrect()) && !SDL_HasIntersection(guard7->gdrect(),player->gdrect()) && !SDL_HasIntersection(guard8->gdrect(),player->gdrect()) && !SDL_HasIntersection(guard9->gdrect(),player->gdrect())  && !SDL_HasIntersection(guard10->gdrect(),player->gdrect()) ))
 {
   hp2=hp2-10000;
  
   death_change=true;

 }

 if(death_change){
  aud->changetodeath();
  death_count=0; 
  death_change=false;
  }
if(death_count==20){aud->startmenuTogamemusic();}


 if(!(!SDL_HasIntersection(snake1->gdrect(),player->gdrect()) && !SDL_HasIntersection(snake2->gdrect(),player->gdrect()) && !SDL_HasIntersection(snake3->gdrect(),player->gdrect()) && !SDL_HasIntersection(snake4->gdrect(),player->gdrect())  && !SDL_HasIntersection(snake5->gdrect(),player->gdrect()) && !SDL_HasIntersection(snake6->gdrect(),player->gdrect()) && !SDL_HasIntersection(snake7->gdrect(),player->gdrect()) && !SDL_HasIntersection(snake8->gdrect(),player->gdrect()) && !SDL_HasIntersection(snake9->gdrect(),player->gdrect())  && !SDL_HasIntersection(snake10->gdrect(),player->gdrect()) ))
 {
   hp2=hp2-10000;
 
 death_change=true;
 }



if(Task1){
  if(SDL_HasIntersection(assignment1->gdrect(),player->gdrect()) && assignment1_to_exist ){
    submitting=true;
    assignment1_to_exist=false;
    song_change=true;
    submitting_count++;

 }
 if(SDL_HasIntersection(assignment2->gdrect(),player->gdrect()) && assignment2_to_exist ){
    submitting=true;
    assignment2_to_exist=false;
    song_change=true;
    submitting_count++;

 }
 if(SDL_HasIntersection(assignment3->gdrect(),player->gdrect()) && assignment3_to_exist ){
    submitting=true;
    assignment3_to_exist=false;
    song_change=true;
    submitting_count++;

 }
 if(SDL_HasIntersection(assignment4->gdrect(),player->gdrect()) && assignment4_to_exist ){
    submitting=true;
    assignment4_to_exist=false;
    song_change=true;
    submitting_count++;


 }
 if(SDL_HasIntersection(assignment5->gdrect(),player->gdrect()) && assignment5_to_exist ){
    submitting=true;
    assignment5_to_exist=false;
    song_change=true;
    submitting_count++;

 }


  if(SDL_HasIntersection(teacher->gdrect(),player->gdrect()) && teacher_to_exist && submitting){
    playscore=playscore+20;
    submitting=false;
   
    if(submitting_count==5){
    teacher_to_exist=false;}
    song_change=true;


 }
}

if(Task2){

 if(SDL_HasIntersection(key1->gdrect(),player->gdrect()) && key1_to_exist){
 
    taking_pass=true;
    key1_to_exist=false;
    song_change=true;
    

 }

 if(SDL_HasIntersection(key2->gdrect(),player->gdrect()) && key2_to_exist){
    taking_pass=true;
    key2_to_exist=false;
    song_change=true;
    

 }


  if(SDL_HasIntersection(pass->gdrect(),player->gdrect()) && pass_to_exist && taking_pass){
    
    pass_to_exist=false;
    key1_to_exist=false;
    key2_to_exist=false;
    taken_pass=true;
    taking_pass=false;

   
    
    song_change=true;


 }

   if(SDL_HasIntersection(rdv->gdrect(),player->gdrect()) && rdv_to_exist && taken_pass){
    playscore=playscore+50;
    taken_pass=false;
   rdv_to_exist=false;

    song_change=true;


 }

}











//coins and diamonds

 if(SDL_HasIntersection(coin1->gdrect(),player->gdrect()) && coin1_to_exist ){
  playscore=playscore+10;
  
    coin1_to_exist=false;
    song_change=true;

 }




 if(SDL_HasIntersection(coin2->gdrect(),player->gdrect()) && coin2_to_exist  ){
  playscore=playscore+10;
   
    coin2_to_exist=false;
  song_change=true;
 }


 if(SDL_HasIntersection(coin3->gdrect(),player->gdrect())  && coin3_to_exist ){
  playscore=playscore+10;
 
    coin3_to_exist=false;
    song_change=true;
 }

 if(SDL_HasIntersection(coin4->gdrect(),player->gdrect())  && coin4_to_exist ){
  playscore=playscore+10;
  
    coin4_to_exist=false;
    song_change=true;
 }

 if(SDL_HasIntersection(coin5->gdrect(),player->gdrect())  && coin5_to_exist ){
  playscore=playscore+10;
  
    coin5_to_exist=false;
   song_change=true;
 }

 if(SDL_HasIntersection(coin6->gdrect(),player->gdrect())  && coin6_to_exist ){
  playscore=playscore+10;
  
    coin6_to_exist=false;
   song_change=true;
 }

 if(SDL_HasIntersection(coin7->gdrect(),player->gdrect())  && coin7_to_exist ){
  playscore=playscore+10;
  
    coin7_to_exist=false;
   song_change=true;
 }


 if(SDL_HasIntersection(coin8->gdrect(),player->gdrect())  && coin8_to_exist ){
  playscore=playscore+10;
  
    coin8_to_exist=false;
    song_change=true;
 }


 if(SDL_HasIntersection(coin9->gdrect(),player->gdrect())  && coin9_to_exist ){
  playscore=playscore+10;
   
    coin9_to_exist=false;
   song_change=true;
 }


 if(SDL_HasIntersection(coin10->gdrect(),player->gdrect())  && coin10_to_exist ){
  playscore=playscore+10;
   
    coin10_to_exist=false;
    song_change=true;
    

 }
 //
 if(song_change){
  aud->changetobooster();
  song_count=0; 
  song_change=false;
  }
if(song_count==20){aud->startmenuTogamemusic();}
 //diamonds


 if(SDL_HasIntersection(diamond1->gdrect(),player->gdrect()) && diamond1_to_exist ){
  playscore=playscore+20;
   
    diamond1_to_exist=false;
  song_change=true;
 }


 if(SDL_HasIntersection(diamond2->gdrect(),player->gdrect()) && diamond2_to_exist  ){
  playscore=playscore+20;
  
    diamond2_to_exist=false;
   song_change=true;
 }


 if(SDL_HasIntersection(diamond3->gdrect(),player->gdrect())  && diamond3_to_exist ){
  playscore=playscore+20;
 
    diamond3_to_exist=false;
   song_change=true;
 }

 if(SDL_HasIntersection(diamond4->gdrect(),player->gdrect())  && diamond4_to_exist ){
  playscore=playscore+20;
  
    diamond4_to_exist=false;
    song_change=true;
 }

 if(SDL_HasIntersection(diamond5->gdrect(),player->gdrect())  && diamond5_to_exist ){
  playscore=playscore+10;
   
    diamond5_to_exist=false;
    song_change=true;
 }

 if(SDL_HasIntersection(diamond6->gdrect(),player->gdrect())  && diamond6_to_exist ){
  playscore=playscore+20;
   
    diamond6_to_exist=false;
   song_change=true;
 }

 if(SDL_HasIntersection(diamond7->gdrect(),player->gdrect())  && diamond7_to_exist ){
  playscore=playscore+20;
  
    diamond7_to_exist=false;
    song_change=true;
 }


 if(SDL_HasIntersection(diamond8->gdrect(),player->gdrect())  && diamond8_to_exist ){
  playscore=playscore+20;
  
    diamond8_to_exist=false;
    song_change=true;
 }


 if(SDL_HasIntersection(diamond9->gdrect(),player->gdrect())  && diamond9_to_exist ){
  playscore=playscore+20;

    diamond9_to_exist=false;
   song_change=true;
 }


 if(SDL_HasIntersection(diamond10->gdrect(),player->gdrect())  && diamond10_to_exist ){
  playscore=playscore+20;
 
    diamond10_to_exist=false;
    song_change=true;

 }

 song_count++;
 death_count++;
//food
 if(SDL_HasIntersection(food1->gdrect(),player->gdrect()) && food1_to_exist ){
  hp2=hp2+500000;
  
    food1_to_exist=false;
    lunch1=0;

 }
 if(SDL_HasIntersection(food2->gdrect(),player->gdrect()) && food2_to_exist ){
  hp2=hp2+500000;
  
    food2_to_exist=false;
    lunch2=0;

 }
 if(SDL_HasIntersection(food3->gdrect(),player->gdrect()) && food3_to_exist ){
  hp2=hp2+500000;
  
    food3_to_exist=false;
    lunch3=0;

 }
 if(SDL_HasIntersection(food4->gdrect(),player->gdrect()) && food4_to_exist ){
  hp2=hp2+500000;
  
    food4_to_exist=false;
    lunch4=0;

 }
 if(SDL_HasIntersection(food5->gdrect(),player->gdrect()) && food5_to_exist ){
  hp2=hp2+500000;
  
    food5_to_exist=false;
    lunch5=0;

 }
stringstream ss;  
  string temp="YOUR HP:";
  ss<<hp2/500000;
   string s;  
  ss>>s;  
  temp=temp+s;
  const char *temp2=temp.c_str();
text=hp->loadFromRenderedText(temp2,textColor);



//score
stringstream ss1;  
  string temp5="YOUR SCORE:";
  ss1<<playscore;
   string s1;  
  ss1>>s1;  
  temp5=temp5+s1;
  const char *temp3=temp5.c_str();
texscore=score->loadFromRenderedText(temp3,textColor);





//************************************************************tiME*************8*************************************8


stringstream realstream222;  
  string temp_real="TIME :";
  realstream222<<realtime;
   string s1234;  
  realstream222>>s1234;  
  temp_real=temp_real+s1234;
  const char *temp3245=temp_real.c_str();
realtime1=realtime2->loadFromRenderedText(temp3245,textColor);




//**************************************************************TIME*******************************************

//player 2 hp


if(temp899.compare("server")==0)
{  
 
 vector<int>hp_score;
 hp_score.push_back(hp2);
  hp_score.push_back(playscore);
   hp_score.push_back(handler);
   
   SDL_Rect *a=player->gdrect();
    int x=a->x;
   int y=a->y;
   hp_score.push_back(x);
      hp_score.push_back(y);
vector<int>return1;
 
  return1=sendHPdataserver(hp_score);
  hp3=return1[0];
  playscore2=return1[1];
  game_situation=return1[2];

//    if(handler==1)
//  { torun=false;
//  SDL_Quit();
//   //exit(1);
//  }

x=return1[3];
y=return1[4];
SDL_Rect *vv=opponent->gdrect();
vv->x=x;
vv->y=y;
//opponent->render();

    hp3=hp3/500000;


if(hp3==0)
 {
   printf("YOU WIN\n");
    SDL_RenderClear( Game::renderer );

                //Render texture to screen
                SDL_RenderCopy(Game::renderer, texture_for_win, NULL, NULL );

                //Update screen
                SDL_RenderPresent( Game::renderer );
                aud->gameTogameovermusic();
                SDL_Delay(5000);
 torun=false;
 // SDL_Quit();
  // exit(1);
 }




}
//int handler=0;
if(temp899.compare("client")==0)
{  
      

 vector<int>hp_score;
 
 hp_score.push_back(hp2);
  hp_score.push_back(playscore);
    hp_score.push_back(handler);
    SDL_Rect *a=player->gdrect();
    int x=a->x;
   int y=a->y;
   hp_score.push_back(x);
      hp_score.push_back(y);


vector<int>return1;
 
  return1=sendHPdataClient(hp_score,ip_adress);
  hp3=return1[0];
  playscore2=return1[1];

x=return1[3];
y=return1[4];
SDL_Rect *vv=opponent->gdrect();
vv->x=x;
vv->y=y;
//opponent->render();


 // if(handler==1)
 //{ torun=false;
 // SDL_Quit();
 // exit(1);}
    hp3=hp3/500000;
  

if(hp3==0)
 {
   printf("YOU WIN\n");
       SDL_RenderClear( Game::renderer );

                //Render texture to screen
                SDL_RenderCopy(Game::renderer, texture_for_win, NULL, NULL );

                //Update screen
                SDL_RenderPresent( Game::renderer );
                aud->gameTogameovermusic();
                SDL_Delay(5000);

 torun=false;
 //  SDL_Quit();
   //exit(1);
 }

}


if(hp2/500000==0)
{
  printf("YOU LOOSE\n");
      SDL_RenderClear( Game::renderer );

                //Render texture to screen
                SDL_RenderCopy(Game::renderer, texture_for_lose, NULL, NULL );

                //Update screen
                SDL_RenderPresent( Game::renderer );
                aud->gameTogameovermusic();
                SDL_Delay(5000);
  torun=false;
}







stringstream stream_other;   
  string temp_other="OPPONENT HP:";
 stream_other<<hp3;
   string s111;  
   stream_other>>s111;  
   temp_other=temp_other+s111;
  temp15=temp_other.c_str();
text5=hp5->loadFromRenderedText(temp15,textColor);



stringstream ss12;  
  string temp52="OPPONENT SCORE:";
  ss12<<playscore2;
   string s12;  
  ss12>>s12;  
  temp52=temp52+s12;
  temp32=temp52.c_str();
texscore2=score2->loadFromRenderedText(temp32,textColor);



}



// clearing all the SDL  initializations before the game quit

void Game::clear(){

     aud->~Audio();
    //Destroy window  
    SDL_DestroyTexture( text );  
    SDL_DestroyRenderer( renderer );
    SDL_DestroyWindow( window );
    window = NULL;
    renderer = NULL;
    
    //Quit SDL subsystems
    TTF_Quit();
    SDL_Quit();

}

  
