#ifndef LOCATOR
#define LOCATOR

#include <boost/scoped_ptr.hpp>
#include "graphics.hpp"
#include "resources.hpp"

class Locator
{
    public:
        static void init ();

        static void setGraphics  (Graphics& graphics);
        static void setResources (Resources& resources);

        static Graphics&  graphics ();
        static Resources& resources ();

    private:
        static boost::scoped_ptr<Graphics>  graphics_;
        static boost::scoped_ptr<Resources> resources_;
};

#endif

