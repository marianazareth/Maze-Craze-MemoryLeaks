#include "nodeCell.h"
#include "Portal.h"
#ifndef NODEMATRIX_H
#define NODEMATRIX_H

#include "nodeCell.h"
#include "Graph.h"
#include "Portal.h"
#include "Power.h"

class nodeMatrix {
    nodeCell*** matrix;
    Portal* portal;
    Power* power;

    void initializeMatrix(int nodeRows, int nodeColumns, nodeCell***& matrix);

public:
    nodeMatrix(int nodeRows, int nodeColumns);
    ~nodeMatrix();
};

#endif // NODEMATRIX_H
