#ifndef SURFACE
#define SURFACE

#include "SDL/SDL.h"
#include "graphics.hpp"
#include <boost/shared_ptr.hpp>
#include "baseSurface.hpp"

class Surface
{
    public:
        Surface (SDL_Surface* sdlSurface = NULL);
        Surface (int width, int height);
        
        void setTransparency (int r, int g, int b);

        void draw (Graphics::Screen screen);
        void draw (Surface target);

        void setDims   (int width, int height);
        void setSource (int x, int y);
        void setDest   (int x, int y);

        int baseWidth  ();
        int baseHeight ();
    
    protected:
        typedef boost::shared_ptr<BaseSurface> BasePtr;

        BasePtr base ();

    private:
        typedef boost::shared_ptr<SDL_Rect> RectPtr;

        BasePtr  surface_;
        RectPtr  dest_, src_;
        SDL_Rect baseDims_;

        void prepareSrc  ();
        void prepareDest ();
};

#endif

