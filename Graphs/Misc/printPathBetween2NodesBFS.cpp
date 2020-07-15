/**
 * Given 2 nodes in a Directed Graph,
 * print the path between them.
 * DFS Based Implementation.
 */

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

# define V 9
#define forn(i, start, end) for(int i=start;i<end;i++)

typedef list<int>* G;

void addEdge(G graph, int u, int v, bool undirected=true)
{
    graph[u].push_back(v);
    if(undirected)
        graph[v].push_back(u);
}

/**
 * Used to print the path when
 * terminal vertex detected.
 */
void printPath(vector<int>& st)
{
    for (auto x : st)
    {
        cout << x << " ";
    }
    cout << endl;
}

bool visitedAlready(int u, vector<int>& path)
{
    for (auto x : path)
    {
        if (x == u)
            return true;
    }
    
    return false;
}

/**
 * The idea is to push in paths into
 * the Queue.
 */
void bfs(G graph, int u, int dest)
{
    vector<int> visited(V, false);
    queue<vector<int>> paths;

    vector<int> path(1, u);
    paths.push(path);

    while (!paths.empty())
    {
        vector<int> currPath = paths.front(); paths.pop();

        if (currPath.back() == dest)
        {
            printPath(currPath);
        }
        
        for (auto x : graph[currPath.back()])
        {
            if (!visitedAlready(x, currPath))
            {
                vector<int> newPath(currPath);
                newPath.push_back(x);
                paths.push(newPath);
            }
        }
    }
}


int main()
{
    list<int> graph[V];

    // Image of Graph: https://imgur.com/a/bLfSv0o
    addEdge(graph, 0, 1, true);
    addEdge(graph, 0, 2, true);
    addEdge(graph, 0, 3, true);
    addEdge(graph, 2, 7, true);
    addEdge(graph, 7, 5, true);
    addEdge(graph, 5, 8, true);
    addEdge(graph, 1, 5, true);
    addEdge(graph, 3, 4, true);
    addEdge(graph, 4, 6, true);

    bfs(graph, 0, 8);
}