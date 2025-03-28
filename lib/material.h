#ifndef MATERIAL_H
#define MATERIAL_H


#include "hittable.h"

class material{
    public:
        virtual ~material() = default;

        virtual bool scatter(const ray& rIn, const hitRecord& rec, color& attenuation, ray& scattered) const = 0;
    };
    
#endif