#include "tileset.hpp"

Tileset::Tileset () {}

Tileset::Tileset (Surface surface, int initialID, int tileWidth, int tileHeight) :
    surface (surface), initialID (initialID), tileWidth (tileWidth), tileHeight (tileHeight) {}
