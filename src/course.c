#include "course.h"

// Now randomly generates obstacles for screen
// TODO: We need distinct golf courses with increased difficulty.
// 1. Heuristics for course difficulty calculation & generation?
// 2. Predefined list of predefined obstacle locations?
void generate_obstacles(Obstacle obstacles[MAX_OBSTACLES], int screen_width, int screen_height)
{
    for (int i = 0; i < MAX_OBSTACLES; i++)
    {
        obstacles[i].rect.width = GetRandomValue(30, 100);
        obstacles[i].rect.height = GetRandomValue(30, 100);
        obstacles[i].rect.x = GetRandomValue(0, screen_width - obstacles[i].rect.width);
        obstacles[i].rect.y = GetRandomValue(0, screen_height - obstacles[i].rect.height);

        // Check for collisions with previously generated obstacles
        while (prevent_overlapping_obstacles(obstacles, i, obstacles[i].rect))
        {
            obstacles[i].rect.x = GetRandomValue(0, screen_width - obstacles[i].rect.width);
            obstacles[i].rect.y = GetRandomValue(0, screen_height - obstacles[i].rect.height);
        }

        obstacles[i].color = RED; // Obstacle color
    }
}

void draw_obstacles(const Obstacle obstacles[MAX_OBSTACLES])
{
    for (int i = 0; i < MAX_OBSTACLES; i++)
    {
        DrawRectangleRec(obstacles[i].rect, obstacles[i].color);
        DrawRectangleLinesEx(obstacles[i].rect, 2, BLACK); // Draw black outline around the obstacles
    }
}

// Check if ball collides with obstacles
bool check_ball_collision(const Ball *ball, const Obstacle obstacles[MAX_OBSTACLES])
{
    for (int i = 0; i < MAX_OBSTACLES; i++)
    {
        if (CheckCollisionCircleRec(ball->position, ball->radius, obstacles[i].rect))
        {
            return true; // Collision detected
        }
    }
    return false; // No collision
}

// Check that course obstacles won't spawn on top of each other
bool prevent_overlapping_obstacles(const Obstacle obstacles[MAX_OBSTACLES], int index, const Rectangle rect) {
    for (int i = 0; i < index; i++)
    {
        if (CheckCollisionRecs(obstacles[i].rect, rect))
        {
            return true; // Collision detected
        }
    }
    return false; // No collision
}