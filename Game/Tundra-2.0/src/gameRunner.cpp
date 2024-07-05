#include "gameRunner.h"

void DrawStatusText(Player *player, clock_t timeSincelastUpdate)
{
    gfx_SetColor(0);
    gfx_SetTextBGColor(0);
    gfx_FillRectangle(0, 0, 320, 16);
    gfx_PrintStringXY("Score: ", 8, 4);
    gfx_PrintInt(player->score, 3);
    gfx_PrintString(" -- ");
    gfx_PrintInt(CLOCKS_PER_SEC / timeSincelastUpdate, 3);
    gfx_PrintString(" Fps");
    gfx_PrintString(" -- Press mode for menu");
}

void runMenu(
    Player *player
    , Menu *currentMenu
    , Menu *winMenu
    , Menu * mainMenu
    , Menu *gameOverMenu
    , Menu *optionsMenu
    , bool *menuOpen
    , bool *stopGame
    )
{
    if (player->isDead)
    {
        currentMenu = gameOverMenu;
        *menuOpen = true;
        gfx_BlitBuffer();
    }
    if (player->hasWon)
    {
        currentMenu = winMenu;
        *menuOpen = true;
        gfx_BlitBuffer();
    }
    if (os_GetCSC() == sk_Mode)
    {
        *menuOpen = true;
        currentMenu = mainMenu;
        gfx_BlitBuffer();
    }
    while (*menuOpen)
    {
        switch (menuInput(currentMenu))
        {
        case 0:
            if (player->isDead || player->hasWon) // don't exit gameover menu
            {
                break;
            }
            *menuOpen = false;
            break;
        case 1:
            currentMenu = optionsMenu;
            break;
        case 2:
            *stopGame = true;
            *menuOpen = false;
            break;
        default:
            break;
        }
        menuUpdate(currentMenu);
    }
}

void runGame(
    Player *player
    , Vector<Tilemap *> levels
    , Weapon *Sword
    , Vector<Enemy> enemies
    , Menu *mainMenu
    , Menu *optionsMenu
    , Menu *gameOverMenu
    , Menu *winMenu
    )
{
    clock_t clockTime = clock();
    clock_t lastUpdate = 0;
    clock_t timeSinceLastUpdate;
    srand(time(NULL));
    rand();
    bool stopGame = false;
    bool menuOpen = false;
    kb_key_t arrows;
    kb_key_t controlButtons;
    Menu *currentMenu;
    currentMenu = mainMenu;
    int levelIndex = 0;
    int amountOfLevels = levels.size();
    Tilemap *currentLevel = levels.at(levelIndex);
    Weapon *currentWeapon = Sword;
    bool hasChestLoot = false;
    do
    {
        clockTime = clock();
        timeSinceLastUpdate = clockTime - lastUpdate;

        kb_Scan();
        arrows = kb_Data[7];
        controlButtons = kb_Data[1];
        // currentTile = ConvertSpritePosition(snowLevel_1, player->x, player->y);

        if (timeSinceLastUpdate > 1092) // update 30 times per second
        {
            movementInput(arrows, currentLevel, player, enemies, currentWeapon);
            weaponInput(controlButtons, currentWeapon);
            updateAll(currentLevel, player, currentWeapon, enemies);
            if (shouldChestOpen(currentLevel, player, controlButtons) && !hasChestLoot)
            {
                delete Sword;
                dbg_printf("deleted ");
                currentWeapon = new Weapon(sword_2_map, SwordSet2_tiles, gfx_tile_no_pow2, sword2Tile_WIDTH, sword2Tile_HEIGHT, sword_DRAW_HEIGHT, sword_DRAW_WIDTH, sword2_HEIGHT, sword2_WIDTH, sword_X_OFFSET, sword_Y_OFFSET, 0, 0, sword2Tile_HEIGHT/2, swordTile_HEIGHT/2, TILE_WIDTH, 0);
                currentWeapon->Flip();
                openChest(currentLevel->tilemapID, currentLevel);
                hasChestLoot = true;
            }
            DrawStatusText(player, timeSinceLastUpdate);
            // dbg_printf("%i \n", CLOCKS_PER_SEC / timeSinceLastUpdate); //fps debug print
            lastUpdate = clockTime;
            if (shouldLevelSwitch(levelIndex, currentLevel, player))
            {
                dbg_printf("index %i  zize %i \n", levelIndex, amountOfLevels);
                if (levelIndex == amountOfLevels - 1)
                {
                    player->hasWon = true;
                    delete currentWeapon;
                }
                else
                {
                    levelIndex++;
                    currentLevel = levels.at(levelIndex);
                    for (int i = 0; i < enemies.size(); i++)
                        enemies.at(i).Respawn(currentLevel);
                    player->x = player->destX = PLAYER_START_X;
                    player->y = player->destY = PLAYER_START_Y;
                }
            }
            runMenu(player, currentMenu, winMenu, mainMenu, gameOverMenu, optionsMenu, &menuOpen, &stopGame);
            
        }
    } while (!stopGame);
    return;
}
