#include "defines.h"
#include "sprite.h"
#include "player.h"
#include "tilemap.h"
#include "weapon.h"
#pragma once

class Enemy : public Sprite
{
private:
    /* data */
public:
    bool isDead;
    Enemy() = default;
    Enemy(gfx_sprite_t *Foreground, int startX, int startY, int spriteWidth, int spriteHeight, clock_t TimeAtCreation, bool IsDead);
    bool TimeAliveGreaterThan(unsigned int time);
    bool TouchingWeapon(Weapon *weapon);
    void Respawn(Tilemap *snowLevel_1);
    void Move(Tilemap *snowLevel_1);
    void update(Player *player, Tilemap *CurrentTilemap);
    ~Enemy();
};
