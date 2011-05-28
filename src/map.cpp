#include "map.hpp"
#include <boost/foreach.hpp>

#define foreach BOOST_FOREACH
#define reverse_foreach BOOST_REVERSE_FOREACH

Map::Map (const Map::LayerList& layers, const Map::TilesetList& tilesets)
    : layers_ (layers), tilesets_ (tilesets), updated_ (false) {}

void Map::draw (Graphics::Screen screen)
{
    if ( not this->updated_ )
    {
        this->updateSurface();
    }

    this->surface_.draw(screen);
}

void Map::updateSurface ()
{
    this->surface_ = Surface(Graphics::SCREEN_WIDTH, Graphics::SCREEN_HEIGHT);
    
    foreach ( TileList layer, this->layers_ )
    {
        int y = 0;

        foreach ( TileRow row, layer )
        {
            int x = 0;

            foreach ( TileID tile, row )
            {
                Surface tileSurface = this->getTile(tile, x, y);
                
                tileSurface.draw(this->surface_);

                x += 1;
            }

            y += 1;
        }
    }
}

Surface Map::getTile (TileID tile, int x, int y)
{
    reverse_foreach ( Tileset tileset, this->tilesets_ )
    {
        if ( tileset.initialID <= tile )
        {
            TileID  relative = tile - tileset.initialID;
            Surface surface  = tileset.surface;
            int     width    = surface.baseWidth() / tileset.tileWidth;
            
            surface.setDims(tileset.tileWidth, tileset.tileHeight);
            surface.setSource((relative % width) * tileset.tileWidth, (relative / width) * tileset.tileHeight);
            surface.setDest(x * tileset.tileWidth, y * tileset.tileHeight);

            return surface;
        }
    }

    return Surface();
}
