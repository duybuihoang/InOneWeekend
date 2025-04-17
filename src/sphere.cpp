#include"sphere.h"

sphere::sphere(const point3& staticCenter, double radius, shared_ptr<material> mat)
    : center(staticCenter, vec3(0,0,0)), radius(fmax(0, radius)), mat(mat)
{
    auto rvec = vec3(radius, radius, radius);
    bbox = aabb(staticCenter - rvec, staticCenter + rvec);
}

sphere::sphere(const point3& center1, const point3& center2, double radius, shared_ptr<material> mat)
    : center(center1, center2 - center1), radius(fmax(0, radius)), mat(mat)
{
    auto rvec = vec3(radius, radius, radius);
    aabb box1(center.at(0) - rvec, center.at(0) + rvec);
    aabb box2(center.at(1) - rvec, center.at(1) + rvec);

    bbox = aabb(box1, box2);
}


bool sphere::hit(const ray& r, interval rayT, hitRecord& rec) const
{

    point3 currentCenter = center.at(r.time());
    vec3 oc = currentCenter - r.origin();
    double a = r.direction().lengthSquared();
    double h = dot(r.direction(), oc);
    double c = oc.lengthSquared() - radius*radius;

    double discriminant = h*h - a*c;

    if(discriminant < 0){
        return false;
    }
    auto sqrtd = std::sqrt(discriminant);
    //Find the nearest root that lies in the acceptable range

    auto root = (h - sqrtd) / a;
    if(!rayT.contains(root)){

        root = (h + sqrtd) / a;
        if(!rayT.contains(root)){
            return false;
        }
    }


    rec.t = root;
    rec.p = r.at(rec.t);
    vec3 outwardNormal = (rec.p - currentCenter) / radius;
    rec.setFaceNormal(r, outwardNormal);
    rec.mat = mat;
    return true;
}

aabb sphere::boundingBox() const
{
    return bbox;
}