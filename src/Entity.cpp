#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <iostream>

#include "Entity.h"

Entity::Entity(int _x, int _y, SDL_Texture* _texture)
:x(_x), y(_y), texture(_texture)
{
    currentFrame = new SDL_FRect {0, 0, 120, 60};
}

float Entity::getX() {
    return this->x;
}

float Entity::getY() {
    return this->y;
}

SDL_Texture* Entity::getTexture() {
    return this->texture;
}

SDL_FRect* Entity::getCurrentFrame() {
    return this->currentFrame;
}