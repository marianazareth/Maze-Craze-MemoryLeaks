#include "Graph.h"

const int directionSize = 4;
const int sublistAmount = 2;
const int rows = 5;
const int columns = 5;

void Graph::addEdges(nodeCell* firstCell, nodeCell* secondCell) {
    std::string key1 = std::to_string(firstCell->info);
    std::string key2 = std::to_string(secondCell->info);
    adj[key1].push_back(key2);
    adj[key2].push_back(key1);
}

void Graph::DFS(int dfsRows, int dfsColumns, nodeCell***& dfsMatrix) {
    int directions[directionSize][sublistAmount] = { {-1,0}, {1,0},{0,-1}, {0,1} };
    dfsMatrix[dfsRows][dfsColumns]->visited = true;

    for (int i = 0; i < directionSize; ++i) {
        int newRow = dfsRows + directions[i][0];
        int newCol = dfsColumns + directions[i][1];
        if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < columns && !dfsMatrix[newRow][newCol]->visited) {
            addEdges(dfsMatrix[dfsRows][dfsColumns], dfsMatrix[newRow][newCol]);
            DFS(newRow, newCol, dfsMatrix);
        }
    }
}

void BFS(int bfsRows, int bfsColumns, nodeCell***& bfsMatrix) {
    int directions[4][2] = { {-1,0}, {1,0},{0,-1}, {0,1} };
    std::queue<std::pair<int, int>> bfsQueue;
    bfsQueue.push({bfsRows, bfsColumns});
    bfsMatrix[bfsRows][bfsColumns]->visited = true;

    while (!bfsQueue.empty()) {
        int currentRow = bfsQueue.front().first;
        int currentCol = bfsQueue.front().second;
        bfsQueue.pop();

        for (int i = 0; i < 4; ++i) {
            int newRow = currentRow + directions[i][0];
            int newCol = currentCol + directions[i][1];
            if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < columns && !bfsMatrix[newRow][newCol]->visited) {
                addEdges(bfsMatrix[currentRow][currentCol], bfsMatrix[newRow][newCol]);
                bfsMatrix[newRow][newCol]->visited = true;
                bfsQueue.push({newRow, newCol});
            }
        }
    }
}
};
