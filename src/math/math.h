//
// Created by eriks on 26/01/2026.
//

#ifndef GAMEENGINE_MATH_H
#define GAMEENGINE_MATH_H
#pragma once


#include "../core/structs.h"
#include <cmath>

float sin( float rad ) {
    return std::sin( rad );
}

float cos( float rad ) {
    return std::cos( rad );
}

Vec3 transform_point( Vec3 vert ) {
    return vert;
}



#endif //GAMEENGINE_MATH_H