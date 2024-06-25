#ifndef BACKEND_H
#define BACKEND_H

#include <vector>
using namespace std;

const int WINDOW_WIDTH = 1280;
const int WINDOW_HEIGHT = 720;
const int CELL_SIZE = 50;
const int GRID_ROWS = 5;
const int GRID_COLS = 5;

class Backend {
public:
    Backend();
    void moveCube(char direction);
    int getCubeRow() const;
    int getCubeCol() const;
    const vector<vector<int>>& getGrid() const;

private:
    void initializeGrid();
    vector<vector<int>> grid;
    int cubeRow;
    int cubeCol;
};

#endif