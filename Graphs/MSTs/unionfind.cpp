#include <iostream>
#include <bits/stdc++.h>

using namespace std;

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

int main()
{
    UnionFind uf(5);
    unordered_map<char, int> M;
    M['A'] = 2;
    M['B'] = 3;
    M['C'] = 0;
    M['D'] = 4;
    M['E'] = 1;

    uf.unify(2, 1);
    uf.unify(3, 2);
    uf.unify(4, 0);
    uf.unify(4, 3);

    vector<int> V = uf.getId();
    cout << "Before compression" ;
    for (auto x : V)
        cout << x << " ";
    cout << endl;

    uf.find(0);
    
    cout << "Before compression" ;
    V = uf.getId();
    for (auto x : V)
        cout << x << " ";
    cout << endl;
}