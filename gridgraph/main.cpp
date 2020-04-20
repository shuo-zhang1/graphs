#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <limits>
#include <unordered_set>
#include "gridgraph.h"

using namespace std;

GridGraph createRandomGridGraph(int n)
{
    GridGraph graph;
    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < n; y++)
        {
            graph.addGridNode(x, y, to_string(n * x + y));
        }
    }

    vector<Node *> allnodes = graph.getAllNodes();
    srand(time(0));
    for (int i = 0; i < allnodes.size(); i++)
    {
        if (i + 1 < n)
        {
            int chance = rand() % 2;
            if (chance = 1)
            {
                graph.addUndirectedEdge(allnodes[i], allnodes[i + 1]);
            }
        }
        if (i + n < (n * n - 1))
        {
            int chance = rand() % 2;
            if (chance = 1)
            {
                graph.addUndirectedEdge(allnodes[i], allnodes[i + n]);
            }
        }
    }
    return graph;
}

int manhattan(Node *curr, Node *dest)
{
    return (abs(curr->x - dest->x) + abs(curr->y - dest->y));
}

Node *minDistance(unordered_map<Node *, pair<int, int>> distances, unordered_set<Node *> &visited)
{
    Node *temp = NULL;
    int tempdist = numeric_limits<int>::max();
    for (pair<Node *, pair<int, int>> node : distances)
    {
        Node *curr = node.first;
        int shortest = node.second.first;
        int heuristic = node.second.second;
        if (visited.find(curr) == visited.end() && shortest + heuristic <= tempdist)
        {
            tempdist = shortest + heuristic;
            temp = curr;
        }
    }
    return temp;
}

unordered_map<Node *, pair<int, int>> astar(Node *sourceNode, Node *destNode)
{
    unordered_map<Node *, pair<int, int>> distances;
    Node *curr = sourceNode;
    distances[sourceNode] = make_pair(0, manhattan(curr, destNode));
    unordered_set<Node *> visited;
    while (curr != NULL && curr != destNode)
    {
        visited.insert(curr);
        for (Node *neighbor : curr->neighbors)
        {
            if (visited.find(neighbor) == visited.end())
            {
                if (distances.find(neighbor) == distances.end())
                {
                    distances[neighbor] = make_pair(numeric_limits<int>::max(), manhattan(neighbor, destNode));
                }
                int h = 1;
                int tempdist = min(distances[curr].first + h, distances[neighbor].first);
                distances[neighbor].first = tempdist;
            }
        }
        curr = minDistance(distances, visited);
    }
    return distances;
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

int main()
{
    cout << "GridGraph of size 5 * 5: " << endl;
    GridGraph g = createRandomGridGraph(5);
    vector<Node *> allNodes = g.getAllNodes();
    print(allNodes);
    cout << endl;
    cout << "A* star from start node to each node: " << endl;
    Node *source = allNodes[0];
    Node *dest = allNodes[allNodes.size() - 1];
    unordered_map<Node *, pair<int, int>> star = astar(source, dest);
    for (auto i : star)
    {
        cout << i.first->value << ": " << i.second.first << endl;
    }
    return 0;
}
