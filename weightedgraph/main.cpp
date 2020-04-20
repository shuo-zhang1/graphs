#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <limits>
#include <algorithm>
#include <unordered_set>
#include "weightedgraph.h"

using namespace std;

WeightedGraph createRandomCompleteWeightedGraph(int n)
{
    WeightedGraph graph;
    for (int i = 0; i < n; i++)
    {
        graph.addNode(to_string(i));
    }
    vector<Node *> graphNodes = graph.getAllNodes();
    srand(time(0));
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int edgeWeight = rand() % 100;
            if (edgeWeight < 30){
                graph.addWeightedEdge(graphNodes[i], graphNodes[j], edgeWeight); 
            } 
        }
    }
    return graph;
}

WeightedGraph createLinkedList(int n)
{
    WeightedGraph graph;
    for (int i = 0; i < n; i++)
    {
        graph.addNode(to_string(i));
    }
    vector<Node *> graphNodes = graph.getAllNodes();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            graph.addWeightedEdge(graphNodes[i], graphNodes[j], 1);
        }
    }
    return graph;
}

Node *minDist(unordered_map<Node *, int> dist, unordered_set<Node *> visited)
{
    Node *minNode = NULL;
    int minDist = numeric_limits<int>::max();
    for (pair<Node *, int> neighbor : dist)
    {
        if (visited.find(neighbor.first) == visited.end() && neighbor.second <= minDist)
        {
            minDist = neighbor.second;
            minNode = neighbor.first;
        }
    }
    return minNode;
}

unordered_map<Node *, int> dijkstras(Node *start)
{
    unordered_map<Node *, int> dist;
    dist[start] = 0;
    Node *curr = start;
    unordered_set<Node *> visited;
    while (curr != NULL)
    {
        visited.insert(curr);
        for (pair<Node *, int> neighbor : curr->neighbors)
        {
            if (visited.find(neighbor.first) == visited.end())
            {
                if (dist.find(neighbor.first) == dist.end())
                {
                    dist[neighbor.first] = numeric_limits<int>::max();
                }
                int tempdist = min(dist[curr] + neighbor.second, dist[neighbor.first]);
                dist[neighbor.first] = tempdist;
            }
        }
        curr = minDist(dist, visited);
    }
    return dist;
}

void print(WeightedGraph graph)
{
    int i = 0;
    vector<Node *> allnodes = graph.getAllNodes();
    for (Node *node : allnodes)
    {
        cout << node->value << ": [";
        for (pair<Node *, int> neighbor : node->neighbors)
        {
            i++;
            cout << "{" << neighbor.first->value << ",";
            cout << neighbor.second;
            if (i < node->neighbors.size())
            {
                cout << "}, ";
            }
        }
        cout << "}]" << endl;
        i = 0;
    }
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

int main()
{

    WeightedGraph gsmall = createRandomCompleteWeightedGraph(10);
    vector<Node *> allNodes1 = gsmall.getAllNodes();
    print(gsmall);
    Node *first = new Node("2");
    Node *second = new Node("8");
    gsmall.removeDirectedEdge(first, second);
    allNodes1 = gsmall.getAllNodes();
    cout << "Removing edge between 2 and 8" << endl;
    print(gsmall);
    WeightedGraph search;
    unordered_map<Node *, int> dijk = dijkstras(allNodes1[0]);
    for (pair<Node*, int> node : dijk)
    {
        cout << "From start to " << node.first->value << ": " << node.second << endl;
    }
    return 0;
}
