#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void foo(vector<vector<int>> &dependencies, int n)
{
    vector<vector<int>> g(n, vector<int>());

    for (auto v : dependencies)
    {
        g[v[0] - 1].push_back(v[1] - 1);
    }

    queue<int> q;
    vector<int> indeg(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (auto x : g[i])
            indeg[x]++;
    }

    for (int i = 0; i < n; i++)
    {
        if (indeg[i] == 0)
        {
            q.push(i);
        }
    }

    int ans = 0;
    while (!q.empty())
    {
        int q_size = q.size();
        ans++;
        for (int i = 0; i < q_size; ++i)
        {
            int curr = q.front();
            q.pop();
            cout << curr << " ";
            for (auto x : g[curr])
            {
                indeg[x]--;
                if (indeg[x] == 0)
                {
                    q.push(x);
                }
            }
        }
        cout << endl;
    }

    cout << "Ans: " << ans << endl;
}

int main()
{
    vector<vector<int>> pre = {{1, 2}, {1, 3},  {7, 5},   {7, 6},  {4, 8},
                               {8, 9}, {9, 10}, {10, 11}, {11, 12}};
    foo(pre, 12);
}
