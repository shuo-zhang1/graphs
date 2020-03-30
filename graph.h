#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <string>
#include <map>
#include <vector>

using namespace std;

struct Node
{
    string value;
    vector<Node *> neighbors;
    bool visited;
    Node(string val= "")
    {
        value = val;
        visited = false;
    }
};

void printVector(vector<Node>);

class Graph
{
    vector<Node*> allnodes;

public:
    void addNode(string nodeVal);
    void addUndirectedEdge(Node *first, Node *second);
    void removeUndirectedEdge(Node *first, Node *second);
    vector<Node *> getAllNodes() { return allnodes; }
    void addDirectedEdge(Node *start, Node *end);
};

#endif