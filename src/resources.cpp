#include "resources.hpp"
#include "SDL/SDL_image.h"

using namespace std;

Surface Resources::loadImage (string file)
{
    SDL_Surface* loadedImage    = NULL;
    SDL_Surface* optimizedImage = NULL;
    
    loadedImage = IMG_Load(this->absolute("img", file).c_str());
    
    if ( loadedImage != NULL )
    {
        optimizedImage = SDL_DisplayFormat(loadedImage);

        SDL_FreeSurface(loadedImage);
    }
    
    return Surface(optimizedImage);
}

string Resources::absolute (string dir, string name)
{
    return "/home/alec/projects/testgame/bin/resources/" + dir + "/" + name;
}
