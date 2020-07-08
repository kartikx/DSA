/**
 * Bellman Ford to find SSSP for general case.
 * Time complexity O(E*V).
 * Here I'm using Adjacency List representation, so it's O(V^3)
 */

#include <bits/stdc++.h>
#include <iostream>
#define print(str) cout << str << endl;
#define forn(i, start, end) for(int i=start;i<end;i++)
using namespace std;
#define V 5
#define INF 100
typedef vector<pair<int,int>>* Graph;

void addEdge(Graph graph, int u, int v, int w=0)
{
    graph[u].push_back(make_pair(v,w));
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

void bellmanFord(Graph g, int v)
{
    int dist[V];
    forn(i,0,V){
        dist[i] = INF;
    }
    dist[v] = 0;

    forn(i,0,V-1)
    {
        forn(j,0,V){
            for(auto x : g[j]){
                if (dist[x.first] > dist[j] + x.second)
                    dist[x.first] = dist[j] + x.second;
            }
        }
    }
    // checking negative cycles
    forn(i,0,V-1)
    {
        forn(j,0,V){
            for(auto x : g[j]){
                if (dist[x.first] > dist[j] + x.second)
                    dist[x.first] = -INF;
            }
        }
    }

    forn(i,0,V)
    {
        cout << dist[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<pair<int,int>> graph[V];
    addEdge(graph, 0, 1, 4);
    addEdge(graph, 0, 2, 3);
    addEdge(graph, 2, 1, 2);
    addEdge(graph, 1, 3, -1);
    addEdge(graph, 3, 2, -2);
    addEdge(graph, 3, 4, 1);
    bellmanFord(graph, 0);
}
