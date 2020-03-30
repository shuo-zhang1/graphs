#include "graph.h"
#include <iostream>

void Graph::addNode(string nodeVal)
{
    Node *temp = new Node(nodeVal);
    allnodes.push_back(temp);
}

void Graph::addUndirectedEdge(Node *first, Node *second)
{
    first->neighbors.push_back(second);
    second->neighbors.push_back(first);
}

void Graph::removeUndirectedEdge(Node *first, Node *second)
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
