#include "raylib.h"
#include <cmath>

typedef struct Player {
    Vector2 position;
    float speed;
} Player;

Vector2 NormalizeVector2(Vector2 v) {
    float magnitude = sqrtf(v.x * v.x + v.y * v.y); // Calculate vector magnitude
    if (magnitude != 0) {
        v.x /= magnitude; // Normalize x-component
        v.y /= magnitude; // Normalize y-component
    }
    return v;
}

void game(int fps) {
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Game title");
    SetTargetFPS(fps);

    const float moveSpeed = 1.5f;

    Player player = { 0 }; //Initializing all variables
    player.position.x = screenWidth / 2;
    player.position.y = screenHeight / 2;

    Vector2 direction = { 0 };

    while (!WindowShouldClose()) {
        // Functionality
        if (IsKeyDown(KEY_RIGHT)) direction.x = 1.0f;
        else if (IsKeyDown(KEY_LEFT)) direction.x = -1.0f;
        else direction.x = 0.0f;

        if (IsKeyDown(KEY_UP)) direction.y = -1.0f;
        else if (IsKeyDown(KEY_DOWN)) direction.y = 1.0f;
        else direction.y = 0.0f;

        direction = NormalizeVector2(direction);

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
