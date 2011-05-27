#ifndef RESOURCES
#define RESOURCES

#include <string>
#include "SDL/SDL.h"

class Resources
{
    public:
        SDL_Surface* loadImage (std::string file);

    private:
        std::string absolute (std::string dir, std::string file);
};

#endif
