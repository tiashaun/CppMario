#include "game.hpp"
#include "graphics.hpp"
#include "mainMenuMode.hpp"

int main ()
{
    Graphics graphics;
    Game     game (MainMenuMode::id);

    game.begin();

    return 0;
}
