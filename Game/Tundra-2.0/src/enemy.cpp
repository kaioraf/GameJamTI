#include "enemy.h"

Enemy::Enemy(gfx_sprite_t *Foreground, int startX, int startY, int spriteWidth, int spriteHeight, clock_t TimeAtCreation, bool IsDead):
    Sprite(Foreground, startX, startY, spriteWidth, spriteHeight)
{
    // foreground = Foreground;
    timeAtCreation = clock();
    isDead = false;
}

bool Enemy::TimeAliveGreaterThan(unsigned int time)
{
    clock_t timeAlive = clock() - timeAtCreation;
    int secondsAlive = timeAlive / CLOCKS_PER_SEC;
    if (secondsAlive > time)
    {
        return true;
    }
    return false;
}

bool Enemy::TouchingWeapon(Weapon *weapon)
{
    int weaponY = weapon->tilemap->tilemap.y_loc;
    int weaponX = weapon->tilemap->tilemap.x_loc;
    bool weaponYMatches = ((weaponY - weapon->reachUp) <= y) & ((weaponY + weapon->reachDown) >= y);
    if (!weaponYMatches) 
    {
        return false;
    }
    if (weapon->isFlipped)
    {   
        return (x >= (weaponX + TILE_WIDTH - weapon->reachForward)) & (x <= (weaponX + TILE_WIDTH + weapon->reachBackward));
    }
    else 
    {
        return (x <= (weaponX + weapon->reachForward)) & (x >= (weaponX - weapon->reachBackward));
    }
}

void Enemy::Respawn(Tilemap *CurrentLevel)
{
    bool foundRespawnPos = false;

    while (foundRespawnPos == false)
    {
        this->x = ((rand() % CurrentLevel->tilemap.width) * 16) - CurrentLevel->x;
        this->destX = this->x;
        this->y = ((rand() % CurrentLevel->tilemap.height) * 16) - CurrentLevel->y;
        this->destY = this->y;
        this->timeAtCreation = clock();
        if (CurrentLevel->isWalkable(CurrentLevel->ConvertPosition(this->x, this->y))) 
        {
            foundRespawnPos = true;
        } // also in player walk funciton
    }
}

void Enemy::Move(Tilemap *snowLevel_1)
{
    int enemyDirection = rand() % 4;
    int moveX = 0;
    int moveY = 0;
    switch (enemyDirection)
    {
    case 0: // up right down left, fall through if not walkable 
        moveX = 0;
        moveY = -16;
        break;
    case 1:
        moveX = 16;
        moveY = 0;
        break;
    case 2:
        moveX = 0;
        moveY = 16;
        break;
    case 3:
        moveX = -16;
        moveY = 0;
        break;
    default:
        return;
    }
    if (snowLevel_1->isWalkable(snowLevel_1->ConvertPosition(x + moveX, y + moveY)))
    {
        MoveDestination(moveX, moveY);
    }
    return;
}

void Enemy::update(Player *player, Tilemap *CurrentTilemap)
{
    if (!isMoving) Move(CurrentTilemap); 
    if (TimeAliveGreaterThan(60))
    {
        Respawn(CurrentTilemap);
    }
    Animate();
    Draw();
    if (IsCollidingWith(player)) player->isDead = true;
}


Enemy::~Enemy()
{
}
