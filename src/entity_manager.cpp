#include "include/entity_manager.h"

#include "include/math.h"

#include <iostream>

EntityManager::EntityManager()
{}

EntityManager::~EntityManager()
{
    for (unsigned long int i = 0; i < this->entities.size(); ++i) 
        this->entities[i].destroy_texture();
    
    this->entities.clear();
    
    std::cout << "ENTITY_MANAGER: Destroyed entity textures and cleared entities vector." << std::endl;
}

void EntityManager::create(Entity entity)
{
    this->entities.emplace_back(entity);
}

void EntityManager::update()
{
    Vector2f player_pos = Vector2f(0.0f, 0.0f);
    for (unsigned long int i = 0; i < this->entities.size(); ++i)
    {
        // Always update the player entity
        if (entities[i].get_id() == PLAYER) {
            player_pos = entities[i].get_pos();
            entities[i].update();
        }
        
        // If the entity is close enough to the player update it
        if (entities[i].get_id() != PLAYER)
        {
            if ((int)get_distance(player_pos, entities[i].get_pos()) <= 430)
            {
                entities[i].update();
            }
        }
    }
}

void EntityManager::render(SDL_Renderer *renderer)
{
    Vector2f player_pos = Vector2f(0.0f, 0.0f);
    for (unsigned long int i = 0; i < this->entities.size(); ++i)
    {
        // Always render the player entity
        if (entities[i].get_id() == PLAYER) {
            player_pos = entities[i].get_pos();
            entities[i].render(renderer);
        }
        
        // If the entity is close enough to the player render it
        if (entities[i].get_id() != PLAYER)
        {
            if ((int)get_distance(player_pos, entities[i].get_pos()) <= 430)
            {
                entities[i].render(renderer);
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
                SDL_RenderDrawLine(renderer, 
                                   (int)player_pos.x,
                                   (int)player_pos.y,
                                   (int)entities[i].get_pos().x, 
                                   (int)entities[i].get_pos().y);
            }
        }
    }
}