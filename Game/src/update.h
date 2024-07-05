#include "defines.h"
#include "player.h"
#include "enemy.h"
#include "tilemap.h"
#include "vector/vector.h"
#include "menu.h"
#include "weapon.h"

void drawEnemyIndicators(
    Player *player
    , Vector<Enemy> enemies
    );

void updateAll(
    Tilemap *snowLevel_1
    , Player *player
    // , Weapon *Sword
    // , Vector<Enemy> enemies
    );

void menuUpdate(Menu *currentMenu);