/**
 * Iterative DFS
 */

#include <bits/stdc++.h>
#include <iostream>
#define print(str) cout << str << endl;
#define forn(i, start, end) for(int i=start;i<end;i++)
using namespace std;
#define V 7
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

/**
 * My intuitive approach,
 * slightly roundabout.
 */
void dfs1(Graph g, int v)
{
    vector<bool> visited(V, false);
    stack<int> s;

    s.push(v);
    visited[v] = true;
    cout << v << " ";

    while(!s.empty())
    {
        int val = s.top();
        int size = s.size();

        /**
         * This approach will first add all nodes along a single
         * path to the stack, then backtrack and add neighbours
         * that weren't added.
         * Hence, at a time, only one neighbour gets added to the stack.
         */
        for (auto x : g[val])
        {
            if (!visited[x.first])
            {
                visited[x.first] = true;
                s.push(x.first);
                cout << x.first << " ";
                break;
            }
        }

        /**
         * Nothing added to stack, i.e. this vertex
         * has no neighbours left to visit.
         * Remove it and backtrack.
         */
        if (s.size() == size){
            s.pop();
        }
        
    }
}

/**
 * GfG approach, much cleaner.
 * Literally exactly the BFS approach, except with a Stack.
 */
void dfs2(Graph g, int v)
{
    vector<bool> visited(V, false);
    stack<int> s;

    s.push(v);
    visited[v] = true;
    while(!s.empty())
    {
        int curr = s.top();
        s.pop();
        cout << curr << " ";

        for (auto x : g[curr])
        {
            if (!visited[x.first])
            {
                visited[x.first] = true;
                s.push(x.first);
            }
        }
    }
}

int main()
{
    vector<pair<int,int>> graph[V];

    // these weights don't mean nothing.
    addEdge(graph, 0, 1, 20);
    addEdge(graph, 0, 2, 5);
    addEdge(graph, 1, 3, 20);
    addEdge(graph, 1, 4, 1);
    addEdge(graph, 1, 5, 3);
    addEdge(graph, 2, 6, 3);    
    dfs2(graph, 0);
}