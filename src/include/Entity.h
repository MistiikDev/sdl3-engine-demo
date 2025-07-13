#pragma once
#ifndef ENTITY_H
#define ENTITY_H

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

class Entity {
    public:
        SDL_FRect* currentFrame;

    private:
        double x, y;
};

#endif