#ifndef _GRAPH_SEARCH_H_
#define _GRAPH_SEARCH_H_

#include <vector>
#include <queue>
#include <stack>
#include "graph.h"

class GraphSearch
{
public:
    void DFSUtil(vector<Node*>& output, Node* current, Node* goal, bool& found);
    vector<Node*> DFSRec(Graph &graph, Node* start,Node* end);
    vector<Node*> DFSIter(Graph &graph, Node* start,Node* end);
    vector<Node*> BFTIter(Graph& graph);
    void BFTUtil(vector<Node*>& output, queue<Node*>& q);
    vector<Node*> BFTRec(Graph& graph);

};

#endif