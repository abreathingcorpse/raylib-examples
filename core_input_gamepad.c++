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

        ballPosition.x += GetGamepadAxisMovement(0, GAMEPAD_AXIS_LEFT_X) * unitary_velocity * elapsed_time;
        ballPosition.y += GetGamepadAxisMovement(0, GAMEPAD_AXIS_LEFT_Y) * unitary_velocity * elapsed_time;
        squarePosition.x += GetGamepadAxisMovement(0, GAMEPAD_AXIS_RIGHT_X) * unitary_velocity * elapsed_time;
        squarePosition.y += GetGamepadAxisMovement(0, GAMEPAD_AXIS_RIGHT_Y) * unitary_velocity * elapsed_time;

        if( IsGamepadButtonPressed(0, GAMEPAD_BUTTON_RIGHT_FACE_LEFT) ) { squareColor = DARKGREEN; }

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawText("move the ball with left stick", 10, 10, 20, DARKGRAY);
            DrawText("move the square around with right stick", 10, 30, 20, DARKGRAY);
            DrawText("hold & release the X button", 10, 50, 20, DARKGRAY);

            for (int i = 0; i < GetGamepadAxisCount(0); i++)
                {
                    DrawText(TextFormat("AXIS %i: %.02f", i, GetGamepadAxisMovement(0, i)), 20, 70 + 20*i, 10, DARKGRAY);
                }

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