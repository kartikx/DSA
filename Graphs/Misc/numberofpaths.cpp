/**
 * Iterative DFS
 */

#include <bits/stdc++.h>
#include <iostream>
#define print(str) cout << str << endl;
#define forn(i, start, end) for(int i=start;i<end;i++)
using namespace std;
#define V 5
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

// Suppose graph is allowed to have cycles.
// it's your job to disregard paths with cycles. Don't count them.
void dfsUtilNaive(Graph g, int u, int v, int& count, vector<bool>& visited)
{
    for (auto x : g[u])
    {   
        if (x.first == v)
        {
            count++;
            continue;
        }
        if (!visited[x.first])
        {
            visited[x.first] = true;
            dfsUtilNaive(g, x.first, v, count, visited);
        }
    }
    // be careful not to return without executing this statement.
    visited[u] = false;
}

/**
 * I think a dfsUtil with DP is not possible if the graph
 * may contain cycles.
 * This is because if you solve a node (say C), you might
 * disregard certain possible paths, because they contain some
 * node that's already in the path. 
 * Hence if you again reach C from some other path, you can't
 * just use dp[c] as it might be lesser than the actual value
 * (as some paths might now be possible). It may also be higher,
 * (if some paths are now not allowed).
 */
// This implementation assumes no cycles in graph.
int dfsUtilDP(Graph g, int u, int v)
{
    if (dp[u] != 0)
    {
        return dp[u];
    }

    for (auto x : g[u])
    {
        dfsUtilDP(g, x.first, v);
    }

    for (auto x : g[u])
    {
        dp[u] += dp[x.first];
    }
    return dp[u];
}

void countPaths(Graph g, int u, int v)
{
    int count = 0;
    vector<bool> visited(V, false);
    visited[u] = true;
    dfsUtilNaive(g, u, v, count, visited);
    cout << count << endl;
}

void countPathsUsingBFS(Graph g, int u, int v)
{
    int count = 0;
    
    // I think we should use BFS for this.
    queue<int> toVisit;
    toVisit.push(u);


    while(!toVisit.empty())
    {
        int val = toVisit.front();
        toVisit.pop();
        for (auto x : g[val])
        {   
            if (x.first == v)
            {
                count++;
            }
            else{
                if (x.first != u)
                    toVisit.push(x.first);

            }
        }
    }
    cout << count << endl;
}

int main()
{
    list<pair<int,int>> graph[V];
    memset(dp, 0, sizeof(int)*V);
    dp[4] = 1;
    addEdge(graph, 0, 1); 
    addEdge(graph, 0, 2);
    addEdge(graph, 0, 3);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 3); 
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 4);
    addEdge(graph, 2, 1);
    addEdge(graph, 3, 2);

    countPaths(graph, 0, 4);     
}