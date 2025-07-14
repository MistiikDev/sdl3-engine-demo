#pragma once
#ifndef WINDOW_RENDERER_H
#define WINDOW_RENDERER_H

#include <iostream>
#include <vector>

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

#include "Entity.h"

class WindowRenderer {
    public: 
        WindowRenderer(const char* _title, int _width, int _height);
        
        SDL_Texture* LoadTexture(const char* filePath);

        void Render(Entity& entity);
        void Render(std::vector<Entity>& entities);

        void Display();
        void ClearWindow();
        void DestroyWindow();
    private:
        int entityCount;

        SDL_Event* windowResized;
        SDL_Window* window;
        SDL_Renderer* renderer;
};

#endif