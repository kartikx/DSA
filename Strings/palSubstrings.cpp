// https://www.geeksforgeeks.org/find-palindromic-sub-strings-given-string-set-2/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string& s) {
    int i = 0; int j = s.length()-1;
    while (i < j) {
        if (s[i++] != s[j--]) {
            return false;
        }   
    }
    return true;
}

void findPalSubstringsNaive(string& s) {
    for (int i=0 ; i<s.length(); i++) {
        for (int j=i+1; j<=s.length(); j++) {
            string s_ = s.substr(i, j-i);
            if (isPalindrome(s_)) {
                cout << s_ << endl;
            }
        }
    }
}

void findPalSubstrings(string& s) {
    // Odd pals.
    // i denotes the center index.
    for (int i=0; i<s.length(); i++) {
        int l = i; int r = i;
        while (l >= 0 && r < s.length() && s[l] == s[r]) {
            cout << s.substr(l, r-l+1) << endl;
            l--; r++;
        }
    }
    // Even pals. i denotes the back center.
    for (int i=0; i<s.length()-1; i++) {
        int l=i; int r=i+1;
        while (l>=0 && r<s.length() && s[l]==s[r]) {
            cout << s.substr(l, r-l+1) << endl;
            l--; r++;
        }
    }
}

int main() {
    string s = "hhellolle";
    findPalSubstrings(s);
}