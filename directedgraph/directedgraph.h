#ifndef _DIRECTED_GRAPH_H_
#define _DIRECTED_GRAPH_H_

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

class DirectedGraph
{
    vector<Node*> allnodes;

public:
    void addNode(string nodeVal);
    void addDirectedEdge(Node *first, Node *second);
    void removeDirectedEdge(Node *first, Node *second);
    vector<Node *> getAllNodes() { return allnodes; }
};

#endif
