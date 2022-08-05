#include <raylib-cpp.hpp>
#include <array>
#include "paddle.hpp"
#include "ball.hpp"
#include <string>

/*
    TODO: Refactor entity code
    Entity code can be deprecated with the use of
    raylib's own functions, paddle and blocks inherit from raylib::rectangle

    TODO: Blocks
    Spawn them, have circle collide with them

    TODO: Score and levels
    Blocks break, get points, all blocks broken, new level

    TODO: Refactor code
    Make the codebase neater, maybe add some comments. Split things up.

    TODO: More intricate circle collision
    Make ball bounce more fun-ly, using maths

    TODO: More involved gameplay
    Make levels different from eachother, bossfights?

*/


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
    newPaddle.SetSize(rectSize);
    Ball newBall(ballSize, ballPosition);

    
    SetTargetFPS(60);

    float speed = 100.0f; // This is in px/millisecond, due to deltaTime being used
    
    // raylib::Vector2 speedVector = {speed, 0.0f};
    float ballSpeed = 200.0f;
    raylib::Vector2 ballDirection = {-1.5f, 0.3f};



    // Main game loop
    while (!w.ShouldClose()) // Detect window close button or ESC key
    {

        float deltaTime = GetFrameTime();

        // Update

        
        if (IsKeyDown(KEY_A) && newPaddle.getPosition().x >= 0){
            // -speed = -1.0 * speedVector{speed, 0.0f}, for inverse
            newPaddle.move(-(newPaddle.getPosition().x + speed) * deltaTime);
        }

        if (IsKeyDown(KEY_D) && newPaddle.getPosition().x < screenWidth - newPaddle.size.x){
            newPaddle.move((newPaddle.getPosition().x + speed) * deltaTime);
        }
    
        // TODO: Update your variables here

        if (newBall.getPosition().x < 0 || newBall.getPosition().x >= screenWidth){
            ballDirection.x *= -1;
        }

        if (newBall.getPosition().y >= screenHeight || newBall.getPosition().y < 0){
            ballDirection.y *= -1;
        }

        if (newPaddle.CheckCollision(newBall.position, newBall.size)){
            ballDirection.y *= -1;
        }

        newBall.move((ballDirection * ballSpeed) * deltaTime);

        newPaddle.SetPosition(newPaddle.getPosition());

        // Draw
        BeginDrawing();
        ClearBackground(Color{153, 255, 255});
        newPaddle.draw();
        newBall.draw();
        std::string newBallText = std::to_string((int)newBall.position.x) + " . " + std::to_string((int)newBall.position.y);
        std::string newPaddleText = std::to_string((int)newPaddle.GetPosition().x) + " . " + std::to_string((int)newPaddle.GetPosition().y);
        std::string collisionText = "Ball - paddle collision = " + std::to_string(newPaddle.CheckCollision(newBall.position, newBall.size));
        std::string paddleText = "Size: " + std::to_string((int)newPaddle.height) + " - " + std::to_string((int)newPaddle.width);
        raylib::DrawText(newBallText, 5, 5, 16, BLACK);
        raylib::DrawText(newPaddleText, 5, 30, 16, BLACK);
        raylib::DrawText(collisionText, 5, 50, 16, BLACK);
        raylib::DrawText(paddleText, 100, 5, 16, BLACK);

        EndDrawing();
    }

    return 0;
}
