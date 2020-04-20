#ifndef _GRID_GRAPH_H_
#define _GRID_GRAPH_H_

#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

struct Node
{
    string value;
    vector<Node *> neighbors;
    bool visited;
    int x, y;
    Node(int x = 0, int y = 0, string val = "")
    {
        value = val;
        visited = false;
        this->x = x;
        this->y = y;
        neighbors = {};
    }
};

void printVector(vector<Node>);

class GridGraph
{
    vector<Node *> allnodes;

public:
    void addGridNode(int x, int y, string nodeVal);
    void addUndirectedEdge(Node *first, Node *second);
    void removeUndirectedEdge(Node *first, Node *second);
    vector<Node *> getAllNodes() { return allnodes; }
};

#endif
