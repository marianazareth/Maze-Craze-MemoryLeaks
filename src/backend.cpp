#include "backend.h"
#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>
#include <stack>
#include <random>


int rows = 5;
int columns = 5;
const int directionSize = 4;
const int sublistAmount = 2;
const int startRow = 0;
const int startColumn = 0;

class Node {
public:
    int info;
    bool visited;
   
    Node* next;

    Node(int d, bool t) : info(d), visited(t), next(nullptr) {}
};

class nodeMatrix {
    Node*** matrix;
    bool** visited;

    private:
    void initializeMatrix (int nodeRows, int nodeColumns, Node*** &matrix) {
        int count = 0;
        bool visited = false; // nodes that haven't been visited are listed as false
        matrix = new Node**[nodeRows];
        for (int i = 0; i < nodeRows; ++i) {
            matrix[i] = new Node*[nodeColumns];
            for (int j = 0; j < nodeColumns; ++j) {
                matrix[i][j] = new Node(count, visited);
                count++;
            }
        }
    }


public:


nodeMatrix(int nodeRows, int nodeColumns) {
        initializeMatrix(nodeRows, nodeColumns, matrix);
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

 bool isVisited(int visitedRow, int visitedColumn, Node*** &visitedMatrix){
        visitedMatrix[visitedRow][visitedColumn] -> visited = true;
        return true;
 }

 bool isValid(int validRow, int validColumn,Node*** &validMatrix ) {
    if (validRow >= 0 && validRow < rows && validColumn >= 0 && validColumn < columns) {
        return true;
    }
    else{
        return false;
    }
}

void initializeWalls(int wallRows, int wallColumns){

}

void DFS(int dfsRows, int dfsColumns, Node*** &dfsMatrix){
int directions[directionSize][sublistAmount] = {{-1,0}, {1,0},{0,-1}, {0,1}};
        initializeMatrix(rows, columns, matrix);
        dfsMatrix[startRow][startColumn]->visited = true;

        for (int i = 0; i < directionSize; ++i) {
               
                int newCol = dfsColumns + directions[i][1];
               // implementar código parecido al del profe

                }
           
        }
    };

class Player {
    private:

    public:
};

class Maze {
    private:

    public:
};

class PowerUp {
    private:

    public:
};

class Portal {
    private:

    public:
};
