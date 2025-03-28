#ifndef LAMBERTIAN_H
#define LAMBERTIAN_H


#include "material.h"

class lambertian: public material{
    public:
        lambertian(const color& a);

        bool scatter(const ray& rIn, const hitRecord& rec, color& attenuation, ray& scattered) const override;

    private:
        color albedo;
};

#endif