#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool comparePairs(pair<int, pair<int, int>> p1, pair<int, pair<int, int>> p2) {
    if (p1.second.first == p2.second.first) {
        return p1.second.second < p2.second.second;
    }

    return p1.second.first > p2.second.first;
}
// Space complexity: O(3*D + N)
void sortByFrequency(vector<int>& v) {
    // val -> (freq, first_index).
    unordered_map<int, pair<int, int>> m;

    for (int i=0; i<v.size(); i++) {
        if (m.count(v[i]) > 0) {
            m[v[i]].first++;
        }
        else {
            m[v[i]] = {1, i};
        }
    }

    vector<pair<int, pair<int, int>>> elems(m.begin(), m.end());
    sort(elems.begin(), elems.end(), comparePairs);
    int c=0; // counter for map.
    for (int i=0; i<v.size();c++) {
        while (elems[c].second.first != 0) {
            v[i++] = elems[c].first;
            elems[c].second.first--;
        }
    }
}

int main() {
    vector<int> v{2, 5, 2, 8, 5, 6, 8, 8};
    sortByFrequency(v);

    for (auto x : v) {
        cout << x << " ";
    }
    cout << endl;
}