#pragma once

#include <SDL2/SDL.h>

#include "dvd.hpp"

class Logo
{
public:
    Logo();
    void init(const char *title, int x, int y, int w, int h, uint32_t flags);
    void update();
    void destroy();
    static SDL_Renderer *gameRenderer;
	void collisionManager();

private:
	int windowWidth;
	int windowHeight;
	DVD logo;
    SDL_Window *window;
};
