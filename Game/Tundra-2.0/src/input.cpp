#include "input.h"

bool tilemapShouldMove(char direction, Tilemap *currentLevel, Player *Player)
{
    bool playerCentred;
    int tilemapLimit;
    // jump speed
    // movement speed
    // fall speed / gravity

    switch (direction)
    {
        case 'd': // up jump
            playerCentred = PLAYER_START_Y == Player->y;
            if (!playerCentred) return false;
            tilemapLimit = (currentLevel->tilemap.height * TILE_HEIGHT) - ((currentLevel->tilemap.draw_height - 1) * TILE_HEIGHT);
            break;
        case 'u': // down gravity
            playerCentred = PLAYER_START_Y == Player->y;
            if (!playerCentred) return false;
            tilemapLimit = 0;
            break;
        case 'r':
            playerCentred = PLAYER_START_X == Player->x;
            if (!playerCentred) return false;
            tilemapLimit = (currentLevel->tilemap.width * TILE_WIDTH) - ((currentLevel->tilemap.draw_width - 1) * TILE_WIDTH);
            break;
        case 'l':
            playerCentred = PLAYER_START_X == Player->x;
            if (!playerCentred) return false;
            tilemapLimit = 0;
            break;
        default:
            break;
    }

    if (direction == 'd' && currentLevel->y < tilemapLimit)
    {
        return true;
    }
    else if (direction == 'u' && currentLevel->y > tilemapLimit)
    {
        return true;
    }
    else if (direction == 'r' && currentLevel->x < tilemapLimit)
    {
        return true;
    }
    else if (direction == 'l' && currentLevel->x > tilemapLimit)
    {
        return true;
    }
    return false;
}

void weaponInput(kb_key_t controlButtons, Weapon *sword)
{
    if (controlButtons && !sword->tilemap->isMoving)
    {
        if (controlButtons & kb_2nd)
        {
            sword->tilemap->x = 0;
            sword->tilemap->destX = sword->tilemap->tilemap.tile_width * (sword->tilemap->tilemap.width - 1);
        }
        else
        {
            return;
        }
    }
}

void movementInput(kb_key_t arrows, Tilemap *currentLevel, Player *Player, Vector<Enemy> enemies, Weapon *sword) // arrows declared in setup
{
    bool animatingTilemap = false;
    int tileToWalkTo;
    int movementX, movementY;
    if (arrows && !currentLevel->isMoving && !Player->isMoving)
    {
        if (arrows & kb_Up) // 2nd instead of kb_up
        {
            player.jumpAccel = 10;

            // tileToWalkTo = currentLevel->ConvertPosition(Player->x + movementX, Player->y + movementY);
            // if (!currentLevel->isWalkable(tileToWalkTo)) return;
            // animatingTilemap = tilemapShouldMove('u', currentLevel, Player);
        }
        if (arrows & kb_Right)
        {
            if (Player->isFlipped)
            {
                Player->FlipSprite();
                sword->Flip();
            }

            movement = player.movementSpeed;

            tileToWalkTo = currentLevel->ConvertPosition(Player->x + movementX, Player->y + 0);
            if (!currentLevel->isWalkable(tileToWalkTo)) return;
            animatingTilemap = tilemapShouldMove('r', currentLevel, Player);
        }
        else if (arrows & kb_Left)
        {
            if (!Player->isFlipped)
            {
                Player->FlipSprite();
                sword->Flip();
            }
            movementX = -player.movementSpeed;

            tileToWalkTo = currentLevel->ConvertPosition(Player->x + movementX, Player->y + 0);
            if (!currentLevel->isWalkable(tileToWalkTo)) return;
            animatingTilemap = tilemapShouldMove('l', currentLevel, Player);
        }
        if (animatingTilemap)
        {
            for (int i = 0; i < enemies.size(); i++)
            {
                enemies.at(i).MoveDestination(-movementX, -movementY);
            }
            currentLevel->MoveDestination(movementX, movementY);
        }
        else
        {
            Player->MoveDestination(movementX, movementY);
        }
    }
}

int menuInput(Menu *currentMenu)
{
    uint8_t key = os_GetCSC();

    switch (key)
    {
    case sk_Down:
        if (currentMenu->selectedItem < currentMenu->amountOfOptions)
        {
            currentMenu->selectedItem++; // move down the menu
        }
        break;
    case sk_Up:
        if (currentMenu->selectedItem > 1)
        {
            currentMenu->selectedItem--; // move up the menu
        }
        break;
    case sk_2nd:
        return currentMenu->items[currentMenu->selectedItem - 1]->id;
        break;
    case sk_Mode:
        return 0; // toggle menu state
        break;
    default:
        break;
    }
    return -1;//do nothing
}


