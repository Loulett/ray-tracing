#pragma once

#ifndef POINT_H
#define POINT_H

#include <cmath>
#include <fstream>

class Point {
public:
    explicit Point(double x = 0, double y = 0, double z = 0): x(x), y(y), z(z) {}

    Point operator + (const Point& other) const {
        return Point(x + other.GetX(), y + other.GetY(), z + other.GetZ());
    }

    Point operator -(const Point& other) const {
        return Point(x - other.GetX(), y - other.GetY(), z - other.GetZ());
    }

    Point operator * (double num) const {
        return Point(x*num, y*num, z*num);
    }
    Point operator / (double num) const {
        return Point(x/num, y/num, z/num);
    }

    double GetX() const { return x; }
    double GetY() const { return y; }
    double GetZ() const { return z; }

    double Length() const { return std::sqrt(x*x+y*y+z*z); }
private:
    double x, y, z;

    friend std::istream& operator >>(std::istream& in, Point& point);
};

std::istream& operator >>(std::istream& in, Point& point);

#endif // POINT_H
