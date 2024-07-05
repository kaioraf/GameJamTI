#include "defines.h"
#include "menuitem.h"
#include "tilemap.h"
#pragma once

class Menu
{
private:
    /* data */
public:
    int amountOfOptions;
    menuItem *items[10];
    Tilemap *Map;
    int selectedItem; // 1 indexed
    int x;
    int y;
    Menu(Tilemap *menuMap, int menuOptionCount, menuItem *menuItems[], int selectedMenuItem);
    void draw();
    ~Menu();
};
