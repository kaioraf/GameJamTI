#include "defines.h"
#include "player.h"
#include "tilemap.h"
#include "enemy.h"
#include "vector/vector.h"
#include "menu.h"
#include "weapon.h"

bool tilemapShouldMove(char direction, Tilemap *currentLevel, Player *Player);
void weaponInput(kb_key_t controlButtons, Weapon *sword);
void movementInput(kb_key_t arrows, Tilemap *currentLevel, Player *Player/* , Vector<Enemy> enemies, Weapon *sword */); // arrows declared in setup
int menuInput(Menu *currentMenu);
bool playerDownCollides(int posx, int posy);