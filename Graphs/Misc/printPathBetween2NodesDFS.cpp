/**
 * Given 2 nodes in a Directed Graph,
 * print the path between them.
 * DFS Based Implementation.
 */

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

# define V 9
#define forn(i, start, end) for(int i=start;i<end;i++)

typedef list<int>* G;

void addEdge(G graph, int u, int v, bool undirected=true)
{
    graph[u].push_back(v);
    if(undirected)
        graph[v].push_back(u);
}

/**
 * Used to print the path when
 * terminal vertex detected.
 */
void printPath(vector<int>& st)
{
    for (auto x : st)
    {
        cout << x << " ";
    }
    cout << endl;
}

/**
 * You have a vector imitating a stack, to keep
 * track of the nodes you have visited.
 * Towards the end, when the function backtracks,
 * so does the stack.
 * Note that we also need to unmark the node
 * as visited, to allow other paths to visit it.
 * Also note that the vectors are passed by reference,
 * (unlike the Article Implementation).
 */

void dfs(G graph, int u, int dest, vector<bool>& visited, vector<int> & st)
{

    st.push_back(u);
    visited[u] = true;

    if (u == dest)
    {
        printPath(st);
        st.pop_back();
        visited[u] = false;
        return;
    }

    for (auto x : graph[u])
    {
        if (!visited[x])
        {
            visited[x] = true;
            dfs(graph, x, dest, visited, st);
        }
    } 

    st.pop_back();
    visited[u] = false;
}

int main()
{
    list<int> graph[V];

    // Image of Graph: https://imgur.com/a/bLfSv0o
    addEdge(graph, 0, 1, true);
    addEdge(graph, 0, 2, true);
    addEdge(graph, 0, 3, true);
    addEdge(graph, 2, 7, true);
    addEdge(graph, 7, 5, true);
    addEdge(graph, 5, 8, true);
    addEdge(graph, 1, 5, true);
    addEdge(graph, 3, 4, true);
    addEdge(graph, 4, 6, true);

    vector<bool> visited(V, false);
    vector<int> st;

    // Feel free to modify these values to check.
    dfs(graph, 1, 4, visited, st);
}