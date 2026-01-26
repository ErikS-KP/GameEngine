//
// Created by eriks on 26/01/2026.
//

#include "application.h"

#include <iostream>
#include <ostream>

Application::Application(){
    int SCREEN_WIDTH    = 1000;
    int SCREEN_HEIGHT   = 800;

    WIN = new Window(SCREEN_WIDTH, SCREEN_HEIGHT);
    window = WIN->getWindow();
    renderer = WIN->getRenderer();
    engine = new Engine(renderer);

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
            // Game loop
            update();
            engine->render();
            // Render
        }
    }
    SDL_Quit();
}

void Application::update() {

}