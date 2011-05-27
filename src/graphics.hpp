#ifndef GRAPHICS
#define GRAPHICS

#include "SDL/SDL.h"

class Graphics
{
    public:
        Graphics ();

        void flip ();

    private:
        SDL_Surface* screen;
};

#endif
