#include "resources.hpp"
#include "SDL/SDL_image.h"
#include <boost/foreach.hpp>
#include <boost/lexical_cast.hpp>

#include <iostream>

#define foreach BOOST_FOREACH
#define reverse_foreach BOOST_REVERSE_FOREACH

using namespace std;
using namespace boost;

Resources::XMLLoadException::XMLLoadException (string file) :
    file_ (file) {}

Resources::XMLLoadException::~XMLLoadException () throw () {}

const char* Resources::XMLLoadException::what ()
{
    return ("Failed to load XML file " + this->file_).c_str();
}

Surface Resources::loadImage (string dir, string file)
{
    SDL_Surface* loadedImage    = NULL;
    SDL_Surface* optimizedImage = NULL;
    
    loadedImage = IMG_Load(this->absolute(dir, file).c_str());
    
    if ( loadedImage != NULL )
    {
        optimizedImage = SDL_DisplayFormat(loadedImage);

        SDL_FreeSurface(loadedImage);
    }
    
    return Surface(optimizedImage);
}

Resources::XMLDoc Resources::loadXML (string dir, string name)
{
    Resources::XMLDoc doc(new pugi::xml_document);

    if ( not doc->load_file(this->absolute(dir, name).c_str()) )
    {
        throw Resources::XMLLoadException(dir + "/" + name);
    }

    return doc;
}

Map Resources::loadMap (string name)
{
    typedef pugi::xml_node          XML;
    typedef pugi::xml_node_iterator Iterator;

    Resources::XMLDoc xml = this->loadXML("maps", name);
    Map::LayerList    layers;
    Map::TilesetList  tilesets;
    
    XML mapXml = xml->child("map");
    
    for ( Iterator it = mapXml.begin(); it != mapXml.end(); ++it )
    {
        if ( it->name() == string("tileset") )
        {
            int initialID = lexical_cast<int>(it->attribute("firstgid").value());
            int tileWidth = lexical_cast<int>(it->attribute("tilewidth").value());
            int tileHeight = lexical_cast<int>(it->attribute("tileheight").value());

            XML imageXml = it->child("image");

            string imagePath = imageXml.attribute("source").value();
            string imageTrans = imageXml.attribute("trans").value();

            Surface image = this->loadImage("img", this->baseName(imagePath));
            
            int transR = this->fromHex(imageTrans.substr(0, 2));
            int transG = this->fromHex(imageTrans.substr(2, 2));
            int transB = this->fromHex(imageTrans.substr(4, 2));
            
            image.setTransparency(transR, transG, transB);
            
            tilesets.push_back(Tileset(image, initialID, tileWidth, tileHeight));
        }
        else if ( it->name() == string("layer") )
        {
            int width  = lexical_cast<int>(it->attribute("width").value());
            int height = lexical_cast<int>(it->attribute("height").value());
            
            int x = 0, y = 0;
            
            Map::TileList layer(height, Map::TileRow(width));

            XML tilesXml = it->child("data");

            for ( Iterator tileIt = tilesXml.begin(); tileIt != tilesXml.end(); ++tileIt )
            {
                layer[y][x] = lexical_cast<int>(tileIt->attribute("gid").value());

                ++x;

                if (x >= width)
                {
                    x = 0;
                    y += 1;
                }
            }
            
            layers.push_back(layer);
        }
    }

    return Map(layers, tilesets);
}

string Resources::absolute (string dir, string name)
{
    return "/home/alec/projects/testgame/bin/resources/" + dir + "/" + name;
}

string Resources::baseName (string path)
{
    int separatorIndex = path.find_last_of('/');

    return path.substr(separatorIndex + 1);
}

int Resources::fromHex (string s)
{
    int multiplier = 1;
    int sum        = 0;

    reverse_foreach ( char c, s )
    {
        int value = 0;

        if ( '0' <= c and c <= '9' )
        {
            value = c - '0';
        }
        else if ( 'a' <= c and c <= 'f' )
        {
            value = 10 + c - 'a';
        }
        else if ( 'A' <= c and c <= 'F' )
        {
            value = 10 + c - 'A';
        }
        else
        {
            value = 0;
        }

        sum        += value * multiplier;
        multiplier *= 16;
    }

    return sum;
}
