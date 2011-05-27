#ifndef PLATFORMER_MODE
#define PLATFORMER_MODE

#include "mode.hpp"

class PlatformerMode : public Mode
{
    public:
        enum { id = 1 };

        PlatformerMode (Game& game);

        void doFrame ();
};

#endif

