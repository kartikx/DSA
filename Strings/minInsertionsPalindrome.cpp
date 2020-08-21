/*
Find the minimum number of Insertions required
to turn the given string into a Palindrome.
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
Similar DP recursive technique where we have a 
diagonal matrix (with lower half unused).
I'm gonna try to optimize it, by using a staggered
dp matrix.
*/
int minInsertions(string& s)
{
    vector<vector<int>> dp(s.length());

    for (int i=0; i<dp.size(); i++) {
        dp[i] = vector<int>(s.length()-i);
    }

    // Column wise traversals in this matrix,
    // correspond to diagonal traversals in orig.
    for (int j=1; j<s.length(); j++) {
        for (int i=0; i<s.length()-j; i++) {
            if (s[i] == s[j+i]) {
                dp[i][j] = dp[i+1][j-i-1];
            }
            else {
                dp[i][j] = 1 + min(dp[i+1][j-1], dp[i][j-1]);
            }
        }
    }
}

int main() {

}