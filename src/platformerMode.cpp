#include "platformerMode.hpp"
#include "game.hpp"
#include "locator.hpp"

using namespace std;

PlatformerMode::PlatformerMode (Game& game) :
    Mode (game) {}

void PlatformerMode::doFrame ()
{
    Graphics&         graphics  = Locator::graphics();
    Resources&        resources = Locator::resources();
    Graphics::Surface image     = resources.loadImage("test.jpg");
    
    SDL_BlitSurface(image, NULL, graphics.screen(), NULL);
    graphics.flip();
    SDL_Delay(1000);

    this->game_.end();
}

