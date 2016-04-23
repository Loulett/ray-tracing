#ifndef MONITOR_H
#define MONITOR_H

#include <vector>
#include <cmath>
#include "ray.h"

class Monitor
{
public:
    Monitor(Point leftTop, Point rightTop, Point leftBottom, Point rightBottom,
            int height, int wight, Point camera): leftTop(leftTop), rightTop(rightTop),
            leftBottom(leftBottom), rightBottom(rightBottom), height(height), wight(wight),
            camera(camera), colors(height, std::vector<int>(wight, 0)) {}

    //Возвращает луч через камеру и пиксель, имеющий данное место в матрице
    Ray GetRay(int h, int w);

    void SetColor(int h, int w, int color);

    double GetStepHeight() {return stepHeight;}
    double GetStepWight() {return stepWight;}
    int GetHeight() {return height;}
    int GetWight() {return wight;}
    int GetColor(int h, int w) {return colors[h][w];}
private:
    //координаты углов матрицы
    Point leftTop, rightTop, leftBottom, rightBottom;

    //координаты камеры
    Point camera;

    // количество пикселей в высоту и в ширину
    int height, wight;

    double stepHeight = (leftBottom - leftTop).Length() / height,
           stepWight = (leftTop - rightTop).Length() / wight;
    // матрица цветов пикселей
    std::vector<std::vector<int> > colors;
};

#endif // MONITOR_H
