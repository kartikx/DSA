/**
 * Find Mother Vertex in a Directed Graph.
 * https://www.geeksforgeeks.org/find-a-mother-vertex-in-a-graph/
 */
#include <bits/stdc++.h>
#include <iostream>
#define print(str) cout << str << endl;
#define forn(i, start, end) for(int i=start;i<end;i++)
using namespace std;

typedef vector<int>* Graph;

void addEdge(Graph graph, int u, int v)
{
    graph[u].push_back(v);
}

void printGraph(Graph graph, int v)
{
    forn(i,0,v)
    {
        for(auto x : graph[i])
            cout << x << " " ;
        cout << endl;
    }
}

void dfsUtil(Graph graph, int v, vector<bool>& visited)
{   
    cout << v << " ";
    for (auto x : graph[v])
    {
        if (!visited[x])
        {
            visited[x] = true;
            dfsUtil(graph, x, visited);
        }
    }
}

void dfsUtil(Graph graph, int v, vector<bool>& visited, int &lastFinished)
{
    for (auto x : graph[v])
    {
        if (!visited[x])
        {
            visited[x] = true;
            dfsUtil(graph, x, visited, lastFinished);
        }
    }
    lastFinished = v;
}
// Remember that mother Vertex doesn't require that vertex
// must be reachable from all others. If it did, then our graph
// would have only 1 SCC, and all vertices would become Mother.
void motherVertex(Graph graph, int size_V)
{
    // the mother Vertex should be present in the Source Componenent.
    vector<bool> visited(size_V, false);
    int lastFinished = 0;
    // going to call for all vertices, because multiple SCCs may exist.
    forn(i,0,size_V)
    {
        if(!visited[i])
        {
            visited[i] = true;
            dfsUtil(graph, i, visited, lastFinished);
        }
    }
    cout << "Vertex finished last is: " << lastFinished << endl;
    cout << "Checking..." << endl;

    fill(visited.begin(), visited.end(), false);
    visited[lastFinished] = true;

    dfsUtil(graph, lastFinished, visited);
    for(auto x : visited)
    {
        if (!x){
            cout << "Something went wrong..." << endl;
            return;
        }
    }
    cout << "Worked fine" << endl;

    // Let's print all mother Vertices
    vector<int> rev_graph[size_V];
    forn(i,0,size_V)
        for(auto x : graph[i])
            rev_graph[x].push_back(i);

    cout << "Printing all mother Vertices..." << endl ;
    fill(visited.begin(), visited.end(), false);
    visited[lastFinished] = true;
    dfsUtil(rev_graph, lastFinished, visited);
}
int main()
{
    int v = 6;
    // cin >> v;
    vector<int> graph[v];

    addEdge(graph,0,1);
    addEdge(graph,0,2);
    addEdge(graph,1,3);
    addEdge(graph,4,1);
    addEdge(graph,5,2);
    // addEdge(graph,5,6);
    // addEdge(graph,6,0);
    // addEdge(graph,6,4);
    // addEdge(graph,5,7);
    // addEdge(graph,7,8);
    // addEdge(graph,8,5);

    motherVertex(graph, v);
}
