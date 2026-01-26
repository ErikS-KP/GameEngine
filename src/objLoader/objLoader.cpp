//
// Created by eriks on 26/01/2026.
//

#include "objLoader.h"



std::vector<std::string> ObjLoader::loadPaths() {
    paths.empty();
    for (const auto& entry : fs::directory_iterator(meshes_path) ) {
        if (entry.is_regular_file() && entry.path().extension() == ".obj") {
            paths.push_back(entry.path().string());
        }
    }
    return paths;
}

Mesh ObjLoader::loadMesh(std::string path) {
    current_path = this->meshes_path+path;
    std::cout << "Loading: " << current_path << std::endl;
}

std::vector<Mesh> ObjLoader::LoadAllObj() {

}
