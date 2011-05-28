#include "baseSurface.hpp"

BaseSurface::BaseSurface (SDL_Surface* surface)
    : surface (surface) {}

BaseSurface::~BaseSurface ()
{
    SDL_FreeSurface(this->surface);
}
