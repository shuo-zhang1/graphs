#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "graph.h"
#include "graphsearch.h"

using namespace std;

Graph createRandomUnweightedGraphIter(int n)
{
    srand(time(0));
    Graph graph;
    for (int i = 0; i < n; i++)
    {
        int tempval = rand() % 100;
        graph.addNode(to_string(i));
    }
    vector<Node *> graphNodes = graph.getAllNodes();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int v1 = rand() % 100;
            if(v1 < 20)
            {
                graph.addUndirectedEdge(graphNodes[i], graphNodes[j]);
            }
        }
    }
    return graph;
}

Graph createLinkedList(int n)
{
    Graph graph;

    for (int i = 0; i < n; i++)
    {
        graph.addNode(to_string(i));
    }

    vector<Node *> graphNodes = graph.getAllNodes();
    Node *curr = new Node();

    for (int n = 0; n < graphNodes.size(); n++)
    {
        graph.addUndirectedEdge(curr, graphNodes[n + 1]);
    }
    return graph;
}

void print(vector<Node *> allNodes)
{
    for (int i = 0; i < allNodes.size(); i++)
    {
        cout << (allNodes[i])->value << ":[";
        for (int j = 0; j < ((allNodes[i])->neighbors.size()); j++)
        {
            cout << ((allNodes[i])->neighbors[j])->value;
            if (j < ((allNodes[i])->neighbors.size()) - 1)
            {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }
    cout << endl;
}

void printTraversal(vector<Node *> allnodes)
{
    for (int i = 0; i < allnodes.size(); i++)
    {
        cout << (allnodes[i])->value;
        if (i < allnodes.size() - 1)
        {
            cout << "->";
        }
    }
    cout << endl;
}

void BFTRecLinkedList(Graph graph)
{
    GraphSearch search;
    vector<Node *> output = search.BFTRec(graph);
    printTraversal(output);
}

void BFTIterLinkedList(Graph graph)
{
    GraphSearch search;
    vector<Node *> output = search.BFTIter(graph);
    printTraversal(output);
}

int main()
{
    return 0;
}
