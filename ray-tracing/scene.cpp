#include "scene.h"
#include <utility>

int MINUS_INF = -1000000;

void Scene::Color() {
    int t = 0;
    for (int i = 100; i < monitor.GetHeight(); i += 1) {
        for (int j = 100; j < monitor.GetWight(); j += 1) {
            t = MINUS_INF;
            for (auto&& k : objects) {
                std::pair<bool, float> res = k->Transection(monitor.GetRay(i,j));
                if (res.first && res.second > t) {
                    t = res.second;
                    monitor.SetColor(i, j, k->GetColor());
                }
            }
        }
    }
}
