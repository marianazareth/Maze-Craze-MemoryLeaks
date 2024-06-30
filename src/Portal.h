#ifndef PORTAL_H
#define PORTAL_H

#include "nodeCell.h"
#include <utility>

class Portal : public nodeCell {
    std::pair<int, int> portalA, portalB;
    bool hasPortal;

public:
    Portal();
    void spawnPortals();
};

#endif // PORTAL_H
