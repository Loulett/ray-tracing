#include "monitor.h"

Ray Monitor::GetRay(int h, int w) {
    Point vectorWidth = (rightTop - leftTop)/width, vectorHeight = (leftBottom - leftTop)/height;
    Point y = vectorHeight * h;
    Point x = leftTop + y;
    y = vectorWidth * w;
    return Ray(camera, x + y);
}

void Monitor::SetColor(int h, int w, QColor color) {
    colors[h][w] = color;
}
