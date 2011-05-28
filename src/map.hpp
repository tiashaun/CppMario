#ifndef MAP
#define MAP

#include <boost/multi_array.hpp>
#include "tileset.hpp"

class Map
{
    public:
        typedef int                   TileID;
        typedef std::vector<TileID>   TileRow; 
        typedef std::vector<TileRow>  TileList;
        typedef std::vector<TileList> LayerList;
        typedef std::vector<Tileset>  TilesetList;

        Map (const LayerList& layers, const TilesetList& tilesets);
        
        void draw (Graphics::Screen screen);
    private:
        LayerList   layers_;
        TilesetList tilesets_;
        Surface     surface_;
        bool        updated_;

        void    updateSurface ();
        Surface getTile       (TileID tile, int x, int y);
};

#endif
