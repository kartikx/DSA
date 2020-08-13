#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* My solution based on Maps.
vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals)
{
    map<int, int> M;
    for (auto x : intervals) {
        auto it = M.find(x[0]);
        if (it == M.end() || x[1] > it->second)
            M[x[0]] = x[1];
    }

    for (auto it1 = M.begin(); it1 != M.end(); ++it1)
    {
        auto it2 = it1;
        it2++;
        while(it2 != M.end() && it1->second >= it2->first) {
            if (it1->second < it2->second) {
                it1->second = it2->second;
            }
            // Important.
            M.erase(it2++);
        }
    }

    vector<vector<int>> output;
    for (auto x : M) {
        vector<int> pair;
        pair.push_back(x.first);
        pair.push_back(x.second);
        output.push_back(pair);
    }
    return output;
}
*/

// Checks whether two given vectors (of size 2 each) intersect.
bool isIntersection(vector<int> v1, vector<int> v2)
{
    // cout << v1.size() << " " << v2.size() << endl;
    // assert(v1.size() == v2.size() == 2);

    if ((v1[0] <= v2[0] && v1[1] >= v2[0]) ||  (v1[0] >= v2[0] && v1[0] <= v2[1]))
        return true;
    return false;
}

void mergeUtil(map<vector<int>, vector<vector<int>>>& graph, vector<int> u,
               int& minStart, int& maxEnd, map<vector<int>, int>& visited)
{
    minStart = min(minStart, u[0]);
    maxEnd = max(maxEnd, u[1]);

    for (auto x : graph[u]) {
        if (visited[x] == 0) {
            visited[x] = 1;
            mergeUtil(graph, x, minStart, maxEnd, visited);
        }
    }
}

vector<vector<int>> merge(vector<vector<int>>& intervals)
{
    // First contruct a Graph.
    map<vector<int>, vector<vector<int>>> graph;

    for (int i=0; i<intervals.size(); i++){
        for (int j=i+1; j<intervals.size(); j++){
            if (isIntersection(intervals[i], intervals[j]))
            {
                graph[intervals[i]].push_back(intervals[j]);
                graph[intervals[j]].push_back(intervals[i]);
            }
        }
    }
    vector<vector<int>> output;
    map<vector<int>, int> visited;
    for (int i=0; i<intervals.size(); ++i)
    {
        auto curr = intervals[i];
        if (visited[curr] == 0){
            visited[curr] = 1;
            int minStart=INT_MAX, maxEnd = INT_MIN;
            mergeUtil(graph, curr, minStart, maxEnd, visited);
            vector<int> res = {minStart, maxEnd};
            output.push_back(res);
        }
    }
}

int main() {
    vector<vector<int>> V = {{1, 9}, {1,3}, {2,6}, {8,10}, {15,18}};
    sort(V.begin(), V.end());
    for (auto v : V){
        for (auto x : v) {
            cout << x << " ";
        }
        cout << endl;
    }
}