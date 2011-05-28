#ifndef RESOURCES
#define RESOURCES

#include <string>
#include <boost/shared_ptr.hpp>
#include "SDL/SDL.h"
#include "surface.hpp"
#include "map.hpp"
#include "pugixml/src/pugixml.hpp"

class Resources
{
    public:
        class XMLLoadException : public std::exception
        {
            public:
                XMLLoadException (std::string file);
                ~XMLLoadException () throw ();

                const char* what ();

            private:
                std::string file_;
        };

        typedef boost::shared_ptr<pugi::xml_document> XMLDoc;

        Surface loadImage (std::string dir, std::string file);
        XMLDoc  loadXML   (std::string dir, std::string file);

        Map     loadMap   (std::string name);

    private:
        std::string absolute (std::string dir, std::string name);
        std::string baseName (std::string path);
        int         fromHex  (std::string s);
};

#endif
