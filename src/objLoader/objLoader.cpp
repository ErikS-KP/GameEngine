#include "objLoader.h"

ObjLoader::ObjLoader() = default;

std::vector<std::string> ObjLoader::loadPaths() {
    for (const auto& entry : fs::directory_iterator(meshes_path) ) {
        if (entry.is_regular_file() && entry.path().extension() == ".obj") {
            paths.push_back(entry.path().string());
        }
    }
    return paths;
}

Mesh ObjLoader::loadMesh(const std::string &path) {
    currentMesh = Mesh();
    currentMesh.name = path.substr(21);
    current_path = path;
    std::cout << "Loading: " << currentMesh.name << std::endl;

    // Load Parts
    currentPart = MeshPart();
    std::ifstream file(path);

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string prefix;
        ss >> prefix;

        // Object name
        if (prefix == "o") {

            if (currentMesh.parts.size() == 0) {
                ss >> currentPart.name;
            }
            else {
                currentMesh.parts.push_back(currentPart);
                currentPart = MeshPart();
                ss >> currentPart.name;
            }
        }

        // Vertices
        else if (prefix == "v") {
            Vec3 v{};
            ss >> v.x >> v.y >> v.z;
            currentPart.vertices.push_back(v);
        }

        // Faces
        else if (prefix == "f") {
            Face f{};
            std::string v1, v2, v3;

            ss >> v1 >> v2 >> v3;
            f.v1 = std::stoi(v1.substr(0, v1.find('/'))) - 1;
            f.v2 = std::stoi(v2.substr(0, v1.find('/'))) - 1;
            f.v3 = std::stoi(v3.substr(0, v1.find('/'))) - 1;

            currentPart.faces.push_back(f);
        }
    }
    currentMesh.parts.push_back(currentPart);

    return currentMesh;
}

std::vector<Mesh> ObjLoader::LoadAllObj() {
    paths = this->loadPaths();

    for (const auto &path : paths) {

        Mesh _mesh = this->loadMesh(path);
        meshes.push_back(_mesh);
    }

    return meshes;
}