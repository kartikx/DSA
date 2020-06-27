/**
 * You're given a tree in the form of an
 * undirected graph with its root.
 * What follows are Q queries, of the form (u,v)
 * where you have to output whether u and v lie
 * on the same path from root to the bottom.
 */

#include <bits/stdc++.h>
#include <iostream>
#define print(str) cout << str << endl;
#define forn(i, start, end) for(int i=start;i<end;i++)
using namespace std;
#define V 7
#define INF 100
typedef list<pair<int,int>>* Graph;

int dp[V];

void addEdge(Graph graph, int u, int v, int w=0)
{
    graph[u].push_back(make_pair(v,w));
}

void printGraph(Graph graph)
{
    forn(i,0,V)
    {
        for(auto x : graph[i])
            printf("%d{%d} ", x.first,x.second);
        cout << endl;
    }
}

void dfsUtil(Graph g, vector<bool>& visited, pair<int,int>* time, int u, int& count)
{
    count++;
    time[u].first = count;
    for (auto x : g[u])
    {
        if(!visited[x.first])
        {
            visited[x.first] = true;
            dfsUtil(g, visited, time, x.first, count);
        }
    }
    count++;
    time[u].second = count;
}

/**
 * My Algo:
 * Two nodes will be on the same path from top to bottom,
 * if the start,finish times of one is nested within the 
 * other.
 */
bool nodesOnSamePath(Graph g, int root, int u, int v, pair<int,int>* time)
{
    auto p1 = time[u];
    auto p2 = time[v];
    if ((p1.first < p2.first && p1.second > p2.second) ||
        (p2.first < p1.first && p2.second > p1.second))
        return true;
    return false;
}

int main()
{
    list<pair<int,int>> graph[V];
    memset(dp, 0, sizeof(int)*V);
    dp[4] = 1;
    addEdge(graph, 0, 1); 
    addEdge(graph, 0, 2);
    addEdge(graph, 0, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 5);
    addEdge(graph, 3, 6);

    // keep the dfs pre-computed.
    vector<bool> visited(V, false);
    int count = 0;
    pair<int,int> time[V];
    dfsUtil(graph, visited, time, 0, count);

    int q;
    cin >> q;
    forn(i,0,q)
    {
        int u,v;
        cin >> u >> v;
        cout << nodesOnSamePath(graph, 0, u, v, time) << endl;
    }
}