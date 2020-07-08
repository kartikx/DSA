/**
 * Given an undirected graph,
 * find the sum of minimum nodes
 * at each level of the tree.
 */

#include <bits/stdc++.h>
#include <iostream>
#define print(str) cout << str << endl;
#define forn(i, start, end) for(int i=start;i<end;i++)
using namespace std;
#define V 8
#define INF 100
typedef list<pair<int,int>>* Graph;

int dp[V];

void addEdge(Graph graph, int u, int v, int w=0)
{
    graph[u].push_back(make_pair(v,w));
    graph[v].push_back(make_pair(u,w));
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

void getMinimumSumAcrossLevels(Graph g, int src)
{
    queue<int> toVisit;
    vector<bool> visited(V, false);
    visited[src] = true;
    toVisit.push(src);
    int sum = src;
    while(!toVisit.empty())
    {
        int size = toVisit.size();
        int minVal = INT_MAX;
        forn (i, 0, size)
        {
            int curr = toVisit.front();
            toVisit.pop();
            for (auto x : g[curr])
            {
                if(!visited[x.first])
                {
                    visited[x.first] = true;
                    toVisit.push(x.first);
                    if (x.first < minVal)
                        minVal = x.first;
                }
            }
        }
        if (minVal != INT_MAX)
            sum += minVal;
    }
    cout << sum << endl;
}


int main()
{
    list<pair<int,int>> graph[V];

    addEdge(graph, 0, 1); 
    addEdge(graph, 0, 6);
    addEdge(graph, 0, 3);
    addEdge(graph, 1, 5);
    addEdge(graph, 1, 4);
    addEdge(graph, 6, 2);
    addEdge(graph, 3, 7);

    getMinimumSumAcrossLevels(graph, 1);
    
}