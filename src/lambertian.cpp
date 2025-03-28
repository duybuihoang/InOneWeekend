#include "lambertian.h"
#include "vec3.h"

lambertian::lambertian(const color& a): albedo(a){}

bool lambertian::scatter(const ray& rIn, const hitRecord& rec, color& attenuation, ray& scattered) const {
    vec3 scatterDirection = rec.normal + randomUnitVector();


    if(scatterDirection.nearZero()){
        scatterDirection = rec.normal;
    }

    scattered = ray(rec.p, scatterDirection);
    attenuation = albedo;
    return true;
}