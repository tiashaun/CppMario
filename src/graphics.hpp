#ifndef GRAPHICS
#define GRAPHICS

#include "SDL/SDL.h"

class Graphics
{
    public:
        typedef SDL_Surface* Screen;

        Graphics  ();

        void flip ();

        Screen screen ();

    private:
        Screen screen_;
};

#endif
