#ifndef COURSE_H
#define COURSE_H

#include "raylib.h"
#include "ball.h"

#define MAX_OBSTACLES 10

typedef struct
{
    Rectangle rect;
    Color color;
} Obstacle;

void generate_obstacles(Obstacle obstacles[MAX_OBSTACLES], int screen_width, int screen_height);
void draw_obstacles(const Obstacle obstacles[MAX_OBSTACLES]);
bool check_ball_collision(const Ball *ball, const Obstacle obstacles[MAX_OBSTACLES]);
bool prevent_overlapping_obstacles(const Obstacle obstacles[MAX_OBSTACLES], int index, const Rectangle rect);

#endif
