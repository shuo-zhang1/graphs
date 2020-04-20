#include "gridgraph.h"
#include <iostream>

void GridGraph::addGridNode(int x, int y, string nodeVal)
{
    Node *temp = new Node(x, y, nodeVal);
    if(find(allnodes.begin(), allnodes.end(), temp) == allnodes.end()){
       allnodes.push_back(temp); 
    }
    allnodes.push_back(temp);
}

void GridGraph::addUndirectedEdge(Node *first, Node *second)
{
    for (Node* node : first->neighbors){
        if (node == second){
            return;
        }
    }
    first->neighbors.push_back(second);
    second->neighbors.push_back(first);
}

void GridGraph::removeUndirectedEdge(Node *first, Node *second)
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
        if (curr->value == second->value)
        {
            int i = 0;
            for (Node *neighbor : curr->neighbors)
            {
                if (neighbor->value == first->value)
                {
                    (curr->neighbors).erase((curr->neighbors).begin() + i);
                }
                i++;
            }
        }
    }
}

