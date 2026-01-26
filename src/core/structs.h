//
// Created by eriks on 26/01/2026.
//

#ifndef GAMEENGINE_STRUCTS_H
#define GAMEENGINE_STRUCTS_H
#pragma once

#include <string>
#include <vector>

struct Vec3 {
    float x, y, z;
};

struct MeshPart {
    std::string name;
    std::vector<Vec3> vertices;
};

struct Mesh {
    std::string name;
    std::vector<MeshPart> parts;
    std::vector<std::vector<int>> faces;
};


#endif //GAMEENGINE_STRUCTS_H