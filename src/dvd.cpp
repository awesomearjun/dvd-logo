#include "dvd.hpp"

#include <SDL2/SDL_image.h>

#include <SDL2/SDL_render.h>

#include <iostream>

#include "SDL2/SDL_error.h"
#include "SDL2/SDL_log.h"
#include "game.hpp"
#include "vector.hpp"

#include <cstddef>

// Image has to be 32x32
void DVD::setImage(const char *path)
{
    SDL_Surface *loadedSurface = IMG_Load(path);

    if (loadedSurface == NULL)
    {
        SDL_Log("Surface is null: %s", SDL_GetError());
    }
    else
    {
        texture =
            SDL_CreateTextureFromSurface(Logo::gameRenderer, loadedSurface);
        SDL_FreeSurface(loadedSurface);
    }

    if (texture == nullptr)
        std::cerr << "Error loading texture: " << SDL_GetError() << std::endl;
}

void DVD::setScale(int s)
{
    dstRect.w *= s;
    dstRect.h *= s;
	scale = s;
}

void DVD::setVelocity(int x, int y)
{
    velocity.x = x;
    velocity.y = y;
}

Vector2D DVD::getVelocity() { return velocity; }

void DVD::init()
{
	// 1 so it doesn't count as collision
    dstRect.x = 1;
    dstRect.y = 1;
    dstRect.w = 32;
    dstRect.h = 32;
}

void DVD::update()
{
    dstRect.x += velocity.x;
    dstRect.y += velocity.y;

    if (texture == nullptr)
    {
        SDL_Log("Texture is null");
        return;
    }

    SDL_RenderCopy(Logo::gameRenderer, texture, NULL, &dstRect);
}

Vector2D DVD::getPos()
{
    Vector2D pos = Vector2D(dstRect.x, dstRect.y);
    return Vector2D(dstRect.x, dstRect.y);
}

void DVD::destroy() { SDL_DestroyTexture(texture); }

int DVD::getSize()
{
	return 32 * scale;
}
