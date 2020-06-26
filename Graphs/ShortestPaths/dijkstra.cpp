/*
 * Dijkstra's Algorithm to find SSSP in graph (DAG or not),
 * with non-negative edge weights.
 * https://www.youtube.com/watch?v=pSqmAO-m7Lk&list=PLDV1Zeh2NRsDGO4--qE8yH72HFL1Km93P&index=18&t=426s
 *
 * Time complexity of this particular implementation is (V+E)logV .. VlogV because each vertex
 * will be inserted into the PQ, and ElogV because for every relaxation (corresponding to every edge),
 * there will be a new dist[u]+weight[u,v], hence this will also be added.
 * If we don't add it, and use Indexed Priority Queue, then we'll need to update it instead,
 * which is in log time, and hence Time Complexity would remain the same.
 */
#include <bits/stdc++.h>
#include <iostream>
#define print(str) cout << str << endl;
#define forn(i, start, end) for(int i=start;i<end;i++)
using namespace std;
#define V 5
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

void dijkstra(Graph g, int v)
{
    vector<int> dist(V, INF);
    dist[v] = 0;

    vector<int> visited(V, false);
    /**
     * How you invoke the Priority Queue is important.
     * Firstly, since we want to extract min-elements, we need a min-heap.
     * This is done by providing the "greater" comparator, the default is less.
     * Now since you're gonna be comparing pairs, the first element of the
     * pair should be the distance.
     */

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push(make_pair(0,v));

    while(!pq.empty())
    {
        pair<int,int> curr = pq.top();
        pq.pop();
        if (curr.first > dist[curr.second])
            continue;
        visited[curr.second] = true;
        for(auto x : g[curr.second]){
            if (!visited[x.first]){
                if (dist[x.first] > dist[curr.second] + x.second){
                    dist[x.first] = dist[curr.second] + x.second;
                    // you should insert, only if update happened.
                    pq.push(make_pair(dist[x.first], x.first));
                }
            }
        }
    }

    for (int i=0;i<V;i++)
    {
        cout << dist[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<pair<int,int>> graph[V];
    addEdge(graph, 0, 1, 4);
    addEdge(graph, 0, 2, 1);
    addEdge(graph, 2, 1, 2);
    addEdge(graph, 1, 3, 1);
    addEdge(graph, 2, 3, 5);
    addEdge(graph, 3, 4, 1);
    dijkstra(graph, 0);

}
