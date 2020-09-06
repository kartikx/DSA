#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int convertRomanToNumber(string& s, unordered_map<char, int>& roman) {
    // Iterate Character by Character, add the current
    // char.'s equivalent to the value, unless it is followed
    // immediately by a large value. 
    int res = 0;
    for (int i=0; i<s.length(); ++i) {
        if (i == s.length()-1 || roman[s[i]] >= roman[s[i+1]]) {
            res += roman[s[i]];
        }

        else {
            // shouldn't try to decrement multiple times.
            res -= roman[s[i]];
        }
    }

    return res;
}

// 984. 950 + 34 CMLXXXIV
// DCCCXC

int main() {
    unordered_map<char, int> roman;
    roman.insert({'I', 1});
    roman.insert({'V', 5});
    roman.insert({'X', 10});
    roman.insert({'L', 50});
    roman.insert({'C', 100});
    roman.insert({'D', 500});
    roman.insert({'M', 1000});

    string s;

    for (int i=0; i<10; ++i) {
        cin >> s;
        cout << convertRomanToNumber(s, roman) << endl;
    }
}