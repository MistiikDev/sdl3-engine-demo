#pragma once
#ifndef WINDOW_RENDERER_H
#define WINDOW_RENDERER_H

#include <SDL3/SDL.h>

class WindowRenderer {
    public: 
        WindowRenderer(const char* _title, int _width, int _height);
        
        SDL_Texture* LoadTexture(const char* filePath);

        void Render(SDL_Texture* texture);
        void Display();
        void ClearWindow();
        void DestroyWindow();
    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
};

#endif