/**
 * Given an undirected Tree, find its
 * center(s)
 */

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

# define V 8
#define forn(i, start, end) for(int i=start;i<end;i++)

typedef list<int>* G;
typedef list<pair<int,int>>* wG;
typedef pair<int, pair<int, int>> T;

// Unweighted graphs generally Undirected
void addEdge(G graph, int u, int v, bool undirected=true)
{
    graph[u].push_back(v);
    if(undirected)
        graph[v].push_back(u);
}

void centerTree(G graph)
{
    vector<int> degree(V, 0);
    vector<int> leaves;
    forn (i, 0, V)
    {
        degree[i] = graph[i].size();
    }

    forn (i, 0, V)
    {
        if (degree[i] == 0 || degree[i] == 1)
            leaves.push_back(i);
    }

    int count = leaves.size();

    while(count < V)
    {
        vector<int> new_leaves;
        for (auto leaf : leaves)
        {
            for (auto neighbour : graph[leaf])
            {
                    degree[neighbour]--;
                    if (degree[neighbour] == 1)
                    {
                        new_leaves.push_back(neighbour);
                    }
            }
        }
        leaves = new_leaves;
        count += new_leaves.size();
    }

    for (auto x : leaves)
    {
        cout << x << " ";
    }
}

int main()
{   
    list<int> graph[V];
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 5);
    addEdge(graph, 2, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 7);
    addEdge(graph, 5, 6);
    centerTree(graph);
}
