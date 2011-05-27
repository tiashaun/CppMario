#include "mainMenuMode.hpp"
#include <iostream>
#include "game.hpp"
#include "platformerMode.hpp"

using namespace std;

MainMenuMode::MainMenuMode (Game& game) :
    Mode (game) {}

void MainMenuMode::doFrame ()
{
    cout << "Main menu." << endl;

    this->game.switchMode(PlatformerMode::id);
}
