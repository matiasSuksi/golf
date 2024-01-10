#include <stdio.h>

#include "raylib.h"

#include "ball.h"

// Window size parameters
#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 800

int main(void)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Ascetic GOLF");
    SetTargetFPS(60);

    // Init ball
    Ball ball;
    init_ball(&ball, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 2.0f, 2.0f, 30, BLACK);

    // Game loop
    while (!WindowShouldClose())
    {
        update_ball(&ball);
        BeginDrawing();
        ClearBackground(RAYWHITE);
        draw_ball(&ball);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}

