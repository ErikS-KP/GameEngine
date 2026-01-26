//
// Created by eriks on 26/01/2026.
//

#include "application.h"

#include <iostream>
#include <ostream>

Application::Application(){
    int SCREEN_WIDTH    = 1000;
    int SCREEN_HEIGHT   = 800;

    windowClass = new Window(SCREEN_WIDTH, SCREEN_HEIGHT);
    window = windowClass->getWindow();
    renderer = windowClass->getRenderer();

}

void Application::run() {
    while (windowClass->isOpen()) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    windowClass->close();
                    std::cout << "Quitting..." << std::endl;
            }
        }
    }
    SDL_Quit();
}
