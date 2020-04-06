#include "topsort.h"
#include <iostream>

vector<Node *> TopSort::Kahns(DirectedGraph &graph)
{
    vector<Node *> nodelist = graph.getAllNodes();
    vector<Node *> output;
    queue<Node *> q;
    int v = nodelist.size();
    map<Node *, int> inDeg;

    for (Node *node : nodelist)
    {
        inDeg[node] = 0;
    }
    vector<Node *> inDegkeys = extract_keys(inDeg);
    vector<Node *> neighbors;
    for (Node *node : nodelist)
    {
        neighbors.insert(neighbors.end(), node->neighbors.begin(), node->neighbors.end());
    }
    for (Node *node : neighbors)
    {
        inDeg[node] += 1;
    }
    for (Node *node : inDegkeys)
    {
        if (inDeg[node] == 0)
        {
            q.push(node);
            inDeg[node] -= 1;
        }
    }
    while (q.size() > 0)
    {
        Node *temp = q.front();
        q.pop();
        output.push_back(temp);
        for (Node *node : temp->neighbors)
        {
            inDeg[node] -= 1;
            if (inDeg[node] == 0)
            {
                q.push(node);
            }
        }
        inDeg[temp] -= 1;
    }
    return output;
}

vector<Node *> TopSort::mDFS(DirectedGraph &graph)
{
    vector<Node *> stack;
    vector<Node *> nodelist = graph.getAllNodes();
    for (Node *node : nodelist)
    {
        node->visited = false;
    }
    for (Node *node : nodelist)
    {
        if (!node->visited)
        {
            mDFSUtil(node, stack);
            
        }
    }
    return stack;
}

void TopSort::mDFSUtil(Node *curr, vector<Node *> &stack)
{
    curr->visited = true;
    for (Node *neighbor : curr->neighbors)
    {
        if (!neighbor->visited)
        {
            mDFSUtil(neighbor, stack);
        }
    }
    stack.push_back(curr);
    
}
