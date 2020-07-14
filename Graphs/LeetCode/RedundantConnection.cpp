/**
 * You're given an undirected graph which used to be
 * a tree, but has been added an edge to, so that it contains
 * a cycle. You have to find this edge.
 * Input: Graph in the form of an edge list.
 * Output: The troublemaker edge, if multiple such edges
 * exist, return the last one.
 */

/**
 * Implementation:
 * Since the input is in the form of an edge list, it seemed
 * intuitive for me to put these edges down one by one,
 * and while putting the edge down, if it had already been
 * "visited" then there's something wrong. However, it isn't
 * as easy as just maintaining a visited array, because
 * edges may be provided in a random order.
 * While thinking of this implementation, I was reminded of
 * Kruskal's algorithm, and that's all this question is.
 * If while putting an edge down, you notice that the vertices
 * in question belong to the same component (implying they 
 * already have a path between them), then the edge being added
 * is the answer.
 */

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class UnionFind
{
public:
    UnionFind(int size)
    {
        this->id = vector<int>(size);
        this->sz = vector<int>(size, 1);
        for (int i=0; i<size; i++)
        {
            this->id[i] = i;
        }
    }
    
    int find(int p)
    {
        int root = p;
        while(this->id[root] != root)
        {
            root = id[root];
        }
        
        while (p != root)
        {
            int parent = id[p];
            id[p] = root;
            p = parent;
        }
        return root;
    }
    
    bool connected(int p, int q)
    {
        return find(p) == find(q);
    }
    
    void unify(int p, int q)
    {
        int root1 = find(p);
        int root2 = find(q);
        
        if (root1 != root2)
        {
            if (sz[root1] < sz[root2])
            {
                sz[root2] += sz[root1];
                id[root1] = root2;
            }
            else{
                sz[root1] += sz[root2];
                id[root2] = root1;
            }
        }
    }
private:
    vector<int> id;
    vector<int> sz;
};
    
vector<int> findRedundantConnection(vector<vector<int>>& edges){

    if (edges.empty())
        return vector<int>();

    UnionFind uf(edges.size() + 1);
    vector<int> res(2, 0);

    for (auto edge : edges)
    {
        if (uf.connected(edge[0], edge[1]))
        {
            res[0] = edge[0];
            res[1] = edge[1];
        }
        else
        {
            uf.unify(edge[0], edge[1]);
        }
    }

    return res;
}

int main()
{
}
