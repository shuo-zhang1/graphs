#include "directedgraph.h"
#include <iostream>

void DirectedGraph::addNode(string nodeVal)
{
    Node *temp = new Node(nodeVal);
    allnodes.push_back(temp);
}

void DirectedGraph::addDirectedEdge(Node *first, Node *second)
{
    if(find(first->neighbors.begin(), first->neighbors.begin(), second) == first->neighbors.end()){
        first->neighbors.push_back(second);
    }
}

void DirectedGraph::removeDirectedEdge(Node *first, Node *second)
{
    if(first->neighbors.empty()){
        return;
    }
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
