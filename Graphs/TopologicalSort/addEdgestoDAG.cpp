/**
 * Given a DAG, find the maximum number
 * of Edges that you can add to it,
 * so that it remains a DAG.
 * Print these edges as well.
 */

#include <bits/stdc++.h>
#include <iostream>
#define print(str) cout << str << endl;
#define forn(i, start, end) for(int i=start;i<end;i++)
using namespace std;
#define V 6
#define INF 100
typedef vector<pair<int,int>>* Graph;

void addEdge(Graph graph, int u, int v, int w=0)
{
    graph[u].push_back(make_pair(v,w));
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
 * Contrary to intuition, this method is not slow.
 * The vector returned isn't later going to be copied
 * value by value. Instead it functions through move semantics,
 * which rearranges the pointers. Also see copy elision.
 */
vector<int> topoSort(Graph graph)
{
    vector<int> inDegree(V,0);
    queue<int> toVisit;

    vector<int> topoSortOrder;

    forn(i,0,V){
        for(auto x : graph[i]){
            inDegree[x.first]++;
       }
    }
    forn(i,0,V){
        if (inDegree[i] == 0)
            toVisit.push(i);
    }
    while(!toVisit.empty())
    {
        int val = toVisit.front();
        toVisit.pop();
        topoSortOrder.push_back(val);
        for (auto x : graph[val]){
            inDegree[x.first]--;
            if(inDegree[x.first] == 0)
                toVisit.push(x.first);
        }
    }
    return topoSortOrder;
}

/**
 * The main idea is that while traversing the Topo Order
 * from L to R. You can add whatever edge that doesn't exist
 * already. For each vertex instead of traversing it's adj list
 * to check if an edge exists, we'll instantiate a visited arr
 * for it. Set true for all neighbours at the start, and then
 * while adding new edge check the value of visited.
 * ? If you just want the number of edges that can be added,
 * ? It's a one-line answer V*(V-1)/2 - |E|
 */

void printMaxEdgesAdded(Graph graph)
{
    vector<int> topoSortOrder = topoSort(graph);
    vector<bool> visited(V, false);
    forn (i, 0, V)
    {   
        for (auto x : graph[topoSortOrder[i]])
            visited[x.first] = true;
    
        forn(j, i+1, V){
            if (!visited[topoSortOrder[j]]) // if not a neighbour
                cout << topoSortOrder[i] << "-" << topoSortOrder[j] << "," ;
            visited[topoSortOrder[j]] = false; // hence you don't need to reinstantiate each time.
        }
    }
}

int main()
{
    vector<pair<int,int>> graph[V];

    addEdge(graph, 2, 3, 1);
    addEdge(graph, 3, 1, 1);
    addEdge(graph, 4, 1, 1);
    addEdge(graph, 4, 0, 1);
    addEdge(graph, 5, 0, 1);
    addEdge(graph, 5, 2, 1);

    printMaxEdgesAdded(graph);
}
