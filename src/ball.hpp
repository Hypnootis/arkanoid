#pragma once

#include "entity.hpp"

class Ball : Entity<float>{
    public:
    using Entity::Entity;
    void draw();

};