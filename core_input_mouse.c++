#include "raylib.h"

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

    Vector2 ballPosition = { (float)screenWidth/2, (float)screenHeight/2 }; // c-like cast notation
    Vector2 squarePosition = { 600.0f, 250.0f };
    Vector2 squareSize = { 20.0f, 20.0f };
    Color squareColor = LIME;
    Vector2 mousePosition;

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

        mousePosition = GetMousePosition();

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && mousePosition.x > squarePosition.x
            && mousePosition.x < (squarePosition.x + squareSize.x)
            && mousePosition.y > squarePosition.y
            && mousePosition.y < (squarePosition.y + squareSize.y))
            { squareColor = DARKGREEN; }

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawText("move the ball with WASD keys", 10, 10, 20, DARKGRAY);

            DrawCircleV(ballPosition, 50, MAROON);
            DrawRectangleV(squarePosition, squareSize, squareColor );

        EndDrawing();
        //----------------------------------------------------------------------------------

    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}