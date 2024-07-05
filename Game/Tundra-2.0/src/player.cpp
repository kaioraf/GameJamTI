#include "player.h"


Player::Player(gfx_sprite_t *Foreground, int startX, int startY, int spriteWidth, int spriteHeight) :
    Sprite(Foreground, startX, startY, spriteWidth, spriteHeight)
{
    // foreground = Foreground;
    InitialiseFlippedSprite();
    isDead = false;
    hasWon = false;
    score = 0;
    
}

// Draws an indicator around the player to show the direction of another sprite (enemy)
void Player::drawSpriteIndicator(Sprite* IndicatedSprite)
{
    float alpha = calculateAngleBetween(IndicatedSprite);

    float dX = cosf(alpha) * 16;
    float dY = sinf(alpha) * 16;
    int circleXPos = this->x + (this->width / 2) + dX;
    int circleYpos = this->y + (this->height / 2) + dY;
    gfx_SetColor(34);
    gfx_FillCircle(circleXPos, circleYpos, 2);
    gfx_SetColor(32);
    gfx_Circle(circleXPos, circleYpos, 2);
}


void Player::InitialiseFlippedSprite()
{
    isFlipped = false;
    unsigned char *flippedData = new unsigned char [242]; 
    flippedForeground = (gfx_sprite_t *)flippedData;
    gfx_FlipSpriteY(foreground, flippedForeground);
}

void Player::FlipSprite()
{
    gfx_sprite_t *oldForeground = foreground;
    foreground = flippedForeground;
    flippedForeground = oldForeground;
    isFlipped = !isFlipped;
}

void Player::update()
{
    Animate();   
    Draw();
}

Player::~Player()
{
}