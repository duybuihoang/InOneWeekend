#ifndef AABB_H
#define AABB_H

#include "interval.h"
#include "utils.h"
class aabb{
  public:
  interval x, y, z;  

  aabb();
  aabb(const interval &x, const interval &y, const interval &z);
  aabb(const point3 &min, const point3 &max);
  aabb(const aabb& box0, const aabb& box1);

  const interval& axisInterval(int n) const;
  bool hit(const ray &r, interval rayT) const;

};

#endif