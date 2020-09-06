#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Finds the element just before and just after the given element in Map.
// Assume distinct keys.
void getElements(map<int, int>& m, int key) {
    if (m.empty()) {
        cout << "Nothing exists" << endl;
        return;
    }

    auto it = m.upper_bound(key);

    if (it == m.end()) {
        cout << "This is larger than all keys" << endl;
    }

    else {
        cout << "Larger Value: " << it->first << endl;
    }

    auto prevIter = m.lower_bound(key);
    prevIter = prev(prevIter);
    if (prevIter->first < key) {
        cout << "Smaller" << prevIter->first << endl;
    }
    else {
        cout << "This is smaller than or equal to all keys" << endl;
    }
}


int main() {
    map<int, int> M;
    M[1] = 3;
    M[2] = 6;
    M[8] = 10;
    M[15] = 18;

    mergeIntervals(M);

    for (auto x : M) {
        cout << x.first << " " << x.second << endl;
    }
}