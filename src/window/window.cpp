//
// Created by eriks on 26/01/2026.
//

#include "window.h"

Window::Window(int width, int height)
    : width(width), height(height){
    window = SDL_CreateWindow(
        "Game Engine",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        width,
        height,
        SDL_WINDOW_SHOWN
        );

    renderer = SDL_CreateRenderer(
        window,
        -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
        );
}

Window::~Window() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
}