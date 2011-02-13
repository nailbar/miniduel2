#ifndef MD_TEST_H
#define MD_TEST_H 1

#ifndef MD_TEST_MAX_ARROWS
#define MD_TEST_MAX_ARROWS 20
#endif

#include "vector.h"

class MD_test {
public:
    RR_vector arrow[7]; // The arrow shape
    RR_vector posses[MD_TEST_MAX_ARROWS]; // The arrow positions
    float arrow_opac;
    
    //Constructor
    MD_test() {
        arrow_opac = 250.0 / float(MD_TEST_MAX_ARROWS);
        
        // Set arrow shape
        arrow[0] = RR_vector(-0,0);
        arrow[1] = RR_vector(-20,-10);
        arrow[2] = RR_vector(-20,-7);
        arrow[3] = RR_vector(-30,-5);
        arrow[4] = RR_vector(-30,5);
        arrow[5] = RR_vector(-20,7);
        arrow[6] = RR_vector(-20,10);
    }
    
    //Display
    void display(SDL_Surface* win, int mpos[], float fspd) {
        
        // Variables used here
        short x[7], y[7];
        RR_vector pos = RR_vector(mpos[0], mpos[1]);
        RR_vector nrm, ext, v1;
        
        // Process each arrow
        for(int i = 0; i < MD_TEST_MAX_ARROWS; i++) {
        
            // Calculate normal
            nrm = RRvf.normal(pos - posses[i]);
            ext = RRvf.extrude(nrm);
        
            // Rotate arrow
            for(int a = 0; a < 7; a++) {
                v1 = nrm * arrow[a].x + ext * arrow[a].y + pos;
                x[a] = v1.x;
                y[a] = v1.y;
            }
            
            // Draw arrow
            filledPolygonRGBA(win,x,y,7,255,0,0,255-i*arrow_opac);
            aapolygonRGBA(win,x,y,7,150,0,0,255-i*arrow_opac);
            
            // Reset position (30 pixels behind previous arrow)
            posses[i] = posses[i] + (pos - posses[i] - nrm * 35.0) * fspd * 10.0;
            pos = posses[i];
        }
    }
};

#endif //MD_TEST_H
