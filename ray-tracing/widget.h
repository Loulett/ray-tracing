#ifndef WIDGET_H
#define WIDGET_H
#include <QWidget>
#include "scene.h"

class MyWidget: public QWidget
{
    Q_OBJECT
public:
    MyWidget(Scene* scene, QWidget* parent = 0);
protected:
    void paintEvent(QPaintEvent *);
private:
    Scene* scene;
    QRect window;
};

#endif // WIDGET_H
