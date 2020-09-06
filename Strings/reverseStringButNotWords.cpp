// Given a string, reverse the order in which words appear, but not the words themselves.

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void reverseString(string s) {
    stringstream ss(s);
        string intermediate;
        vector<string> strings;

        while (getline(ss, intermediate, '.')) {
            strings.push_back(intermediate);
        }

        reverse(strings.begin(), strings.end());

        for (int i=0; i<strings.size()-1; i++) {
            cout << strings[i] << ".";
        }
        cout << strings.back() << endl;
}

/**
 * Algorithm
 * First reverse each word.
 * Then reverse each string.
 */

void reverseWord(string& s, int l, int r) {
    while (l < r) {
        swap(s[l], s[r]);
        l++;
        r--;
    }
}

void reverseStringOpt(string& s) {
    int i=0, j=0;

    while (j<s.length()) {
        if (s[j] == '.') {
            reverseWord(s, i, j-1);
            j++;
            i = j;
        }
        j++;
    }
    reverseWord(s, i, j-1);
    reverse(s.begin(), s.end());
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin>>t;
    while (t--) {
        string s;
        cin >> s;

        reverseStringOpt(s);
        cout << s << endl;
    }
}