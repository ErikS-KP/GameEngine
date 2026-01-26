//
// Created by eriks on 26/01/2026.
//

#ifndef GAMEENGINE_ENGINE_H
#define GAMEENGINE_ENGINE_H

#include "../objLoader/objLoader.h"
#include <SDL2/SDL.h>

class engine {
private:
    SDL_Renderer* renderer;
    ObjLoader* objLoader;

    std::vector<Mesh> meshes;

    public:
    engine();
    void render();

};


#endif //GAMEENGINE_ENGINE_H