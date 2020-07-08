#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// TODO Predecessor path.

// assuming source is 0, 0
void bfs(char g[][7], int r, int c)
{
    queue<pair<int, int>> toVisit;
    toVisit.push({0, 0});

    int visited[r][c];
    memset(visited, 0, r*c*4);
    visited[0][0] = 1;

    // Each of this cell will store a number from 0 .. 34
    int pred[r][c];
    pred[0][0] = -1;

    int x1[] = {1, -1, 0, 0};
    int x2[] = {0, 0, -1, 1}; 

    bool reachable = false;
    pair<int, int> end;

    while(!toVisit.empty() && !reachable)
    {   
        pair<int, int> p = toVisit.front();
        toVisit.pop();
        int r1 = p.first;
        int c1 = p.second;
        for (int i=0;i<4;i++)
        {
            int rr = r1 + x1[i];
            int cc = c1 + x2[i];
            if (rr < 0 || cc < 0)   continue;
            if (rr >= r || cc >= c) continue;

            if (visited[rr][cc] == 0)
            {
                visited[rr][cc] = 1;
                if (g[rr][cc] == '.')
                {
                    toVisit.push(make_pair(rr, cc));
                    pred[rr][cc] = (r*r1 + c1);
                }
                if (g[rr][cc] == 'E')
                {
                    reachable = true;
                    end.first = rr;
                    end.second = cc;
                    pred[rr][cc] = (r*r1 + c1);
                    // cout << "End value is " << pred[rr][cc] ;
                }
            }
        }
    }

    if (reachable){
        // reconstruct the path.
        // while (pred[end.first][end.second] != -1)
        // {
        //     int val = pred[end.first][end.second];
        //     cout << g[end.first][end.second] << " ";
        //     end.first = val / r;
        //     end.second = val % c;
        // }
        for (int i=0;i<3;i++)
        {
            int val = pred[end.first][end.second];
            cout << val;
            cout << g[end.first][end.second] << " ";
            end.first = val / r;
            end.second = val % c;
            cout << end.first << " " << end.second;
        }
        cout << 'S' << endl;
    }
    return;
}

int main()
{
    char g[5][7] = {
        {'S', '.', '.', '#', '.', '.', '.',},
        {'.', '#', '.', '.', '.', '#', '.',},
        {'.', '#', '.', '.', '.', '.', '.',},
        {'.', '.', '#', '#', '.', '.', '.',},
        {'#', '.', '#', 'E', '.', '#', '.',}
    };

    bfs(g, 5, 7);
}