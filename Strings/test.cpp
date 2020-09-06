#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int fooUtil(string& s1, string& s2, int i, int j) {
    // base case.
    if (j == 0) {
        return 1;
    }

    if (i < 0) {
        return 0;
    }

    if (s1[i] == s2[j]) {
        return fooUtil(s1, s2, i-1, j-1) + fooUtil(s1, s2, i-1, j);
    }

    return fooUtil(s1, s2, i-1, j);
}

int fooDP(string& s1, string& s2) {
    vector<vector<int>> dp(s1.length()+1, vector<int>(s2.length()+1));

    for (int i=0; i<=s2.length(); i++) {
        dp[0][i] = 0;
    }

    for (int i=0; i<=s1.length(); i++) {
        dp[i][0] = 1;
    }

    for (int i=1; i<=s1.length(); ++i) {
        for (int j=1; j<=s2.length(); ++j) {
            if (s1[i] == s2[j]) {
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp.back().back();
}

int foo(string& s1, string& s2) {
    return fooUtil(s1, s2, s1.length()-1, s2.length()-1);
}

int barUtil(string& s1, string& s2, string& s, int i1, int i2, int i) {
    
    int ans = 0;
    if (s1[i1] == s[i]) {
        ans += barUtil(s1, s2, s, i1-1, i2, i-1) + barUtil(s1, s2, s, i1-1, i2, i);
    }

    else {
        ans += barUtil(s1, s2, s, i1-1, i2, i);
    }
}

int bar(string& s1, string& s2, string& s) {
    
}

int main() {
    string s1("ababc");
    string s2("abc");

    cout << fooDP(s1, s2) << endl;
}