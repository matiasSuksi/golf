#include "gui.h"
#include "ball.h"
#include "course.h"

Font custom_font;
/*
GUI abstraction
*/
void init_gui_attributes()
{
    custom_font = LoadFont("./fonts/SamuraiBlast.ttf");
}

// Draw all GUI elements
void draw_gui_elements(const Ball *ball, const Hole *hole, const Obstacle obstacles[MAX_OBSTACLES])
{
    draw_obstacles(obstacles);
    draw_hole(hole);
    draw_ball(ball);
    draw_swing_count(ball, custom_font);
}

void draw_ball(const Ball *ball)
{
    DrawCircleV(ball->position, ball->radius, ball->color);
    // Aiming line for the ball
    if (ball->is_drawing)
    {
        DrawLineEx(ball->draw_start_pos, GetMousePosition(), 2.5f, GOLD);
    }
}

void draw_obstacles(const Obstacle obstacles[MAX_OBSTACLES])
{
    for (int i = 0; i < MAX_OBSTACLES; i++)
    {
        DrawRectangleRounded(obstacles[i].rect, 0.3, 8, obstacles[i].color);
    }
}

void draw_hole(const Hole *hole)
{
    DrawCircleV(hole->position, hole->radius, hole->color);
}

void draw_swing_count(const Ball *ball, Font custom_font)
{
    // Customize the position, font size, spacing, and tint as needed
    Vector2 position = {10, 10};
    int fontSize = 30;
    float spacing = 0;
    Color tint = BLACK;

    DrawTextEx(custom_font, TextFormat("Swing Count: %d", ball->swing_count), position, fontSize, spacing, tint);
}

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