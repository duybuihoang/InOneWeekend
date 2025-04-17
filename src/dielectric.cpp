#include "dielectric.h"

dielectric::dielectric(double refractionIndex): refractionIndex(refractionIndex)
{}

bool dielectric::scatter(const ray& rIn, const hitRecord& rec, color& attenuation, ray& scattered) const {
    attenuation = color(1.0, 1.0, 1.0);
    double ri = rec.frontFace ? (1.0 / refractionIndex) : refractionIndex;

    vec3 unitDirection = unitVector(rIn.direction());
    double cosTheta = fmin(dot(-unitDirection, rec.normal), 1.0);
    double sinTheta = sqrt(1.0 - cosTheta * cosTheta);

    bool cannotRefract = ri * sinTheta > 1.0;
    vec3 direction;

    if(cannotRefract)
    {
        direction = reflect(unitDirection, rec.normal);
    }
    else
    {
        direction = refract(unitDirection, rec.normal, ri);
    }

    scattered = ray(rec.p, direction, rIn.time());
    return true;
}
