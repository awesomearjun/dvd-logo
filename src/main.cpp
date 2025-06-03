#include "SDL2/SDL_error.h"
#include "SDL2/SDL_events.h"
#include "SDL2/SDL_render.h"
#include "SDL2/SDL_video.h"
#include <SDL2/SDL.h>
#include <iostream>

int main()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cerr << "SDL not getting inited" << SDL_GetError() << std::endl;
        return -1;
    }

    SDL_Window *window = SDL_CreateWindow("DVD", SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED, 800, 600, 0);

    if (window == nullptr)
    {
        std::cerr << "Window problem: " << SDL_GetError() << std::endl;
        return -2;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(
        window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (renderer == nullptr)
    {
        std::cerr << "Renderer problem: " << SDL_GetError() << std::endl;
        return -3;
    }

    bool gameOver = false;
    SDL_Event event;

    while (!gameOver)
    {
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                gameOver = true;
                break;
            default:
                break;
            }
        }

        SDL_SetRenderDrawColor(renderer, 22, 84, 150, 255);
        SDL_RenderClear(renderer);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
