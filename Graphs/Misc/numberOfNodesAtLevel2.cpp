/**
 * Find number of nodes in a tree at 
 * level L (levels start from 0).
 * The tree is provided as an undirected graph,
 * rooted at node 0.
 */

#include <bits/stdc++.h>
#include <iostream>
#define print(str) cout << str << endl;
#define forn(i, start, end) for(int i=start;i<end;i++)
using namespace std;
#define V 7
#define INF 100
typedef vector<pair<int,int>>* Graph;

void addEdge(Graph graph, int u, int v, int w=0)
{
    graph[u].push_back(make_pair(v,w));
    graph[v].push_back(make_pair(u,w));
}

void printGraph(Graph graph, int v)
{
    forn(i,0,v)
    {
        for(auto x : graph[i])
            printf("%d{%d} ", x.first,x.second);
        cout << endl;
    }
}

void dfsUtil(Graph g,int v, vector<bool>& visited, int level, int& count, int currLevel)
{
    // If you're at that level, don't go deeper.
    if (currLevel == level)
    {
        count++;
        return;
    }
    for (auto x : g[v]){
        // I need visited, as Undirected Graph
        if (!visited[x.first]){
            visited[x.first] = true;
            dfsUtil(g, x.first, visited, level, count, currLevel+1);
        }
    }
    return;
}

// DFS Based Approach.
void getNumberOfNodes(Graph g, int level)
{
    vector<bool> visited(V, false);
    visited[0] = true;
    int count = 0;
    dfsUtil(g, 0, visited, level, count, 0);
    cout << count << endl;
}

int main()
{
    vector<pair<int,int>> graph[V];

    // these weights don't mean nothing.
    addEdge(graph, 0, 1, 20);
    addEdge(graph, 0, 2, 5);
    addEdge(graph, 1, 3, 20);
    addEdge(graph, 1, 4, 1);
    addEdge(graph, 1, 5, 3);
    addEdge(graph, 2, 6, 3);    
    getNumberOfNodes(graph, 2);
}