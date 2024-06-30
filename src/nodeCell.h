
#ifndef NODECELL_H
#define NODECELL_H

class nodeCell {
public:
    int info;
    bool visited;
    nodeCell* next;

    nodeCell(int d, bool t);
};

#endif // NODECELL_H
