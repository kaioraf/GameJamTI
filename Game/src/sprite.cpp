#include "sprite.h"

Sprite::Sprite(gfx_sprite_t *Foreground, int startX, int startY, int spriteWidth, int spriteHeight):
        Animated(startX, startY, false)
{
    width = spriteWidth;
    height = spriteHeight;
    foreground = Foreground;
}

void Sprite::Draw()
{
    gfx_TransparentSprite(foreground, x, y);
}

bool Sprite::IsCollidingWith(Sprite *OtherSprite)
{
    int thisTileX = (int)floor(this->x / TILE_WIDTH);
    int thisTileY = (int)floor(this->y / TILE_WIDTH);
    int otherTileX = (int)floor(OtherSprite->x / TILE_WIDTH);
    int otherTileY = (int)floor(OtherSprite->y / TILE_WIDTH);

    bool xMatches = thisTileX == otherTileX;
    bool yMatches = thisTileY == otherTileY;
    if (xMatches && yMatches)
    {
        return true;
    }
    return false;
}

float Sprite::calculateAngleBetween(Sprite *OtherSprite)
{
    float dX = OtherSprite->x + (OtherSprite->width / 2) - this->x + (this->width / 2);
    float dY = OtherSprite->y + (OtherSprite->height / 2) - this->y + (this->height /2);

    if (dX == 0)
    {
        if (dY < 0)
        {
            return M_PI_2;
        }
        else
        {
            return -M_PI_2;
        }
    }

    float alpha = atanf(dY / dX);
    if (dX < 0) 
    {
        alpha += M_PI;
    }
    return alpha;
}

bool Sprite::isSpriteOffscreen()
{
    if (this->x > GFX_LCD_WIDTH || this->x < 0)
    {
        return true;
    }
    else if (this->y > GFX_LCD_HEIGHT || this->y < 0)
    {
        return true;
    }
    return false;
}

Sprite::~Sprite()
{

}
