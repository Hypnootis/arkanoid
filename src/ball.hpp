#pragma once

#include "entity.hpp"

class Ball : public Entity<float>{
    public:
    using Entity::Entity;
    raylib::Vector2 direction = {1.0f, -1.0f};
    void draw();
};