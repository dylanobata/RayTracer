#pragma once

#include "Vec3.h"

class Ray
{
public:
    // attributes
    point3 orig;
    Vec3 dir;

    // methods
    Ray() {}
    Ray(const point3& origin, const Vec3& direction)
        : orig(origin), dir(direction) {}
    point3 origin() const { return orig; }
    Vec3 direction() const { return dir; }

    point3 at(double t) const { return orig + t*dir; }

};
