#include "interval.h"
#include "utils.h"

const interval interval::empty = interval(+infinity, -infinity);
const interval interval::universe = interval(-infinity, +infinity);

interval::interval():
    min(0),
    max(0)
{}

interval::interval(double min, double max):
    min(min),
    max(max)
{}

double interval::size() const{
    return max - min;
}

bool interval::contains(double x) const{
    return min <= x && x <= max;
}

bool interval::surrounds(double x) const{
    return min <= x && x <= max;
}

double interval::clamp(double x) const{
    return std::fmin(std::fmax(min, x), max);
}

