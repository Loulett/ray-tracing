#include <QPainter>
#include <QPen>
#include <QWidget>
#include <QPoint>
#include "widget.h"

MyWidget::MyWidget(Scene* scene, QWidget* parent) : QWidget(parent), scene(scene) {}

void MyWidget::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    window = painter.window();
    painter.setWindow(0, 0, scene->GetWidth(), scene->GetHeight());
    for (int i = 0; i < scene->GetHeight(); i++){
        for (int j = 0; j < scene->GetWidth(); j++) {
            if (scene->GetColor(i,j) == 0)
                painter.setPen(Qt::black);
            else
                painter.setPen(Qt::red);
            painter.drawPoint(i,j);
        }
    }
}
/*
void MyWidget::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    window = painter.window();
    painter.setPen(QPen(Qt::black,20));
    painter.drawPoint(1, 1);
}*/
