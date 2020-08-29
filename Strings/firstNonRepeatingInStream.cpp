// https://www.geeksforgeeks.org/find-first-non-repeating-character-stream-characters/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void firstNonRepeatingInStream(string& s) {
    // HEAD stores first non-repeating character. Subsequent items store
    // next non-repeating char.s, these elements may be removed as and when
    // an identical character is encountered.
    list<char> l;

    vector<bool> repeated(52, false);
    vector<list<char>::iterator> nodes(52, l.end());

    for (int i=0; i<s.length(); i++) {
        int index = s[i] - 'A';
        if (repeated[index]) {
            cout << l.front() << " ";
            continue;
        }
        
        if (nodes[index] == l.end()) {
            l.push_back(s[i]);
            auto it = l.end();
            nodes[index] = --it;
        }
        else {
            repeated[index] = true;
            l.erase(nodes[index]);
        }
        cout << l.front() << " "; 
    }
    cout << endl;
}

int main() {
    string s("GeeksForGeeks");
    firstNonRepeatingInStream(s);
}