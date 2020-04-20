#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;

struct Node
{
    string value;
    unordered_map<Node *, int> neighbors;
    bool visited;
    Node(string val = "")
    {
        value = val;
        visited = false;
        neighbors = {};
    }
};

void printVector(vector<Node>);

class WeightedGraph
{
    vector<Node *> allnodes;

public:
    void addNode(string nodeVal);
    void addWeightedEdge(Node *first, Node *second, int edgeWeight);
    void removeDirectedEdge(Node *first, Node *second);
    vector<Node *> getAllNodes() { return allnodes; }
};

#endif
