#include "nodeCell.h"
#include "Portal.h"
#ifndef NODEMATRIX_H
#define NODEMATRIX_H

#include "nodeCell.h"
#include "Graph.h"
#include "Portal.h"
#include "Power.h"
#include "Player.h"

class nodeMatrix {
    nodeCell*** matrix;
    Portal* portal;
    Power* power;
    Player player1;
    Player player2;

    void initializeMatrix(int nodeRows, int nodeColumns, nodeCell***& matrix);

public:
    nodeMatrix(int nodeRows, int nodeColumns);
    ~nodeMatrix();
    void movePlayer(Player& player, int dx, int dy);

};

#endif // NODEMATRIX_H
