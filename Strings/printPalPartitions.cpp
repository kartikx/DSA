// https://www.geeksforgeeks.org/given-a-string-print-all-possible-palindromic-partition/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isPal(string& s, int l, int r) {
    while (l < r) {
        if (s[l++] != s[r--]) {
            return false;
        }
    }
    return true;
}

vector<vector<string>> printPalindromicPartitionsUtil(string& s, int l, int r) {
    // Find pals rooted at i=0;
    vector<vector<string>> v;
    for (int i=l; i<r; i++) {
        v.push_back({s.substr(0, i+1)});
        if (isPal(s, 0, i)) {
            v.back().push_back(printPalindromicPartitionsUtil(s, l+1, r));
        }
    }
}

void printPalindromicPartitions(string& s) {
    printPalindromicPartitionsUtil(s, 0, s.length() -1);
}

int main() {
    string s = "nitin";
    printPalindromicPartitions(s);
}