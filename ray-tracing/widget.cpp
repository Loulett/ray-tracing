#include <QPainter>
#include <QPen>
#include <QWidget>
#include <QPoint>
#include "widget.h"

MyWidget::MyWidget(Scene *scene, QWidget *parent) : QWidget(parent), scene(scene) { }

void MyWidget::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    window = painter.window();
    painter.setWindow(0, 0, scene->GetWidth(), scene->GetHeight());
    for (int i = 0; i < scene->GetHeight(); i++) {
        for (int j = 0; j < scene->GetWidth(); j++) {
            painter.setPen(scene->GetColor(i, j));
            painter.drawPoint(i, j);
        }
    }
}
