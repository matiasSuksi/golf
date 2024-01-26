#include <stdio.h>
#include "raylib.h"

#include "ball.h"
#include "course.h"

#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 800

int main(void)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Ascetic GOLF");
    SetTargetFPS(60);

    // Init ball
    Ball ball;
    init_ball(&ball, SCREEN_WIDTH / 2, SCREEN_HEIGHT - 50, 0.0f, 0.0f, 20, BLACK);

    // Generate golf course
    Obstacle obstacles[MAX_OBSTACLES];
    generate_obstacles(obstacles, SCREEN_WIDTH, SCREEN_HEIGHT);

    // Game loop
    while (!WindowShouldClose())
    {
        update_ball(&ball);

        // Check for collision with obstacles
        if (check_ball_collision(&ball, obstacles))
        {
            ball.velocity.x = -ball.velocity.x; // Reverse velocity on collision with obstacles
            ball.velocity.y = -ball.velocity.y;
        }

        // Graphics drawing section
        BeginDrawing();
        ClearBackground(RAYWHITE);
        draw_obstacles(obstacles);
        draw_ball(&ball);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}

