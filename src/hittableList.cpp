#include "hittableList.h"

hittableList::hittableList() {}
hittableList::hittableList(shared_ptr<hittable> object) { add(object); }

void hittableList::clear() { objects.clear(); }
void hittableList::add(shared_ptr<hittable> object) {objects.push_back(object);}

bool hittableList::hit(const ray& r, double rayTMin, double rayTMax, hitRecord& rec)const {
    hitRecord tempRec;
    bool hitAnything = false;
    double closestSoFar = rayTMax;

    for(const auto& object: objects){
        if(object->hit(r, rayTMin, closestSoFar, tempRec)){
            hitAnything = true;
            closestSoFar = tempRec.t;
            rec = tempRec;
        }
    }
    return hitAnything;
}