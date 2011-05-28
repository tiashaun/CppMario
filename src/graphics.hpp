#ifndef GRAPHICS
#define GRAPHICS

#include "SDL/SDL.h"

class Graphics
{
    public:
        enum
        {
            SCREEN_WIDTH  = 640,
            SCREEN_HEIGHT = 480,
            SCREEN_BPP    = 32
        };

        typedef SDL_Surface* Screen;

        Graphics  ();

        void flip ();

        Screen screen ();

    private:
        Screen screen_;
};

#endif
