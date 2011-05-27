#include "platformerMode.hpp"
#include <iostream>
#include "game.hpp"

using namespace std;

PlatformerMode::PlatformerMode (Game& game) :
    Mode (game) {}

void PlatformerMode::doFrame ()
{
    
    cout << "Platformer." << endl;

    this->game.end();
}

