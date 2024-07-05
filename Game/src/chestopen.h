#include "defines.h"
#include "player.h"
#include "vector/vector.h"
#include "tilemap.h"
#include "weapon.h"
#define chestTile 54
#define Sl1chestMapPos 847
#define Sl2chestMapPos 516

void openChest(int tilemapID, Tilemap* currrentTilemap);
bool shouldChestOpen(Tilemap *currentTilemap, Player *player, kb_key_t controlButtons);