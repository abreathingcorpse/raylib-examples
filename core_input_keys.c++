#include "raylib.h"
#include <iostream>

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - keyboard input");

    Vector2 ballPosition = { (float)screenWidth/2, (float)screenHeight/2 };

    int randValue = GetRandomValue(-8, 5);   // Get a random integer number between -8 and 5 (both included)

    float elapsed_time; // This will hold the time in seconds for last frame drawn(delta time)
    float sum_elapsed_time; // This will hold the time in seconds 
    float unitary_velocity = 200.0f;

//    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------
        elapsed_time = GetFrameTime();
        sum_elapsed_time += elapsed_time;

        if (IsKeyDown(KEY_D)) ballPosition.x += unitary_velocity * elapsed_time;
        if (IsKeyDown(KEY_A)) ballPosition.x -= unitary_velocity * elapsed_time;
        if (IsKeyDown(KEY_W)) ballPosition.y -= unitary_velocity * elapsed_time;
        if (IsKeyDown(KEY_S)) ballPosition.y += unitary_velocity * elapsed_time;

        // Every two seconds a new random value is generated
        if (sum_elapsed_time >= 2.0f)
        {
            randValue = GetRandomValue(-8, 5);
            sum_elapsed_time -= 2.0f;
        }
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawText("move the ball with WASD keys", 10, 10, 20, DARKGRAY);

            DrawText("Every 2 seconds a new random value is generated:", 10, 30, 20, MAROON);

            DrawText(TextFormat("%i", randValue), 10, 50, 20, LIGHTGRAY);
            DrawText(TextFormat("%.2f", sum_elapsed_time), 10, 70, 20, LIGHTGRAY);

            DrawCircleV(ballPosition, 50, MAROON);

        EndDrawing();
        //----------------------------------------------------------------------------------

    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}