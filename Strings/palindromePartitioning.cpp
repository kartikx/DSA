/*
https://www.geeksforgeeks.org/palindrome-partitioning-dp-17/
Given a string, partition it such that each partition is a palindrome.
Return the minimum number of Partitions required.
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string& s, int l, int r) {
    int i=l; int j=r;
    while (i < j) {
        if (s[i++] != s[j--])
            return false;
    }
    return true;
}

int partitionPalindromeUtil(string& s, int l, int r) {
    if (l > r) {
        return -1;
    }

    int ans = INT_MAX;
    for (int i=l; i<=r; i++) {
        if (isPalindrome(s, l, i)) {
            ans = min(ans, 1 + partitionPalindromeUtil(s, i+1, r));
        }
    }
    return ans;
}
/*
My Approach
Basically traverse the string from L to R,
if you encounter a palindrome ([l,i]) then you have two options,
either keep it (that is make a partition at this point), or not.
If you don't keep it, keep iterating along in the same case,
else make a recursive call to [i+1, r].
*/
int partitionPalindromeIntuitive(string& s) {
    int ans =  partitionPalindromeUtil(s, 0, s.length()-1);
    return ans == INT_MAX ? -1 : ans;
}

/*
Bottom Up DP approach.
For a string [l..r], I could traverse across it, and make
all possible partitions. I have to minimize
f(left) + f(right) + 1. I'll build answers up from length=1
upto length=N.
*/
int partitionPalindromeGfG(string& s) {

    vector<vector<int>> dp(s.length(), vector<int>(s.length(), 0));
    // This stores whether i,j is a palindrome. To avoid recomputation.
    vector<vector<int>> pal(s.length(), vector<int>(s.length(), 0));

    for (int i=0; i<s.length(); i++) {
        pal[i][i] = 1;
    }

    for (int l=2; l<=s.length(); l++) {
        for (int i=0; i<s.length()-l+1; i++) {
            int j = i + l - 1;
            if (l == 2) {
                if (s[i] == s[j]) {
                    pal[i][j] = 1;
                }
            }
            else {
                pal[i][j] = (s[i] == s[j]) & (pal[i+1][j-1]);
            }

            if (pal[i][j]) {
                dp[i][j] = 0;
            }
            else {
                dp[i][j] = INT_MAX;
                for (int k=i; k <= j-1; k++) {
                    dp[i][j] = min(dp[i][j], 1+dp[i][k]+dp[k+1][j]);
                }
            }
        }
    }
    return dp[0][s.length()-1];
}

// More optimized O(N^2) approach.
int partitionPalindromeOptimized(string& s) {

    vector<int> cut(s.length(), 0);
    vector<vector<bool>> pal(s.length(), vector<bool>(s.length(), false));

    // Iterate over possible ending points of substrings.
    for (int i=0; i<s.length(); ++i ) {
        int minCut = INT_MAX;
        for (int j=0; j<=i; j++) {
            if (s[j] == s[i] && (i-j > 2 || pal[j+1][i-1])) {
                pal[j][i] = true;
                minCut = min(minCut, j == 0 ? 0 : cut[j-1] + 1);
            }
        }
        cut[i] = minCut;
    }

    return cut.back();
}

int main() {
    string s;
    for (int i=0; i<10; i++) {
        cin >> s;
        cout << partitionPalindromeGfG(s);
    }
}