#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int getMinSwaps(vector<int>& v) {
    vector<pair<int, int>> vals;
    for (int i=0; i<v.size(); i++) {
        vals.push_back({v[i], i});
    }

    sort(vals.begin(), vals.end());
    int ans=0, cycleCount=0; 
    vector<bool> visited(vals.size(), false);

    for (int i=0; i<vals.size(); i++) {
        cycleCount=0;
        int j = i;
        while (j != vals[j].second && !visited[j]) {
            cycleCount++;
            visited[j] = true;
            j = vals[j].second;
        }
        ans += max(cycleCount-1, 0);
    }

    return ans;
}

int main() {
    // 1, 2, 3, 5, 7
    vector<int> v{7, 5, 1, 2, 3};
    cout << getMinSwaps(v) << endl;
}