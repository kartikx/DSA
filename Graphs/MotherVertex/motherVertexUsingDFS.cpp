/**
 * Attempt to find neighbours of all vertices,
 * by running DFS V times. However, to save time,
 * if a vertex encountered in a path has been computed
 * before, it's neighbours will be merged.
 *
 * Problem with this code is that it doesn't work if you have
 * back edges, i.e. a vertex you encounter is a neighbour of a 
 * vertex in the parent path (which hasn't been completely solved yet)
 * You can't merge it with its parent, as the parent isn't complete.
 */
// ? Hence, find better algo. to find all vertices reachable.
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

void my_merge(vector<int> arr[], int x, int y)
{
    forn(i,0,arr[0].size())
    {
        if(arr[y][i] == 1)
            arr[x][i] = 1;
    }
}

void mVUtil(vector<int> graph[], int v, vector<int> arr[], vector<bool>& visited)
{   
    if (arr[v][0] == 1)
        return;
    arr[v][0] = 1;
    arr[v][v+1] = 1;
    for (auto x : graph[v])
    {
        arr[v][x+1] = 1;
        if (arr[x][0] == 1)
            my_merge(arr, v, x);
        else{
            if (!visited[x]){
                visited[x] = true;
                mVUtil(graph, x, arr, visited);
                my_merge(arr, v, x);
            }
        }
    }
}

void motherVertex(vector<int> graph[], int size)
{
    vector<int> store[size];

    forn(i,0,size)
        store[i] = vector<int>(size+1,0);

    for(int i=0;i<size;i++)
    {
        vector<bool> visited(size, false);
        bool flag = 0;
        mVUtil(graph, i, store, visited);
        forn(j,1,size+1)
        {   
            if (store[i][j] == 0)
                flag = 1;       
        }
        if (!flag)
            cout << "Mother " << i << endl; 
    }
}

int main()
{
    int v;
    cin >> v;
    vector<int> graph[v];

    addEdge(graph,0,1);
    addEdge(graph,0,2);
    addEdge(graph,1,3);
    addEdge(graph,4,1);
    addEdge(graph,5,2);
    addEdge(graph,5,6);
    addEdge(graph,6,4);
    addEdge(graph,6,0);

    motherVertex(graph, v);
}
