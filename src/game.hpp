#ifndef GAME
#define GAME

#include <map>
#include "graphics.hpp"
#include "mode.hpp"

class Game
{
    public:
        Game (ModeID initialMode);

        void begin ();
        void end   ();

        void switchMode (ModeID newMode);

    private:
        typedef std::map<ModeID, Mode*> ModeMap;

        ModeMap  modes;
        Mode*    currentMode;
        bool     done;
};

#endif
