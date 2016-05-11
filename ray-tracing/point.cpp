#include "point.h"

std::istream& operator >>(std::istream& in, Point& point) {
    return in >> point.x >> point.y >> point.z;
}

