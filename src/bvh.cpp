#include "bvh.h"

bvhNode::bvhNode(hittableList list) {
        // There's a C++ subtlety here. This constructor (without span indices) creates an
        // implicit copy of the hittable list, which we will modify. The lifetime of the copied
        // list only extends until this constructor exits. That's OK, because we only need to
        // persist the resulting bounding volume hierarchy.
}

bvhNode::bvhNode(std::vector<shared_ptr<hittable>>& objects, size_t start, size_t end) {
    // tobe implement later
}

bool bvhNode::hit(const ray& r, interval rayT, hitRecord& rec) const {
   if(bbox.hit(r, rayT)) return false;

   bool hitLeft = left->hit(r, rayT, rec);
   bool hitRight = right->hit(r, interval(rayT.min, hitLeft ? rec.t: rayT.max), rec);

   return hitLeft || hitRight;
}