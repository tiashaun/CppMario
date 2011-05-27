#ifndef GAME
#define GAME

#include <map>
#include <boost/weak_ptr.hpp>
#include <boost/shared_ptr.hpp>
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
        typedef std::map< ModeID, boost::shared_ptr<Mode> > ModeMap;

        ModeMap               modes_;
        boost::weak_ptr<Mode> currentMode_;
        bool                  done_;
};

#endif
