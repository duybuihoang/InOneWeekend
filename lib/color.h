#ifndef COLOR_H
#define COLOR_H

#include "interval.h"
#include "vec3.h"

using color = vec3;
void write_color(std::ostream& out, const color& pixel_color);
inline double linearToGamma(double linearComponent);

#endif