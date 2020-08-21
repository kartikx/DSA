#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isRotatedPalindrome(string& s) {
    if (s.length() % 2 == 1) {
        // i is the center. This is for odd length strings.
        for (int i=0; i<s.length(); i++) {
            int d;
            for (d=1; d<=s.length()/2; d++) {
                int lower = i-d;
                if (lower < 0) {
                    lower = s.length() + lower;
                }
                int upper = i+d;
                if (upper >= s.length()) {
                    upper =upper - s.length();
                }

                if (s[lower] != s[upper]) {
                    break;
                }
            }
            if (d == s.length()/2 + 1) {
                return true;
            }
        }
        return false;
    }
    else {
        // For even length strings. i denotes the first center.
        for (int i=0; i<s.length(); i++) {
            int d;
            for (d=0; d<s.length()/2; d++) {
                int lower = i-d;
                int upper = i+1+d;

                if (lower < 0) {
                    lower = s.length() + lower;
                }

                if (upper >= s.length()) {
                    upper = upper - s.length();
                }

                if (s[lower] != s[upper]) {
                    break;
                }
            }
            if (d == s.length()/2) {
                return true;
            }
        }
        return false;
    }
}

int main() {
    // Palindrome of anutforajaroftuna
    string s("aroftunaanutforaj");
    cout << isRotatedPalindrome(s);
}