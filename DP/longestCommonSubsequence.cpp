// https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/**
 * The first thing to take note of is the Recursion.
 * First, note that you only have to find the maximum length,
 * so it's relatively easier.
 * Consider the last letter of each.
 * If they are equal then they should be included in the final
 * answer (it doesn't hurt to include it). So answer will be
 * 1 + (ans if you remove these two from the strings).
 * If they are not equal, answer is the maximum of the two cases
 * in which you include the letter. You can't include both of them,
 * since the substrings won't be equal in that case.
 * 
 * Now optimize using DP, try unfolding the recursion tree for a case,
 * you'll notice that you end up resolving a lot.
 */

int findLongestCommonSubseq(string& s1, string& s2)
{
    int m = s1.size();
    int n = s2.size();

    // dp[i][j] contains the answer for first i characters of s1,
    // compared with first j characters of s2.
    int dp[m+1][n+1];

    memset(dp, 0, sizeof(int)*(m+1)*(n+1));

    for (int i=0; i <= m; i++) {
        for (int j=0; j<=n; j++) {
            if (i==0 || j==0)
                dp[i][j] = 0;
            
            else if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }

            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[m][n];
}

int main() {
    string s1("kartik");
    string s2("ktaik");
    cout << findLongestCommonSubseq(s1, s2);
}