#ifndef POWER_H
#define POWER_H

#include "nodeCell.h"
#include <string>

enum class PowerType { NONE, DOUBLE_PLAY, CONTROL_ENEMY, JUMP_WALL };

class Power : public nodeCell {
private:
    bool powerPresence;
    PowerType powerType;

public:
    Power();
    void spawnPowers();
    std::string getPowerTypeString() const;
    bool isPowerPresent() const;
};

#endif // POWER_H
