#include <stdio.h>
#include "raylib.h"
#include "gui.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 1000

void run_game(void)
{
    // Init ball
    Ball ball;
    init_ball(&ball, SCREEN_WIDTH / 2, SCREEN_HEIGHT - 50, 0.0f, 0.0f, 15, WHITE);

    // Generate golf course
    Hole hole;
    generate_hole(&hole, SCREEN_WIDTH, SCREEN_HEIGHT);
    Obstacle obstacles[MAX_OBSTACLES];
    generate_obstacles(obstacles, &hole, SCREEN_WIDTH, SCREEN_HEIGHT);

    // Game loop
    while (!WindowShouldClose())
    {
        update_ball(&ball);
        reflect_ball_from_obstacle(&ball, obstacles);
        // Check if ball is in hole
        if (is_ball_in_hole(&ball, &hole))
        {
            init_ball(&ball, SCREEN_WIDTH / 2, SCREEN_HEIGHT - 50, 0.0f, 0.0f, 15, WHITE); // Reset ball location
            ball.swing_count = 0; // Reset swing count
            generate_obstacles(obstacles, &hole, SCREEN_WIDTH, SCREEN_HEIGHT); // Generate new course
        }
        BeginDrawing();
        ClearBackground(GREEN);
        draw_gui_elements(&ball, &hole, obstacles); //Draw all game GUI elements
        EndDrawing();
    }
}

int main(void)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Ascetic GOLF");
    SetTargetFPS(60);

    init_gui_attributes();
    
    // Game loop
    while (!WindowShouldClose())
    {
        BeginDrawing();
        MenuItem selected_option = main_menu(); // Show main menu

        // Handling main menu selection
        switch (selected_option)
        {
            case MENU_START_GAME:
                run_game();
                break;
            case MENU_EXIT:
                CloseWindow();
                break;
            default:
                break;
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
