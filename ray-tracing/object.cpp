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

std::pair<bool, double> TriangleIntersect(Point first, Point second, Point third, const Ray& r) {
    Point e1 = second - first, e2 = third - first, t = r.GetStart() - first;
    double u = dot(cross(r.GetVector() * -1, t), e2)/dot(cross(r.GetVector() * -1, e1), e2);
    if (u < 0 || u > 1)
        return std::make_pair(false, -1);
    double v = dot(cross(r.GetVector() * -1, e1), t)/ dot(cross(r.GetVector() * -1, e1), e2);
    if (v < 0 || u + v > 1)
        return std::make_pair(false, -1);
    double x = dot(cross(t, e1), e2)/dot(cross(r.GetVector() * -1, e1), e2);
    if (x < 0)
        return std::make_pair(false, -1);
    else
        return std::make_pair(true, x);
}

std::pair<bool, double> Sphere::Intersection(const Ray& r) const {
    double a = dot(r.GetVector(), r.GetVector());
    Point normalized = r.GetStart() - centre;
    double b = 2 * dot(normalized, r.GetVector());
    double c = dot(r.GetStart(), r.GetStart()) + dot(centre, centre) - radius * radius;
    double d = b*b - 4 * a *c;

    if (d < 0)
        return std::make_pair(false, -1);
    d = std::sqrt(d);
    double x1 = (-b + d)/(2*a), x2 = (-b - d)/(2*a);
    double x = std::min(x1, x2) >= 0 ? std::min(x1, x2) : std::max(x1,x2);
    if (x < 0)
        return std::make_pair(false, -1);
    else
        return std::make_pair(true, x);
}


std::pair<bool, double> Triangle::Intersection(const Ray &r) const {
    Point e1 = second - first, e2 = third - first, t = r.GetStart() - first;
    double u = dot(cross(r.GetVector() * -1, t), e2)/dot(cross(r.GetVector() * -1, e1), e2);
    if (u < 0 || u > 1)
        return std::make_pair(false, -1);
    double v = dot(cross(r.GetVector() * -1, e1), t)/ dot(cross(r.GetVector() * -1, e1), e2);
    if (v < 0 || u + v > 1)
        return std::make_pair(false, -1);
    double x = dot(cross(t, e1), e2)/dot(cross(r.GetVector() * -1, e1), e2);
    if (x < 0)
        return std::make_pair(false, -1);
    else
        return std::make_pair(true, x);
}

std::pair<bool, double> Rectangle::Intersection(const Ray &r) const {
    auto res1 = TriangleIntersect(leftTop, leftBottom, rightTop, r);
    auto res2 = TriangleIntersect(rightBottom, leftBottom, rightTop, r);
    return res1.first ? res1 : res2;
}

void Triangle::setNormal() {
    normal = cross(second - first, third - first);
    normal = normal / normal.Length();
}

void Rectangle::setNormal() {
    normal = cross(leftBottom - leftTop, rightTop - leftTop);
    normal = normal / normal.Length();
}
