#include "graphics.hpp"

Graphics::Graphics ()
{
    SDL_Init(SDL_INIT_VIDEO);

    this->screen_ = SDL_SetVideoMode(
        Graphics::SCREEN_WIDTH,
        Graphics::SCREEN_HEIGHT,
        Graphics::SCREEN_BPP,
        SDL_SWSURFACE
    );
}

void Graphics::flip ()
{
    SDL_Flip(this->screen_);
}

Graphics::Screen Graphics::screen ()
{
    return this->screen_;
}

