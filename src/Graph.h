#ifndef GRAPH_H
#define GRAPH_H

#include "nodeCell.h"
#include <unordered_map>
#include <vector>
#include <string>

class Graph {
public:
    std::unordered_map<std::string, std::vector<std::string>> adj;

    void addEdges(nodeCell* firstCell, nodeCell* secondCell);
    void DFS(int dfsRows, int dfsColumns, nodeCell***& dfsMatrix);
};

#endif // GRAPH_H
