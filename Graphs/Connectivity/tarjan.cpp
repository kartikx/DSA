#include <iostream>
#include <bits/stdc++.h>

using namespace std;

# define V 7
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

int id = 0;
int scc = 0;
void dfsUtil(G graph, int u, vector<int>& ids, vector<int>& lows, vector<bool>& onStack, stack<int>& nums)
{
    ids[u] = lows[u] = id++;
    onStack[u] = true;
    nums.push(u);

    for (auto x : graph[u])
    {
        if (ids[x] == -1)
        {
            dfsUtil(graph, x, ids, lows, onStack, nums);
        }
        
        if (onStack[x])
        {
            lows[u] = min(lows[u], lows[x]);
        }
    }

    if (ids[u] == lows[u])
    {
        while (nums.top() != u)
        {
            int val = nums.top();
            nums.pop();
            onStack[val] = false;
            lows[val] = ids[u];
        }
        scc++;
    }
}

void tarjanSCC(G graph)
{
    vector<int> ids(V, -1);
    vector<int> lows(V);
    vector<bool> onStack(V, false);
    stack<int> nums;

    forn(i, 0, V)
    {
        if (ids[i] == -1)
        {
            dfsUtil(graph, i, ids, lows, onStack, nums);
        }
    }
}

int main()
{   
    list<int> graph[V];
    addEdge(graph, 0, 1, false);
    addEdge(graph, 0, 2, false);
    addEdge(graph, 2, 1, false);
    addEdge(graph, 1, 3, false);
    addEdge(graph, 3, 2, false);
    addEdge(graph, 4, 1, false);
    addEdge(graph, 4, 5, false);
    addEdge(graph, 5, 3, false);
    addEdge(graph, 5, 6, false);
    addEdge(graph, 6, 4, false);

    tarjanSCC(graph);

    cout << scc << endl;
}