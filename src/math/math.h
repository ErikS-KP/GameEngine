#ifndef GAMEENGINE_MATH_H
#define GAMEENGINE_MATH_H
#pragma once


#include "../core/structs.h"
#include <cmath>

inline float sin( float rad ) {
    return std::sin( rad );
}

inline float cos( float rad ) {
    return std::cos( rad );
}



inline Vec3 rotateY(const Vec3& p, const float angle) {
    float cosA = cosf(angle);
    float sinA = sinf(angle);

    return {
        p.x * cosA + p.z * sinA,
        p.y,
        -p.x * sinA + p.z * cosA
    };
}

inline Vec3 rotateX(const Vec3& p, float angle) {
    float cosA = cosf(angle);
    float sinA = sinf(angle);

    return {
        p.x,
        p.y * cosA - p.z * sinA,
        p.y * sinA + p.z * cosA
    };
}



#endif //GAMEENGINE_MATH_H