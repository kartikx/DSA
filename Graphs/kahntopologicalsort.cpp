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

void kahntoposort(vector<int> graph[], int size)
{
    // initialize
    vector<int> indegree(size,0);
    vector<int> result;
    forn(i,0,size)      //O(V+E)
    {
        for(auto it = graph[i].cbegin(); it!=graph[i].cend();it++)
        {
            indegree[*it]++;
        }
    }
    queue<int> toVisit;
    forn(i,0,size)  // O(V)
    {
        if (indegree[i] == 0)
            toVisit.push(i);
    }
    while(!toVisit.empty())
    {
        int val = toVisit.front();
        toVisit.pop();
        cout << val << " ";
        for(auto x : graph[val])
        {
            indegree[x]--;
            if (indegree[x] == 0)
                toVisit.push(x);
        }
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

    kahntoposort(graph, v);
}