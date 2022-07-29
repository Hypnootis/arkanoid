#pragma once

#include "raylib-cpp.hpp"

// Using a template to not have the size be a certain type, i.e vector.
template<typename Size>
class Entity {
    public:
    explicit Entity(Size size, raylib::Vector2 initPosition){
        this->size = size;
        this->position = initPosition;
    }
        raylib::Vector2 getPosition(){
            return this->position;
        }
        void move(raylib::Vector2 newPosition){
            this->position += newPosition;
        }
        virtual void draw() = 0;
        Size size;
        raylib::Vector2 position;

};