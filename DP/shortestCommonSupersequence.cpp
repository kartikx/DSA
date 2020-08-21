// https://www.geeksforgeeks.org/shortest-common-supersequence/

/*
Logic:
First compute the longest common subsequence,
then iterate over the letters of the LCS.
For each letter, first add the letters appearing
before this letter in s1, same for s2, then add this letter,
and continue..
*/

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

string getShortestSuperSeq(string& s1, string& s2, string& lcs) {
    int start = 0;
    int ss1 = 0; int ss2 = 0;
    string shortestSuperSeq;
    while (start < lcs.length()) {
        while (s1[ss1] != lcs[start]) {
            shortestSuperSeq += s1[ss1];
            ss1++;
        }
        while (s2[ss2] != lcs[start]) {
            shortestSuperSeq += s2[ss2];
            ss2++;
        }
        shortestSuperSeq += lcs[start];
        start++; ss1++; ss2++;
    }

    while (ss1 < s1.length()) {
        shortestSuperSeq += s1[ss1];
        ss1++;
    }

    while (ss2 < s2.length()) {
        shortestSuperSeq += s2[ss2];
        ss2++;
    }

    return shortestSuperSeq;
}

string gSCSSUtil(string& s1, string& s2, int l, int r) {
    if (l == -1) {
        return s2.substr(0, r+1);
    }
    if (r == -1) {
        return s1.substr(0, l+1);
    }

    if (s1[l] == s2[r]) {
        string sub =  gSCSSUtil(s1, s2, l-1, r-1);
        return sub + s1[l];
    }

    string ss1 = gSCSSUtil(s1, s2, l-1, r);
    string ss2 = gSCSSUtil(s1, s2, l, r-1);

    if (ss1.length() < ss2.length()) {
        return ss1 + s1[l];
    }
    else {
        return ss2 + s2[r];
    }
}

/*
 * Another Approach Could be to form the SuperSequence in the
 * Recursive path itself. The main idea is that if the terminal
 * characters are the same, then that will be included in the
 * supersequence (and would be included only once).
 * If they're not equal, then I could include either of them
 * in the supersequence, and find the one whose inclusion
 * gives me the minimum length.
 */
string getShortestSuperSeqGfG(string& s1, string& s2) {
    return gSCSSUtil(s1, s2, s1.size()-1, s2.size()-1);
}

int main() {
    string s1, s2;
    for (int i=0; i<5; i++) {
        cin >> s1 >> s2;
        // string lcs = getLongestCommonSubseq(s1, s2);
        // cout << getShortestSuperSeq(s1, s2, lcs) << endl;
        cout << getShortestSuperSeqGfG(s1, s2) << endl;
    }
}