#include "scene.h"
#include <utility>
#include <algorithm>

double dot(Point a, Point b);

int PLUS_INF = 1000000;

QColor lerp(double l, const QColor& color, double k) {
    return QColor(color.red()*(k/(0.5*l*l)), color.green()*(k/(0.5*l*l)), color.blue()*(k/(0.5*l*l)));
}

void Scene::Color() {
    int t = 0;
    for (int i = 0; i < monitor.GetHeight(); i += 1) {
        for (int j = 0; j < monitor.GetWight(); j += 1) {
            t = PLUS_INF;
            for (auto&& k : objects) {
                Ray r = monitor.GetRay(i, j);
                std::pair<bool, float> res = k->Intersection(r);
                if (res.first && res.second < t) {
                    t = res.second;
                    Point intersect = r.GetT(t);
                    Ray l(light, intersect);
                    Point norm = l.GetVector() / (l.GetVector().Length());
                    monitor.SetColor(i, j, lerp(l.GetVector().Length(), k->GetColor(), std::max(0.0,
                                                                        dot(norm,
                                                                             k->GetNorm(intersect)))));
                }
            }
        }
    }
}
