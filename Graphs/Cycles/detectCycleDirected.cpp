/**
 * Detecting Cycle in a Directed Graph,
 * by performing DFS, keeping track of
 * nodes in the current stack.
 */

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

# define V 6
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

bool dfsUtil(G graph, int u, vector<bool>& visited, vector<bool>& stack)
{
    for (auto x : graph[u])
    {
        if (visited[x] && stack[x])
            return true;
        if (!visited[x])
        {
            visited[x] = true;
            stack[x] = true;
            if (dfsUtil(graph, x, visited, stack))
                return true;
        }
    }

    stack[u] = false;
    return false;
}

bool detectCycle(G graph)
{
    vector<bool> visited(V, false);
    vector<bool> stack(V, false);
    
    forn(i, 0, V){
        if (!visited[i]){
            visited[i] = true;
            stack[i] = true;
            if(dfsUtil(graph, i, visited, stack))
                return true;
        }
    }
    return false;
}

int main()
{
    list<int> graph[V];
    addEdge(graph, 0, 1, false);
    addEdge(graph, 0, 5, false);
    addEdge(graph, 1, 2, false);
    addEdge(graph, 1, 3, false);
    addEdge(graph, 1, 4, false);
    addEdge(graph, 2, 3, false);
    addEdge(graph, 2, 4, false);
    addEdge(graph, 3, 4, false);
    addEdge(graph, 5, 1, false);
    addEdge(graph, 5, 2, false);

    cout << detectCycle(graph);
}