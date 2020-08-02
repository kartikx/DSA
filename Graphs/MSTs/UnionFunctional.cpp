#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int find(int u, vector<int>& ids)
{
    int root = u;
    while(root != ids[root])
    {
        root = ids[root];
    }

    // compress path.

    while (u != root) {
        int next = ids[u];
        ids[u] = root;
        u = next;
    }

    return root;
}

void getunion(int u, int v, vector<int>& ids, vector<int>& sizes)
{
    int root1 = find(u, ids);
    int root2 = find(v, ids);

    if (root1 != root2) {
        if (sizes[root1] >= sizes[root2]) {
            ids[root2] = root1;
            sizes[root1] += sizes[root2];
        }
        else {
            ids[root1] = root2;
            sizes[root2] += sizes[root1];
        }
    }
}

void printVec(vector<int>& ids)
{
    for (auto x : ids) {
        cout << x << " " ;
    }
    cout << endl;
}

int main()
{
    vector<int> ids(6, 1);
    vector<int> sizes(6, 1);
    for (int i=0 ; i<6 ; i++) {
        ids[i] = i;
    }
    getunion(0, 2, ids, sizes);
    getunion(1, 3, ids, sizes);
    getunion(3, 4, ids, sizes);
    getunion(5, 1, ids, sizes);
    printVec(ids); 
}