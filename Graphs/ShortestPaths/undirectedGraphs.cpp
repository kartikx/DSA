/**
 * Find SSSP for Undirected Weighted Graphs
 * Using BFS
 * In Dijkstra's, you're forced to use a PQ, because
 * you want to pick the best node each time. However that's not
 * needed here, as even if you pick the poor one, if it's connected
 * by an edge to the better one, it will be rectified later.
 */

#include <bits/stdc++.h>
#include <iostream>
#define print(str) cout << str << endl;
#define forn(i, start, end) for(int i=start;i<end;i++)
using namespace std;
#define V 6
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

void shortestPath(Graph g, int source)
{
    vector<int> dist(V, INF);
    vector<bool> visited(V, false);
    queue<int> toVisit;

    dist[source] = 0;
    visited[source] = true;
    toVisit.push(source);

    while(!toVisit.empty())
    {
        int visit = toVisit.front();
        toVisit.pop();
        for (auto x : g[visit])
        {   
            // this should be done, even for vertices that have been visited.
            int newDist = dist[visit] + x.second;
            if (newDist < dist[x.first])
                dist[x.first] = newDist;
            if (!visited[x.first]){
                visited[x.first] = true;
                toVisit.push(x.first);
            }
        }
    }

    for_each(dist.begin(), dist.end(), [](int &d){cout << d << " ";});
    cout << endl;
}

int main()
{
    vector<pair<int,int>> graph[V];

    addEdge(graph, 0, 1, 20);
    addEdge(graph, 0, 2, 5);
    addEdge(graph, 1, 2, 20);
    addEdge(graph, 2, 3, 1);
    addEdge(graph, 1, 3, 3);
    addEdge(graph, 2, 4, 3);
    addEdge(graph, 4, 5, 1);
    addEdge(graph, 3, 5, 1);

    shortestPath(graph, 0);
}
