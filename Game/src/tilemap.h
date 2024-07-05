#include "defines.h"
#include "animated.h"
#include "iswalkable.h"
#pragma once

class Tilemap : public Animated
{
public:
    gfx_tilemap_t tilemap;
    Tilemap(unsigned char currentTileMap[], gfx_sprite_t **tilesetTiles, uint8_t tileType, uint8_t tileWidth, uint8_t tileHeight, uint8_t drawWidth, uint8_t drawHeight, uint8_t tilemapHeight, uint16_t tilemapWidth, uint8_t xOffset, uint8_t yOffset, int tilesetId, int tilemapId);
    int tilesetID;
    int tilemapID;
    bool isWalkable(int tileID);
    bool kills(int tileID);
    int ConvertPosition(int x, int y);
    void update();
    bool collisionDown(int posx, int posy);
    ~Tilemap();
};
