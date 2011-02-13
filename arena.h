#ifndef MD_ARENA_H
#define MD_ARENA_H 1

#ifndef MD_ARENA_MAX_SHIPS
#define MD_ARENA_MAX_SHIPS 25
#endif

#include "vector.h"
#include "ship.h"

class MD_arena {
public:
    MD_ship a[MD_ARENA_MAX_SHIPS];
    RR_vector cam;
    
    // Constructor
    MD_arena() {
        cam = RR_vector(0,0);
        for(int i = 0; i < MD_ARENA_MAX_SHIPS; i++) {
            a[i].pos = RR_vector(rand()%800, rand()%600) - RR_vector(wsiz[0],wsiz[1]) * 0.5;
            a[i].nrm = (RR_vector(rand()%800, rand()%600) - RR_vector(wsiz[0],wsiz[1]) * 0.5) - a[i].pos;
            a[i].nrm.normalise();
        }
    }
    
    // Display
    void display(SDL_Surface* win) {
        
        // Draw each ship
        for(int i = 0; i < MD_ARENA_MAX_SHIPS; i++) {
            a[i].draw(win, a[i].pos - cam + RR_vector(wsiz[0],wsiz[1]) * 0.5, a[i].nrm, 1.0);
        }
    }
};

#endif //MD_ARENA_H
