#include "game.hpp"
#include "mainMenuMode.hpp"
#include "platformerMode.hpp"

using namespace std;

Game::Game (ModeID initialModeID) :
    currentMode (NULL), done (false)
{
    this->modes[MainMenuMode  ::id] = new MainMenuMode(*this);
    this->modes[PlatformerMode::id] = new PlatformerMode(*this);

    this->currentMode = this->modes[initialModeID];
}


void Game::begin ()
{
    while ( not this->done and this->currentMode != NULL )
    {
        this->currentMode->doFrame();
    }
}

void Game::end ()
{
    this->done = true;
}

void Game::switchMode (ModeID newMode)
{
    this->currentMode = this->modes[newMode];
}

