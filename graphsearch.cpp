#include "graphsearch.h"
#include <iostream>

void GraphSearch::DFSUtil(vector<Node *> &output, Node *current, Node *goal, bool &found)
{
    if (!found)
    {
        current->visited = true;
        output.push_back(current);
        if (current->value == goal->value)
        {
            found = true;
        }
        for (Node *neighbor : current->neighbors)
        {
            if (!neighbor->visited)
            {
                DFSUtil(output, neighbor, goal, found);
            }
        }
    }
}

vector<Node *> GraphSearch::DFSRec(Graph &graph, Node *start, Node *end)
{
    vector<Node *> nodelist = graph.getAllNodes();
    for(Node* node: nodelist){
        node->visited= false;
    }
    vector<Node *> output;
    bool found = false;
    DFSUtil(output, start, end, found);
    if (found == false)
    {
        output = {};
    }
    return output;
}

vector<Node *> GraphSearch::DFSIter(Graph &graph, Node *start, Node *end)
{
    vector<Node *> nodelist = graph.getAllNodes();
    for( Node* node: nodelist){
        node->visited= false;
    }
    vector<Node *> output;
    stack<Node *> nodestack;
    start->visited = true;
    nodestack.push(start);
    while (!nodestack.empty())
    {
        Node *newCurr = nodestack.top();
        output.push_back(newCurr);
        nodestack.pop();
        if (newCurr->value == end->value)
        {
            return output;
        }
        for (Node *v : newCurr->neighbors)
        {
            if (!v->visited)
            {
                v->visited = true;
                nodestack.push(v);
            }
        }
    }
    return {};
}

vector<Node *> GraphSearch::BFTIter(Graph &graph)
{
    queue<Node *> q;
    vector<Node *> nodelist = graph.getAllNodes();
    vector<Node *> output;
    for( Node* node: nodelist){
        node->visited= false;
    }

    for (Node *node : nodelist)
    {
        if (!node->visited)
        {
            q.push(node);
            node->visited = true;
            while (!q.empty())
            {
                Node *newCurr = q.front();
                output.push_back(newCurr);
                q.pop();
                for (Node *v : newCurr->neighbors)
                {
                    if (!v->visited)
                    {
                        q.push(v);
                        v->visited = true;
                    }
                }
            }
        }
    }
    return output;
}

void GraphSearch::BFTUtil(vector<Node *> &output, queue<Node *> &q)
{
    if (!q.empty())
    {
        Node *newCurr = q.front();
        output.push_back(newCurr);
        q.pop();
        for (Node *neighbor : newCurr->neighbors)
        {
            if (!neighbor->visited)
            {
                q.push(neighbor);
                neighbor->visited = true;
            }
        }
        BFTUtil(output, q);
    }
}

vector<Node *> GraphSearch::BFTRec(Graph &graph)
{
    queue<Node *> q;
    vector<Node *> nodelist = graph.getAllNodes();
    vector<Node *> output;
    for( Node* node: nodelist){
        node->visited= false;
    }

    for (Node *node : nodelist)
    {
        if (!node->visited)
        {
            q.push(node);
            node->visited = true;
            BFTUtil(output, q);
        }
    }
    return output;
}
