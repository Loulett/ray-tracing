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
    double a = dot(r.GetVector(), r.GetVector());
    Point normalized = r.GetStart() - centre;
    double b = 2 * dot(normalized, r.GetVector());
    double c = dot(r.GetStart(), r.GetStart()) + dot(centre,centre)
               - radius * radius;
    double d = b*b - 4 * a *c;

    if (d < 0)
        return std::make_pair(false, -1);
    d = std::sqrt(d);
    double x1 = (-b + d)/(2*a), x2 = (-b - d)/(2*a);
    double x = std::min(x1,x2) >= 0 ? std::min(x1, x2) : std::max(x1,x2);
    if (x < 0)
        return std::make_pair(false, -1);
    else
        return std::make_pair(true, x);
}
