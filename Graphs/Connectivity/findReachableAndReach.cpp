/**
 * Get Vertices that can be reached from a vertex, and 
 * that can reach this vertex.
 * The main idea is that to find vertices that can reach V,
 * you can reverse the Graph, and perform DFS from V.
 * Forms the underlying Idea for Kosaraju.
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

void findReachableAndReach(Graph graph,int size_v, int v)
{
    vector<bool> visited = vector<bool>(size_v, false);
    visited[v] = true;
    dfsUtil(graph, v, visited);
    forn(i,0,size_v)
    {
        if(visited[i])
            cout << i << " ";
    }
    cout << endl;
    
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
    visited[v] = true;
    dfsUtil(rev_graph, v, visited);
    
    forn(i,0,size_v)
    {
        if(visited[i])
            cout << i << " ";
    }
    cout << endl;
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
    addEdge(graph,1,4);
    addEdge(graph,4,5);

    findReachableAndReach(graph, v, 1);
}
