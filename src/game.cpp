#include "game.hpp"
#include "mainMenuMode.hpp"
#include "platformerMode.hpp"

using namespace std;
using namespace boost;

Game::Game (ModeID initialModeID) :
    done_ (false)
{
    this->modes_[MainMenuMode::id]   = shared_ptr<Mode>(new MainMenuMode(*this));
    this->modes_[PlatformerMode::id] = shared_ptr<Mode>(new PlatformerMode(*this));

    this->currentMode_ = weak_ptr<Mode>(this->modes_[initialModeID]);
}


void Game::begin ()
{
    while ( not this->done_ )
    {
        this->currentMode_.lock()->doFrame();
    }
}

void Game::end ()
{
    this->done_ = true;
}

void Game::switchMode (ModeID newMode)
{
    this->currentMode_ = weak_ptr<Mode>(this->modes_.at(newMode));
}

