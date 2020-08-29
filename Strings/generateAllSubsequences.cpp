#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void generateAllSubsequences(string& s) {
    int totalSubsequences = (int) pow(2, s.length());
    for (int i=0; i<totalSubsequences; i++) {
        for (int j=0; j<s.length(); j++) {
            if (i & (1 << j)) {
                cout << s[j];
            }
        }
        cout << endl;
    }
}

int main() {
    string s("kartik");
    generateAllSubsequences(s);
}