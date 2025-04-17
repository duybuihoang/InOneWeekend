#ifndef INTERVAL_H
#define INTERVAL_H

class interval{

    public:

    double min, max;

    interval();
    interval(double min, double max);
    interval(const interval &a, const interval& b);
 
    double size() const;
    bool contains(double x) const;
    bool surrounds(double x) const;
    double clamp(double x) const;

    static const interval empty, universe;

    interval expand(double delta) const;
};


#endif