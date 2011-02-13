#ifndef MD_SHIP_H
#define MD_SHIP_H 1

#ifndef MD_SHIP_MAX_PARTS
#define MD_SHIP_MAX_PARTS 10
#endif

#include "vector.h"

class MD_ship {
public:
    RR_vector pos,nrm,spd;
    
    //Constructor
    MD_ship() {
        pos = RR_vector(0,0);
        nrm = RR_vector(1,0);
        spd = RR_vector(0,0);
    }
    
    // Draw ship at given position, angle and scale
    void draw(SDL_Surface* win, RR_vector apos, RR_vector anrm, double ascale) {
        filledEllipseRGBA(
            win,
            apos.x - 10.0 * ascale,
            apos.y - 10.0 * ascale,
            20.0 * ascale,
            20.0 * ascale,
            255, 0, 0, 255);
        
        RR_vector nose = apos + anrm * 5.0 * ascale;
        filledEllipseRGBA(
            win,
            nose.x - 5.0 * ascale,
            nose.y - 5.0 * ascale,
            10.0 * ascale,
            10.0 * ascale,
            255, 100, 100, 255);
    }
};

#endif //MD_SHIP_H
