#include "graphics.hpp"

Graphics::Graphics ()
{
    SDL_Init(SDL_INIT_VIDEO);

    this->screen = SDL_SetVideoMode(640, 480, 32, SDL_SWSURFACE);
}

void Graphics::flip ()
{
    SDL_Flip(this->screen);
}
