#ifndef RAY_H
#define RAY_H

#include "point.h"

class Ray
{
public:
    //Конструктор по двум точкам
    Ray(Point start, Point on): start(start), on(on) {}

    Point GetVector() const { return vector; }
    Point GetStart() const { return start; }
    Point GetOn() const { return on; }

    Point GetT(double t) const { return start + vector * t; }

private:
    //Начальная точка луча (камера), точка, лежащая на луче (пиксель)
    Point start, on;

    //Направляющий вектор
    Point vector = on - start;
};

#endif // RAY_H
