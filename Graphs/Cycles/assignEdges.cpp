/**
 * Given a directed graph that doesn't
 * contain any cycles,
 * and a set of undirected edges. You need
 * to convert these undirected edges into directed,
 * so that the graph remains acyclic.
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

/**
 * Consider all undirected edges one by one,
 * say I consider from u to v
 * Now considering the directed edges, check
 * whether u -> .. -> v or reverse (both can't happen, given)
 * It's also possible that none of these is true, should I just
 * arbitrarily do then?
 */

void topoDfsUtil(G graph, vector<int>& topoSort, vector<bool>& visited, int u)
{
    for (auto x : graph[u])
    {
        if (!visited[x])
        {
            visited[x] = true;
            topoDfsUtil(graph, topoSort, visited, x);
        }
    }
    topoSort.push_back(u);
}

/**
 * Generally, you would use a list to return,
 * however we will need to find the positions
 * of the elements in the topoSort,
 * which is problematic in lists, since you can't
 * dereference indices, nor can you compare iterators.
 */

vector<int> topologicalSort(G graph)
{
    vector<int> topoSort;
    vector<bool> visited(V, false);
    forn(i, 0, V)
    {
        if (!visited[i]){
            visited[i] = true;
            topoDfsUtil(graph, topoSort, visited, 0);
        }
    }
    return topoSort;
}

void assignEdges(G graph, vector<pair<int,int>>& undirectedEdges)
{
    vector<int> topoSort = topologicalSort(graph);

    for (auto pair : undirectedEdges)
    {
        int pos1 = find(topoSort.begin(), topoSort.end(), pair.first) - topoSort.begin();
        int pos2 = find(topoSort.begin(), topoSort.end(), pair.second) - topoSort.begin();

        // Remember, topoList is reversed. I didn't waste time in reversing, kya zarurat.
        if (pos1 < pos2){
            addEdge(graph, pair.second, pair.first, false);
        }
        else {
            addEdge(graph, pair.first, pair.second, false);
        }
    }
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

    // list of undirected edges.
    vector<pair<int,int>> undirectedEdges = {{0, 2}, {0, 3}, {4,5}};

    assignEdges(graph, undirectedEdges);

    forn (i, 0, V)
        for (auto x : graph[i])
        {
            cout << i << " " <<x ;
            cout << endl;
        }
}