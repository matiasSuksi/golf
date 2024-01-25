#ifndef BALL_H
#define BALL_H

#include "raylib.h"
#include "raymath.h"

// Ball stuct
typedef struct
{
    Vector2 position;
    Vector2 velocity;
    float radius;
    Color color;
    bool is_drawing;         // Flag for draw and release
    Vector2 draw_start_pos;  // Start position of draw and release
} Ball;

void init_ball(Ball *ball, float start_x, float start_y, float start_vel_x, float start_vel_y, float radius, Color color);
void update_ball(Ball *ball);
void draw_ball(const Ball *ball);

#endif

