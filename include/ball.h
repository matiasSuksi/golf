#ifndef BALL_H
#define BALL_H

#include "raylib.h"
#include "raymath.h"

// Ball stuct
typedef struct
{
    Vector2 position;
    Vector2 velocity;
    Vector2 draw_start_pos;    // Start position of draw and release
    float damping_factor;      // Damping factor to gradually reduce speed
    float radius;
    Color color;
    bool is_drawing;           // Flag for draw and release
    int swing_count;           // How many hits player has used
} Ball;

void init_ball(Ball *ball, float start_x, float start_y, float start_vel_x, float start_vel_y, float radius, Color color);
void update_ball(Ball *ball);

#endif
