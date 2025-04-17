#ifndef HITTABLELIST_H
#define HITTABLELIST_H


#include "hittable.h"
#include "utils.h"

#include <vector>

class hittableList : public hittable{
    private:
        aabb bbox;
    public: 
    std::vector<shared_ptr<hittable>> objects;

    hittableList();
    hittableList(shared_ptr<hittable> object);  

    void clear();
    void add(shared_ptr<hittable> object);  
    bool hit(const ray& r, interval rayT, hitRecord& rec) const override;

    aabb boundingBox() const override;
};


#endif