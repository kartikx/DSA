// Print all possible rotations of a string.
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// using std::rotate
// void printRotations(string& s) {
//     for (int i=0; i<s.length(); i++) {
//         cout << s << endl;
//         rotate(s.begin(), s.begin()+1, s.end());
//     }
// }

// without std::rotate
void printRotations(string& s) {
    for (int i=1; i<=s.length(); i++) {
        string s1 = s.substr(0, i);
        string s2 = s.substr(i);
        string s = s2.append(s1);
        cout << s << endl;
    }
}
int main() {
    // string s = "barua";
    // printRotations(s);
    while(true) {
        ;
    }
}