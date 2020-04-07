#include "weightedgraph.h"
#include <iostream>

void WeightedGraph::addNode(string nodeVal)
{
    Node *temp = new Node(nodeVal);
    allnodes.push_back(temp);
}

void WeightedGraph::addWeightedEdge(Node *first, Node *second, int edgeWeight)
{
    first->neighbors[second] = edgeWeight;
}

void WeightedGraph::removeDirectedEdge(Node *first, Node *second)
{
    for (Node *curr : allnodes)
    {
        if (curr->value == first->value)
        {
            int i = 0;
            for (pair<Node *, int> neighbor : curr->neighbors)
            {
                if (neighbor.first->value == second->value)
                {
                    (curr->neighbors).erase(neighbor.first);
                }
                i++;
            }
        }
    }
}
