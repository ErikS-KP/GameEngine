#ifndef GAMEENGINE_OBJLOADER_H
#define GAMEENGINE_OBJLOADER_H


#include "../core/structs.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

class ObjLoader {
private:
    std::vector<std::string>    paths;
    const std::string           meshes_path = "../src/Assets/Meshes";
    std::vector<std::string>    loadPaths();

    std::vector<Mesh>   meshes;
    std::string         current_path;
    MeshPart            currentPart;
    Mesh                currentMesh;
    Mesh                loadMesh(const std::string &path);



public:
    ObjLoader();
    std::vector<Mesh> LoadAllObj();
};


#endif //GAMEENGINE_OBJLOADER_H