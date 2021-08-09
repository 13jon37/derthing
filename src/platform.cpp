#include "include/platform.h"
#include <iostream>

Platform::Platform(const char *title)
:window(0), renderer(0)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) 
    {
        std::cout << "Failed to init SDL." << std::endl;
        exit(1);
    }
    
    this->window = 
        SDL_CreateWindow(title,
                         SDL_WINDOWPOS_UNDEFINED,
                         SDL_WINDOWPOS_UNDEFINED,
                         800,
                         600,
                         SDL_WINDOW_SHOWN);
    
    if (!this->window) 
    {
        std::cout << "Failed to create window." << std::endl;
        exit(1);
    }
    
    this->renderer =
        SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    
    if (!this->renderer) 
    {
        std::cout << "Failed to create renderer." << std::endl;
        exit(1);
    }
}

Platform::~Platform()
{
    SDL_DestroyWindow(this->window);
    SDL_DestroyRenderer(this->renderer);
    SDL_Quit();
    std::cout << "PLATFORM: Destroyed window and renderer and quit SDL." << std::endl;
}

void Platform::present()
{
    SDL_RenderPresent(this->renderer);
}

void Platform::clear()
{
    SDL_RenderClear(this->renderer);
}

SDL_Renderer *Platform::get_renderer()
{
    return this->renderer;
}

