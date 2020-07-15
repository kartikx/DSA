#include <iostream>
#include <bits/stdc++.h>

using namespace std;

# define V 8
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

// void printPath(vector<int>& predU, vector<int>& predV, int toU, int toV, int u, int v)
// {
// }

void bidirectionalBFS(G graph, int u, int v)
{
    /**
     * PredU stores preds encountered during BFS from U,
     * and PredV for BFS from V.
     * -2 is a placeholder for not visited yet.
     * -1 means the start.
     */
    vector<int> predU(V, -2);
    vector<int> predV(V, -2);
    predU[u] = -1;
    predV[v] = -1;

    queue<int> qU, qV;
    qU.push(u); qV.push(v);

    bool found = false;
    while (!qU.empty() && !qV.empty() && !found)
    {
        int currU = qU.front(); qU.pop();
        for (auto x : graph[currU])
        {   
            /**
             * If the current node I'm visiting,
             * has been visited in the route from V.
             */
            if (predV[x] != -2){
                found = true;
                // currU -> u and v -> x
                // printPath(predU, predV, currU, x, u, v);
            }

            else if (predU[x] == -2)
            {
                predU[x] = currU;
                qU.push(x);
            }
        }

        if (!found)
        {
            int currV = qV.front(); qV.pop();
            for (auto x : graph[currV])
            {
                if (predU[x] != -2) {
                    found = true;
                    // x -> u and v -> currV
                    // printPath(predU, predV, x, currV, u, v);
                }

                else if (predV[x] == -2)
                {
                    predV[x] = currV;
                    qV.push(x);
                }
            }
        }
    }
}

int main()
{
    list<int> graph[V];
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 0, 3);
    addEdge(graph, 0, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 5);
    addEdge(graph, 3, 6);
    addEdge(graph, 5, 7);
    addEdge(graph, 6, 7);

    bidirectionalBFS(graph, 0, 7);
}