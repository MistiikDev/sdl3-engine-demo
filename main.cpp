#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3/SDL_video.h>

#include "WindowRenderer.h"
#include "Entity.h"

const int WIDTH = 1280;
const int HEIGTH = 720;

int main( int argc, char* argv[] ) {
    SDL_Init( SDL_INIT_VIDEO );

    WindowRenderer renderWindow("Game Template", WIDTH, HEIGTH);

    SDL_Event windowEvent;
    Entity Cross;
    SDL_Texture* cross = renderWindow.LoadTexture("images/sprites/cross.png");

    while (true) {
        if (SDL_PollEvent(&windowEvent)) {
            if (windowEvent.type == SDL_EVENT_QUIT) {
                break;
            }
        }

        renderWindow.ClearWindow();
        renderWindow.Render(cross);
        renderWindow.Display();
    }

    renderWindow.DestroyWindow();
    SDL_Quit();

    return EXIT_SUCCESS;
}

