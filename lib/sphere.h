#ifndef SPHERE_H
#define SPHERE_H

#include "hittable.h"
#include "material.h"

class sphere: public hittable{
    private:
        ray center;
        double radius;
        shared_ptr<material> mat;
    public:
        //sphere(const point3& center, double radius, shared_ptr<material> mat);

        sphere(const point3& staticCenter, double radius, shared_ptr<material> mat);
        sphere(const point3& center1, const point3& center2, double radius, shared_ptr<material> mat);

        bool hit(const ray& r, double rayTMin, double rayTMax, hitRecord & rec) const override;
};


#endif