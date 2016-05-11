#ifndef SCENE_H
#define SCENE_H
#include <vector>
#include <QColor>
#include <memory>

#include "point.h"
#include "ray.h"
#include "monitor.h"
#include "object.h"

class Scene {
public:
    Scene(Monitor monitor, Point light): monitor(monitor), light(light) {}
    // заполняет матрицу пикселей цветами
    void Color();

    int GetHeight() { return monitor.GetHeight(); }
    int GetWidth() { return monitor.GetWight(); }
    void AddRectangle(Point first, Point second, Point third, Point forth, int r, int g, int b) {
        objects.emplace_back(new Rectangle(first, second, third, forth, r, g, b));
    }

    void AddSphere(Point centre, double radius, int r, int g, int b) {
        objects.emplace_back(new Sphere(centre, radius, r, g, b));
    }
    void AddTriangle(Point first, Point second, Point third, int r, int g, int b) {
        objects.emplace_back(new Triangle(first, second, third, r, g, b));
    }

    QColor GetColor(int h, int w) { return monitor.GetColor(h, w); }
private:
    // камера и матрица пикселей
    Monitor monitor;

    // освещение
    Point light;

    // все объекты. TODO - заменить на KD дерево
    std::vector<std::unique_ptr<Object>> objects;
};

#endif // SCENE_H
