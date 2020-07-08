/**
 * Detecting Cycle in an unDirected Graph,
 * by performing DFS. 
 * You can't use Directed Graph code for this, as it will
 * return cycle for parent as well.
 * 
 * Basic idea is that whenever you call DFSUtil for a new node,
 * you pass into it information about the parent, i.e. the vertex
 * that called this method.
 * 
 * During a DFSUtil, if a neighbour has been visited, but is not the
 * parent, then there's a cycle.
 * 
 * Food for thought: In an undirected graph, if a neighbour has been visited,
 * then either you called from that neighbour. If you didn't, then why wasn't
 * this vertex detected earlier?
 */
// test nahi kiya
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

# define V 4
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

bool dfsUtil(G graph, int u, vector<bool>& visited, int parent)
{
    for (auto x : graph[u])
    {
        if (!visited[x])
        {
            visited[x] = true;
            if(dfsUtil(graph, x, visited, u))
                return true;
        }
        
        else if (x != parent)
            return true;
    }

    return false;
}

bool detectCycle(G graph)
{
    vector<bool> visited(V, false);
    
    forn(i, 0, V){
        if (!visited[i]){
            visited[i] = true;
            if(dfsUtil(graph, i, visited, -1))
                return true;
        }
    }
    return false;
}

int main()
{
    list<int> graph[V];

    cout << detectCycle(graph);
    // Ignoring cycles for now.
}