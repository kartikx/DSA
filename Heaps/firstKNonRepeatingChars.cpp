// Similar to Find first Non Repeating Character in a Stream.
// We would like to find the first K NRC in a single pass.
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void findFirstKNRC(string& text, int k) {
    list<char> l;
    vector<bool> repeated(26, false);
    vector<list<char>::iterator> nodes(26, l.end());

    for (char ch : text) {
        if (nodes[ch-'a'] != l.end()) {
            repeated[ch-'a'] = true;
            l.erase(nodes[ch-'a']);
            nodes[ch-'a'] = l.end();
        }

        else if (!repeated[ch-'a']) {
            l.push_back(ch);
            nodes[ch-'a'] = --l.end();
        }
    }

    auto it = l.begin();
    for (int i=0; i<k; i++) {
        if (it == l.end()) {
            cout << "Insufficient Characters!" << endl;
        }

        cout << *it << " ";
        it++;
    }
    cout << endl;
}

int main() {
    string text("ABCDBAGHCHFAC");
    transform(text.begin(), text.end(), text.begin(), ::tolower);
    findFirstKNRC(text, 3);
}