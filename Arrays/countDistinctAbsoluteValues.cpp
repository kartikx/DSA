#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void countDistinctAbsoluteValues(vector<int>& v) {
    if (v.empty()) {
        return;
    }

    int l=0, r=v.size()-1;

    while (l < r) {
        if (abs(v[l]) == abs(v[r])) {
            cout << abs(v[r]) << " ";
            l++;
            r--;
        }

        else if (abs(v[l]) < abs(v[r])) {
            r--;
        }
        else {
            l++;
        }
    }
}

int main() {
    vector<int> v{-9, -7, -3, -1, 0, 3,  9, 10};
    countDistinctAbsoluteValues(v);
}