#ifndef VEC3_H
#define VEC3_H

#include<cmath>
#include<exception>
#include<iostream>
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
    double length_squared() const;

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
    return t*v;
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

inline vec3 unit_vector(vec3 v)
{
    return v/v.length();
}

#endif
