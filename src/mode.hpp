#ifndef MODE
#define MODE

class Game;

typedef int ModeID;

class Mode
{
    public:
        Mode (Game& game);

        virtual void doFrame () = 0;

    protected:
        Game& game_;
};

#endif

