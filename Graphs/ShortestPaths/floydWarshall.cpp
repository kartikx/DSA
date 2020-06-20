/**
 * Floyd Warshall to find
 * all shortest paths in a adjacency matrix
 * representation in O(V^3).
 */
#include <iostream>
#include <bits/stdc++.h>
// set INF to a large constant instead of INT_MAX, to prevent overflows.
#define INF 100
#define V 4
using namespace std;
typedef unordered_set<int>* Graph;

void floydWarshall(int graph[][V])
{   
    /**
     * We're considering a 2D matrix, because
     * each time the more optimal solution for case k,
     * will build off of the previous opt. sol. (k-1).
     */
    int dist[V][V];

    /**
     * To allow printing the shortest path.
     * For next[i][j] outputs which vertex you should visit,
     * in order to be on the shortest path from i to j.
     */
    int next[V][V];

    /**
     * Initializing the dist matrix, to be the Adj. Matrix,
     * this is the base case, k=0, when no intermediate vertices
     * are considered.
     */
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            dist[i][j] = graph[i][j];
            // Since in the base case we're considering direct paths i->j.
            if (dist[i][j] != INF)
                next[i][j] = j;
        }
    }

    /**
     * Think recursively.. if you've come up with an optimal solution
     * for i -> j using intermediate vertices 0..k-1, and are now to consider
     * for k intermediate vertices. Then your new optimal path may be :
     * i .. k .. j where we'll use (0..k-1) vertices in i..k and k..j each.
     * Hence the optimal value for the subpaths, can be computed using the 
     * output from the previous iteration [This is the importance of this loop structure]
     */
    for(int k=0;k<V;k++)
        for(int i=0;i<V;i++)
            for(int j=0;j<V;j++)
            {
                if (dist[i][j] > dist[i][k]+dist[k][j])
                {
                    dist[i][j] = dist[i][k]+dist[k][j];
                    next[i][j] = next[i][k];
                }
            }

    /**
     * Negative Cycle Checking.
     * In the above loop, you considered the solution using K vertices.
     * Now if using the same K vertices, you can obtain an even better solution,
     * then that would imply there's a negative cycle.
     */

    for (int k=0;k<V;k++)
        for(int i=0;i<V;i++)
            for(int j=0;j<V;j++)
                if (dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = -INF;
                    next[i][j] = -1;
                }

    // you may write implementation here, to print shortest path as well.. Skipping for now.

    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }

}

int main()
{
    int graph[V][V] = {{0,5,INF,10},{INF,0,3,INF},{INF,INF,0,1},{INF,INF,INF,0}};
    floydWarshall(graph);
}
