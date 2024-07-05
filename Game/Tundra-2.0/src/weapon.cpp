#include "weapon.h"

Weapon::Weapon(unsigned char currentTileMap[], gfx_sprite_t **tilesetTiles, uint8_t tileType, uint8_t tileWidth, uint8_t tileHeight, uint8_t drawWidth, uint8_t drawHeight, uint8_t tilemapHeight, uint16_t tilemapWidth, uint8_t xOffset, uint8_t yOffset, int tilesetId, int tilemapId, int ReachUp, int ReachDown, int ReachForward, int ReachBackward)
{
    tilemap = new Tilemap(currentTileMap, tilesetTiles, tileType, tileWidth, tileHeight, drawWidth, drawHeight, tilemapHeight, tilemapWidth, xOffset, yOffset, 0, 0);
    tilemap->animationSteps = tileWidth;
    reachUp = ReachUp;
    reachDown = ReachDown;
    reachForward = ReachForward;
    reachBackward =ReachBackward;
}

void Weapon::Flip()
{
    isFlipped = !isFlipped;
    if (isFlipped)
    {
        tilemap->y = tilemap->destY = tilemap->tilemap.tile_height;
    }
    else
    {
        tilemap->y = tilemap->destY = 0;
    }
}


Weapon::~Weapon()
{
    delete tilemap;
}