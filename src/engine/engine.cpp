//
// Created by eriks on 26/01/2026.
//

#include "engine.h"

Engine::Engine( SDL_Renderer* _renderer) {
    renderer = _renderer;
}

void Engine::render() {
    SDL_SetRenderDrawColor(renderer, 0,0,0,0);
    SDL_RenderClear;


    // Draw
    SDL_SetRenderDrawColor(renderer, 255,0,0,255);
    SDL_RenderDrawPoint(renderer, 100,100);

    // Present
    SDL_RenderPresent(renderer);
}