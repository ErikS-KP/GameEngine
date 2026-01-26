#include "engine.h"

Engine::Engine( Vec2 _WIN_Size, SDL_Renderer* _renderer, const Camera* _player) {
    WIN_Size = _WIN_Size;
    renderer = _renderer;
    player = _player;

    objLoader = new ObjLoader();
    meshes = objLoader->LoadAllObj();
}

Engine::~Engine() {
    delete objLoader;
}

void Engine::render() {

    SDL_SetRenderDrawColor(renderer, 0,0,0,0);
    SDL_RenderClear(renderer);


    // Draw
    SDL_SetRenderDrawColor(renderer, 255,0,0,255);
    std::vector<SDL_Point> pointsToDraw;
    pointsToDraw.reserve(10000);
    SDL_Point _point;


    for (const Mesh &mesh : meshes) {
        for (const MeshPart &part : mesh.parts) {
            for (const Vec3 point : part.vertices) {
                Vec3 currentPoint = point;
                // Rotate points

                // Camera+World translation
                currentPoint.x += mesh.pos.x + part.pos.x - player->pos.x;
                currentPoint.y += mesh.pos.y + part.pos.y - player->pos.y;
                currentPoint.z += mesh.pos.z + part.pos.z - player->pos.z;


                // Camera rotate
                currentPoint = rotateY(currentPoint, player->yaw);
                currentPoint = rotateX(currentPoint, player->pitch);

                // Project
                if (currentPoint.z > 0) {
                    _point.x = (currentPoint.x / currentPoint.z) * player->focalLength + WIN_Size.x/2;
                    _point.y = -(currentPoint.y / currentPoint.z) * player->focalLength + WIN_Size.y/2;
                    pointsToDraw.push_back(_point);
                }
            }
        }
    }
    SDL_RenderDrawPoints(renderer, pointsToDraw.data(), pointsToDraw.size());

    // Present
    SDL_RenderPresent(renderer);
}