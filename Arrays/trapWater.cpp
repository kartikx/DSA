// https://practice.geeksforgeeks.org/problems/trapping-rain-water/0

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/**
 * Logic: View from the point of view of the Bars.
 * A Bar can store water on top of it, if it is bounded by bigger
 * bars to the left and right.
 * So find the biggest bars on the left and right, compute the minimum of
 * the two. The amound of water that you can store on the current bar,
 * will be the difference with the computed minimum.
 */

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> v(n, 0);
        for (int i=0; i<n; i++) {
            cin >> v[i];
        }

        vector<int> leftGreater(n, INT_MIN);
        vector<int> rightGreater(n, INT_MIN);

        int currMax = leftGreater[0];
        for (int i=1; i<n; i++) {
            currMax = max(currMax, v[i-1]);
            leftGreater[i] = currMax;
        }

        currMax = rightGreater.back();
        for (int i=n-2; i>=0; i--) {
            currMax = max(currMax, v[i+1]);
            rightGreater[i] = currMax;
        }
        
        int ans = 0;
        for (int i=0; i<n; i++) {
            int minHeight = min(leftGreater[i], rightGreater[i]);
            if (minHeight > v[i])
                ans += (minHeight - v[i]);
        }

        cout << ans << endl;
    }
}