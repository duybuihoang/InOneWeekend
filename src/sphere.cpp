#include"sphere.h"

sphere::sphere(const point3& center, double radius, shared_ptr<material> mat):
 center(center), 
 radius(std::fmax(0, radius)), 
 mat(mat){
    std::clog << "Sphere created with center: " << center << " and radius: " << radius << "\n";

    //TODO: Initialize the material pointer `mat`.
}

bool sphere::hit(const ray& r, double rayTMin, double rayTMax, hitRecord& rec) const
{
    vec3 oc = center - r.origin();
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
    if(root < rayTMin || rayTMax < root){
        root = (h + sqrtd) / a;
        if(root < rayTMin || rayTMax < root){
            return false;
        }
    }
    rec.t = root;
    rec.p = r.at(rec.t);
    vec3 outwardNormal = (rec.p - center) / radius;
    rec.setFaceNormal(r, outwardNormal);
    rec.mat = mat;
    return true;
}