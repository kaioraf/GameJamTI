#include "update.h"

void drawEnemyIndicators(Player *player, Vector<Enemy> enemies)
{
    int l = enemies.size();
    for (int i = 0; i < l; i++)
    {
        if (enemies.at(i).isSpriteOffscreen())
        {
            player->drawSpriteIndicator(&enemies.at(i));
        }
    }
}

void updateAll(Tilemap *currentLevel, Player *player/* , Weapon *weapon, Vector<Enemy> enemies */)
{
    currentLevel->update();
    // int l = enemies.size();
    // for (int i = 0; i < l; i++)
    //     enemies.at(i).update(player, currentLevel);
    player->update();
    // drawEnemyIndicators(player, enemies); // TODO fast sine cos atan functions

    // weapon->tilemap->Animate();
    // if (weapon->tilemap->isMoving)
    // {
    //     //hit test
    //     for (int i = 0; i < enemies.size(); i++)
    //     {
    //         if (enemies.at(i).TouchingWeapon(weapon))
    //         {
    //             player->score++;
    //             enemies.at(i).Respawn(currentLevel);
    //         }
    //     }
    //     //move
    //     if (player->isFlipped)
    //     {
    //         weapon->tilemap->tilemap.x_loc = player->x - 20;
    //     }
    //     else
    //     {
    //         weapon->tilemap->tilemap.x_loc = player->x + 9;
    //     }
    //     weapon->tilemap->tilemap.y_loc = player->y - 11;
    //     gfx_TransparentTilemap(&weapon->tilemap->tilemap, weapon->tilemap->x, weapon->tilemap->y);
    // }
    gfx_SwapDraw();
}

void menuUpdate(Menu *currentMenu)
{
    currentMenu->draw();
    gfx_SwapDraw();
}