#ifndef BVH_H
#define BVH_H


#include <vector>
#include "aabb.h"
#include "hittable.h"
#include "hittableList.h"


class bvhNode : public hittable {

    public: 
    bvhNode(hittableList list);
    bvhNode(std::vector<shared_ptr<hittable>> &objects, size_t start, size_t end);

    bool hit(const ray& r, interval rayT, hitRecord& rec) const override;

    aabb boundingBox() const override;

    private:
    shared_ptr<hittable> left, right;
    aabb bbox;

};

#endif // BVH_H