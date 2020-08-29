// Find the length of the Smallest Subarray whose Sum is Greater than the Given Number.

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void findSmallest(vector<int>& v, int k) {
    int l=0, r=0;
    int currSum = v[r];
    int minRange = INT_MAX;
    pair<int, int> ans;

    while (r < v.size()) {
        while (currSum <= k && r < v.size()) {
            r++;
            currSum += v[r];
        }

        // Optimize.s
        while (currSum > k) {
            currSum -= v[l];
            l++;
        }

        // At this point, l is at an element just ahead of the one which was the minimum range.
        // [l-1, r] r - l + 1 + 1
        if (r-l+2 < minRange) {
            minRange = r-l+2;
            ans = {l-1, r};
        }
    }

    cout << "Minimum Range is: " << minRange << " from: " << v[ans.first] << " to " << v[ans.second] << endl;
}

int main() {
    vector<int> v{1, 2, 3, 4, 5, 6, 7, 8};
    findSmallest(v, 20);
}