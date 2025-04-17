#include "hittableList.h"

hittableList::hittableList() {}
hittableList::hittableList(shared_ptr<hittable> object) { add(object); }

void hittableList::clear() { objects.clear(); }
void hittableList::add(shared_ptr<hittable> object) {
    objects.push_back(object);
    bbox = aabb(bbox, object->boundingBox());
}

bool hittableList::hit(const ray& r, interval rayT, hitRecord& rec)const {
    hitRecord tempRec;
    bool hitAnything = false;
    double closestSoFar = rayT.max;

    for(const auto& object: objects){
        if(object->hit(r, rayT, tempRec)){
            hitAnything = true;
            closestSoFar = tempRec.t;
            rec = tempRec;
        }
    }
    return hitAnything;
}

aabb hittableList::boundingBox() const {
    return bbox;
}