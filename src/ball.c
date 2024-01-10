#include "ball.h"

void init_ball(Ball *ball, float start_x, float start_y, float start_vel_x, float start_vel_y, float radius, Color color) {
    ball->position = (Vector2){start_x, start_y};
    ball->velocity = (Vector2){start_vel_x, start_vel_y};
    ball->radius = radius;
    ball->color = color;
}

void update_ball(Ball *ball) {
    ball->position.x += ball->velocity.x;
    ball->position.y += ball->velocity.y;
}

void draw_ball(const Ball *ball) {
    DrawCircleV(ball->position, ball->radius, ball->color);
}

