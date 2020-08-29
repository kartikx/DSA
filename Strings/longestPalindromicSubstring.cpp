/*
https://www.geeksforgeeks.org/longest-palindrome-substring-set-1/
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string longestPalindromicSubstring(string& s) {
    // Stores whether the substring(0..i) is a Palindrome.
    vector<vector<int>> dp(s.length(), vector<int>(s.length(), 0));
    
    for (int i=0; i<s.length(); i++) {
        dp[i][i] = 1;
    }
    int maxVal = 1;
    int start = 0;

    for (int sl=2; sl <= s.length(); sl++) {
        for (int i=0; i<=s.length() - sl; i++){
            int j = i + sl - 1;
            if (s[i] == s[j] && (sl == 2 || dp[i+1][j-1])) {
                dp[i][j] = 1;
                if (sl > maxVal) {
                    maxVal = sl;
                    start = i;
                }
            }
        }
    }

    string s_("");
    for (int i=start; i <= start + maxVal - 1; i++) {
        s_ += s[i];
    }
    return s_;
}

int main() {
    string s;
    for (int i=0; i<5; i++){
        cin >> s;
        cout << longestPalindromicSubstring(s) << endl;
    }
}