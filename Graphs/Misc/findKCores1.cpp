/**
 * Find K-Cores of an undirected Graph,
 * i.e. the Modified Graph when all vertices
 * with degree < k have been removed.
 * 
 * This code is the first version I implemented
 * based on intuition.
 */

#include <bits/stdc++.h>
#include <iostream>
#define print(str) cout << str << endl;
#define forn(i, start, end) for(int i=start;i<end;i++)
using namespace std;
#define V 9
#define INF 100
typedef list<pair<int,int>>* Graph;

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

void removeNode(Graph g, int v, vector<int>& indegree, int k, Graph new_g)
{
    /**
     * This marks that the given node
     * has been removed. Helps prevent
     * infinte recursive calls.
     */
    indegree[v] = -1;

    for (auto x : g[v])
    {
        /**
         * Remove the two edges.
         * Since I only have a vertex v, and not a pair,
         * I'll make one, since un-weighted.
         * If this was weighted, I might have to change
         * the calling function.
         */
        new_g[v].remove(x);
        new_g[x.first].remove(make_pair(v,0));
    
        if (indegree[x.first] != -1)
        {
            indegree[x.first]--;
            if (indegree[x.first] < k)
            {
                removeNode(g, x.first, indegree, k, new_g);
            }
        }
    }

}

/**
 * My algorithm is as follow:
 * Compute the indegrees.
 * Iterate over the indegrees, if indegree[v] < k then
 * call removeNode which:
 * 1. Removes the vertex from the graph.
 * 2. Decreases Indegree of all Neighbours.
 * 3. Recursively calls function for necessary neighbours.
 */

void kCore(Graph g, int k)
{
    // Compute Indegree
    vector<int> indegree(V, 0);
    forn(i,0,V)
    {
        for (auto x : g[i])
        {
            indegree[x.first]++;
        }
    }

    // stores the modified graph.
    list<pair<int,int>> new_g[V];
    forn(i,0,V)
    {
        new_g[i] = list<pair<int,int>>(g[i]);
    }

    forn(i, 0, V)
    {
        if (indegree[i]!=-1 && indegree[i] < k)
        {
            removeNode(g, i, indegree, k, new_g);
        }
    }

    forn(i, 0, V)
    {
        cout << indegree[i] << " " ;
    }
    cout << endl;

    printGraph(new_g);
}

/**
 * If you'll need to carry out
 * remove operations, it's better to use
 * array of lists instead.
 */
int main()
{
    list<pair<int,int>> graph[V];

    // these weights don't mean nothing.
    addEdge(graph, 0, 1); 
    addEdge(graph, 0, 2); 
    addEdge(graph, 1, 2); 
    addEdge(graph, 1, 5); 
    addEdge(graph, 2, 3); 
    addEdge(graph, 2, 4); 
    addEdge(graph, 2, 5); 
    addEdge(graph, 2, 6); 
    addEdge(graph, 3, 4); 
    addEdge(graph, 3, 6); 
    addEdge(graph, 3, 7); 
    addEdge(graph, 4, 6); 
    addEdge(graph, 4, 7); 
    addEdge(graph, 5, 6); 
    addEdge(graph, 5, 8); 
    addEdge(graph, 6, 7); 
    addEdge(graph, 6, 8);  

    kCore(graph, 3);
}