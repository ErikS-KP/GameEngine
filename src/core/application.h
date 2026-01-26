//
// Created by eriks on 26/01/2026.
//

#ifndef GAMEENGINE_APPLICATION_H
#define GAMEENGINE_APPLICATION_H
#pragma once

// ====================
// Init window
// Init renderer
// Run
// Handle events
// Game loop
// ====================

#include "../window/window.h"
#include "../engine/engine.h"
#include <SDL2/SDL.h>

class Application {
private:
    int width, height;

    Window* WIN;


    SDL_Window* window;
    SDL_Renderer* renderer;
    Engine* engine;


public:
    Application();

    void run();
    void update();
};


#endif //GAMEENGINE_APPLICATION_H