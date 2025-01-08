#include "raylib.h"

typedef struct Player {
    Vector2 position;
    float speed;
} Player;

void DrawRectangle(int posX, int posY, int width, int height, Color color);

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Game title");
    SetTargetFPS(60);

    Player player = { 0 }; //Initializing all variables
    player.position.x = screenWidth / 2;
    player.position.y = screenHeight / 2;

    while (!WindowShouldClose())
    {
        BeginDrawing();

            DrawRectangle(player.position.x, player.position.y, 25, 25, RED);

            ClearBackground(RAYWHITE);
            DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
