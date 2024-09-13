#include <iostream>
#include <raylib.h>
using namespace std;

Color green = {173, 204, 96, 255};
Color dark_green = {43, 24, 51, 255};

int cell_size = 30;
int cell_count = 25;

class Food
{
public:
    Vector2 position;
    Texture2D texture;

    Food()
    {
        Image image = LoadImage("./graphics/apple1.png");
        texture = LoadTextureFromImage(image);
        UnloadImage(image);
        position = GenerateRandompos();
    }

    ~Food()
    {
        UnloadTexture(texture);
    }

    void Draw()
    {
        DrawTexture(texture, position.x * cell_size, position.y * cell_size, WHITE);
    }
    Vector2 GenerateRandompos()
    {
        float x = GetRandomValue(0, cell_count - 1);
        float y = GetRandomValue(0, cell_count - 1);
        return Vector2{x, y};
    }
};

int main()
{
    std::cout << "Hello, World!" << std::endl;

    InitWindow(cell_count * cell_size, cell_count * cell_size, "Snake game");
    SetTargetFPS(60);

    Food food = Food();

    while (WindowShouldClose() == false)
    {
        BeginDrawing();

        ClearBackground(green);
        food.Draw();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
