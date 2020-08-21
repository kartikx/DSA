#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void search(string& text, string& pattern) {

    int q = 101; // serves as a primary number for module calculation, as hash value could be > MAX_INT.
    int d = 256; // char limit.
    long long int window_hash=0;
    long long int pattern_hash=0;
    long long int h = (int)pow(d, pattern.size()-1)%q;
    for (int i=0; i<pattern.size(); i++) {
        window_hash = (window_hash*d + (text[i]))%q;
        pattern_hash = (pattern_hash*d + (pattern[i]))%q;
    }

    // cout << "WindowHash: " << window_hash << " " << "Pattern hash: " << pattern_hash << endl;
    
    for (int i=0; i<text.size()-pattern.size()+1; i++) {
        if (window_hash == pattern_hash) {
            cout << "Hash matched" << endl;
            int j;
            for (j=0; j<pattern.size(); j++) {
                if (pattern[j] != text[i+j]) {
                    break;
                }
            }
            if (j == pattern.size()) {
                cout << "Pattern found at index: " << i << endl;
            }
        }

        // recompute window_hash
        // ! understand this.
        window_hash = ((window_hash - text[i]*h)*d + text[i+pattern.size()]) % q;

        if (window_hash < 0) {
            window_hash += q;
        }
    }
}

int main() {
    string text = "ABCAABCAB";
    string pattern = "ABC";
    search(text, pattern);
}