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

enum class PowerType { NONE, DOUBLE_PLAY, CONTROL_ENEMY, JUMP_WALL };

class nodeCell {
public:
    int info;
    bool visited;
    nodeCell* next;

    nodeCell(int d, bool t) : info(d), visited(t), next(nullptr) {}

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
    Portal portal;
    Power power;

    void initializeMatrix(int nodeRows, int nodeColumns, nodeCell*** &matrix) {
        int count = 0;
        matrix = new nodeCell**[nodeRows];
        for (int i = 0; i < nodeRows; ++i) {
            matrix[i] = new nodeCell*[nodeColumns];
            for (int j = 0; j < nodeColumns; ++j) {
                std::random_device rd;
                std::mt19937 gen(rd());
                matrix[i][j] = new nodeCell(count, false);
                count++;
            }
        }
    }
    public:
    nodeMatrix(int nodeRows, int nodeColumns) {
        initializeMatrix(nodeRows, nodeColumns, matrix);
        Graph graph;
        graph.DFS(startRow, startColumn, matrix);
        power.spawnPowers();
        portal.spawnPortals();
    }

    ~nodeMatrix() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                delete matrix[i][j];
            }
            delete[] matrix[i];
        }
        delete[] matrix;
};



};

class Portal : public nodeCell {
    std::pair<int, int> portalA, portalB;
    bool hasPortal;
    Portal() : hasPortal(false), portalA({-1, -1}), portalB({-1, -1}) {}

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
    

};


class Power : public nodeCell {
private:
    bool powerPresence;
    PowerType powerType;

public:
    Power() : powerPresence(false), powerType(PowerType::NONE) {}

    void spawnPowers() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(0, 1);

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                if (dis(gen) < POWER_SPAWN_RATE) {
                    int type = rand() % 3 + 1; 
                    powerType = static_cast<PowerType>(type); //converts from int to PowerType
                    powerPresence = true;
                    return; 
                }
            }
        }
    }

    std::string getPowerTypeString() const {
        switch (powerType) {
            case PowerType::NONE:
                return "NONE";
            case PowerType::DOUBLE_PLAY:
                return "DOUBLE_PLAY";
            case PowerType::CONTROL_ENEMY:
                return "CONTROL_ENEMY";
            case PowerType::JUMP_WALL:
                return "JUMP_WALL";
            default:
                return "UNKNOWN";
        }
    }

    bool isPowerPresent() const {
        return powerPresence;
    }
};


enum playerTurn{
    player1, player2
};


enum class PlayerTurn { PLAYER1, PLAYER2 };
class Player {
private:
    std::pair<int, int> currentPosition;
    bool hasWon;
    PlayerTurn turn;

public:
    Player(const std::string& id, const std::pair<int, int>& startPos, PlayerTurn playerTurn)
        : playerID(id), currentPosition(startPos), hasWon(false), turn(playerTurn) {}


    std::string getPlayerID() const {
        return playerID;
    }

    std::pair<int, int> getCurrentPosition() const {
        return currentPosition;
    }

    bool getHasWon() const {
        return hasWon;
    }

    PlayerTurn getTurn() const {
        return turn;
    }

    void setPlayerID(const std::string& id) {
        playerID = id;
    }

    void setCurrentPosition(const std::pair<int, int>& pos) {
        currentPosition = pos;
    }

    void setHasWon(bool won) {
        hasWon = won;
    }

    void setTurn(PlayerTurn playerTurn) {
        turn = playerTurn;
    }
};




