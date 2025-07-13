#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

#include "WindowRenderer.h"

WindowRenderer::WindowRenderer(const char* _title, int _width, int _height) : window(NULL), renderer(NULL)
{
    this->window = SDL_CreateWindow(_title, _width, _height, SDL_WINDOW_INPUT_FOCUS);

    if (window == NULL) {
        std::cout << "Window failed to create : " << SDL_GetError() << std::endl;
    }

    this->renderer = SDL_CreateRenderer(window, NULL);
}

SDL_Texture* WindowRenderer::LoadTexture(const char* filePath) {
    SDL_Texture* texture = NULL;

    texture = IMG_LoadTexture(this->renderer, filePath);

    if (texture == NULL) {
        std::cout << "Failed to load texture : " << filePath << '\n';
    }

    return texture;
}

void WindowRenderer::Display() {
    SDL_RenderPresent(this->renderer);
}

void WindowRenderer::Render(SDL_Texture* texture) {
    SDL_FRect src;
    src.x = 0; 
    src.y = 0;
    src.h = texture->h;
    src.w = texture->w;

    SDL_FRect dst;
    dst.x = 0; 
    dst.y = 0;
    dst.h = texture->h;
    dst.w = texture->w;

    SDL_RenderTexture(this->renderer, texture, &src, &dst);
}

void WindowRenderer::ClearWindow() {
    SDL_RenderClear(this->renderer);
}

void WindowRenderer::DestroyWindow() {
    SDL_DestroyWindow(this->window);
}