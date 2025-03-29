#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

class vec3{

    private:
    double e[3];

    public:
    vec3();
    vec3(double e0, double e1, double e2);
    vec3(const vec3 &v);
    vec3& operator=(const vec3 &v);

    double x() const;
    double y() const;
    double z() const;

    vec3 operator-() const;
    double operator[](int i) const;
    double& operator[](int i);

    vec3& operator+=(const vec3 &v);
    vec3& operator-=(const vec3 &v);
    vec3& operator*=(const double t);
    vec3& operator/=(const double t);

    double length() const;
    double lengthSquared() const;
    bool nearZero() const;

    static vec3 random(double min = 0, double max = 0);

};


//type alias for vec3
using point3 = vec3;

//Utility function
inline std::ostream& operator<<(std::ostream &out, const vec3 &v){
    return out << v[0] << ' ' << v[1] << ' ' << v[2];
}

inline vec3 operator+(const vec3& u, const vec3&v)
{
    return vec3(u[0]+v[0], u[1]+v[1], u[2]+v[2]);
}

inline vec3 operator-(const vec3& u, const vec3&v)
{
    //return vec3(u[0]-v[0], u[1]-v[1], u[2]-v[2]);

  
    return vec3(u[0]-v[0], u[1]-v[1], u[2]-v[2]);    
    
    
}

inline vec3 operator*(const vec3& u, const vec3&v)
{
    return vec3(u[0]*v[0], u[1]*v[1], u[2]*v[2]);
}

inline vec3 operator*(double t, const vec3&v)
{
    return vec3(t*v[0], t*v[1], t*v[2]);
}   

inline vec3 operator*(const vec3&v, double t)
{
    return vec3(v.x() * t, v.y() * t, v.z() * t);
}

inline vec3 operator/(vec3 v, double t)
{
    return (1/t)*v;
}

inline double dot(const vec3& u, const vec3& v)
{
    return u[0] * v[0] + u[1] * v[1] + u[2] * v[2];
}

inline vec3 cross(const vec3& u, const vec3& v)
{
    return vec3(u[1]*v[2] - u[2]*v[1],
                u[2]*v[0] - u[0]*v[2],
                u[0]*v[1] - u[1]*v[0]);
}

inline vec3 unitVector(vec3 v)
{
    return v/v.length();
}

inline vec3 randomUnitVector(){
    
    while(true){
        auto p = vec3::random(-1, 1);
        auto lensq = p.lengthSquared();
        if (1e-160 < lensq && lensq <= 1)
        {
            return p / sqrt(lensq);
        }
    }
}

vec3 randomInUnitDisk();

inline vec3 randomOnHemiSphere(const vec3& normal){
    vec3 onUnitSphere = randomUnitVector();
    if(dot(onUnitSphere, normal) > 0.0){
        return onUnitSphere;
    }
    else{
        return -onUnitSphere;
    }
}

inline vec3 reflect(const vec3& v, const vec3& n){
    return v - 2*dot(v,n)*n;
}

inline vec3 refract(const vec3& uv, const vec3& n, double etaIOverEtaT){
    auto cosTheta = fmin(dot(-uv, n), 1.0);
    vec3 rOutPerp = etaIOverEtaT * (uv + cosTheta*n);
    vec3 rOutParallel = -sqrt(fabs(1.0 - rOutPerp.lengthSquared())) * n;
    return rOutPerp + rOutParallel;
}

#endif
