#include "animated.h"

void Animated::MoveDestination(int dX, int dY)
{
    destX += dX;
    destY += dY;
    isMoving = dX || dY;
}

void Animated::Animate()
{
    int horizontalMove = destX - x;
    int verticalMove = destY - y;
    if (horizontalMove)
    {
        if (horizontalMove < 0)
        {
            x -= animationSteps;
        }
        else
        {
            x += animationSteps;
        }
    }
    if (verticalMove)
    {
        if (verticalMove < 0)
        {
            y -= animationSteps;
        }
        else
        {
            y += animationSteps;
        }
    }
    isMoving = horizontalMove || verticalMove;
}

Animated::Animated(int startX, int startY, bool startIsMoving)
{
    x = startX;
    destX = startX;
    y = startY;
    destY = startY;
    isMoving = startIsMoving;
}

Animated::~Animated()
{
}
