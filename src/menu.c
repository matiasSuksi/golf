#include "menu.h"

MenuItem main_menu(void)
{
    ClearBackground(RAYWHITE);

    // Draw menu options
    DrawText("Main Menu", GetScreenWidth() / 2 - MeasureText("Main Menu", 40) / 2, 80, 40, DARKGRAY);
    DrawText("1. Start Game", GetScreenWidth() / 2 - MeasureText("1. Start Game", 20) / 2, 220, 20, DARKGRAY);
    DrawText("2. Exit", GetScreenWidth() / 2 - MeasureText("2. Exit", 20) / 2, 250, 20, DARKGRAY);

    // Get user input
    if (IsKeyPressed(KEY_ONE))
    {
        return MENU_START_GAME;
    }
    else if (IsKeyPressed(KEY_TWO))
    {
        return MENU_EXIT;
    }

    return -1; // No selection made
}