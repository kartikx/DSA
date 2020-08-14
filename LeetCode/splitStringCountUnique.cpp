/*
Split a string into two substrings, so that
the count of unique characters in the two are equal.
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int splitString(string& s)
{
    if (s.empty())
        return 0;
    
    unordered_map<char, int> M1;
    unordered_map<char, int> M2;

    for (auto ch: s) {
        M2[ch]++;
    }
    int ans = 0;
    // M1 includes all letters from [0, i].
    for (int i=0; i < s.size(); i++)
    {
        if(--M2[s[i]] == 0) {
            M2.erase(s[i]);
        }
        M1[s[i]]++;

        if (M1.size() == M2.size())
            ans++;
    }

    return ans;
}

int main() {
    string s = "ababa";
    cout << splitString(s);
}