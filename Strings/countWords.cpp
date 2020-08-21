/*
Count the number of Words in a String,
using stringstream.
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void countWords(string& s) {
    stringstream ss(s);
    string word;

    while (getline(ss, word, ',')) {
        cout << word << endl;
    }
}

int main() {
    string s;
    getline(cin, s);
    countWords(s);
}