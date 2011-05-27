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
    Surface    image     = resources.loadImage("test.jpg");
    
    image.setDims(10, 10);
    image.setSource(50, 50);
    image.setDest(50, 50);
        
    image.draw(graphics.screen());
    graphics.flip();
    SDL_Delay(1000);

    this->game_.end();
}

