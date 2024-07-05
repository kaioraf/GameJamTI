#include "iswalkable.h"

bool snowLevel_1isWalkable(int tileID)
{
    switch (tileID)
    {
    case 15:
    case 16:
    case 17:    
    case 18:
    case 19:
    case 22:
    case 23:
    case 29:
    case 30:
    case 31:
    case 32:
    case 33:
    case 35:
    case 36:
    case 37:
    case 38:
    case 39:
    case 41:
    case 42:
    case 43:
    case 45:
    case 46:
    case 47:
    case 48:
    case 55:
    case 56:
    case 57:
    case 58:
    case 59:
    case 65:
    case 66:
    case 67:
    case 68:
    case 88:
    case 98:
    case 99:
    case 101:
    case 108:
    case 111:
    case 113:
    case 116:
    case 128:
    case 133:
        return true;
        break;
    default:
        return false;
        break;
    }
}