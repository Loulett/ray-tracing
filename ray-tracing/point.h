#ifndef POINT_H
#define POINT_H
#include <cmath>

class Point
{
public:
    Point(double x, double y, double z): x(x), y(y), z(z) {}

    Point operator + (Point& other) const {
        return Point(x + other.GetX(), y + other.GetY(), z + other.GetZ());
    }

    Point operator -(const Point& other) const {
        return Point(x - other.GetX(), y - other.GetY(), z - other.GetZ());
    }

    Point operator * (double num) const {
        return Point(x*num, y*num, z*num);
    }

    Point operator * (int num) const {
        return Point(x*num, y*num, z*num);
    }

    double GetX() const { return x; }
    double GetY() const { return y; }
    double GetZ() const { return z; }

    double Length() const { return std::sqrt(x*x+y*y+z*z); }
private:
    double x;
    double y;
    double z;
};

#endif // POINT_H
