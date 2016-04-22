#include "scene.h"
#include <utility>

int MINUS_INF = -1000000;

void Scene::Color() {
    int t = 0;
    for (int i = 0; i < monitor.GetHeight(); i += 1) { //monitor.GetStepHeight()
        for (int j = 0; j < monitor.GetWight(); j += 1) { //monitor.GetStepWight()
            t = MINUS_INF;
            for (auto&& k : objects) {
                std::pair<bool, float> res = k->Intersection(monitor.GetRay(i, j));
                if (res.first && res.second > t) {
                    t = res.second;
                    monitor.SetColor(i, j, k->GetColor());
                }
            }
        }
    }
}
