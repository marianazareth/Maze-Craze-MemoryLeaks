#include "Portal.h"
#include <random>

const int rows = 5;
const int columns = 5;
const double PORTAL_SPAWN_RATE = 0.05;

Portal::Portal() : nodeCell(-1, false), hasPortal(false), portalA({ -1, -1 }), portalB({ -1, -1 }) {}

void Portal::spawnPortals() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0, 1);
    hasPortal = false;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            if (!hasPortal && dis(gen) < PORTAL_SPAWN_RATE) {
                portalA = std::make_pair(i, j);
                hasPortal = true;
            }
            else if (hasPortal && dis(gen) < PORTAL_SPAWN_RATE) {
                portalB = std::make_pair(i, j);
                break;
            }
        }
        if (hasPortal && portalB.first != -1 && portalB.second != -1) break;
    }
}
