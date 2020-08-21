/*
https://www.geeksforgeeks.org/ways-to-write-n-as-sum-of-two-or-more-positive-integers/
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int numberOfParts(int n) {

    vector<int> dp(n+1, 0);
    dp[0] = 1;
    for (int i=1; i<n; ++i) {
        for (int j=i; j<=n; ++j) {
            dp[j] += dp[j-i];
        }
    }
    return dp[n];
}

int main() {
    cout << numberOfParts(1) << endl;
}