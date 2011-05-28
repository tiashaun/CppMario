#include "platformerMode.hpp"
#include "game.hpp"
#include "locator.hpp"

using namespace std;

PlatformerMode::PlatformerMode (Game& game) :
    Mode (game) {}

void PlatformerMode::doFrame ()
{
    Graphics&  graphics  = Locator::graphics();
    Resources& resources = Locator::resources();
    Map        map       = resources.loadMap("test1.tmx");
    
    map.draw(graphics.screen());
    graphics.flip();
    SDL_Delay(5000);

    this->game_.end();
}

