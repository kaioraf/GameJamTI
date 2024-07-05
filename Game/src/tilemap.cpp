#include "tilemap.h"

Tilemap::Tilemap(unsigned char currentTileMap[], gfx_sprite_t **tilesetTiles, uint8_t tileType, uint8_t tileWidth, uint8_t tileHeight, uint8_t drawWidth, uint8_t drawHeight, uint8_t tilemapHeight, uint16_t tilemapWidth, uint8_t xOffset, uint8_t yOffset, int tilesetId, int tilemapId) :
    Animated(0, 0, false)
{
    tilemap.map = currentTileMap;
    tilemap.tiles = tilesetTiles;
    tilemap.type_width = tileType;
    tilemap.type_height = tileType;
    tilemap.tile_height = tileHeight;
    tilemap.tile_width = tileWidth;
    tilemap.draw_height = drawHeight; 
    tilemap.draw_width = drawWidth;
    tilemap.height = tilemapHeight;
    tilemap.width = tilemapWidth;
    tilemap.x_loc = xOffset;
    tilemap.y_loc = yOffset;
    tilesetID = tilesetId;
    tilemapID = tilemapId;
}

//gets the tile id of given x and y positions with tilemap x and y offsets
int Tilemap::ConvertPosition(int x, int y)
{
    int tileAtSpritePos = gfx_GetTile(&this->tilemap, this->x + x - dungeonmap_X_OFFSET, this->y + y - dungeonmap_Y_OFFSET); 
    return tileAtSpritePos;
}

bool Tilemap::isWalkable(int tileID) //returns based on the iswalkable.h file that has function pointers
{
    bool (*isWalkablePtr[1])(int tileID) = {snowLevel_1isWalkable};
    return (*isWalkablePtr[tilesetID])(tileID);
}

bool Tilemap::collisionDown(int posx, int posy) {
    int tileAtSpritePos = ConvertPosition(posx, posy);
    isWalkable(tileAtSpritePos);
}

// bool Tilemap::kills(int tileID)
// {
//     bool (*killsPtr[1])(int tileID) = {snowLevel_1kills};
//     return (*killsPtr[tilessetID])(tileID);
// } 

void Tilemap::update()
{
    Animate();
    gfx_Tilemap(&tilemap, x, y);
}

Tilemap::~Tilemap()
{
}
