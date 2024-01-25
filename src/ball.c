#include "ball.h"

void init_ball(Ball *ball, float start_x, float start_y, float start_vel_x, float start_vel_y, float radius, Color color)
{
    ball->position = (Vector2){start_x, start_y};
    ball->velocity = (Vector2){start_vel_x, start_vel_y};
    ball->radius = radius;
    ball->color = color;
    ball->is_drawing = false;
    ball->draw_start_pos = (Vector2){0};
    ball->damping_factor = 0.98f;  // This factor reduces speed of ball gradually
}

void update_ball(Ball *ball)
{
    if(IsMouseButtonDown(MOUSE_LEFT_BUTTON))
    {
        if(!ball->is_drawing)
        {
            ball->is_drawing = true;
            ball->draw_start_pos = GetMousePosition();
        }
    } else
    {
        if(ball->is_drawing)
        {
            ball->is_drawing = false;
            // Calculate velocity based on difference between start and end positions of draw
            ball->velocity = Vector2Subtract(GetMousePosition(), ball->draw_start_pos);
        }
    }

    // Update ball velocity
    ball->velocity.x *= ball->damping_factor;
    ball->velocity.y *= ball->damping_factor;

    // Update ball position
    ball->position.x += ball->velocity.x;
    ball->position.y += ball->velocity.y;

    // Check window borders and adjust position and velocity if needed
    if(ball->position.x - ball->radius < 0)
    {
        ball->position.x = ball->radius;
        ball->velocity.x = -ball->velocity.x * ball->damping_factor;  // Reverse velocity and apply damping
    } else if(ball->position.x + ball->radius > GetScreenWidth())
    {
        ball->position.x = GetScreenWidth() - ball->radius;
        ball->velocity.x = -ball->velocity.x * ball->damping_factor;
    }

    if(ball->position.y - ball->radius < 0)
    {
        ball->position.y = ball->radius;
        ball->velocity.y = -ball->velocity.y * ball->damping_factor;
    } else if(ball->position.y + ball->radius > GetScreenHeight())
    {
        ball->position.y = GetScreenHeight() - ball->radius;
        ball->velocity.y = -ball->velocity.y * ball->damping_factor;
    }
}

void draw_ball(const Ball *ball)
{
    DrawCircleV(ball->position, ball->radius, ball->color);
    // Aiming line for the ball
    if(ball->is_drawing)
    {
        DrawLineV(ball->draw_start_pos, GetMousePosition(), GRAY);
    }
}
