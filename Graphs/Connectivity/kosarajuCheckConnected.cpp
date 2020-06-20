/**
 * Kosaraju's Algorithm to check whether
 * a Direct Graph is strongly connected, or not.
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
    for (auto x : graph[v])
    {
        if (!visited[x])
        {
            visited[x] = true;
            dfsUtil(graph, x, visited);
        }
    }
}

/**
 * If a graph is connected, then for a vertex V :
 * You should be able to reach every vertex from V,
 * You should be able to reach every V from every vertex.
 * 
 * If this is true for any one vertex (say 0), then for
 * any other vertex (say v), v can reach 0 and 0 can reach
 * everyone, so v can reach everyone AND
 * everyone can reach 0, and 0 can reach v, so everyone can reach v.
 */

bool isConnected(Graph graph, int size_v)
{
    vector<bool> visited = vector<bool>(size_v, false);
    visited[0] = true;
    dfsUtil(graph, 0, visited);
    forn(i,0,size_v)
    {
        if(!visited[i])
            return false;
    }
    
    // reverse graph.
    vector<int> rev_graph[size_v];

    forn(i,0,size_v)
    {
        for (auto x : graph[i])
        {
            rev_graph[x].push_back(i);
        }
    }

    visited = vector<bool>(size_v, false);
    visited[0] = true;
    dfsUtil(rev_graph, 0, visited);
    
    forn(i,0,size_v)
    {
        if(!visited[i])
            return false;
    }
    return true;
}

int main()
{
    int v;
    cin >> v;
    vector<int> graph[v];

    addEdge(graph,0,1);
    addEdge(graph,1,2);
    addEdge(graph,2,3);
    addEdge(graph,3,1);
    addEdge(graph,1,6);
    addEdge(graph,6,0);
    addEdge(graph,5,0);
    addEdge(graph,1,4);
    addEdge(graph,4,5);

    isConnected(graph, v) ? cout << "Connected" << endl : cout << "Nope" << endl;
}
