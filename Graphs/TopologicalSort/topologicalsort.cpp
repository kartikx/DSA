/**
 * Program to print a single topological sort
 * given a Graph. Uses standard algorithm,
 * based on DFS intuition.
 */
#include <bits/stdc++.h>
#include <iostream>
# define print(str) cout << str << endl;
# define forn(i, start, end) for(int i=start;i<end;i++) 
using namespace std;

void addEdge(vector<int> graph[], int u, int v)
{
    graph[u].push_back(v);
}

void printGraph(vector<int> graph[], int v)
{
    forn(i,0,v)
    {
        for(auto x : graph[i])
            cout << x << " " ;
        cout << endl;
    }
}

void toposortUtil(vector<int> graph[], vector<bool> &visited, list<int> &toposort, int v)
{
    for (auto x : graph[v])
    {
        if(!visited[x]){
            visited[x] = true;
            toposortUtil(graph, visited, toposort, x);
        }
    }
    toposort.push_front(v);
}

void toposort(vector<int> graph[], int size)
{
    vector<bool> visited(size, false);
    list<int> toposort;
    forn(i,0,size){
        if (!visited[i]){
            visited[i] = true;
            toposortUtil(graph, visited, toposort, i);
        }
    }
    for(auto x : toposort)
    {
        cout << x << " ";
    }
    cout << endl;
}        

int main()
{
    int v;
    cin >> v;
    vector<int> graph[v];

    addEdge(graph, 2, 3);
    addEdge(graph, 3, 1);
    addEdge(graph, 4, 0);
    addEdge(graph, 4, 1);
    addEdge(graph, 5, 0);
    addEdge(graph, 5, 2);

    toposort(graph, v);
}