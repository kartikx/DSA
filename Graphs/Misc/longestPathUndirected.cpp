/**
 * Find the longest path in an
 * Undirected Graph.
 */

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

# define V 9
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

pair<int, int> bfs(G graph, int u)
{
    int dist[V];
    memset(dist, -1, sizeof(dist));

    dist[u] = 0;
    queue<int> toVisit;
    toVisit.push(u);

    while(!toVisit.empty())
    {
        int curr = toVisit.front(); toVisit.pop();
        for (auto x : graph[curr])
        {
            if (dist[x] == -1)
            {
                dist[x] = dist[curr] + 1;
                toVisit.push(x);
            }
        }
    }
    int max = -1, maxIndex=0;
    forn (i, 0, V)
    {
        if (dist[i] > max){
            max = dist[i];
            maxIndex = i;
        }
    }

    return make_pair(maxIndex, max);
}

void dfsUtil(G graph, int u, int parent, vector<int> path, pair<int, vector<int>>& max)
{
    path.push_back(u);
    for (auto x : graph[u])
    {
        if (x != parent)
        {
            dfsUtil(graph, x, u, path, max);
        }
    }

    if (path.size() > max.first){
        max.first = path.size();
        max.second = path;
    }
}

// Because I have the two nodes I want to connect, I could start BFS from both?
void findLongestPath(G graph)
{
    // first find one terminal of the longest path.
    int t1 = bfs(graph, 0).first;

    /**
     * This code allows for an easy find of 
     * the terminal nodes and the length of the longest path.
        auto res = bfs(graph, t1);

        printf("Longest path is from %d to %d of length %d", t1, res.first, res.second);
     */

    // Now that I have one end, I could perform dfs from this node.
    vector<int> path;
    pair<int, vector<int>> maxPath(0, vector<int>());
    dfsUtil(graph, t1, -1, path, maxPath);

    cout << "The longest path is: " << endl;
    for (auto x : maxPath.second)
        cout << x << " ";
    cout << endl;
}

int main()
{
    list<int> graph[V];
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 0, 3);
    addEdge(graph, 2, 7);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 6);
    addEdge(graph, 1, 5);
    addEdge(graph, 5, 8);

    bidirectionalBFS(graph, 6, 8);
    // findLongestPath(graph);
}