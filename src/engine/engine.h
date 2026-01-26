//
// Created by eriks on 26/01/2026.
//

#ifndef GAMEENGINE_ENGINE_H
#define GAMEENGINE_ENGINE_H

#include "../objLoader/objLoader.h"
#include <SDL2/SDL.h>

class Engine {
private:
    SDL_Renderer* renderer;
    ObjLoader* objLoader;

    std::vector<Mesh> meshes;

    public:
    Engine( SDL_Renderer* renderer );
    void render();

};


#endif //GAMEENGINE_ENGINE_H