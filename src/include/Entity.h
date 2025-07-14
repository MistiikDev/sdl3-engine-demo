#pragma once
#ifndef ENTITY_H
#define ENTITY_H

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

class Entity {
    public:
        Entity(int _x, int _y, SDL_Texture* _texture);

        float getX();
        float getY();

        SDL_Texture* getTexture();
        SDL_FRect* getCurrentFrame();
    private:
        double x, y;

        SDL_FRect* currentFrame;
        SDL_Texture* texture;
};

#endif