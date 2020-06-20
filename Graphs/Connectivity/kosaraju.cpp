/**
 * Kosaraju's Algorithm to 
 * find all SCCs of a Graph.
 */
#include <bits/stdc++.h>
#include <iostream>
#define print(str) cout << str << endl;
#define forn(i, start, end) for(int i=start;i<end;i++)
using namespace std;

typedef vector<int>* Graph;

void addEdge(Graph graph, int u, int v)
{
    graph[u].push_back(v);
}

void printGraph(Graph graph, int v)
{
    forn(i,0,v)
    {
        for(auto x : graph[i])
            cout << x << " " ;
        cout << endl;
    }
}

void dfsUtil(Graph graph, int v, vector<bool>& visited)
{   
    cout << v << " ";
    for (auto x : graph[v])
    {
        if (!visited[x])
        {
            visited[x] = true;
            dfsUtil(graph, x, visited);
        }
    }
}

void dfsUtil(Graph graph, int v, vector<bool>& visited, stack<int>& order)
{
    for (auto x : graph[v])
    {
        if (!visited[x])
        {
            visited[x] = true;
            dfsUtil(graph, x, visited, order);
        }
    }
    order.push(v);
}


void getSCCs(Graph graph, int size_V)
{
    vector<bool> visited(size_V, false);
    stack<int> order;
    forn(i,0,size_V)
    {
        if(!visited[i]){
            visited[i] = true;
            dfsUtil(graph,i,visited,order);
        }
    }
    // reverse graph
    vector<int> rev_graph[size_V];

    forn(i,0,size_V){
        for(auto x: graph[i]){
            rev_graph[x].push_back(i);
        }
    }
    
    visited = vector<bool>(size_V, false);
    while(!order.empty())
    {
        int v = order.top();
        order.pop();
        if(!visited[v]){
            visited[v] = true;
            dfsUtil(rev_graph, v, visited);   
            cout << endl;
        }
    }
}

int main()
{
    int v = 7;
    // cin >> v;
    vector<int> graph[v];

    addEdge(graph,0,1);
    addEdge(graph,1,2);
    addEdge(graph,2,3);
    addEdge(graph,3,1);
    addEdge(graph,1,6);
    addEdge(graph,6,0);
    addEdge(graph,1,4);
    addEdge(graph,4,5);
    addEdge(graph,2,5);

    getSCCs(graph, 7);
}
