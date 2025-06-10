#include "game.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <cmath>
#include <cstdio>
#include <format>
#include <iostream>
#include <sstream>
#include <utility>

#include "SDL2/SDL_render.h"
#include "SDL2/SDL_video.h"
#include "vector.hpp"

#define INVERT_LOGO_X_VELO                                                     \
    logo.setVelocity(logo.getVelocity().x * -1, logo.getVelocity().y)
#define INVERT_LOGO_Y_VELO                                                     \
    logo.setVelocity(logo.getVelocity().x, logo.getVelocity().y * -1)
#define DEBUG_MODE false
#include <stdio.h>

SDL_Renderer *Logo::gameRenderer = nullptr;

Logo::Logo() : window(nullptr) {}

void Logo::init(const char *title, int x, int y, int w, int h, uint32_t flags)
{

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        std::cerr << "Error initializing SDL: " << SDL_GetError() << std::endl;

    if (IMG_Init(IMG_INIT_PNG) < 0)
    {
        std::cerr << "Error initializing SDL_image: " << SDL_GetError()
                  << std::endl;
    }

    window = SDL_CreateWindow(title, x, y, w, h, flags);

    if (window == nullptr)
        std::cerr << "Error making window: " << SDL_GetError() << std::endl;

    Logo::gameRenderer = SDL_CreateRenderer(
        window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (Logo::gameRenderer == nullptr)
        std::cerr << "Error making renderer" << SDL_GetError() << std::endl;

    logo.init();
    logo.setImage("./assets/dvd-logo.png");
    logo.setScale(2);
    logo.setVelocity(1, 1);
}

void Logo::update()
{
    SDL_Event event;
    bool gameOver = false;

    while (!gameOver)
    {
        while (SDL_PollEvent(&event))
            if (event.type == SDL_QUIT)
                gameOver = true;

        SDL_RenderClear(Logo::gameRenderer);

        SDL_GetWindowSize(window, &windowWidth, &windowHeight);

        logo.update();
        collisionManager();

        SDL_RenderPresent(Logo::gameRenderer);
    }
}

void Logo::destroy()
{
    logo.destroy();

    IMG_Quit();
    SDL_DestroyRenderer(Logo::gameRenderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Logo::collisionManager()
{
    // Get pos of each corner
    const int logoSize = logo.getSize();
    const Vector2D topLeft = logo.getPos();
    const Vector2D topRight = Vector2D(topLeft.x + logoSize, logo.getPos().y);
    const Vector2D bottomRight = Vector2D(topLeft.x, topRight.y + logoSize);

    if (topRight.x > windowWidth || topLeft.x < 0)
        INVERT_LOGO_X_VELO;

    if (bottomRight.y > windowHeight || topRight.y < 0)
        INVERT_LOGO_Y_VELO;
}
