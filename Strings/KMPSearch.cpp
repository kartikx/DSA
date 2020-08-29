#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> createLPSArray(string& pattern) {
    vector<int> lps(pattern.length());
    lps[0] = 0;
    int len=0, i=1;
    while (i < lps.size()) {
        if (pattern[i] == pattern[len]) {
            // len stores the length of the string matched so far,
            // I'm making use of Cached Information.
            lps[i] = len + 1;
            i++;
            len++;
        }

        // If the current Letter doesn't match, then I should alter cached info.
        else {
            if (len != 0)
                len = lps[len-1];
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

void KMPSearch(string& text, string& pattern) {
    int i=0; int j=0;

    vector<int> lps = createLPSArray(pattern);

    while (i < text.size() - pattern.size() + 1) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        }
        else {
            if (j == 0)
                i++;
            else 
                j = lps[j-1];
        }

        // Found the Pattern.
        if (j == pattern.size()) {
            cout << "Pattern found at: " << i - j << endl;            
            j = 0;
        }
    }
}

int main() {
    string text("kartik likes to eat brkaread and drink");
    string pattern("kar");
    KMPSearch(text, pattern);
}