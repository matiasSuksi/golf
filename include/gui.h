#ifndef GUI_H
#define GUI_H

#include "ball.h"
#include "course.h"

void draw_obstacles(const Obstacle obstacles[MAX_OBSTACLES]);
void draw_hole(const Hole *hole);
void draw_ball(const Ball *ball);
void draw_swing_count(const Ball *ball);
void draw_gui_elements(const Ball *ball, const Hole *hole, const Obstacle obstacles[MAX_OBSTACLES]);

#endif