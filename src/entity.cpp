#include "include/entity.h"

#include <iostream>
#include <SDL2/SDL_image.h>

Entity::Entity(const char *texture_path, 
               Vector2f p_pos, int p_id, SDL_Renderer *renderer)
: pos(p_pos), texture(0), id(p_id) 
{
    SDL_Surface *surface = IMG_Load(texture_path);
    this->texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    
    if (!this->texture) 
    {
        std::cout << "Failed to create texture from surface!" << std::endl;
        exit(1);
    }
}

Entity::~Entity()
{}

Vector2f &Entity::get_pos()
{
    return this->pos;
}

void Entity::input()
{
    const unsigned char *keyboard = SDL_GetKeyboardState(NULL);
    
    if (keyboard[SDL_SCANCODE_A])
        this->pos.x -= 1;
    if (keyboard[SDL_SCANCODE_D])
        this->pos.x += 1;
    if (keyboard[SDL_SCANCODE_W])
        this->pos.y -= 1;
    if (keyboard[SDL_SCANCODE_S])
        this->pos.y += 1;
}

void Entity::update()
{
    switch (this->id) {
        case PLAYER: {
            input();
        } break;
        
        case ENEMY: {
            this->pos.x += 1;
        } break;
        
        default: {};
    }
}

void Entity::render(SDL_Renderer *renderer)
{
    SDL_Rect rect = { (int)pos.x,(int)pos.y, 16, 16 };
    SDL_RenderCopy(renderer, this->texture, 0, &rect);
}

void Entity::destroy_texture()
{
    SDL_DestroyTexture(this->texture);
}