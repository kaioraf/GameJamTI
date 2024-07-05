#include "chestopen.h"

void openChest(int tilemapID, Tilemap *currrentTilemap)
{
    switch (tilemapID)
    {
    case 0:
        currrentTilemap->tilemap.map[Sl1chestMapPos] = 34;
        currrentTilemap->tilemap.map[Sl1chestMapPos - currrentTilemap->tilemap.width] = 14;
        break;
    case 1:
        currrentTilemap->tilemap.map[Sl2chestMapPos] = 34;
        currrentTilemap->tilemap.map[Sl2chestMapPos - currrentTilemap->tilemap.width] = 14;
    default:
        break;
    }
}

bool shouldChestOpen(Tilemap *currentTilemap, Player *player, kb_key_t controlButtons)
{
    if (controlButtons & kb_Del)
    {
        int tilemapID = currentTilemap->tilemapID;
        switch (tilemapID)
        {
        case 0:
            if (player->x == snowLevel1ChestLocationX && player->y - TILE_HEIGHT == snowLevel1ChestLocationY)
            {
                return true;
            }
            break;
        case 1:
            if (player->x == snowLevel2ChestLocationX && player->y - TILE_HEIGHT == snowLevel2ChestLocationY)
            {
                return true;
            }
            break;
        default:
            break;
        }
    }
    return false;
}