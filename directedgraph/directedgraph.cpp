#include "directedgraph.h"
#include <iostream>

void DirectedGraph::addNode(string nodeVal)
{
    Node *temp = new Node(nodeVal);
    allnodes.push_back(temp);
}

void DirectedGraph::addDirectedEdge(Node *first, Node *second)
{
    first->neighbors.push_back(second);
}

void DirectedGraph::removeDirectedEdge(Node *first, Node *second)
{
    for (Node *curr : allnodes)
    {
        if (curr->value == first->value)
        {
            int i = 0;
            for (Node *neighbor : curr->neighbors)
            {
                if (neighbor->value == second->value)
                {
                    (curr->neighbors).erase((curr->neighbors).begin() + i);
                }
                i++;
            }
        }
    }
}
