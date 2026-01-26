#ifndef GAMEENGINE_ENGINE_H
#define GAMEENGINE_ENGINE_H

#include "../objLoader/objLoader.h"
#include "../math/math.h"
#include <SDL2/SDL.h>

class Engine {
private:
    SDL_Window*     window;
    Vec2            WIN_Size;
    SDL_Renderer*   renderer;
    ObjLoader*      objLoader;
    const Camera *player;

    std::vector<Mesh> meshes;

    public:
    Engine( Vec2 _WIN_Size, SDL_Renderer* _renderer, const Camera* _player );
    ~Engine();

    void render();

};


#endif //GAMEENGINE_ENGINE_H