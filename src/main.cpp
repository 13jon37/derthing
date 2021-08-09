#include "include/platform.h"
#include "include/entity_manager.h"

int main(int argc, char *argv[])
{
    Platform platform = Platform("derthing");
    
    static EntityManager entity_manager = {};
    
    Entity player = Entity("Assets/ball.png",
                           Vector2f(25, 25), 
                           PLAYER,
                           platform.get_renderer());
    // Push player to entity manager vector
    entity_manager.create(player);
    
    Entity enemy = Entity("Assets/grass_block.png",
                          Vector2f(25, 455), 
                          ENEMY,
                          platform.get_renderer());
    entity_manager.create(enemy);
    
    Entity enemy2 = Entity("Assets/grass_block.png",
                           Vector2f(55, 43), 
                           ENEMY,
                           platform.get_renderer());
    entity_manager.create(enemy2);
    
    bool running = true;
    SDL_Event event = {};
    
    while (running)
    {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                running = false;
        }
        
        // Update
        entity_manager.update();
        
        // Render
        SDL_SetRenderDrawColor(platform.get_renderer(), 0, 0, 0, 255);
        platform.clear();
        
        entity_manager.render(platform.get_renderer());
        
        platform.present();
    }
    
    return 0;
}