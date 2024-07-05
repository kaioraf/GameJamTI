#include <defines.h>
#include "menu.h"
#include "player.h"
#include "enemy.h"
#include "tilemap.h"
#include "gameRunner.h"
#include "vector/vector.h"
#include "weapon.h"
// initialise classes
// run game seperate file
// handle game shutdown

void GraphxSetup()
{
    gfx_Begin();
    gfx_SetClipRegion(0, 16, 320, 240);
    /* Set the palette */
    gfx_SetPalette(global_palette, sizeof_global_palette, 0);
    // gfx_SetColor(64);
    // gfx_SetTextFGColor(1);
    // gfx_SetTextBGColor(0);

    /* Draw to buffer to avoid tearing */
    gfx_SetDrawBuffer();
    return;
}

int main()
{
    GraphxSetup();
    // decompress(snowSet1_tiles, snowSet1_tiles_compressed, 16, 16);
    // decompress(GUI_tiles, GUI_tiles_compressed, 16, 16);
    // decompress(SwordMap_tiles, SwordMap_tiles_compressed, 27, 27);
    // decompress(SwordSet2_tiles, SwordSet2_tiles_compressed, 25, 38);
    Tilemap *snowLevel_1 = new Tilemap(snowLevel_1_map, snowSet1_tiles, gfx_tile_16_pixel, TILE_WIDTH, TILE_HEIGHT, snowLevel1_DRAW_WIDTH, snowLevel1_DRAW_HEIGHT, snowLevel1_HEIGHT, snowLevel1_WIDTH, snowLevel1_X_OFFSET, snowLevel1_Y_OFFSET, 0, 0);
    Vector<Tilemap*> levels(0);
    levels.pushBack(snowLevel_2);
    levels.pushBack(snowLevel_1);
    Player *player = new Player(PlayerSprite, PLAYER_START_X, PLAYER_START_Y, PlayerSprite_width, PlayerSprite_height);
    Weapon *sword = new Weapon(sword_map, SwordMap_tiles, gfx_tile_no_pow2, swordTile_WIDTH, swordTile_HEIGHT, sword_DRAW_HEIGHT, sword_DRAW_WIDTH, sword_HEIGHT, sword_WIDTH, sword_X_OFFSET, sword_Y_OFFSET, 0, 0, 16, 0, TILE_WIDTH, 0);
    Tilemap *mainMenuTilemap = new Tilemap(mainMenu_map, GUI_tiles, gfx_tile_16_pixel, TILE_HEIGHT, TILE_WIDTH, mainMenu_DRAW_WIDTH, mainMenu_DRAW_HEIGHT, mainMenu_HEIGHT, mainMenu_WIDTH, mainMenu_X_OFFSET, mainMenu_Y_OFFSET, 0, 0);
    Tilemap *optionsMenuTilemap = new Tilemap(mainMenu_map, GUI_tiles, gfx_tile_16_pixel, TILE_WIDTH, TILE_HEIGHT, mainMenu_DRAW_WIDTH, mainMenu_DRAW_HEIGHT, mainMenu_HEIGHT, mainMenu_WIDTH, optionsMenu_X_OFFSET, optionsMenu_Y_OFFSET, 0, 0);
    menuItem *menuContinue = new menuItem(0, "Continue");
    menuItem *menuOptions = new menuItem(1, "Options");
    menuItem *menuClosegame = new menuItem(2, "Close game");
    menuItem *menuWinText = new menuItem(-1, "You Win!");
    menuItem *menuGameoverText = new menuItem(-1, "You Lose!");


    int mainMenuSize = 3;
    menuItem *mainMenuItems[3] = {menuContinue, menuOptions, menuClosegame};
    int mainMenuSelectedItem = 1;
    Menu *mainMenu = new Menu(mainMenuTilemap, mainMenuSize, mainMenuItems, mainMenuSelectedItem);

    int optionsMenuSize = 1;
    menuItem *optionsMenuItems[1] = {menuContinue};
    int optionsSelectedItem = 1;
    Menu *optionsMenu = new Menu(optionsMenuTilemap, optionsMenuSize, optionsMenuItems, optionsSelectedItem);

    int gameOverSize = 2;
    menuItem *gameOverItems[2] = {menuGameoverText, menuClosegame};
    int gameOverSelectedItem = 1;
    Menu *gameOverMenu = new Menu(optionsMenuTilemap, gameOverSize, gameOverItems, gameOverSelectedItem);

    int winMenuSize = 2;
    menuItem *winMenuItems[2] = {menuWinText, menuClosegame};
    int winMenuSelectedItem = 1;
    Menu *winMenu = new Menu(optionsMenuTilemap, winMenuSize, winMenuItems, winMenuSelectedItem);

    int startXLocation = (rand() % levels.at(0)->tilemap.width) * TILE_WIDTH;
    int startYLocation = (rand() % levels.at(0)->tilemap.height) * TILE_HEIGHT;
    Enemy *Knight = new Enemy(knightEnemy, startXLocation, startYLocation, knightEnemy_width, knightEnemy_height, clock(), false);
    startXLocation = (rand() % levels.at(0)->tilemap.width) * TILE_WIDTH;
    startYLocation = (rand() % levels.at(0)->tilemap.height) * TILE_HEIGHT;
    Enemy *Knight2 = new Enemy(knight2, startXLocation, startYLocation, knightEnemy_width, knightEnemy_height, clock(), false);
    Vector<Enemy> enemies(0);
    enemies.pushBack(*Knight);
    enemies.pushBack(*Knight2);
    runGame(
            player
            , levels
            , sword
            , enemies
            , mainMenu
            , optionsMenu
            , gameOverMenu
            , winMenu
            );
    delete player;
    delete snowLevel_1;
    delete snowLevel_2;
    delete sword;
    delete Knight;
    delete mainMenuTilemap;
    delete optionsMenuTilemap;
    delete menuContinue;
    delete menuClosegame;
    delete menuOptions;
    delete mainMenu;
    delete optionsMenu;
    delete gameOverMenu;
    delete winMenu;
    gfx_End();
    return 0;
}
