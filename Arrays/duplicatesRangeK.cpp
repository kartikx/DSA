// Find whether a duplicate exists in a given range.
// https://www.techiedelight.com/find-duplicates-within-given-range-array/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool findDuplicates(vector<int>& v, int k) {
    k = min((int)v.size(), k);

    unordered_set<int> s;
    for (int i=0; i<k; i++) {
        if (s.count(v[i]) > 0) {
            cout << "Duplicate is: " << v[i] << endl;
            return true;
        }
        s.insert(v[i]);
    }

    int slow = 0, fast = k;
    while (fast < v.size()) {
        s.erase(v[slow]);
        slow++;
        if (s.count(v[fast]) > 0) {
            cout << "Duplicate is: " << v[fast] << endl;
            return true;
        }
        s.insert(v[fast]);
        fast++;
    }

    return false;
}

int main() {
    vector<int> v{1, 2, 3, 1, 3, 4};
    cout << findDuplicates(v, 10) << endl;
}