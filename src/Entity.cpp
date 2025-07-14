#include "Entity.h"

Entity::Entity(Vector2 pos, SDL_Texture* _texture)
    :position(pos), texture(_texture)
{
    entityBounds = new SDL_FRect {0, 0, static_cast<float>(_texture->w), static_cast<float>(_texture->h)};
}

Vector2& Entity::getPosition() {
    return this->position;
}

SDL_Texture* Entity::getTexture() {
    return this->texture;
}

SDL_FRect* Entity::getEntityBounds() {
    return this->entityBounds;
}