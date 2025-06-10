#include "SDL2/SDL_video.h"
#include "game.hpp"

int main()
{
    Logo dvdLogo;

    dvdLogo.init("Bouncing DVD Logo", SDL_WINDOWPOS_CENTERED,
                 SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_RESIZABLE);
    dvdLogo.update();
    dvdLogo.destroy();
}
