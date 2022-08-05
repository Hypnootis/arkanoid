#pragma once

#include "entity.hpp"

class Paddle : public Entity<raylib::Vector2>, public raylib::Rectangle{
    public:
        using Entity::Entity;
        void draw();

};