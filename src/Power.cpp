#include "Power.h"
#include <random>

const int rows = 5;
const int columns = 5;
const double POWER_SPAWN_RATE = 0.1;

Power::Power() : nodeCell(-1, false), powerPresence(false), powerType(PowerType::NONE) {}

void Power::spawnPowers() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0, 1);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            if (dis(gen) < POWER_SPAWN_RATE) {
                int type = rand() % 3 + 1;
                powerType = static_cast<PowerType>(type);
                powerPresence = true;
                return;
            }
        }
    }
}

Power Power::getPowerType(PlayerTurn playerToGetPower) const {
    switch (powerType) {
    case PowerType::NONE:
        return "NONE";
    case PowerType::DOUBLE_PLAY:
        return doublePlay(playerToGetPower);
    case PowerType::CONTROL_ENEMY:
        return "CONTROL_ENEMY";
    case PowerType::JUMP_WALL:
        return "JUMP_WALL";
    default:
        return "UNKNOWN";
    }
}

bool Power::isPowerPresent() const {
    return powerPresence;
}

Player doublePlay(Player& playerGetsDouble){
    if(player.setTurn (playerGetsDouble)){
        player.setNextTurn(playerGetsDouble);
    }

}