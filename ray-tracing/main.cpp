#include <QApplication>
#include <QPaintEvent>
#include <QPen>
#include <QWidget>
#include <QPainter>
#include <fstream>
#include <vector>
#include <memory>

#include "widget.h"
#include "monitor.h"
#include "object.h"
#include "scene.h"
#include "point.h"



int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    std::ifstream finp("../ray-tracing/input.txt");
    double x = 0, y = 0, z = 0, r = 0;
    Point camera, leftTop, rightTop, leftBottom, rightBottom;
    finp >> camera >> leftTop >> rightTop >> leftBottom >> rightBottom;
    int h = 0, w = 0;
    finp >> h >> w;
    Monitor monitor(leftTop, rightTop, leftBottom, rightBottom, h, w, camera);
    Point light;
    finp >> light;

    Scene scene(monitor, light);

    int n = 0;
    char c;
    finp >> n;

    for (int i = 0; i < n; i++) {
        finp >> c;
        if (c == 's') {
            finp >> x >> y >> z;
            Point centre(x, y, z);
            finp >> r;
            finp >> x >> y >> z;
            scene.AddSphere(centre, r, x, y, z);
        } else if (c == 't') {
            finp >> x >> y >> z;
            Point first(x, y, z);
            finp >> x >> y >> z;
            Point second(x, y, z);
            finp >> x >> y >> z;
            Point third(x, y, z);
            finp >> x >> y >> z;
            scene.AddTriangle(first, second, third, x, y, z);
        } else if (c == 'r') {
            finp >> x >> y >> z;
            Point first(x, y, z);
            finp >> x >> y >> z;
            Point second(x, y, z);
            finp >> x >> y >> z;
            Point third(x, y, z);
            finp >> x >> y >> z;
            Point forth(x, y, z);
            finp >> x >> y >> z;
            scene.AddRectangle(first, second, third, forth, x, y, z);
        }
    }
    scene.Color();
    MyWidget myWidget(&scene);
    myWidget.show();

    return a.exec();
}
