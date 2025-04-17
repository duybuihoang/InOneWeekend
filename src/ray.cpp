#include"ray.h"

ray::ray():
    orig{0,0,0},
    dir{0,0,0}
{}

ray::ray(const point3& origin, const vec3& direction, double time):
    orig{origin},
    dir{direction},
    tm{time}
{}
ray::ray(const point3& origin, const vec3& direction):
    orig{origin},
    dir{direction}
{}

const point3& ray::origin() const{
    return orig;
}

const vec3& ray::direction() const{
    return dir;
}

point3 ray::at(double t) const{
    return orig + t*dir;
}

double ray::time() const{
    return tm;
}