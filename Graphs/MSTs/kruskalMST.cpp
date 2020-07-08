#include <iostream>
#include <bits/stdc++.h>
using namespace std;

# define V 8
# define forn(i, start, end) for(int i=start;i<end;i++)

typedef list<pair<int,int>>* wG;


void addEdge(wG graph, int u, int v, int w, bool undirected=false)
{
    graph[u].push_back(make_pair(v, w));
    if (undirected){
        graph[v].push_back(make_pair(u, w));
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

class UnionFind{
public:

    UnionFind(int size)
    {
        this->numComponents = size;
        this->size = size;
        this->id = vector<int>(size);
        this->sz = vector<int>(size);

        for (int i=0;i<size;i++)
        {
            id[i] = i;
            sz[i] = 1;
        }
    }

    /**
     * Returns the root node for p.
     * Any function that calls this, will lead
     * to compression of path.
     */
    int find(int p)
    {
        int root = p;
        while( root != id[root])
        {
            root = id[root];
        }

        /**
         * Compress all parents of p.
         */
        while (p != root)
        {
            int next = id[p];
            id[p] = root;
            p = next;
        }

        return root;
    }

    // Checks whether p and q belong to same component
    bool connected(int p, int q)
    {
        return find(p) == find(q);
    }

    // Return size of component that p belongs to.
    int componentSize(int p)
    {
        return sz[find(p)];
    }

    int getSize()
    {
        return this->size;
    }

    int components()
    {
        return this->numComponents;
    }

    vector<int> getId()
    {
        return this->id;
    }

    // Unify components of p and q.
    void unify(int p, int q)
    {
        int root1 = find(p);
        int root2 = find(q);

        if (root1 != root2)
        {
            if (sz[root1] < sz[root2])
            {   
                /**
                 * No need to modify sz[root1], as whenever componentSize is called
                 * for any node in Component1, the root will now return root2, and hence,
                 * it's size will be returned.
                 * Also, not compressing path here, will be compressed later.
                 */
                sz[root2] += sz[root1];
                id[root1] = root2;
            }
            else
            {
                sz[root1] += sz[root2];
                id[root2] = root1;
            }
            this->numComponents--;
        }
    }


private:
    int size;
    int numComponents;
    /**
     * For each index i, id[i] stores
     * the root of i.
     */
    vector<int> id;
    vector<int> sz;
};

void kruskal(wG graph)
{
    // Store the edges in sorted order in a Map
    multimap<int, pair<int, int>> Edges;
    forn (i, 0, V){
        for (auto x : graph[i]){
            Edges.insert({x.second, {i, x.first}});
        }
    }

    // for (auto x : Edges)
    // {
    //     cout << x.first << " {"<<x.second.first<<","<<x.second.second<<"}" ; 
    //     cout << endl; 
    // }

    list<pair<int, int>> MST[V];

    UnionFind uf(V);

    for (auto edge : Edges)
    {
        int p = edge.second.first;
        int q = edge.second.second;

        if (!uf.connected(p, q))
        {
            addEdge(MST, p, q, edge.first);
            uf.unify(p, q);
        }
    }

    forn (i, 0, V)
    {
        cout << i << ":" ;
        for (auto x : MST[i])
            printf("%d{%d} ", x.first, x.second);
        cout << endl;
    }

    cout << endl;
}

int main()
{
    list<pair<int, int>> graph[V];
    addEdge(graph, 0, 1, 3);
    addEdge(graph, 0, 2, 1);
    addEdge(graph, 0, 5, 1);
    addEdge(graph, 2, 3, 1);
    addEdge(graph, 2, 6, 2);
    addEdge(graph, 4, 2, 2);
    addEdge(graph, 4, 5, 1);
    addEdge(graph, 5, 7, 0);
    addEdge(graph, 6, 4, 1);
    addEdge(graph, 6, 7, 3);
    addEdge(graph, 6, 1, 1);
    kruskal(graph);
}