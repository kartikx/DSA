// https://www.geeksforgeeks.org/word-break-problem-dp-32/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
 * This was a Top Down approach, and I was storing pairs
 * of (l, r) indices, to denote whether the pair can be
 * segmented into words of the dictionary. A more Space Optimized
 * Solution, and do this in lesser space, see solution below.
 */
bool existsWord(string& s, int l, int r, unordered_set<string>& words, vector<vector<int>>& dp)
{
    // empty string.
    if (l > r)
        return true;

    if (dp[l][r] != -1)
    {
        cout << "Cached" << endl;
        return dp[l][r];
    }
    string currString("");
    for (int i=l; i<=r; i++) {
        currString += s[i];
        // cout << currString << endl;
        if (words.count(currString) > 0 && existsWord(s, i+1, r, words, dp)) {
            dp[l][r] = 1;
            return true;
        }
    }
    dp[l][r] = 0;
    return false;
} 

bool existsSentence(string& s, unordered_set<string>& words) {
    vector<vector<int>> dp(s.length(), vector<int>(s.length(), -1));
    return existsWord(s, 0, s.length()-1, words, dp);
}

/**
 * Bottom Up DP Solution, using O(N) space.
 */
bool wordBreak(string& s, unordered_set<string>& words) {

    // dp[i] = true, if substr(0..i-1) can be segmented.
    vector<int> dp(words.size()+1, 0);

    for (int i=1; i<=words.size(); i++) {
        if (dp[i] == 0 && words.count(s.subtr(0, i)) > 0)
            dp[i] = 1;

        if (dp[i] == 1) {
            if (i == words.size())
                return true;
            for (int j=i+1; j <= words.size(); j++) {
                if (dp[j] == 0 && words.count(s.substr(i, j-i)) > 0)
                    dp[j] = 1;
                
                if (j == words.size() && dp[j] == 1)
                    return true;
            }
        }
    }

    return false;
}

int main() {
    unordered_set<string> words{"i", "like", "ilike", "sam", "sung"};
    string s;
    for (int i=0; i<5; i++) {
        cin >> s;
        cout << existsSentence(s, words) << endl;
    }
}