#ifndef HITRECORD_H
#define HITRECORD_H

#include "ray.h"
#include "utils.h"
class material;

class hitRecord{
    public:
        point3 p;
        vec3 normal;
        double t;  
        bool frontFace;
        shared_ptr<material> mat;
        
        void setFaceNormal(const ray& r, const vec3& outwardNormal);
};

#endif