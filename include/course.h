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
void generate_hole(Hole *hole, int screen_width, int screen_height);
bool prevent_overlapping_obstacles(const Obstacle obstacles[MAX_OBSTACLES], int index, const Rectangle rect);
void reflect_ball_from_obstacle(Ball *ball, const Obstacle obstacles[MAX_OBSTACLES]);

#endif
