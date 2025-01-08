#include "raylib.h"
#include <cmath>
#include "stdio.h"

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

    //const float moveSpeed = 15.0;

    InitWindow(screenWidth, screenHeight, "Game title");
    SetTargetFPS(fps);

    Player player = { 0 }; //Initializing all variables
    player.position.x = screenWidth / 2;
    player.position.y = screenHeight / 2;

    float horizontal = 0.0f;
    float vertical = 0.0f;

    while (!WindowShouldClose()) {
        // Functionality
        if (IsKeyDown(KEY_RIGHT)) horizontal = 1.0f;
        if (IsKeyDown(KEY_LEFT)) horizontal = -1.0f;
        if (IsKeyDown(KEY_UP)) vertical = -1.0f;
        if (IsKeyDown(KEY_DOWN)) vertical = 1.0f;

        NormalizeVector2(player.position);

        // Rendering
        BeginDrawing();

            DrawRectangle(player.position.x, player.position.y, 25, 25, RED);

            ClearBackground(RAYWHITE);

        EndDrawing();

    }

    CloseWindow();
}
