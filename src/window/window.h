#ifndef GAMEENGINE_WINDOW_H
#define GAMEENGINE_WINDOW_H

#include "SDL2/SDL_render.h"
#include "../core/structs.h"

// ====================
// Create window
// Create renderer
// ====================

class Window {
private:
    int width, height;

    SDL_Window* window;
    SDL_Renderer* renderer;

    bool isOpenVar;

public:
    Window( int width, int height );
    ~Window();

    SDL_Window* getWindow(){ return window; };
    SDL_Renderer* getRenderer(){ return renderer; };
    bool isOpen(){ return isOpenVar; };
    bool close(){ return isOpenVar = false; };
    Vec2 getSize();
};


#endif //GAMEENGINE_WINDOW_H