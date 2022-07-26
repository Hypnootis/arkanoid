#pragma once

#include "raylib-cpp.hpp"

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