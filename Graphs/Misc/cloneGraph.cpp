/**
 * Given a source Node of an undirected connected graph,
 * create a clone of it.
 * The catch is that you aren't provided the graph in the 
 * vector<vector<int>> form that you're familiar with.
 * 
 * For v large graphs, it makes sense to allocate memory on 
 * the Heap. Hence your graph consists of Nodes where each Node
 * has associate with it a vector<GraphNode*> of neighbours.
 * All edge connections have been made through this vector,
 * and you only have access to the source.
 * 
 * This has the added advantage that this is a class based representation,
 * which may be useful in real-world applications.
 */
#include <bits/stdc++.h>
using namespace std;


class GraphNode{
public:
    int val;
    vector<GraphNode*> neighbours;
};

// This currently builds an arbitrary graph.
GraphNode* buildGraph()
{
    GraphNode* node1 = new GraphNode();
    node1->val = 1;
    GraphNode* node2 = new GraphNode();
    node2->val = 2;
    GraphNode* node3 = new GraphNode();
    node3->val = 3;
    GraphNode* node4 = new GraphNode();
    node4->val = 4;
    GraphNode* node5 = new GraphNode();
    node5->val = 5;

    vector<GraphNode*> v;
    v.push_back(node2);
    v.push_back(node3);
    node1->neighbours = v;
    v.clear();

    v.push_back(node1);
    v.push_back(node4);
    node2->neighbours = v;
    v.clear();

    v.push_back(node1);
    v.push_back(node4);
    v.push_back(node5);
    node3->neighbours = v;
    v.clear();

    v.push_back(node2);
    v.push_back(node3);
    node4->neighbours = v;
    v.clear();

    v.push_back(node3);
    node5->neighbours = v;
    v.clear();

    // serves as the source
    return node1;
}

void printGraph(GraphNode* src)
{
    queue<GraphNode*> toVisit;
    toVisit.push(src);
    map<GraphNode*, bool> visited;
    visited[src] = true;

    while(!toVisit.empty())
    {
        GraphNode* val = toVisit.front();
        toVisit.pop();
        cout << "[" << val->val << "," << val << "] ";
        for (auto x : val->neighbours)
        {
            if (!visited[x])
            {
                visited[x] = true;
                toVisit.push(x);
            }
        }
        cout << endl;
    }
}

GraphNode* cloneGraph(GraphNode* src)
{
    /**
     * Algorithm:
     * From the source begin BFS, you're guaranteed to traverse the whole graph.
     * For every new node, create it.
     */
    GraphNode* new_src = new GraphNode();
    new_src->val = src->val;
    
    /**
     * Maps nodes in the original Graph, to
     * newly created nodes.
     */
    map<GraphNode*, GraphNode*> M;
    M[src] = new_src;

    /**
     * You can't just copy src->neighbours bc src neighbours
     * stores addresses of the original graph, we'd want to
     * store addresses of the new graph.
     */
    queue<GraphNode*> toVisit;
    toVisit.push(src);
    map<GraphNode*, bool> visited;
    visited[src] = true;
    while(!toVisit.empty())
    {
        GraphNode* val = toVisit.front();
        toVisit.pop();
        vector<GraphNode*> v;
        for (auto x : val->neighbours)
        {
            if (M[x] == NULL)
            {
                GraphNode* tempNode = new GraphNode();
                tempNode->val = x->val;
                M[x] = tempNode;
            }
            v.push_back(M[x]);
            if (!visited[x])
            {
                visited[x] = true;
                toVisit.push(x);
            }
        }
        M[val]->neighbours = v;
    }
    cout << "Original" << endl;
    printGraph(src);

    cout << "Cloned" << endl;
    printGraph(new_src);
}
int main()
{
    GraphNode* src = buildGraph();
    cloneGraph(src);
}
