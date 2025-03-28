#ifndef HITTABLE_H
#define HITTABLE_H

#include "hitRecord.h"

class hittable{
    public:
        virtual ~hittable() = default;

        virtual bool hit(const ray& r, double rayTMin, double rayTMax, hitRecord & rec) const = 0;
};


#endif