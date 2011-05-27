#ifndef RESOURCES
#define RESOURCES

#include <string>
#include "SDL/SDL.h"
#include "surface.hpp"

class Resources
{
    public:
        Surface loadImage (std::string file);

    private:
        std::string absolute (std::string dir, std::string file);
};

#endif
