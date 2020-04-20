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
        curr = graphNodes[n];
        int v1 = rand() % 100;
        if(v1 < 20)
        {
            graph.addUndirectedEdge(curr, graphNodes[n + 1]);
        }
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
    Graph gsmall = createRandomUnweightedGraphIter(10);
    Graph gbig = createLinkedList(20);
    vector<Node *> allNodes1 = gsmall.getAllNodes();
    print(allNodes1);
    vector<Node *> allNodes2 = gbig.getAllNodes();
    print(allNodes2);

    Node *first = new Node("8");
    Node *second = new Node("2");

    gsmall.removeUndirectedEdge(first, second);
    allNodes1 = gsmall.getAllNodes();
    cout << "Removing edge between 2 and 8" << endl;
    print(allNodes1);
    GraphSearch search;
    Node *target = new Node("9");
    vector<Node *> DFSOutput;
    DFSOutput = search.DFSRec(gsmall, allNodes1[0], target);
    cout << "DFSRec from 0 to 9" << endl;
    printTraversal(DFSOutput);
    DFSOutput = search.DFSIter(gsmall, allNodes1[0], target);
    cout << "DFSIter from 0 to 9" << endl;
    printTraversal(DFSOutput);
    vector<Node *> BFTOutput;
    BFTOutput = search.BFTRec(gsmall);
    cout << "BFTRec" << endl;
    printTraversal(BFTOutput);

    BFTOutput = search.BFTIter(gsmall);
    cout << "BFTIter" << endl;
    printTraversal(BFTOutput);

    Graph tenk = createLinkedList(10000);
    BFTRecLinkedList(tenk);
    BFTIterLinkedList(tenk);

    return 0;
}
