#ifndef HITTABLE_H
#define HITTABLE_H

#include "hitRecord.h"
#include "aabb.h"

class hittable{
    public:
        virtual ~hittable() = default;

        virtual bool hit(const ray& r, interval rayT, hitRecord & rec) const = 0;

        virtual aabb boundingBox() const = 0;
};


#endif