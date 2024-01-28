#include "menu.h"
#include "gui.h"

// Show main menu
MenuItem main_menu(void)
{
    ClearBackground(BLACK);

    // Draw menu options
    DrawTextEx(custom_font, "Main Menu", (Vector2){GetScreenWidth() / 2 - MeasureTextEx(custom_font, "Main Menu", 60, 0).x / 2, 80}, 60, 0, GOLD);
    DrawTextEx(custom_font, "1. Start Game", (Vector2){GetScreenWidth() / 2 - MeasureTextEx(custom_font, "1. Start Game", 40, 0).x / 2, 220}, 40, 0, GOLD);
    DrawTextEx(custom_font, "2. Exit", (Vector2){GetScreenWidth() / 2 - MeasureTextEx(custom_font, "2. Exit", 40, 0).x / 2, 250}, 40, 0, GOLD);

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