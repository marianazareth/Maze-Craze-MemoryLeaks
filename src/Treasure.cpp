#include "Treasure.h"
#include <random>
#include <cmath>

Treasure::Treasure() : nodeCell(-1, false), position({ -1, -1 }) {}

void Treasure::placeTreasureEquidistant(int rows, int columns, const std::pair<int, int>& player1Start, const std::pair<int, int>& player2Start) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> disRow(0, rows - 1);
    std::uniform_int_distribution<> disCol(0, columns - 1);

    int row, col;
    do {
        row = disRow(gen);
        col = disCol(gen);

        int distanceToPlayer1 = std::abs(row - player1Start.first) + std::abs(col - player1Start.second);
        int distanceToPlayer2 = std::abs(row - player2Start.first) + std::abs(col - player2Start.second);

        if (distanceToPlayer1 == distanceToPlayer2) {
            position = { row, col };
            break;
        }

    } while (true);
}

std::pair<int, int> Treasure::getPosition() const {
    return position;
}
