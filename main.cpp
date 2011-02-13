#include "SDL/SDL.h"
#include "SDL/SDL_gfxPrimitives.h"
#include <cmath>

// Settings
#define MD_MIN_FSPD 15.0
#define MD_MAX_FSPD 60.0

// Global stuff
int mpos[2] = {320, 200}; // Mouse coordinates
int wsiz[2] = {800, 600}; // Window size
float fspd; // Seconds per frame
Uint8* keys; // Keyboard input
Uint8 mkeys; // Mouse keys

// Game parts to include
#include "arena.h"

int main(int argc, char* args[]){
  
    // Create the window
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Surface* win = SDL_SetVideoMode(wsiz[0], wsiz[1], 32, SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE);
    SDL_WM_SetCaption("MiniDuel2", NULL);
    
    // Important variables
    SDL_Event event;
    bool inloop = true;
    Uint32 time1; // Current time
    Uint32 time2; // Last time
    
    // Init stuff
    keys = SDL_GetKeyState(NULL);
    time1 = SDL_GetTicks();
    time2 = 0;
    fspd = 1.0 / MD_MAX_FSPD;
    srand(time1);
    
    // Game related stuff
    MD_arena arena;
  
    //Game loop
    while(inloop){
        while(SDL_PollEvent(&event)){
            switch(event.type){
            case SDL_QUIT: inloop = false; break;
            
            //Mouse moved
            case SDL_MOUSEMOTION:
                mpos[0] = event.motion.x;
                mpos[1] = event.motion.y;
                break;
            
            // Window resized
            case SDL_VIDEORESIZE:
                wsiz[0] = event.resize.w;
                wsiz[1] = event.resize.h;
                win = SDL_SetVideoMode(wsiz[0], wsiz[1], 32, SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE);
                break;
            }
      }
      
      // Calculate seconds per frame
      time1 = SDL_GetTicks();
      if(time2){
          fspd = float(time1 - time2) / 1000.0;
          if(1.0 / fspd > MD_MAX_FSPD) {
              SDL_Delay(int((1.0 / MD_MAX_FSPD - fspd) * 1000.0));
              fspd = 1.0 / MD_MAX_FSPD;
          } else if(1.0 / fspd < MD_MIN_FSPD) fspd = 1.0 / MD_MIN_FSPD;
      }
      time2 = time1;
      //fspd = 1.0 / MD_MAX_FSPD;
      
      //Mouse keys
      mkeys = SDL_GetMouseState(NULL, NULL);
      
      //Clear screen (white)
      boxRGBA(win, -5, -5, wsiz[0] + 5, wsiz[1] + 5, 255, 255, 255, 255);
      
      // Draw test output
      arena.display(win);
      
      //Swap double buffer
      SDL_Flip(win);
      
      //Close on Escape
      if(keys[SDLK_ESCAPE]) inloop = false;
    }
    
    
    //Clean up
    SDL_Quit();
    
    //Done
    return 0;
}
