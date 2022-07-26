#include "paddle.hpp"
#include "raylib-cpp.hpp"

void Paddle::draw(){
    position.DrawRectangle(this->size, MAROON);
}

