#include "nodeMatrix.h"

const int rows = 5;
const int columns = 5;
const int startRow = 0;
const int startColumn = 0;

void nodeMatrix::initializeMatrix(int nodeRows, int nodeColumns, nodeCell***& matrix) {
    int count = 0;
    matrix = new nodeCell * *[nodeRows];
    for (int i = 0; i < nodeRows; ++i) {
        matrix[i] = new nodeCell * [nodeColumns];
        for (int j = 0; j < nodeColumns; ++j) {
            matrix[i][j] = new nodeCell(count, false);
            count++;
        }
    }
}

nodeMatrix::nodeMatrix(int nodeRows, int nodeColumns) {
    initializeMatrix(nodeRows, nodeColumns, matrix);
    Graph graph;
    graph.DFS(startRow, startColumn, matrix);
    power = new Power();
    portal = new Portal();
    power->spawnPowers();
    portal->spawnPortals();
}

void nodeMatrix::movePlayer(Player& player, int dx, int dy) {
    auto currentPos = player.getCurrentPosition();
    int newRow = currentPos.first + dx;
    int newCol = currentPos.second + dy;
        
    if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < columns) {
        movePlayer(player, dx, dy);
    }
};

nodeMatrix::~nodeMatrix() {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            delete matrix[i][j];
        }
        delete[] matrix[i];
    }
    delete[] matrix;
    delete power;
    delete portal;
}
