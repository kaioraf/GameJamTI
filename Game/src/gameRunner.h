#include "defines.h"
#include "menu.h"
#include "player.h"
#include "enemy.h"
#include "update.h"
#include "input.h"
#include "vector/vector.h"
#include "levelswitch.h"
#include "weapon.h"

void DrawStatusText(
            Player *player
            , clock_t timeSincelastUpdate
            );

// void runMenu(
//     Player *player
//     , Menu *currentMenu
//     , Menu *winMenu
//     , Menu * mainMenu
//     , Menu *gameOverMenu
//     , Menu *optionsMenu
//     , bool *menuOpen
//     , bool *stopGame
//     );

void runGame(
            Player *player
            , Vector<Tilemap*> levels
            // , Weapon *Sword
            // , Vector<Enemy> enemies
            // , Menu *mainMenu
            // , Menu *optionsMenu
            // , Menu *gameOverMenu
            // , Menu *winMenu
            );
