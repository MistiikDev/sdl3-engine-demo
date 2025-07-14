#pragma once
#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

#include "Math.h"

class Entity {
    public:
        Entity(Vector2, SDL_Texture* _texture);

        Vector2& getPosition();

        SDL_Texture* getTexture();
        SDL_FRect* getEntityBounds();
    private:
        Vector2& position;

        SDL_FRect* entityBounds;
        SDL_Texture* texture;
};

#endif