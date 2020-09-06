#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void removeAdjDuplicates(string& s) {
    // Stores last filled character.
    int k=0;

    int i=1;
    while (i < s.length()) {
        if (s[i] != s[k]) {
            s[++k] = s[i++];
        }

        else {
            while (s[i] == s[k]) {
                i++;
            }
            k--;
        }
    }

    s.erase(s.begin()+k+1, s.end());
}

int main() {
    int t; cin >> t;
    while (t--) {
        string s;
        cin >> s;

        removeAdjDuplicates(s);
        cout << s << endl;
    }
}