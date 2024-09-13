#include <iostream>
#include <raylib.h>
using namespace std;
#include <deque>

Color green = {173, 204, 96, 255};
Color dark_green = {43, 24, 51, 255};

int cell_size = 30;
int cell_count = 25;

class Snake
{
public:
    deque<Vector2> body = {Vector2{6, 9}, Vector2{4, 9}, Vector2{5, 9}};

    void Draw()
    {
        for (int i = 0; i < body.size(); i++)
        {
            float x = body[i].x;
            float y = body[i].y;
            Rectangle segment = Rectangle{x * cell_size, y * cell_size, float(cell_size), float(cell_size)};
            DrawRectangleRounded(segment, 0.5, 6, dark_green);
        }
    }
};

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
    Snake snake = Snake();

    while (WindowShouldClose() == false)
    {
        BeginDrawing();

        ClearBackground(green);
        food.Draw();
        snake.Draw();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
