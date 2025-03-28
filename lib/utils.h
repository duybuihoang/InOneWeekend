#ifndef UTILS_H
#define UTILS_H
#include <cmath>  //C++ math library
#include <limits> //C++ limits library
#include <memory> //C++ memory library
#include <cstdlib> //C++ cstdlib library
#include <iostream> //C++ iostream library

#include <algorithm> //C++ algorithm library
#include <vector> //C++ vector library
#include <string> //C++ string library
#include <random> //C++ random library

//C++ std using
using std::shared_ptr;
using std::make_shared;
using std::unique_ptr;
using std::make_unique;
using std::weak_ptr;

using std::sqrt;
using std::fabs;
using std::numeric_limits;

//constants
const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

//Utility functions
inline double degreesToRadians(double degrees){
    return degrees * pi / 180.0;
}

inline double randomDouble(double min = 0.0, double max = 1.0) {
    static std::mt19937 generator(std::random_device{}()); // Bộ sinh số ngẫu nhiên
    std::uniform_real_distribution<double> distribution(min, max);
    return distribution(generator);
}

//common headers
class vec3;

#include "color.h"
#include "vec3.h"
#include "ray.h"
#include "interval.h"
#endif