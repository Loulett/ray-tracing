#ifndef RAY_H
#define RAY_H

#include "point.h"

class Ray
{
public:
    //Конструктор по двум точкам
    Ray(Point start, Point on): start(start), on(on) {}

    //Проверка, лежит ли точка на луче
    bool OnRay(Point& p);

    //Выдаёт параметр, при котором получится данная точка на данном луче
    //(работает, если точка лежит на луче, иначе падает!)
    double ParamOnRay(Point& p);

    Point GetVector() const { return vector; }
    Point GetStart() const { return start; }
    Point GetOn() const { return on; }

    //double GetA() { return a; }
    //double GetB() { return b; }
    //double GetC() { return c; }
private:
    //Начальная точка луча (камера), точка, лежащая на луче (пиксель)
    Point start, on;

    //Направляющий вектор
    Point vector = on - start;

    //Коэффициенты прямой, которую задаёт луч (фиг знает, нужно ли, но пусть будет)
    //double a = on.GetY() - start.GetY(),
    //       b = start.GetX() - on.GetX(),
    //       c = (start.GetY() - on.GetY())*start.GetX() + (on.GetX() - start.GetX())*start.GetY();
};

#endif // RAY_H
