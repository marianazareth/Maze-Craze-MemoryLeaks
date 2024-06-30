#ifndef TREASURE_H
#define TREASURE_H

#include "nodeCell.h"
#include <utility>

class Treasure : public nodeCell {
private:
    std::pair<int, int> position;

public:
    Treasure();
    void placeTreasureEquidistant(int rows, int columns, const std::pair<int, int>& player1Start, const std::pair<int, int>& player2Start);
    std::pair<int, int> getPosition() const;
};

#endif // TREASURE_H
