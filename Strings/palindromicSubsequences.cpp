// For a given string, count the number of Palindromic Subsequences.
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int countPalindromicSubsequences(string& s) {

    vector<vector<int>> dp(s.length(), vector<int>(s.length(), 0));

    for (int i=0; i<s.length(); ++i) {
        dp[i][i] = 1;
    }

    for (int l=2; l <= s.length(); l++) {
        for (int i=0; i < s.length()-l+1; i++) {
            // j represents the right index in my string. i  represents the start.
            int j = i + l - 1;
            int ans = 1 + dp[i][j-1];
            // 1 + dp[i][j-1] + (matches).
            for (int k=i; k<j; k++) {
                if (s[k] == s[j]) {
                    ans += (1 + dp[k+1][j-1]);
                }
            }
            dp[i][j] = ans;
        }
    }

    return dp[0][s.length()-1];
}

int main() {
    string s;
    for (int i=0; i<10; ++i) {
        cin >> s;
        cout << countPalindromicSubsequences(s) << endl;
    }
}