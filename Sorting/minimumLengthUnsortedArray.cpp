/**
 * Find the Minimum length Unsorted Subarray, sorting which makes the complete array sorted
 * https://www.geeksforgeeks.org/minimum-length-unsorted-subarray-sorting-which-makes-the-complete-array-sorted/
 */

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void findMinUnsorted(vector<int>& v) {
    int l=-1, r=-1;

    for (int i=0; i<v.size()-1; i++) {
        if (v[i] > v[i+1]) {
            l = i;
            break;
        }
    }

    for (int i=v.size()-1; i > 0; --i) {
        if (v[i] < v[i-1]) {
            r = i;
            break;
        }
    }
    int newL=-1, newR=-1;
    for (int i=0; i<=l; i++) {
        if (v[i] >= v[r]) {
            newL = i;
            break;
        }
    }

    for (int i=v.size()-1; i>=r; i--) {
        if (v[i] <= v[l]) {
            newR = i;
            break;
        }
    }

    cout << "Sort from: " << newL <<  " To: " << newR << endl;
}

int main() {
    vector<int> v{0, 1, 15, 25, 6, 7, 30, 40, 50};
    findMinUnsorted(v);
}