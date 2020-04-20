#include "weightedgraph.h"
#include <iostream>

void WeightedGraph::addNode(string nodeVal)
{
    Node *temp = new Node(nodeVal);
    if(find(allnodes.begin(), allnodes.end(), temp) == allnodes.end()){
       allnodes.push_back(temp); 
    }
}

void WeightedGraph::addWeightedEdge(Node *first, Node *second, int edgeWeight)
{
    first->neighbors[second] = edgeWeight;
}

void WeightedGraph::removeDirectedEdge(Node *first, Node *second)
{
    if(first->neighbors.empty()){
        return;
    }
    for (Node *curr : allnodes)
    {
        if (curr->value == first->value)
        {
            for (pair<Node *, int> neighbor : curr->neighbors)
            {
                if (neighbor.first->value == second->value)
                {
                    (curr->neighbors).erase(neighbor.first);
                }
            }
        }
    }
}
