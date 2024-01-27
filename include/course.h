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

typedef struct {
    Vector2 position;
    float radius;
    Color color;
} Hole;

void generate_obstacles(Obstacle obstacles[MAX_OBSTACLES], const Hole *hole, int screen_width, int screen_height);
void draw_obstacles(const Obstacle obstacles[MAX_OBSTACLES]);
bool check_ball_collision(const Ball *ball, const Obstacle obstacles[MAX_OBSTACLES]);
bool prevent_overlapping_obstacles(const Obstacle obstacles[MAX_OBSTACLES], int index, const Rectangle rect);

void generate_hole(Hole *hole, int screen_width, int screen_height);
void draw_hole(const Hole *hole);

#endif
