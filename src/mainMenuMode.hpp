#ifndef MAIN_MENU_MODE
#define MAIN_MENU_MODE

#include "mode.hpp"

class MainMenuMode : public Mode
{
    public:
        enum { id = 0 };
        
        MainMenuMode (Game& game);

        void doFrame ();
};

#endif

