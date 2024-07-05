#include "defines.h"
#include "tilemap.h"
#pragma once

class Weapon
{
private:
    /* data */
public:
//tilemap
    Tilemap *tilemap;
//hitbox    
    int reachUp;
    int reachDown;
    int reachForward;
    int reachBackward;
    bool isFlipped = false;
//inherits animated class functions
    void Flip();
    Weapon(unsigned char currentTileMap[], gfx_sprite_t **tilesetTiles, uint8_t tileType, uint8_t tileWidth, uint8_t tileHeight, uint8_t drawWidth, uint8_t drawHeight, uint8_t tilemapHeight, uint16_t tilemapWidth, uint8_t xOffset, uint8_t yOffset, int tilesetId, int tilemapId, int ReachUp, int ReachDown, int ReachForward, int ReachBackward);
    ~Weapon();
};


