#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/**
 * Fuck up number 1 : can't return char, resolved by ""+s[l] something wrong.
 * Fuck up number 2 : reversed sub1 and sub2.
 */
string longestPalSubseqUtil(string& s, int l, int r) {
    if (l > r)
        return "";

    if (l == r)
        return s.substr(l, 1);

    if (s[l] == s[r]) {
        string sub = longestPalSubseqUtil(s, l+1, r-1);
        return s[l] + sub + s[r];
    }

    string sub1 = longestPalSubseqUtil(s, l+1, r); // keeping R
    string sub2 = longestPalSubseqUtil(s, l, r-1); // keeping L

    return sub2.length() > sub1.length() ? sub2 : sub1;
}

string longestPalSubseq(string& s) {
    return longestPalSubseqUtil(s, 0, s.length()-1);
}

int longestPalSubseqGfG(string& s) {
    vector<vector<int>> dp(s.length(), vector<int>(s.length(), 0));

    // Base Case.
    for (int i=0; i<s.length(); ++i) {
        dp[i][i] = 1;
    }

    // To fill an (i, j). You need the immediate value to the left
    // and to the bototm. Hence you can't fill in order from 1..n, 1..n.
    // Instead first stick to the main diagonal, and build the smaller diagonal
    // just above it, and so on..
    // This is equivalent to first building all subsequences of length 2 (pairs
    // such as (0,1) (1,2) .. and then of length 3 and so on..
    // I represents left, and J represents right.

    int n = s.length();
    for (int sl=2; sl<=n; sl++) {
        for (int i=0; i<=n-sl; i++) {
            int j = i+sl-1;
            if (s[i] == s[j]) {
                dp[i][j] = 2 + dp[i+1][j-1];
            }
            else {
                dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }
    }
    return dp[0].back();
}

int main() {
    string s;
    for (int i=0; i<10; i++) {
        cin >> s;
        cout << longestPalSubseqGfG(s) << endl;
    }
}