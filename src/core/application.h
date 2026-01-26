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
#include "../math/math.h"
#include <SDL2/SDL.h>

class Application {
private:
    int width, height;

    Window* WIN;

    SDL_Window* window;
    SDL_Renderer* renderer;
    Engine* engine;
    Camera* player;


public:
    Application();
    ~Application();

    void run();
    void update();
};


#endif //GAMEENGINE_APPLICATION_H