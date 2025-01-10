#include <raylib.h> // version 5.5
#include "game.h"
#include "gmath.h"

typedef struct Player {
    Vector2 position;
    float speed;
} Player;

void game(int fps, int screenWidth, int screenHeight)
{
    InitWindow(screenWidth, screenHeight, "Game title");
    SetTargetFPS(fps);
    ToggleFullscreen(); // Needs proper mechanic

    const float moveSpeed = 1.5f;

    Player player = { 0 }; //Initializing all variables
    player.position.x = screenWidth / 2.0f;
    player.position.y = screenHeight / 2.0f;

    Vector2 direction = { 0 };

    // Camera variables
    Camera2D camera = { 0 };
    camera.target = (Vector2){player.position.x, player.position.y};
    camera.offset = (Vector2){screenWidth / 2.0f, screenHeight / 2.0f};
    camera.zoom = 1.0f;

    while (!WindowShouldClose()) {
        // Functionality
        if (IsKeyDown(KEY_RIGHT)) direction.x = 1.0f;
        else if (IsKeyDown(KEY_LEFT)) direction.x = -1.0f;
        else direction.x = 0.0f;

        if (IsKeyDown(KEY_UP)) direction.y = -1.0f;
        else if (IsKeyDown(KEY_DOWN)) direction.y = 1.0f;
        else direction.y = 0.0f;

        // Vector normalization
        NormalizeVector2(&direction);

        player.position.x += direction.x * moveSpeed;
        player.position.y += direction.y * moveSpeed;

        // Camera follows player
        camera.target = (Vector2){ player.position.x + 25, player.position.y + 25};

        // Rendering
        BeginDrawing();

            ClearBackground(RAYWHITE);

            BeginMode2D(camera);

                DrawRectangle(player.position.x, player.position.y, 50, 50, RED);

                DrawRectangle(550, 550, 100, 100, BLUE); // TEST OBJECT

            EndMode2D();

        EndDrawing();
    }

    CloseWindow();
}
