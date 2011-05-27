#ifndef GRAPHICS
#define GRAPHICS

#include "SDL/SDL.h"

class Graphics
{
    public:
        typedef SDL_Surface* Surface;

        Graphics ();

        void flip ();

        Surface screen ();

    private:
        Surface screen_;
};

#endif
