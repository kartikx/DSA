/**
 * Find number of nodes in a tree at 
 * level L (levels start from 0).
 * The tree is provided as an undirected graph,
 * rooted at node 0.
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

// BFS Based Approach
void getNumberOfNodes(Graph g, int level)
{
    queue<int> toVisit;
    vector<bool> visited(V, false);
    int countLevel = 0;

    // root node is 0, given.
    toVisit.push(0);
    visited[0] = true;
    while(!toVisit.empty())
    {
        int size = toVisit.size();
        if (countLevel == level)
        {
            cout << size << endl;
            break;
        }
        forn (i, 0, size){
            int val = toVisit.front();
            toVisit.pop();
            for (auto x : g[val])
            {
                if (!visited[x.first])
                {
                    visited[x.first] = true;
                    toVisit.push(x.first);
                }
            }
        }
        ++countLevel;
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
    getNumberOfNodes(graph, 3);
}
