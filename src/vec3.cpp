#include"vec3.h"
#include "utils.h"
vec3::vec3():
    e{0,0,0}
{}

vec3::vec3(double e0, double e1, double e2):
    e{e0,e1,e2}
{}

vec3::vec3(const vec3 &v){
    e[0] = v.e[0];
    e[1] = v.e[1];
    e[2] = v.e[2];
}

vec3& vec3::operator=(const vec3 &v){
    e[0] = v.e[0];
    e[1] = v.e[1];
    e[2] = v.e[2];
    return *this;
}

double vec3::x() const{
    return e[0];
}

double vec3::y() const{
    return e[1];
}

double vec3::z() const{
    return e[2];
}

vec3 vec3::operator-() const{
    return vec3(-e[0], -e[1], -e[2]);
}

double vec3::operator[](int i) const{
    return e[i];
}

double& vec3::operator[](int i){
    return e[i];
}

vec3& vec3::operator+=(const vec3 &v){
    e[0] += v.e[0];
    e[1] += v.e[1];
    e[2] += v.e[2];
    return *this;
}

vec3& vec3::operator-=(const vec3 &v){
    e[0] -= v.e[0];
    e[1] -= v.e[1];
    e[2] -= v.e[2];
    return *this;
}

vec3& vec3::operator*=(const double t){
    e[0] *= t;
    e[1] *= t;
    e[2] *= t;
    return *this;
}

vec3& vec3::operator/=(const double t){
    return *this *= 1/t;
}

double vec3::length() const{
    return std::sqrt(lengthSquared());
}

double vec3::lengthSquared() const{
    return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
}

 vec3 vec3::random(double min, double max){
    return vec3(randomDouble(min, max), randomDouble(min, max), randomDouble(min, max));
}

bool vec3::nearZero() const{
    // Return true if the vector is close to zero in all dimensions.
    const auto s = 1e-8;
    return (std::fabs(e[0]) < s) && (std::fabs(e[1]) < s) && (std::fabs(e[2]) < s);
}


// Utility Functions
vec3 randomInUnitDisk(){
    while(true){
        auto p = vec3(randomDouble(-1, 1), randomDouble(-1, 1), 0);
        if(p.lengthSquared() >= 1) continue;
        return p;
    }
}
