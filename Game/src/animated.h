#include "defines.h"
#pragma once

class Animated
{
private:
    /* data */
public:
    int x, destX;
    int y, destY;
    int animationLength = 16;
    int animationSteps = 4;
    bool isMoving;
    void MoveDestination(int dX, int dY);
    void Animate();
    Animated() = default;
    Animated(int startX, int startY, bool startIsMoving);
    ~Animated();
};
