#include "levelswitch.h"

bool shouldLevelSwitch(int levelIndex, Tilemap *currentLevel ,Player *player)
{
    if (currentLevel->ConvertPosition(player->x, player->y) == portalTileID)
    {
        return true;
    }
    return false;
}