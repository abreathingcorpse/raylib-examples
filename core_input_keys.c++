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

    float elapsed_time; // This will hold the time in seconds for last frame drawn(delta time)
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

        if (IsKeyDown(KEY_D)) ballPosition.x += unitary_velocity * elapsed_time;
        if (IsKeyDown(KEY_A)) ballPosition.x -= unitary_velocity * elapsed_time;
        if (IsKeyDown(KEY_W)) ballPosition.y -= unitary_velocity * elapsed_time;
        if (IsKeyDown(KEY_S)) ballPosition.y += unitary_velocity * elapsed_time;

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawText("move the ball with WASD keys", 10, 10, 20, DARKGRAY);

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