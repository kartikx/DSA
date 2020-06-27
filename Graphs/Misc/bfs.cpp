/**
 * Breadth First Search of a Graph
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

void bfs(Graph graph, int v)
{   
    vector<int> visited(V, false);
    queue<int> toVisit;
    visited[v] = true;
    toVisit.push(v);
    while(!toVisit.empty())
    {
        int visit = toVisit.front();
        toVisit.pop();
        cout << visit << " ";
        for (auto x : graph[visit])
        {   
            if (!visited[x.first]){
                visited[x.first] = true;
                toVisit.push(x.first);
            }
        }
    }
}

int main()
{
    vector<pair<int,int>> graph[V];

    addEdge(graph, 0, 1, 1);
    addEdge(graph, 0, 2, 1);
    addEdge(graph, 1, 2, 1);
    addEdge(graph, 2, 3, 1);
    addEdge(graph, 1, 3, 1);
    addEdge(graph, 3, 4, 1);
    addEdge(graph, 2, 4, 1);

    bfs(graph, 0);
}
