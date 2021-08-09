/* date = August 8th 2021 6:01 pm */

#ifndef ENTITY_H
#define ENTITY_H

#include <SDL2/SDL.h>

#include "math.h"

enum EntityType 
{
    PLAYER = 0,
    ENEMY = 1
};

class Entity 
{
    public:
    Entity(const char *texture_path, Vector2f p_pos, int p_id, SDL_Renderer *renderer);
    ~Entity();
    Vector2f &get_pos();
    void input();
    void update();
    void render(SDL_Renderer *renderer);
    void destroy_texture();
    int get_id() { return this->id; };
    
    private:
    Vector2f pos;
    SDL_Texture *texture;
    int id;
};

#endif //ENTITY_H
