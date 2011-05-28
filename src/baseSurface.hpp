#ifndef BASE_SURFACE
#define BASE_SURFACE

#include "SDL/SDL.h"

struct BaseSurface
{
    SDL_Surface* surface;

    BaseSurface  (SDL_Surface* surface);
    ~BaseSurface ();
};

#endif
