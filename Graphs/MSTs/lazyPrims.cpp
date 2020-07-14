#include <iostream>
#include <bits/stdc++.h>

using namespace std;

# define V 8
#define forn(i, start, end) for(int i=start;i<end;i++)

typedef list<int>* G;
typedef list<pair<int,int>>* wG;
typedef pair<int, pair<int, int>> T;

// Unweighted graphs generally Undirected
void addEdge(G graph, int u, int v, bool undirected=true)
{
    graph[u].push_back(v);
    if(undirected)
        graph[v].push_back(u);
}

// Weighted graphs generally Directed
void addEdge(wG graph, int u, int v, int w, bool undirected=false)
{
    graph[u].push_back(make_pair(v, w));
    if (undirected){
        graph[v].push_back(make_pair(u, w));
    }
}

void printGraph(G graph)
{
    forn(i, 0, V){
        for (auto x : graph[i]){
            cout << x << " ";
        }
        cout << endl;
    }
}

void printGraph(wG graph)
{
    forn(i, 0, V){
        for (auto x : graph[i]){
            printf("%d{%d} ", x.first, x.second);
        }
        cout << endl;
    }
}

void addEdges(wG graph, int u, vector<bool>& visited, priority_queue<T, vector<T>, greater<T>>& pq)
{   
    visited[u] = true;
    for (auto x : graph[u])
    {
        if (!visited[x.first])
        {
            pq.push(make_pair(x.second, make_pair(u, x.first)));
        }
    }
}

void lazyPrims(wG graph)
{
    priority_queue<T, vector<T>, greater<T>> pq;

    int totalEdges = V-1;
    int numEdges = 0;
    // defining source to be 0
    vector<bool> visited(V, false);
    addEdges(graph, 0, visited, pq);

    vector<pair<int, int>> mst;

    while (!pq.empty() && numEdges!=totalEdges)
    {
        auto currentEdge = pq.top();
        pq.pop();
        
        if (visited[currentEdge.second.second])
            continue;
        
        addEdges(graph, currentEdge.second.second, visited, pq);

        mst.push_back(currentEdge.second);
        numEdges++;
    }

    for (auto x : mst)
    {
        printf("(%d, %d) ", x.first, x.second);
    }
}

int main()
{   
    list<pair<int, int>> graph[V];

    addEdge(graph, 0, 1, 10, true);
    addEdge(graph, 0, 2, 1, true);
    addEdge(graph, 0, 3, 4, true);
    addEdge(graph, 1, 2, 3, true);
    addEdge(graph, 1, 4, 0, true);
    addEdge(graph, 2, 3, 2, true);
    addEdge(graph, 2, 5, 8, true);
    addEdge(graph, 3, 5, 2, true);
    addEdge(graph, 3, 6, 7, true);
    addEdge(graph, 5, 4, 1, true);
    addEdge(graph, 5, 6, 6, true);
    addEdge(graph, 5, 7, 9, true);
    addEdge(graph, 4, 7, 8, true);
    addEdge(graph, 6, 7, 12, true);

    lazyPrims(graph);
}