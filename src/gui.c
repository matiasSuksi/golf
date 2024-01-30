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
        // Draw obstacle depending on its type
        switch (obstacles[i].type)
        {
            case RECTANGLE:
                DrawRectangleRounded(obstacles[i].rect, 0.3, 8, obstacles[i].color);
                break;
            case CIRCLE:
                Vector2 center = {obstacles[i].rect.x + obstacles[i].rect.width / 2, obstacles[i].rect.y + obstacles[i].rect.height / 2};
                DrawCircleV(center, obstacles[i].rect.width / 2, obstacles[i].color);
                break;
            case TRIANGLE:
                Vector2 p1 = {obstacles[i].rect.x + obstacles[i].rect.width / 2, obstacles[i].rect.y};
                Vector2 p2 = {obstacles[i].rect.x, obstacles[i].rect.y + obstacles[i].rect.height};
                Vector2 p3 = {obstacles[i].rect.x + obstacles[i].rect.width, obstacles[i].rect.y + obstacles[i].rect.height};
                DrawTriangle(p1, p2, p3, obstacles[i].color);
                break;
            default:
                break;
        }
    }
}

void draw_hole(const Hole *hole)
{
    DrawCircleV(hole->position, hole->radius, hole->color);
}

void draw_swing_count(const Ball *ball, Font custom_font)
{
    Vector2 position = {10, 10};
    int font_size = 30;
    float spacing = 0;
    Color tint = BLACK;

    DrawTextEx(custom_font, TextFormat("Swing Count: %d", ball->swing_count), position, font_size, spacing, tint);
}

// Show main menu
MenuItem main_menu(void)
{
    ClearBackground(DARKGREEN);

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