#ifndef RAY_H
#define RAY_H

#include "vec3.h"
class ray{
    private:
    point3 orig;
    vec3 dir;
    double tm;

    public:
    ray();
    ray(const point3& origin, const vec3& direction, double time);
    ray(const point3& origin, const vec3& direction);


    const point3& origin() const;
    const vec3& direction() const;

    point3 at(double t) const;
    double time() const;

    double Time() const;
};



#endif