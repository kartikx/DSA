#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/**
 * kartik
 * artikar   atartik
 * 
 * index=0.
 * if i != j , s1, s2, i, j+1.
 * 
 * if i == j. int ans = 1 + s1, s2, i+1, j+1. int ans2 = s1, s2, i, j+1.
 * 
 * set up limit for j.
 * 
 * In the main (non util), I should have a for loop which iterates over all indexes, and picks them
 * as the starting point, and stores the max value.
 *
 */

int lCSUtil(string& s1, string& s2, int l, int r) {
    if (l >= s1.length() || r >= s2.length()) {
        return 0;
    }

    if (s1[l] != s2[r]) {
        return lCSUtil(s1, s2, l+1, r+1);
    }

    return max(1+lCSUtil(s1, s2, l+1, r+1), lCSUtil(s1, s2, l, r+1));
}

void longestCommonSubstring(string& s1, string& s2) {
    if (s1.empty() || s2.empty()) {
        cout << "Empty String" << endl ;
        return ;   
    }
    int ans = INT_MIN;
    for (int i=0; i<s1.length(); i++) {
        ans = max(ans, lCSUtil(s1, s2, i, 0));
    }

    cout << "LCS is: " << ans << endl;
}

/**
 * Start from the right of both vectors.
 * If match, then you can either match those two
 * or not.
 * If not match, then decrement i.
 */

int lCSDP(string& s1, string& s2) {
    
    vector<vector<int>> dp(s2.length()+1, vector<int>(s1.length()+1));

    // i counts from right of s2 to start.
    // j counts from right of s1 to start.
    for (int i=0; i<=s2.length(); i++) {
        for (int j=0; j<=s1.length(); j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
                continue;
            }
            if (s2[i-1] == s1[j-1]) {
                dp[i][j] =  max(1 + dp[i-1][j-1], dp[i][j-1]);
            }
            else {
                dp[i][j] = dp[i][j-1];
            }
        }
    }

    for (int i=0; i<=s2.length(); i++) {
        for (int j=0; j<=s1.length(); j++) {
            cout << dp[i][j] << " ";
         }
         cout << endl;
    }    
}

/**
 * ! BEST APPROACH
 * The problem with the above approach is that I didn't consider
 * any systematic approach.
 * 1. It's beneficial in String questions to start from the right.
 * 2. The LCS will end at some index (in both strings), so for each
 * pair of index, find the Longest Common Suffix which ends at that index.
 * If the last characters match, then LCS = 1 + (i-1, j-1).
 * If they don't then LCSuffix is simply zero.
 */

int lcSDPGfG(string& s1, string& s2) {
    vector<vector<int>> dp(s1.length()+1, (vector<int>(s2.length()+1, 0)));
    int ans = INT_MAX;
    for (int i=0; i<=s1.length(); ++i) {
        for (int j=0; j<=s2.length(); ++j) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
                continue;
            }

            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
                ans = max(dp[i][j], ans);
            }
            else {
                dp[i][j] = 0;
            }
        }
    }
    return ans;
}

int main() {
    string s1("kartik");
    string s2("artikar");

    cout << lCSDP(s1, s2) << endl;
}