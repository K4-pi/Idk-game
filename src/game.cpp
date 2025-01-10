#include <raylib.h> // version 5.5

#include "game.hpp"
#include "gmath.hpp"

typedef struct Player {
    Vector2 position;
    float speed;
} Player;

void game(int fps, int screenWidth, int screenHeight) {

    const float moveSpeed = 1.5f;

    Player player = { 0 }; //Initializing all variables
    player.position.x = screenWidth / 2;
    player.position.y = screenHeight / 2;

    Vector2 direction = { 0 };

    InitWindow(screenWidth, screenHeight, "Game title");
    SetTargetFPS(fps);

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

        // Rendering
        BeginDrawing();

            DrawRectangle(player.position.x, player.position.y, 25, 25, RED);
            ClearBackground(RAYWHITE);

        EndDrawing();
    }

    CloseWindow();
}
