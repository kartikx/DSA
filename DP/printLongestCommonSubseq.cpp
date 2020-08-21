#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string getSubseqUtil(string& s1, string& s2, int l, int r, unordered_map<int, string>& dp)
{
    if (l == -1 || r == -1)
    {
        return "";
    }

    if (s1[l] == s2[r]) {
        string subCommon = getSubseqUtil(s1, s2, l-1, r-1, dp);
        return subCommon + s1[l];
    }

    // calculate the 1d index for (l, r);
    int currIndex = (l+1)*(s2.length())+(r+1);

    if (dp.count(currIndex) > 0) 
    {
        return dp[currIndex];
    }

    string sub1 = getSubseqUtil(s1, s2, l-1, r, dp);
    string sub2 = getSubseqUtil(s1, s2, l, r-1, dp);
    string sub = sub1.length() > sub2.length() ? sub1 : sub2;

    dp[currIndex] = sub;
    return sub;
}

string getLongestCommonSubseq(string& s1, string& s2)
{
    unordered_map<int, string> dp;
    return (getSubseqUtil(s1, s2, s1.length()-1, s2.length()-1, dp));
}

int main() {
    string s1, s2;
    for (int i=0; i<5; i++) {
        cin >> s1 >> s2;
        string lcs = getLongestCommonSubseq(s1, s2);
        cout << lcs << endl;
    }
}