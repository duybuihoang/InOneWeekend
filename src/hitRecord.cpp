#include "hitRecord.h"

void hitRecord::setFaceNormal(const ray& r, const vec3& outwardNormal){
    frontFace = dot(r.direction(), outwardNormal) < 0;
    normal = frontFace ? outwardNormal : -outwardNormal;
}