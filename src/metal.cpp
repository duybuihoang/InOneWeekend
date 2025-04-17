#include "metal.h"
#include "sphere.h"
#include "utils.h"

metal::metal(const color& albedo, double fuzz): 
albedo(albedo),
fuzz(fuzz < 1 ? fuzz : 1)
{}


bool metal::scatter(const ray& rIn, const hitRecord& rec, color& attenuation, ray& scattered) const {
    vec3 reflected = reflect(unitVector(rIn.direction()), rec.normal);
    reflected = unitVector(reflected) + fuzz * randomUnitVector();

    scattered = ray(rec.p, reflected, rIn.time());
    attenuation = albedo;

    return (dot(scattered.direction(), rec.normal) > 0);
}
// Compare this snippet from src/main.cpp