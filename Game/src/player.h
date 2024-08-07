#include "defines.h"
#include "sprite.h"
#include "vector/vector.h"
#pragma once

class Player : public Sprite
{
private:
    /* data */
public:
    bool isDead;
    bool hasWon;
    int score;
    int movementSpeed;
    int jumpAccel;
    int jumpVelocity;
    int gravity;

    gfx_sprite_t *flippedForeground;
    Player(gfx_sprite_t *Foreground, int startX, int startY, int spriteWidth, int spriteHeight);
    void InitialiseFlippedSprite();
    void FlipSprite();
    void drawSpriteIndicator(Sprite* IndicatedSprite);
    int updateMovement(int timeSinceLastUpdate);
    void update();
    ~Player();
};