#include <stdio.h>
#include "raylib.h"

int main(void)
{
    InitWindow(800, 450, "GOLF game");

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("Golf", 190, 200, 20, LIGHTGRAY);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
