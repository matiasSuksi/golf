#ifndef MENU_H
#define MENU_H

#include "raylib.h"

typedef enum {
    MENU_START_GAME,
    MENU_EXIT
} MenuItem;

MenuItem main_menu(void);

#endif