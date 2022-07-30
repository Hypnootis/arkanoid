#pragma once

#include "entity.hpp"

class Paddle : public Entity<raylib::Vector2>{
    public:
        using Entity::Entity;
        void draw();

};