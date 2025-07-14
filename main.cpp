#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3/SDL_video.h>

#include "WindowRenderer.h"
#include "Entity.h"

const int WIDTH = 1280;
const int HEIGTH = 720;

int main( int argc, char* argv[] ) {
    SDL_Init( SDL_INIT_VIDEO  );

    WindowRenderer renderWindow("Game", WIDTH, HEIGTH);

    SDL_Event windowEvent;
    SDL_Texture* cross_tex = renderWindow.LoadTexture("images/sprites/cross.png");

    Entity Cross(0, 0, cross_tex);

    while (true) {
        if (SDL_PollEvent(&windowEvent)) {
            if (windowEvent.type == SDL_EVENT_QUIT) {
                break;
            }
        }

        renderWindow.ClearWindow();
        renderWindow.Render(Cross);
        renderWindow.Display();
    }

    renderWindow.DestroyWindow();
    SDL_Quit();

    return EXIT_SUCCESS;
}

