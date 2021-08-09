/* date = August 8th 2021 5:49 pm */

#ifndef PLATFORM_H
#define PLATFORM_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Platform 
{
    public:
    Platform(const char *title);
    ~Platform();
    void present();
    void clear();
    SDL_Renderer *get_renderer();
    
    private:
    SDL_Window *window;
    SDL_Renderer *renderer;
};

#endif //PLATFORM_H
