#include "course.h"

/*
Now randomly generates obstacles for screen
TODO: We need distinct golf courses with increased difficulty.
1. Heuristics for course difficulty calculation & generation?
2. Predefined list of predefined obstacle locations?
*/
void generate_obstacles(Obstacle obstacles[MAX_OBSTACLES], int screen_width, int screen_height)
{
    for (int i = 0; i < MAX_OBSTACLES; i++)
    {
        obstacles[i].rect.width = GetRandomValue(30, 100);
        obstacles[i].rect.height = GetRandomValue(30, 100);
        obstacles[i].rect.x = GetRandomValue(0, screen_width - obstacles[i].rect.width);
        obstacles[i].rect.y = GetRandomValue(0, screen_height - obstacles[i].rect.height);

        // Check overlapping with previously generated obstacles
        while (prevent_overlapping_obstacles(obstacles, i, obstacles[i].rect))
        {
            obstacles[i].rect.x = GetRandomValue(0, screen_width - obstacles[i].rect.width);
            obstacles[i].rect.y = GetRandomValue(0, screen_height - obstacles[i].rect.height);
        }

        obstacles[i].color = DARKBROWN; // Obstacle color
    }
}

void generate_hole(Hole *hole, int screen_width, int screen_height)
{
    hole->position.x = screen_width / 2;
    hole->position.y = 25; // Fixed position near the top
    hole->radius = 20.0f; // Adjust the size
    hole->color = BLACK; // Adjust the color
}

// Check that course obstacles won't spawn on top of each other
bool prevent_overlapping_obstacles(const Obstacle obstacles[MAX_OBSTACLES], int index, const Rectangle rect)
{
    for (int i = 0; i < index; i++)
    {
        if (CheckCollisionRecs(obstacles[i].rect, rect))
        {
            return true; // Collision detected
        }
    }
    return false; // No collision
}

// Reflect ball from the obstacle
void reflect_ball_from_obstacle(Ball *ball, const Obstacle obstacles[MAX_OBSTACLES])
{
    for (int i = 0; i < MAX_OBSTACLES; i++)
    {
        if (CheckCollisionCircleRec(ball->position, ball->radius, obstacles[i].rect))
        {
            // Calculate the collision vector
            Vector2 collision_vector = {obstacles[i].rect.x + obstacles[i].rect.width / 2 - ball->position.x,
                                        obstacles[i].rect.y + obstacles[i].rect.height / 2 - ball->position.y};

            // Normalize collision vector
            collision_vector= Vector2Normalize(collision_vector);

            // Calculate the dot product of ball's velocity & collision vector
            float dot_product = 2 * (ball->velocity.x * collision_vector.x + ball->velocity.y * collision_vector.y);

            // Reflect ball's velocity using the collision vector
            ball->velocity.x -= dot_product * collision_vector.x;
            ball->velocity.y -= dot_product * collision_vector.y;
        }
    }
}

// Check if ball goes into hole
bool is_ball_in_hole(const Ball *ball, const Hole *hole)
{
    bool close_enough = Vector2Distance(ball->position, hole->position) < ball->radius + hole->radius;  // Check if distance between ball and hole center is less than sum of their radius
    bool slow_enough = Vector2Length(ball->velocity) < 5.0f; // Check if speed of ball is slow enough to go in

    return close_enough && slow_enough;
}