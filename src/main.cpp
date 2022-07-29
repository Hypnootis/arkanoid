#include <raylib-cpp.hpp>
#include <array>
#include "paddle.hpp"
#include "ball.hpp"


int main() {
    
    // Initialization
    constexpr int screenWidth = 800;
    constexpr int screenHeight = 450;

    raylib::Color textColor(LIGHTGRAY);
    raylib::Window w(screenWidth, screenHeight, "Arkanoid in Raylib - Hypnootis");

    raylib::Vector2 rectSize = {float(screenWidth) * 0.2f, 20.0f};
    float ballSize = 12.0f;
    raylib::Vector2 paddlePosition = {(float)screenWidth / 2 - (rectSize.x / 2), (float)screenHeight * 0.85f};
    raylib::Vector2 ballPosition = {(float)screenWidth / 2 - (ballSize / 2), (float)screenHeight / 2};
    
    Paddle newPaddle(rectSize, paddlePosition);
    Ball newBall(ballSize, ballPosition);

    
    SetTargetFPS(60);

    float speed = 500.0f; // This is in px/millisecond, due to deltaTime being used
    
    raylib::Vector2 speedVector = {speed, 0.0f};
    raylib::Vector2 ballSpeed = {1.0f, 1.0f};
    raylib::Vector2 ballDirection = {-1.0f, 0.5f};



    // Main game loop
    while (!w.ShouldClose()) // Detect window close button or ESC key
    {

        float deltaTime = GetFrameTime();

        // Update

        
        if (IsKeyDown(KEY_A) && newPaddle.getPosition().x >= 0){
            // -speed = -1.0 * speedVector{speed, 0.0f}, for inverse
            newPaddle.move(-speedVector * deltaTime);
        }

        if (IsKeyDown(KEY_D) && newPaddle.getPosition().x < screenWidth - newPaddle.size.x){
            newPaddle.move(speedVector * deltaTime);
        }
    
        // TODO: Update your variables here

        newBall.move((ballDirection * speedVector) * deltaTime);


        // Draw
        BeginDrawing();
        ClearBackground(Color{153, 255, 255});
        newPaddle.draw();
        newBall.draw();

        EndDrawing();
    }

    return 0;
}