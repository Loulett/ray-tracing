#include <QApplication>
#include <QPaintEvent>
#include <QPen>
#include <QWidget>
#include <QPainter>
#include <fstream>
#include <vector>

#include "widget.h"
#include "monitor.h"
#include "object.h"
#include "scene.h"
#include "widget.h"
#include "point.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    std::ifstream finp("../ray-tracing/input.txt");
    double x = 0, y = 0, z = 0, r = 0;
    finp >> x >> y >> z;
    Point camera(x,y,z);
    finp >> x >> y >> z;
    Point leftTop(x,y,z);
    finp >> x >> y >> z;
    Point rightTop(x,y,z);
    finp >> x >> y >> z;
    Point leftBottom(x,y,z);
    finp >> x >> y >> z;
    Point rightBottom(x,y,z);
    int h = 0, w = 0;
    finp >> h >> w;
    Monitor monitor(leftTop, rightTop, leftBottom, rightBottom, h, w, camera);
    int color = 0;
    finp >> x >> y >> z;
    Point centre(x,y,z);
    finp >> r >> color;
    std::vector<Object*> objects;
    Sphere s(centre, r, color);
    objects.push_back(&s);
    Scene scene(monitor, objects);
    scene.Color();
    MyWidget myWidget(&scene);
    myWidget.show();

    return a.exec();
}
