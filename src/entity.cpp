
/*
Why this didn't work:
https://stackoverflow.com/a/20385508
Had to move definitions to header
#####################################

#include "raylib-cpp.hpp"
#include "entity.hpp"

template<typename Size>
raylib::Vector2 Entity<Size>::getPosition(){
    return this->position;
    
}

template <typename Size>
void Entity<Size>::move(raylib::Vector2 newPosition){
    this->position += newPosition;
}

*/