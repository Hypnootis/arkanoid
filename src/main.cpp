#include <raylib-cpp.hpp>
#include "paddle.hpp"
#include <array>

int main() {
    
    // Initialization
    constexpr int screenWidth = 800;
    constexpr int screenHeight = 450;

    raylib::Color textColor(LIGHTGRAY);
    raylib::Window w(screenWidth, screenHeight, "Raylib C++ Starter Kit Example");

    raylib::Vector2 rectSize = {float(screenWidth) * 0.2f, 20.0f};
    raylib::Vector2 paddlePosition = {(float)screenWidth / 2 - (rectSize.x / 2), (float)screenHeight * 0.85f};
    
    Paddle newPaddle (rectSize, paddlePosition);
    
    SetTargetFPS(60);

    // Main game loop
    while (!w.ShouldClose()) // Detect window close button or ESC key
    {
        // Update

     
        if (IsKeyDown(KEY_A)){
            newPaddle.movePaddle(paddlePosition.x -= 2.0f);
        }

        if (IsKeyDown(KEY_D)){
        }
    
        // TODO: Update your variables here

        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);
        newPaddle.draw();

        EndDrawing();
    }

    return 0;
}