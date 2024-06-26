#include "backend.h"
#include <iostream>
#include <stack>
#include <queue>
#include <random>
#include <ctime>
#include <utility>
#include <unordered_map>
#include <vector>
#include <string>

int rows = 5;
int columns = 5;
const int directionSize = 4;
const int sublistAmount = 2;
const int startRow = 0;
const int startColumn = 0;

const double EXTRA_EDGE_PROB = 0.2; 
const double POWER_SPAWN_RATE = 0.1; 
const double PORTAL_SPAWN_RATE = 0.05;

enum Power { NONE, DOUBLE_PLAY, CONTROL_ENEMY, JUMP_WALL };

class nodeCell {
public:
    int info;
    bool visited;
    Power power; 
    nodeCell* next;

    nodeCell(int d, bool t) : info(d), visited(t), power(NONE), next(nullptr) {}
};

class Graph {
public:
    std::unordered_map<std::string, std::vector<std::string>> adj;

    void addEdges(nodeCell* firstCell, nodeCell* secondCell) {
        std::string key1 = std::to_string(firstCell->info);
        std::string key2 = std::to_string(secondCell->info);
        adj[key1].push_back(key2);
        adj[key2].push_back(key1);
    }

    void DFS(int dfsRows, int dfsColumns, nodeCell*** &dfsMatrix) {
        int directions[directionSize][sublistAmount] = {{-1,0}, {1,0},{0,-1}, {0,1}};
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
};

class nodeMatrix {
    nodeCell*** matrix;
    std::pair<int, int> portalA, portalB;
    bool hasPortal;

    void initializeMatrix(int nodeRows, int nodeColumns, nodeCell*** &matrix) {
        int count = 0;
        matrix = new nodeCell**[nodeRows];
        for (int i = 0; i < nodeRows; ++i) {
            matrix[i] = new nodeCell*[nodeColumns];
            for (int j = 0; j < nodeColumns; ++j) {
                matrix[i][j] = new nodeCell(count, false);
                count++;
            }
        }
    }

    void spawnPowers() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(0, 1);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                if (dis(gen) < POWER_SPAWN_RATE) {
                    int powerType = rand() % 3 + 1; // 1 to 3 for DOUBLE_PLAY, CONTROL_ENEMY, JUMP_WALL
                    matrix[i][j]->power = static_cast<Power>(powerType);
                }
            }
        }
    }

    void spawnPortals() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(0, 1);
        hasPortal = false;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                if (!hasPortal && dis(gen) < PORTAL_SPAWN_RATE) {
                    portalA = std::make_pair(i, j);
                    hasPortal = true;
                } else if (hasPortal && dis(gen) < PORTAL_SPAWN_RATE) {
                    portalB = std::make_pair(i, j);
                    break;
                }
            }
            if (hasPortal && portalB.first != 0 && portalB.second != 0) break;
        }
        
        }
    

public:
    nodeMatrix(int nodeRows, int nodeColumns) {
        initializeMatrix(nodeRows, nodeColumns, matrix);
        Graph graph;
        graph.DFS(startRow, startColumn, matrix);
        spawnPowers();
        spawnPortals();
    }

    ~nodeMatrix() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                delete matrix[i][j];
            }
            delete[] matrix[i];
        }
        delete[] matrix;
    }
};




    public:
};
