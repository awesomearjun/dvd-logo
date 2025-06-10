#pragma once

#include <SDL2/SDL.h>
#include <cstddef>

#include "vector.hpp"

class DVD
{
public:
    DVD() = default;
    void init();
    void update();
    void destroy();
    void setImage(const char *path);
    void setVelocity(int x, int y);
	Vector2D getVelocity();
	void setScale(int s);
	Vector2D getPos();
	int getSize();

private:
	int scale;
    SDL_Rect dstRect;
    SDL_Texture *texture;
    Vector2D velocity;
};
