/**
 * Detecting Negative Cycle in a graph,
 * using BellmanFord algo.
 */

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

# define V 5
# define INF 100
#define forn(i, start, end) for(int i=start;i<end;i++)

typedef list<int>* G;
typedef list<pair<int,int>>* wG;

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

bool detectNegCycleUtil(wG graph, vector<int>& d, int u)
{
    forn(i, 0, V-1)
    {
        forn(j, 0, V)
        {
            for (auto x : graph[j])
            {
                int newDist = d[j] + x.second;
                if (newDist < d[x.first]){
                    d[x.first] = newDist;
                }
            }
        }
    }

    forn(j, 0, V)
    {
        for (auto x : graph[j])
        {
            int newDist = d[j] + x.second;
            if (newDist < d[x.first]){
                return true;
            }
        }
    }

    return false;
}

// This will work even for graph with multiple connected components
bool detectNegCycle(wG graph)
{
    vector<int> dist(V, INF);
    forn (i, 0, V)
    {
        if (dist[i] = INF)
        {
            dist[i] = 0;
            if (detectNegCycleUtil(graph, dist, i))
                return true;
        }
    }
    return false;
}

int main()
{
    list<pair<int,int>> graph[V];
    addEdge(graph, 0, 1, -1);
    addEdge(graph, 0, 2, 4);
    addEdge(graph, 1, 2, 3);
    addEdge(graph, 1, 3, 2);
    addEdge(graph, 1, 4, 2);
    addEdge(graph, 3, 2, 5);
    addEdge(graph, 3, 1, 1);
    addEdge(graph, 4, 3, -3);

    cout << detectNegCycle(graph);
}