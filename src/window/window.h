//
// Created by eriks on 26/01/2026.
//

#ifndef GAMEENGINE_WINDOW_H
#define GAMEENGINE_WINDOW_H

#include "SDL2/SDL_render.h"

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
};


#endif //GAMEENGINE_WINDOW_H