/* date = August 8th 2021 6:20 pm */

#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H

#include "entity.h"

#include <vector>

class EntityManager 
{
    public:
    EntityManager();
    ~EntityManager();
    void create(Entity entity);
    void update();
    void render(SDL_Renderer *renderer);
    
    private:
    std::vector<Entity> entities;
};

#endif //ENTITY_MANAGER_H
