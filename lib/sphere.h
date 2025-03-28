#ifndef SPHERE_H
#define SPHERE_H

#include "hittable.h"
#include "material.h"

class sphere: public hittable{
    private:
        point3 center;
        double radius;
        shared_ptr<material> mat;
    public:
        sphere(const point3& center, double radius, shared_ptr<material> mat);
        bool hit(const ray& r, double rayTMin, double rayTMax, hitRecord & rec) const override;
};


#endif