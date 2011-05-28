#ifndef TILESET
#define TILESET

#include "surface.hpp"

struct Tileset
{
    Surface surface;
    int     initialID;
    int     tileWidth, tileHeight;

    Tileset ();
    Tileset (Surface surface, int initialID, int tileWidth, int tileHeight);
};

#endif
