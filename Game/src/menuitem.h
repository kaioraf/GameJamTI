#include "defines.h"
#pragma once

class menuItem
{
private:
    /* data */
public:
    bool closeMenu = false;
    bool optionsMenuOpen = false;
    const char *itemText;
    int id;
    menuItem(int ID, const char *text);
    ~menuItem();
};
