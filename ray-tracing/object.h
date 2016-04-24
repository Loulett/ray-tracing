#ifndef OBJECT_H
#define OBJECT_H

#include <utility>
#include <QColor>

#include "point.h"
#include "ray.h"

class Object
{
public:
    //Проверяет, пересечётся ли данный луч с данным объектом. Возвращает пару.
    //Если bool == true, то в Point лежит точка пересечения
    //Если bool == false, то пересечения нет

    virtual std::pair<bool, double> Intersection(const Ray& r) const = 0;

    //Получает цвет объекта а вы как думали
    QColor GetColor() { return color; }

    Object(int r, int g, int b): color(r,g,b) {}

    Object(const Object& other) = default;
protected:
    QColor color;
};

class Sphere: public Object {
public:
    Sphere(Point centre, double radius, int r, int g, int b): Object(r,g,b), centre(centre), radius(radius) {}
    Sphere(const Sphere& other) = default;

    std::pair<bool, double> Intersection(const Ray& r) const;

    Point GetCenter() { return centre; }
private:
    Point centre;
    double radius;
};

class Rectangle: public Object {
public:
    Rectangle(Point leftTop, Point rightTop, Point leftBottom, Point rightBottom, int r, int g, int b):
           Object(r,g,b), leftTop(leftTop), rightTop(rightTop),
           leftBottom(leftBottom), rightBottom(rightBottom) {}

    std::pair<bool, double> Intersection(const Ray& r) const;

private:
    Point leftTop, rightTop, leftBottom, rightBottom;
};

class Triangle: public Object {
public:
    Triangle(Point first, Point second, Point third, int r, int g, int b):
             Object(r,g,b), first(first), second(second), third(third) {}

    std::pair<bool, double> Intersection(const Ray& r) const;

private:
    Point first, second, third;
};

#endif // OBJECT_H
