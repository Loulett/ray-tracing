#include "scene.h"
#include <utility>
#include <algorithm>

double dot(Point a, Point b);

constexpr int PLUS_INF = 1000000;

QColor lerp(const QColor& color, double k) {
    return QColor(color.red() * k, color.green() * k, color.blue() * k);
}

double attenuation(double l) {
    return 1.;
}

void Scene::Color() {
    for (int i = 0; i < monitor.GetHeight(); i += 1) {
        for (int j = 0; j < monitor.GetWigth(); j += 1) {
            double t = PLUS_INF;
            for (auto&& k : objects) {
                Ray r = monitor.GetRay(i, j);
                auto intersection = k->Intersection(r);
                if (intersection.happened && intersection.t < t) {
                    t = intersection.t;
                    Point intersect = r.GetT(intersection.t);
                    Ray l(light, intersect);
                    bool occluded = false;
                    for (auto&& q: objects) {
                        if(k != q) {
                            auto shade = q->Intersection(l);
                            if (shade.happened && shade.t < 1.) {
                                occluded = true;
                                break;
                            }
                        }
                    }

                    double shaded = occluded ? 0.2 : (std::max(dot(l.GetVector().normalized(),
                                                                   k->GetNormal(intersect)), .0)
                                                      * attenuation(l.GetVector().Length()));
                    monitor.SetColor(i, j, lerp(k->GetColor(), shaded));
                }
            }
        }
    }
}
