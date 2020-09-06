// Given the order of insertion of Keys of 2 BSTS.
// Check whether they represent the same structure,
// without actually constructing the Trees.
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool checkIdentical(vector<int>& v1, vector<int>& v2) {
    if (v1[0] != v2[0]) {
        return false;
    }

    // L1 stores smaller elements, L2 bigger elements than v1[0].
    list<int> l1, l2;
    
    for (int i=1; i<v1.size(); i++) {
        if (v1[i] > v1.front()) {
            l1.push_back(v1[i]);
        }
        else {
            l2.push_back(v1[i]);
        }
    }
    auto it1 = l1.begin(), it2 = l2.begin();
    for (int i=1; i<v2.size(); i++) {
        if (it1 != l1.end() && v2[i] == *it1) {
            it1++;
        }

        else if (it2 != l2.end() && v2[i] == *it2) {
            it2++;
        }

        else {
            return false;
        }
    }

    return true;
}

int main() {
    // vector<int> v1{8, 3, 6, 1, 4, 7, 10, 14, 13};
    // vector<int> v2{8, 10, 14, 3, 6, 4, 1, 7, 13};
    
    // cout << checkIdentical(v1, v2) << endl;
}