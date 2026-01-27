#ifndef GAMEENGINE_STRUCTS_H
#define GAMEENGINE_STRUCTS_H
#pragma once

#include <string>
#include <vector>

struct Vec2 {
    float x,y;
};

struct Vec3 {
    float x, y, z, w=1;
};


struct Mat4 {
    float m[4][4];
};

struct Face {
    int v1, v2, v3;
};

struct MeshPart {
    std::string         name;
    std::vector<Vec3>   vertices;
    Vec3                pos;
    Vec3                rot;
    std::vector<Face>   faces;
};

struct Mesh {
    std::string name;
    std::vector<MeshPart> parts;
    Vec3                pos;
    Vec3                rot;
};


struct Camera {
    Vec3 pos;
    float yaw = 0;
    float pitch = 0;
    float focalLength = 400;
    float speed = 5000000;
};

#endif //GAMEENGINE_STRUCTS_H