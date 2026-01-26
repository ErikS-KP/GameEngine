//
// Created by eriks on 26/01/2026.
//

#ifndef GAMEENGINE_APPLICATION_H
#define GAMEENGINE_APPLICATION_H
#pragma once

#include "../window/window.h"
#include <SDL2/SDL.h>

// ====================
// Init window
// Init renderer
// Run
// Handle events
// Game loop
// ====================

class Application {
private:
    int width, height;

    Window* windowClass;

    SDL_Window* window;
    SDL_Renderer* renderer;


public:
    Application();

    void run();
};


#endif //GAMEENGINE_APPLICATION_H