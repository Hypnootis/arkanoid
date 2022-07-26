#pragma once

#include "raylib-cpp.hpp"
#include "entity.hpp"

class Paddle : public Entity {
    public:
        using Entity::Entity;
        void movePaddle(raylib::Vector2 newPosition);
        void draw();

};