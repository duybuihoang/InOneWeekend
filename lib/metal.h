#ifndef METAL_H
#define METAL_H

#include "material.h"

class metal: public material{
    public:
        metal(const color& albedo, double fuzz);

        bool scatter(const ray& rIn, const hitRecord& rec, color& attenuation, ray& scattered) const override;

    private:
        color albedo;
        double fuzz;
};
#endif