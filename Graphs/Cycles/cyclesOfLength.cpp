#include <iostream>
#include <bits/stdc++.h>

using namespace std;

# define V 10
#define forn(i, start, end) for(int i=start;i<end;i++)

typedef list<int>* G;
typedef list<pair<int,int>>* wG;

void addEdge(G graph, int u, int v, bool undirected=true)
{
    graph[u].push_back(v);
    if(undirected)
        graph[v].push_back(u);
}


int total = 0;

void printPath(int start, int end, vector<int>& parent)
{
    total++;
    while(start != end)
    {
        cout << start << " ";
        start = parent[start];
    }
    cout << end << endl;
}

void dfsUtil(G graph, int n, int u,vector<int>& parent, vector<bool>& visited, vector<int>& count)
{
    for (int x : graph[u])
    {
        if (!visited[x])
        {
            visited[x] = true;
            count[x] = count[u]+1;
            parent[x] = u;
            dfsUtil(graph, n, x, parent, visited, count);
        }
        
        else if (x != parent[u]) {
            if (abs(count[u] - count[x]) + 1 == n){

                // I'll only print path for one of the two times this edge is considered.
                if (count[u] > count[x])
                {
                    printPath(u, x, parent);
                }
            }
        }
    }
}

/**
 * Basic Idea:
 * Start from an arbitrary vertex, and perform DFS,
 * this will lead to the traversal of the entire graph.
 * Initially set count[source] = 0;
 * 
 * Subsequently whenever you reach a vertex v from u,
 * do count[v] = count[u] + 1.
 * 
 * Similar to having a clock, however don't use a global
 * variable. As that would lead to different results based
 * on different traversals.
 * 
 * Eventually if you get to a vertex whose neighbour has been
 * visited and is not its parent, check if the difference of
 * the counts of the two is n-1.
 */
void cyclesOfLength(G graph, int n)
{

    vector<bool> visited(V, false);
    visited[0] = true;
    vector<int> count(V, 0);
    vector<int> parent(V, -1);

    dfsUtil(graph, n, 0, parent, visited, count);
    cout << total << endl;
}

int main()
{
    list<int> graph[V];

    /**
     * View the Graph as an Image: 
     * https://imgur.com/a/bCRlD8R
     */

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 6);

    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 5);

    addEdge(graph, 2, 4);

    addEdge(graph, 3, 4);

    addEdge(graph, 5, 6);
    addEdge(graph, 5, 7);
    addEdge(graph, 5, 9);

    addEdge(graph, 7, 8);
    addEdge(graph, 9, 8);

    cyclesOfLength(graph, 4);
}