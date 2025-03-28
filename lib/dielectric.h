#ifndef DIELECTRIC_H
#define DIELECTRIC_H


#include "material.h"
#include "hittable.h"

class dielectric: public material{

    public:
    dielectric(double refractionIndex);
    bool scatter(const ray& rIn, const hitRecord& rec, color& attenuation, ray& scattered) const override;

    private:
    double refractionIndex;

    static double reflectance(double cosine, double refractionIndex){
        // Use Schlick's approximation for reflectance
        auto r0 = (1-refractionIndex) / (1+refractionIndex);
        r0 = r0 * r0;
        return r0 + (1-r0) * pow((1 - cosine), 5);
    }

};


#endif