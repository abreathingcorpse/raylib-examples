# include "raylib.h"

#define MAX_TILES 10

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - 2d camera");

    Vector2 ballPosition = { (float)screenWidth/2, (float)screenHeight/2 }; // c-like cast notation
    Rectangle tiles[MAX_TILES] = { 0 };
    Color tileColors[MAX_TILES] = { 0 };

    for (int i = 0; i < MAX_TILES; i++)
    {
        tiles[i].x = i * 20;
        tiles[i].y = 0;
        tiles[i].width = 20;
        tiles[i].height = 20;

        int red = GetRandomValue(200, 240);
        int green = GetRandomValue(200, 240);
        int blue = GetRandomValue(200, 250);
        tileColors[i] = (Color){ (unsigned char)red, (unsigned char)green, (unsigned char)blue, 255 };
    }

    Camera2D camera = { 0 };
    camera.target = (Vector2){ ballPosition.x, ballPosition.y };
    camera.offset = (Vector2){ screenWidth/2.0f, screenHeight/2.0f };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;
    const float cameraRotationSpeed = 10.0f;

    float elapsed_time; // This will hold the time in seconds for last frame drawn(delta time)
    //--------------------------------------------------------------------------------------
    

    // Main game loop
    while (!WindowShouldClose())        // Detect window close button or ESC key
    {

        // Update
        //----------------------------------------------------------------------------------
        elapsed_time = GetFrameTime();

        // Camera target follows player
        camera.target = (Vector2){ ballPosition.x, ballPosition.y };

        // Camera rotation controls
        if (IsKeyDown(KEY_Q)) {
            camera.rotation -= cameraRotationSpeed * elapsed_time ;
        }
        else if (IsKeyDown(KEY_E)) {
            camera.rotation += cameraRotationSpeed * elapsed_time ;
        } 

        // Camera zoom controls
        camera.zoom += ((float)GetMouseWheelMove()*0.05f);

        if (camera.zoom > 2.0f) camera.zoom = 2.0f;
        else if (camera.zoom < 0.5f) camera.zoom = 0.5f;

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            BeginMode2D(camera);

                for (int i = 0; i < MAX_TILES; i++) DrawRectangleRec(tiles[i], tileColors[i]);
                DrawCircleV(ballPosition, 50, MAROON);

            EndMode2D();
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

     // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}