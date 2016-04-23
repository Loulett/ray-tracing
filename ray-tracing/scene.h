#ifndef SCENE_H
#define SCENE_H
#include <vector>

#include "point.h"
#include "ray.h"
#include "monitor.h"
#include "object.h"

class Scene
{
public:
    Scene(Monitor monitor, const std::vector<Object*> objects): monitor(monitor), objects(objects) {}
    // заполняет матрицу пикселей цветами
    void Color();
    int GetHeight() { return monitor.GetHeight(); }
    int GetWidth() { return monitor.GetWight(); }
    int GetStepHeight() { return monitor.GetStepHeight(); }  // здесь что-то очень плохое
    int GetStepWidth() { return monitor.GetStepWight(); }
    int GetColor(int h, int w) {return monitor.GetColor(h,w);}
private:
    // камера и матрица пикселей
    Monitor monitor;

    // все объекты. TODO - заменить на KD дерево
    std::vector<Object*> objects;
};

#endif // SCENE_H
