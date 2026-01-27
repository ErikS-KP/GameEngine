#include "application.h"

#include <iostream>
#include <ostream>

Application::Application(){
    int SCREEN_WIDTH    = 1000;
    int SCREEN_HEIGHT   = 800;

    WIN = new Window(SCREEN_WIDTH, SCREEN_HEIGHT);
    window = WIN->getWindow();
    renderer = WIN->getRenderer();
    player = new Camera();
    engine = new Engine(WIN->getSize(), renderer, player);


    SDL_SetRelativeMouseMode(SDL_TRUE);

}

Application::~Application() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    delete WIN;
}


// Run loop
void Application::run() {
    while (WIN->isOpen()) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    WIN->close();
                    std::cout << "Quitting..." << std::endl;
            }
        }
        // Game loop
        update();

        // Render
        engine->render();
    }
    SDL_Quit();
}

void Application::update() {
    Uint64 lastTime = SDL_GetPerformanceCounter();
    float deltaTime = 0.0f;
    Uint64 currentTime = SDL_GetPerformanceCounter();
    deltaTime = (float)(currentTime - lastTime) / (float)SDL_GetPerformanceFrequency();
    lastTime = currentTime;

    SDL_PumpEvents();

    // Keyboard Input
    const Uint8 *keys = SDL_GetKeyboardState(nullptr);

    float speed = deltaTime * player->speed;

    if (keys[SDL_SCANCODE_W]) {
        player->pos.z += cos(player->yaw) * speed;
        player->pos.x -= sin(player->yaw) * speed;
    }

    if (keys[SDL_SCANCODE_S]) {
        player->pos.z -= cos(player->yaw) * speed;
        player->pos.x += sin(player->yaw) * speed;
    }

    if (keys[SDL_SCANCODE_A]) {
        player->pos.z -= sin(player->yaw) * speed;
        player->pos.x -= cos(player->yaw) * speed;
    }

    if (keys[SDL_SCANCODE_D]) {
        player->pos.z += sin(player->yaw) * speed;
        player->pos.x += cos(player->yaw) * speed;
    }

    if (keys[SDL_SCANCODE_SPACE]) {
        player->pos.y += speed;
    }
    if (keys[SDL_SCANCODE_LSHIFT]) {
        player->pos.y -= speed;
    }


    if (keys[SDL_SCANCODE_ESCAPE]) {
        WIN->close();
    }

    int dx, dy;
    SDL_GetRelativeMouseState(&dx, &dy);
    player->yaw -= dx * speed * 0.0005;
    player->pitch -= dy * speed * 0.0005;

}