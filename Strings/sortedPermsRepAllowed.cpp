/*
Given an input string, print all permutations in sorted order,
if repetition of characters is allowed.
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void sortedPermsUtil(string& s, int index, string& currString, vector<string>& ans) {
    if (index == s.length()) {
        ans.push_back(currString);
        return;
    }

    for (int i=0; i<s.length(); i++) {
        string s_(currString);
        s_.push_back(s[i]);
        sortedPermsUtil(s, index+1, s_, ans);
    }
}

void sortedPerms(string& s) {
    string s_(s);
    sort(s_.begin(), s_.end());
    string currString("");
    vector<string> ans;
    sortedPermsUtil(s_, 0, currString, ans); 

    for (auto x : ans)
        cout << x << endl;
}

int main() {
    string s = "cab";
    sortedPerms(s);
}