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
    init_ball(&ball, SCREEN_WIDTH / 2, SCREEN_HEIGHT - 50, 0.0f, 0.0f, 15, WHITE);

    Hole hole;
    generate_hole(&hole, SCREEN_WIDTH, SCREEN_HEIGHT);

    // Generate golf course
    Obstacle obstacles[MAX_OBSTACLES];
    generate_obstacles(obstacles, &hole, SCREEN_WIDTH, SCREEN_HEIGHT);

    // Game loop
    while (!WindowShouldClose())
    {
        update_ball(&ball);
        reflect_ball_from_obstacle(&ball, obstacles);

        // Graphics drawing section
        BeginDrawing();
        ClearBackground(GREEN);

        draw_obstacles(obstacles);
        draw_hole(&hole);
        draw_ball(&ball);
        draw_swing_count(&ball);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}

