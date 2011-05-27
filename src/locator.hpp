#ifndef LOCATOR
#define LOCATOR

#include "graphics.hpp"
#include "resources.hpp"

class Locator
{
    public:
        static void init ();

        static void setGraphics  (Graphics& graphics);
        static void setResources (Resources& resources);

        static Graphics&  getGraphics ();
        static Resources& getResources ();

    private:
        static Graphics*  graphics;
        static Resources* resources;
};

#endif

