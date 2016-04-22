#include <cmath>
#include <algorithm>
#include <utility>
#include "object.h"

Point cross(Point a, Point b) {
    return Point(a.GetY()*b.GetZ() - a.GetZ()*b.GetY(),
                 a.GetZ()*b.GetX() - a.GetX()*b.GetZ(),
                 a.GetX()*b.GetY() - a.GetY()*b.GetX());
}

double dot(Point a, Point b) {
    return a.GetX()*b.GetX() + a.GetY()*b.GetY() + a.GetZ()*b.GetZ();
}

std::pair<bool, double> Sphere::Intersection(const Ray& r) const {
    double a = 0;
    Point normalized = r.GetStart() - centre;
    double b = dot(normalized, r.GetVector());
    double c = dot(normalized, normalized) - radius * radius;
    double d = b*b - c;

    if (d < 0)
        return std::make_pair(false, -1);
    d = std::sqrt(d);
    double x1 = -b + d, x2 = -b - d;
    double x = std::min(x1,x2) >= 0 ? std::min(x1, x2) : std::max(x1,x2);
    if (x < 0)
        return std::make_pair(false, -1);
    else
        return std::make_pair(true, x);
}
