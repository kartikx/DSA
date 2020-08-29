#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool checkIfSubequence(string& s1, string& s2) {
    int i=0, j=0;

    while(j < s2.length()) {
        if (s1[i] == s2[j]) {
            i++; j++;
        }
        else {
            j++;
        }
    }

    if (i < s1.length()) {
        return false;
    }
    return true;
}

int main() {
    string s1, s2;
    for (int i=0; i<=10; i++) {
        cin >> s1 >> s2;
        cout << checkIfSubequence(s1, s2) << endl;
    }
}