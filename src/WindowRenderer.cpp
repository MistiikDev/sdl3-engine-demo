#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

#include "WindowRenderer.h"
#include "Entity.h"

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

void WindowRenderer::Render(Entity& entity) {
    SDL_FRect src;
    src.x = entity.getCurrentFrame()->x; 
    src.y = entity.getCurrentFrame()->y;
    src.h = entity.getCurrentFrame()->h;
    src.w = entity.getCurrentFrame()->w;

    SDL_FRect dst;
    dst.x = entity.getX(); 
    dst.y = entity.getY();
    dst.h = entity.getCurrentFrame()->h * 4;
    dst.w = entity.getCurrentFrame()->w * 4;

    SDL_RenderTexture(this->renderer, entity.getTexture(), &src, &dst);
}

void WindowRenderer::ClearWindow() {
    SDL_RenderClear(this->renderer);
}

void WindowRenderer::DestroyWindow() {
    SDL_DestroyWindow(this->window);
}