#include "paddle.hpp"
#include "raylib-cpp.hpp"

void Paddle::draw(){
    position.DrawRectangle(this->size, MAROON);
}

void Paddle::movePaddle(raylib::Vector2 newPosition){
    this->position += newPosition;
}

