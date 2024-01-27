#include "gui.h"
#include "ball.h"
#include "course.h"

/*
GUI abstraction
*/

// Draw all GUI elements
void draw_gui_elements(const Ball *ball, const Hole *hole, const Obstacle obstacles[MAX_OBSTACLES])
{
    draw_obstacles(obstacles);
    draw_hole(hole);
    draw_ball(ball);
    draw_swing_count(ball);
}

void draw_ball(const Ball *ball)
{
    DrawCircleV(ball->position, ball->radius, ball->color);
    // Aiming line for the ball
    if (ball->is_drawing)
    {
        DrawLineEx(ball->draw_start_pos, GetMousePosition(), 2.5f, BLUE);
    }
}

void draw_swing_count(const Ball *ball)
{
    DrawText(TextFormat("Swing Count: %d", ball->swing_count), 10, 10, 20, BLACK);
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