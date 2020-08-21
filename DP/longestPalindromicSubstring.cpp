/*
https://www.geeksforgeeks.org/longest-palindrome-substring-set-1/
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string longestPalindromicSubstring(string& s) {
    vector<vector<int>> dp(s.length(), vector<int>(s.length(), 0));
    int maxVal = -1;
    pair<int, int> p{0, 0};
    for (int sl=2; sl <= s.length(); sl++) {
        for (int i=0; i<=s.length()-sl; i++){
            int j = i + sl - 1;
            if (s[i] == s[j]) {
                dp[i][j] = 2 + dp[i+1][j-1];
            }
            if (dp[i][j] > maxVal) {
                maxVal = dp[i][j];
                p = {i, j};
            }
        }
    }
    string s_("");
    for (int i=p.first; i<=p.second; i++) {
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