/**
 * SSSP in Directed Acyclic Graphs.
 * This can be done using Topological Sort in O(E+V)
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

void toposortUtil(Graph graph, vector<bool> &visited, list<int> &toposort, int v)
{
    for (auto x : graph[v])
    {
        if(!visited[x.first]){
            visited[x.first] = true;
            toposortUtil(graph, visited, toposort, x.first);
        }
    }
    toposort.push_front(v);
}

list<int> toposort(Graph graph, int size)
{
    vector<bool> visited(size, false);
    list<int> toposortList;
    forn(i,0,size){
        if (!visited[i]){
            visited[i] = true;
            toposortUtil(graph, visited, toposortList, i);
        }
    }
    return toposortList;
}        

/**
 * You can also use this method to get
 * the longest paths, by multiplying each
 * edge weight by -1.
 * This won't alter the Topological Sort.
 */
void shortestPath(Graph graph, int v)
{
    // get the topological sort
    vector<int> dist(V, INF);
    dist[v] = 0;
    list<int> toposortList = toposort(graph, V);

    for (auto it=toposortList.begin(); it!=toposortList.end(); it++)
    {
        for (auto x : graph[*it])
        {
            if (dist[x.first] > dist[*it] + x.second){
                dist[x.first] = dist[*it] + x.second;
            }
        }
    }
    for (auto x : dist)
        cout << x << " ";
    cout << endl;
}

int main()
{
    vector<pair<int,int>> graph[V];
    addEdge(graph, 0, 1, 4);
    addEdge(graph, 0, 2, 3);
    addEdge(graph, 1, 2, 1);
    addEdge(graph, 2, 3, 1);
    addEdge(graph, 1, 3, 3);
    addEdge(graph, 3, 4, 1);
    addEdge(graph, 1, 4, 1);
    shortestPath(graph, 0);
}
