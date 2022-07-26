#pragma once

#include "raylib-cpp.hpp"

class Entity {
    public:
        
    explicit Entity(raylib::Vector2 size, raylib::Vector2 initPosition){
        this->size = size;
        this->position = initPosition;
    }
        raylib::Vector2 getPosition();
        virtual void draw() = 0;
        raylib::Vector2 size;
        raylib::Vector2 position;
};