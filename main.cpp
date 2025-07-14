#include <iostream>
#include <vector>
#include <SDL3/SDL.h>
#include <SDL3/SDL_video.h>

#include "WindowRenderer.h"
#include "Entity.h"
#include "Math.h"

const int WIDTH = 1280;
const int HEIGTH = 720;

int main( int argc, char* argv[] ) {
    SDL_Init( SDL_INIT_VIDEO );

    WindowRenderer renderWindow("Game", WIDTH, HEIGTH);

    SDL_Event windowEvent;
    SDL_Texture* background_tex = renderWindow.LoadTexture("images/background/day_background.jpg");
    SDL_Texture* grass_tex = renderWindow.LoadTexture("images/sprites/grass.png");

    Entity Background(Vector2(), background_tex);
    Entity Grass1(Vector2(100, 300), grass_tex);
    Entity Grass2(Vector2(116, 300), grass_tex);
    Entity Grass3(Vector2(132, 300), grass_tex);
    Entity Grass4(Vector2(148, 300), grass_tex);

    std::vector<Entity> entities = {Background, Grass1, Grass2, Grass3, Grass4};

    while (true) {
        if (SDL_PollEvent(&windowEvent)) {
            if (windowEvent.type == SDL_EVENT_QUIT) {
                break;
            }
        }

        renderWindow.ClearWindow();
        renderWindow.Render(entities);
        renderWindow.Display();
    }

    renderWindow.DestroyWindow();
    SDL_Quit();

    return EXIT_SUCCESS;
}

