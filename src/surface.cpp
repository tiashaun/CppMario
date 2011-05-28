#include "surface.hpp"

Surface::Surface (SDL_Surface* sdlSurface)
    : surface_ (Surface::BasePtr(new BaseSurface(sdlSurface)))
{
    SDL_GetClipRect(sdlSurface, &this->baseDims_);
}

Surface::Surface (int width, int height)
    : surface_ (Surface::BasePtr(new BaseSurface(SDL_CreateRGBSurface(
        SDL_SWSURFACE,
        width,
        height,
        Graphics::SCREEN_BPP,
        0, 0, 0, 0
    ))))
{
    this->baseDims_.w = width;
    this->baseDims_.h = height;
}

void Surface::setTransparency (int r, int g, int b)
{
    Uint32 colorKey = SDL_MapRGB(this->surface_->surface->format, r, g, b);

    SDL_SetColorKey(this->surface_->surface, SDL_SRCCOLORKEY, colorKey);
}

void Surface::draw (Graphics::Screen screen)
{
    SDL_Surface* surface = this->surface_->surface;
    
    if ( surface == NULL )
    {
        return;
    }

    SDL_BlitSurface(surface, this->src_.get(), screen, this->dest_.get());
}

void Surface::draw (Surface target)
{
    this->draw(target.base()->surface);
}

void Surface::setDims (int width, int height)
{
    this->prepareSrc();

    this->src_->w = width;
    this->src_->h = height;
}

void Surface::setSource (int x, int y)
{
    this->prepareSrc();

    this->src_->x = x;
    this->src_->y = y;
}

void Surface::setDest (int x, int y)
{
    this->prepareDest();

    this->dest_->x = x;
    this->dest_->y = y;
}

int Surface::baseWidth ()
{
    return this->baseDims_.w;
}

int Surface::baseHeight ()
{
    return this->baseDims_.h;
}

Surface::BasePtr Surface::base ()
{
    return this->surface_;
}

void Surface::prepareSrc ()
{
    if ( this->src_ == NULL )
    {
        this->src_.reset(new SDL_Rect());
    }
}

void Surface::prepareDest ()
{
    if ( this->dest_ == NULL )
    {
        this->dest_.reset(new SDL_Rect());
    }
}


