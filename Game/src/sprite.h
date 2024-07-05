#include "defines.h"
#include "animated.h"
#pragma once

class Sprite : public Animated
{
private:
    // gfx_sprite_t *background;

public:
    int speed;
    bool isFlipped;
    int width;
    int height;
    clock_t timeAtCreation;
    gfx_sprite_t *foreground;
    Sprite() = default;
    Sprite(gfx_sprite_t *Foreground, int startX, int startY, int spriteWidth, int spriteHeight);
    void Draw();
    bool IsCollidingWith(Sprite* OtherSprite);
    float calculateAngleBetween(Sprite *OtherSprite);
    bool isSpriteOffscreen();
    ~Sprite();
};


